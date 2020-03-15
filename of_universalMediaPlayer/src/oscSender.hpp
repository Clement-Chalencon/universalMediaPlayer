//
//  oscSender.hpp
//  of_universalMediaPlayer
//
//  Created by Admin Mac on 24/02/2020.
//

#ifndef oscSender_hpp
#define oscSender_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOscSender.h"


class oscSender{
    
public:
    oscSender();
    oscSender(string s, int p);
    ofxOscSender sender;
    int port;
    void send(string ad, int num);
    void send(string ad, string word);
	void send(string ad, string word, int index);
    void send(string add, float f1, float f2, float f3);
    
    
};

#endif /* oscSender_hpp */
