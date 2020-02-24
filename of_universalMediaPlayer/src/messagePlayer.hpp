//
//  messagePlayer.hpp
//  Radiologic
//
//  Created by Admin Mac on 28/07/2019.
//

#ifndef messagePlayer_hpp
#define messagePlayer_hpp

#include <stdio.h>
#include "ofMain.h"
#include "errorManager.hpp"

class messagePlayer{
    
public:
    messagePlayer();
    messagePlayer(errorManager* e);
    void init();
    void setFadeTime(int millis );
    void setFont(string f);
    void setMessage(string message);
    void setSize(int size);
    void setFadeIn(int duration);
    void setFadeOut(int duration);
    int getAlpha();
    void setAlpha(int a);
    void clear();
    void draw();
    
    string currentMsg;
    bool isMessageOnScreen();
    bool isFading();
    
    //Error Manager
    errorManager* error;
    
    
    
private:
    
    //Font to display
    ofTrueTypeFont fontBig;
    ofTrueTypeFont fontMedium;
    ofTrueTypeFont fontSmall;
    string fontName;
    int fontSizeBig;
    int fontSizeMedium;
    int fontSizeSmall;
    int maxMessageLenght;
    
    //Fade settings
    bool display;
    bool messageOnScreen;
    int fadeInDuration;
    int fadeOutDuration;
    float timeToFade;
    int alpha;
    
    
    
};

#endif /* messagePlayer_hpp */
