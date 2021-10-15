#include "QuadRenderMRT.h"
quadRenderMRT::quadRenderMRT(const MString& name)
    : MQuadRender(name)
    , mShaderInstance(NULL)
{
    mOutputTargetCount = 0;
    mOutputTargets = NULL;
    mViewRectangle[0] = 0.1f;
    mViewRectangle[1] = 0.1f;
    mViewRectangle[2] = 0.8f;
    mViewRectangle[3] = 0.8f;
    mUseViewportRect = false;
}
quadRenderMRT::~quadRenderMRT()
{
    mOutputTargetCount = 0;
    mOutputTargets = NULL;
    mShaderInstance = NULL;
}
const MHWRender::MShaderInstance*
quadRenderMRT::shader()
{
    return mShaderInstance;
}
MHWRender::MRenderTarget* const*
quadRenderMRT::targetOverrideList(unsigned int& listSize)
{
    if (mOutputTargets)
    {
        listSize = mOutputTargetCount;
        return &mOutputTargets[0];
    }
    listSize = 0;
    return NULL;
}
const MFloatPoint*
quadRenderMRT::viewportRectangleOverride()
{
    if (mUseViewportRect)
        return &mViewRectangle;
    return NULL;
}
MHWRender::MClearOperation&
quadRenderMRT::clearOperation()
{
    mClearOperation.setMask((unsigned int)MHWRender::MClearOperation::kClearAll);
    return mClearOperation;
}
