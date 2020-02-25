//
//  timeCode.hpp
//  of_universalMediaPlayer
//
//  Created by Admin Mac on 24/02/2020.
//

#ifndef timeCode_hpp
#define timeCode_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxCsv.h"
#include "oscSender.hpp"

class timeCode{
    
    public :
    timeCode();
    void loadFile(string name);
    void update(int fps);
    void printTimeCode();
    void unload();
    
    bool isEnabled;
    bool isLoaded;
    bool doPrintTimeCode;
    int index;
    ofxCsv csv;
    vector<int> listOfFrame;
    vector<int> listOfMemory;
    oscSender* oscsender;
    
};

#endif /* timeCode_hpp */
