#include <maya/MSyntax.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MArgDatabase.h>
#include <maya/MGlobal.h>
#include <maya/M3dView.h>
#include "IntersectionCmd.h"
#include "viewRenderOverrideMRT.h"
IntersetcionCmd::IntersetcionCmd() : displayColor(true)
{
}
IntersetcionCmd::~IntersetcionCmd()
{
}
void* IntersetcionCmd::creator()
{
    return (void*)(new IntersetcionCmd);
}
MSyntax IntersetcionCmd::newSyntax()
{
    MSyntax syntax;
    syntax.addFlag(kDisplayColor, kDisplayColorLong, MSyntax::kBoolean);
    syntax.addFlag(kShaderSearchPath, kShaderSearchPathLong, MSyntax::kString);
    syntax.enableQuery(true);
    return syntax;
}
MStatus IntersetcionCmd::doIt(const MArgList& args)
{
    MStatus status = MStatus::kFailure;
    MHWRender::MRenderer* renderer = MHWRender::MRenderer::theRenderer();
    if (!renderer)
    {
        MGlobal::displayError("VP2 renderer not initialized.");
        return status;
    }
    viewRenderOverrideMRT* _viewRenderOverrideMRT = NULL;
    _viewRenderOverrideMRT = (viewRenderOverrideMRT*)renderer->findRenderOverride("my_viewRenderOverrideMRT");
    if (_viewRenderOverrideMRT == NULL)
    {
        MGlobal::displayError("my_viewRenderOverrideMRT is not registered.");
        return status;
    }
    MArgDatabase argData(syntax(), args, &status);
    if (!status)
        return status;
    bool isQuery = argData.isQuery();
    if (argData.isFlagSet(kDisplayColor))
    {
        _viewRenderOverrideMRT->displayColor = !_viewRenderOverrideMRT->displayColor;
    }

    MArgParser parser = MArgParser(newSyntax(), args);
    if (argData.isFlagSet(kShaderSearchPath))
    {
        MString _shaderSearchPath;
        parser.getFlagArgument(kShaderSearchPath, 0, _shaderSearchPath);
        _viewRenderOverrideMRT->addShaderSearchPath(_shaderSearchPath);
    }
    M3dView view = M3dView::active3dView(&status);
    if (!status)
    {
        MGlobal::displayWarning("Failed to find an active 3d view.");
        return status;
    }
    view.refresh(false, true);
    return MStatus::kSuccess;
}