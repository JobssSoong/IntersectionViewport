#include "UserOperationMRT.h"

userOperationMRT::userOperationMRT(const MString& name)
    : MUserRenderOperation(name)
{
    mTargets = NULL;
}
userOperationMRT::~userOperationMRT()
{
    mTargets = NULL;
}
MStatus userOperationMRT::execute(const MHWRender::MDrawContext& drawContext)
{
    // Empty execute
    return MStatus::kSuccess;
}
MHWRender::MRenderTarget* const*
userOperationMRT::targetOverrideList(unsigned int& listSize)
{
    if (mTargets)
    {
        listSize = 2;
        return &mTargets[0];
    }
    return NULL;
}
