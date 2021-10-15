#pragma once
#include <stdio.h>
#include <maya/MString.h>
#include <maya/MColor.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MRenderTargetManager.h>
#include <maya/MShaderManager.h>

// Scene render to output to targets
class sceneRenderMRT : public MHWRender::MSceneRender
{
public:
    sceneRenderMRT(const MString& name);
    virtual ~sceneRenderMRT();
    virtual MHWRender::MRenderTarget* const* targetOverrideList(unsigned int& listSize);
    virtual MHWRender::MClearOperation& clearOperation();
    virtual const MHWRender::MShaderInstance* shaderOverride();
    virtual MHWRender::MSceneRender::MSceneFilterOption renderFilterOverride();
    void setRenderTargets(MHWRender::MRenderTarget** targets);
    void setShader(MHWRender::MShaderInstance* shader)
    {
        mShaderInstance = shader;
    }
    void useViewportRect(bool val)
    {
        mUseViewportRect = val;
    }
    const MFloatPoint* viewportRectangleOverride();
protected:
    MHWRender::MRenderTarget** mTargets;
    MHWRender::MShaderInstance* mShaderInstance;
    MFloatPoint mViewRectangle;
    bool mUseViewportRect;
};
