#pragma once
#include <stdio.h>
#include <maya/MString.h>
#include <maya/MColor.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MRenderTargetManager.h>
#include <maya/MShaderManager.h>
// Quad render
class quadRenderMRT : public MHWRender::MQuadRender
{
public:
    quadRenderMRT(const MString& name);
    ~quadRenderMRT();
    virtual const MHWRender::MShaderInstance* shader();
    virtual MHWRender::MRenderTarget* const* targetOverrideList(unsigned int& listSize);
    virtual MHWRender::MClearOperation& clearOperation();
    void setRenderTargets(MHWRender::MRenderTarget** targets, unsigned int count)
    {
        mOutputTargets = targets;
        mOutputTargetCount = count;
    }
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
    // Shader to use for the quad render
    MHWRender::MShaderInstance* mShaderInstance;
    // Output targets
    MHWRender::MRenderTarget** mOutputTargets;
    unsigned int mOutputTargetCount;
    MFloatPoint mViewRectangle;
    bool mUseViewportRect;
};

