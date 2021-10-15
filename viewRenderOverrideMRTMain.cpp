#include <stdio.h>
#include <maya/MString.h>
#include <maya/MFnPlugin.h>
#include <maya/MViewport2Renderer.h>
#include "viewRenderOverrideMRT.h"
#include "IntersectionCmd.h"
static viewRenderOverrideMRT* viewRenderOverrideMRTInstance = NULL;
MStatus initializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj, PLUGIN_COMPANY, "1.0", "Any");
    MHWRender::MRenderer* renderer = MHWRender::MRenderer::theRenderer();
    if (renderer)
    {
        if (!viewRenderOverrideMRTInstance)
        {
            viewRenderOverrideMRTInstance = new viewRenderOverrideMRT("my_viewRenderOverrideMRT");
            renderer->registerOverride(viewRenderOverrideMRTInstance);
        }
        plugin.registerCommand(commandName,
            IntersetcionCmd::creator,
            IntersetcionCmd::newSyntax);
    }
    return status;
}
MStatus uninitializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj);
    MHWRender::MRenderer* renderer = MHWRender::MRenderer::theRenderer();
    if (renderer)
    {
        if (viewRenderOverrideMRTInstance)
        {
            renderer->deregisterOverride(viewRenderOverrideMRTInstance);
            delete viewRenderOverrideMRTInstance;
        }
        viewRenderOverrideMRTInstance = NULL;
        plugin.deregisterCommand(commandName);
    }
    return status;
}