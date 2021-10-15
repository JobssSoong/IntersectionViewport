#include <maya/MPxCommand.h>
/*
    Command arguments and command name
*/
#define kDisplayColor      "-dc"
#define kDisplayColorLong  "-displayColor"

#define kShaderSearchPath  "-ssp"
#define kShaderSearchPathLong  "-shaderSearchPath"

#define commandName         "intersectionViewport"
/*
    Command class declaration
*/
class IntersetcionCmd : public MPxCommand
{
public:
    IntersetcionCmd();
    virtual         ~IntersetcionCmd();
    MStatus         doIt(const MArgList& args);
    static MSyntax  newSyntax();
    static void* creator();
private:
    bool            displayColor;
};