
#include "FORZE.h"
using namespace FORZE;


// CUSTOM SUBCLASS OF FORZE::SCENE
class HelloWorld : public Scene {
public:
    HelloWorld()
    {
        // Label with text and font filename.d
        Label *label = new Label("Hello world!", "helvdetica.fnt");
        
        // Place label at the middle of the layer
        label->setPosition(getContentSize() /2);
        
        // Attach label to the layer
        addChild(label);
    }
};


// APPLICATION DELEGATE
class AppDelegate : public ApplicationProtocol {
public:
    AppDelegate() {}
    
    void applicationLaunched(void *options)
    {
        // INITIALIZE HELLOWORLD SCENE
        HelloWorld *scene = new HelloWorld();
        
        // PUSH SCENE
        Director::Instance().pushScene(scene);
    }
};


// APPLICATION'S ENTRY POINT
int main(int argc, char *argv[])
{
    FORZE_INIT(new AppDelegate(), kFZSize_iPhone, argc, argv);
    return EXIT_SUCCESS;
}