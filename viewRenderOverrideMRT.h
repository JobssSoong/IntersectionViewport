#include <stdio.h>
#include <maya/MString.h>
#include <maya/MColor.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MRenderTargetManager.h>
#include <maya/MShaderManager.h>


#include "PresentTargetMRT.h"
#include "QuadRenderMRT.h"
#include "SceneRenderMRT.h"
#include "UserOperationMRT.h"

class viewRenderOverrideMRT : public MHWRender::MRenderOverride
{
public:
    enum
    {
        kTargetClear,
        kFirstDepthRender,
        kSecondDepthRender,
        kUserOp,
        kTargetPreview,
        kPresentOp,
        kOperationCount
    };
    enum {
        kFirstDepthColor = 0,    // Intermediate target 1
        kFirstIDColor,        // Intermediate target 2
        kSecondDepthColor,
        kSecondIDColor,
        kTargetCount
    };
    enum {
        kTargetClearShader,     // To clear targets to specific color
        kFirstDepthBufferShader,  // To render first buffer
        kSecondDepthBufferShader, //To render second buffer
        kTargetPreviewShader,   // To preview targets
        kShaderCount
    };
    viewRenderOverrideMRT(const MString& name);
    virtual ~viewRenderOverrideMRT();
    virtual MHWRender::DrawAPI supportedDrawAPIs() const;
    virtual bool startOperationIterator();
    virtual MHWRender::MRenderOperation* renderOperation();
    virtual bool nextRenderOperation();
    virtual MStatus setup(const MString& destination);
    virtual MStatus cleanup();
    virtual MString uiName() const
    {
        return mUIName;
    }
    void addShaderSearchPath(MString _path);
    bool displayColor = true;
protected:
    MStatus updateRenderOperations();

    MStatus updateRenderTargets(MHWRender::MRenderer* theRenderer,
        const MHWRender::MRenderTargetManager* targetManager);

    MStatus updateShaders(const MHWRender::MShaderManager* shaderMgr);
    

    MString mUIName;
    MColor mClearColor;


    MHWRender::MRenderOperation* mRenderOperations[kOperationCount];
    MString mRenderOperationNames[kOperationCount];
    bool mRenderOperationEnabled[kOperationCount];
    int mCurrentOperation;


    MString mTargetOverrideNames[kTargetCount];
    MHWRender::MRenderTargetDescription* mTargetDescriptions[kTargetCount];
    MHWRender::MRenderTarget* mTargets[kTargetCount];


    MHWRender::MShaderInstance* mShaderInstances[kShaderCount];
};









