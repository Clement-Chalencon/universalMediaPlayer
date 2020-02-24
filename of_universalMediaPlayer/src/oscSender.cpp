//
//  oscSender.cpp
//  of_universalMediaPlayer
//
//  Created by Admin Mac on 24/02/2020.
//

#include "oscSender.hpp"

oscSender::oscSender(){
}

oscSender::oscSender(string adress, int port){
    
    sender.setup(adress, port);
}

void oscSender::send(string ad, int num){
    ofxOscMessage m;
    m.setAddress(ad);
    m.addIntArg(num);
    sender.sendMessage(m, false);
}


void oscSender::send(string ad, float f1, float f2, float f3){
    
    ofxOscMessage m;
    m.setAddress(ad);
    m.addFloatArg(f1);
    m.addFloatArg(f2);
    m.addFloatArg(f3);
    sender.sendMessage(m, false);
}


#include "oscSender.hpp"
