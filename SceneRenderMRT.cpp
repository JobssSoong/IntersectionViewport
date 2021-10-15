#include "SceneRenderMRT.h"

sceneRenderMRT::sceneRenderMRT(const MString& name)
    : MSceneRender(name)
{
    float val[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
    mClearOperation.setClearColor(val);
    mTargets = NULL;
    mShaderInstance = NULL;
    mViewRectangle[0] = 0.1f;
    mViewRectangle[1] = 0.1f;
    mViewRectangle[2] = 0.8f;
    mViewRectangle[3] = 0.8f;
    mUseViewportRect = false;
}
sceneRenderMRT ::~sceneRenderMRT()
{
    mTargets = NULL;
    mShaderInstance = NULL;
}
/* virtual */
MHWRender::MRenderTarget* const*
sceneRenderMRT::targetOverrideList(unsigned int& listSize)
{
    if (mTargets)
    {
        listSize = 2;
        return &mTargets[0];
    }
    return NULL;
}
/* virtual */
MHWRender::MClearOperation&
sceneRenderMRT::clearOperation()
{
    mClearOperation.setMask((unsigned int)
        (MHWRender::MClearOperation::kClearDepth | MHWRender::MClearOperation::kClearStencil));
    return mClearOperation;
}
/* virtual */
const MHWRender::MShaderInstance* sceneRenderMRT::shaderOverride()
{
    return mShaderInstance;
}
/* virtual */
// We only care about the opaque objects
MHWRender::MSceneRender::MSceneFilterOption sceneRenderMRT::renderFilterOverride()
{
    return MHWRender::MSceneRender::kRenderOpaqueShadedItems;
}
void
sceneRenderMRT::setRenderTargets(MHWRender::MRenderTarget** targets)
{
    mTargets = targets;
}
const MFloatPoint*
sceneRenderMRT::viewportRectangleOverride()
{
    if (mUseViewportRect)
        return &mViewRectangle;
    return NULL;
}