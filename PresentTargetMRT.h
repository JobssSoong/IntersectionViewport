#pragma once
#include <stdio.h>
#include <maya/MString.h>
#include <maya/MColor.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MRenderTargetManager.h>
#include <maya/MShaderManager.h>
// Present operation to present to screen
class presentTargetMRT : public MHWRender::MPresentTarget
{
public:
    presentTargetMRT(const MString& name);
    virtual ~presentTargetMRT();
    virtual MHWRender::MRenderTarget* const* targetOverrideList(unsigned int& listSize);
    void setRenderTargets(MHWRender::MRenderTarget** targets);
protected:
    MHWRender::MRenderTarget** mTargets;
};



