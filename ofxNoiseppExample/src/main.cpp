#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main(){
    #ifdef OF_TARGET_OPENGLES
        ofGLESWindowSettings settings;
        //settings.setSize(1920, 1080);
        settings.glesVersionMajor = 3;
        settings.glesVersionMinor = 0;
    #else
        ofGLWindowSettings settings;
        settings.setSize(1920, 1080);
        settings.setGLVersion(3, 3);
    #endif
    ofCreateWindow(settings);

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
}

