#pragma once
#include <stdio.h>
#include <maya/MString.h>
#include <maya/MColor.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MRenderTargetManager.h>
#include <maya/MShaderManager.h>
// User operation
class userOperationMRT : public MHWRender::MUserRenderOperation
{
public:
    userOperationMRT(const MString& name);
    virtual ~userOperationMRT();
    virtual MStatus execute(const MHWRender::MDrawContext& drawContext);
    virtual MHWRender::MRenderTarget* const* targetOverrideList(unsigned int& listSize);
    void setRenderTargets(MHWRender::MRenderTarget** targets)
    {
        mTargets = targets;
    }
protected:
    // Output targets
    MHWRender::MRenderTarget** mTargets;
};
