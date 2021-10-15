#include "PresentTargetMRT.h"
presentTargetMRT::presentTargetMRT(const MString& name)
    : MPresentTarget(name)
{
    mTargets = NULL;
}
presentTargetMRT ::~presentTargetMRT()
{
    mTargets = NULL;
}
/* virtual */
MHWRender::MRenderTarget* const*
presentTargetMRT::targetOverrideList(unsigned int& listSize)
{
    if (mTargets)
    {
        listSize = 2;
        return &mTargets[0];
    }
    listSize = 0;
    return NULL;
}
void
presentTargetMRT::setRenderTargets(MHWRender::MRenderTarget** targets)
{
    mTargets = targets;
}
