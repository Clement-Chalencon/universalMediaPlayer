#include "ofMain.h"
#include "PlatformConfig.h"


#include "ofApp.h"

//========================================================================
int main( ){
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    
    //Change to YUV system for B&W video issue
    // https://forum.openframeworks.cc/t/videoplayerexample-on-raspberrypi/18525/14
    ofGLESWindowSettings settings;
#ifndef RADIOLOGIC_OMX
    
    settings.setGLESVersion(2);
#endif
    
    // SET FULLSCREEN ON RPI
    #ifdef __arm__
    settings.windowMode = OF_FULLSCREEN;
    #endif
    // SET WINDOWED ON LAPTOP
    #ifdef __APPLE__
    settings.windowMode = OF_WINDOW;
    #endif
    ofCreateWindow(settings);

	ofRunApp(new ofApp());

}
