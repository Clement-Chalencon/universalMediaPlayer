//
//  messagePlayer.cpp
//  Radiologic
//
//  Created by Admin Mac on 28/07/2019.
//

#include "messagePlayer.hpp"

//------------------------------------------------
messagePlayer::messagePlayer(){
    
    init();
}


//------------------------------------------------
messagePlayer::messagePlayer(errorManager* e){
    
    error = e;
    init();
}

//------------------------------------------------
//                  INIT
//------------------------------------------------
void messagePlayer::init(){
    
    currentMsg = "";
    fontName = "font.ttf";
    //SetSize take as argument the biggest size
    setSize(120);


    //font.setSpaceSize(1);
    //font.setLineHeight(1);
    
    //Message option
    maxMessageLenght = 20;
    
    //Display
    display = false;
    messageOnScreen = false;
    fadeInDuration = 3;
    fadeOutDuration = 2;
    alpha = 0;
    
}

//------------------------------------------------
void messagePlayer::setMessage(string message){
    
    if(message.size()>maxMessageLenght){
        
        //SEND ERROR
        //message.shrink_to_fit(); //WHAT IS THAT ?
        string cutMessage = "";
        
        for(std::string::iterator it = message.begin(); it < message.end(); it++   ){
            cutMessage += *it;
        }
        
        currentMsg = cutMessage;
        
        
    }else{
        
        currentMsg = message;
        
    }
    
    //Force message to be directly display
    display = true;
    timeToFade = ofGetElapsedTimef();
    alpha = 0;

}

//------------------------------------------------
void messagePlayer::clear(){
    
    if(display){
        
        display = false;
        timeToFade = ofGetElapsedTimef();
        alpha = 255;
        
    }else{
        //SEND ERROR ... already clearing
        
    }

}


//------------------------------------------------
void messagePlayer::draw(){
    
    //TODO : never change video luminosity, but can add a grey filter on top of the video, then draw message.
    
    if(display){

        float timeFromFade = ofGetElapsedTimef() - timeToFade;
        //FADING IN
        if(timeFromFade < fadeInDuration){
            float percentage = timeFromFade/fadeInDuration;
            alpha = 255*percentage;
        }

    }else{

        float timeFromFade = ofGetElapsedTimef() - timeToFade;
        //FADING OUT
        if(timeFromFade < fadeOutDuration){
            float percentage = 1.0 - (timeFromFade/fadeOutDuration);
            alpha = 255*percentage;
        }

    }
    
    if(alpha > 0){
        //DISPLAY MESSAGE ONLY IF ALPHA > 0
        ofSetColor(255, 255, 255, alpha);
        
        //Create margin
        int marginX = 0;
        int marginY = 0;
        
        //TRY THE BIG FONT
        ofRectangle rectBig = fontBig.getStringBoundingBox(currentMsg, 10, ofGetHeight());
        if(rectBig.width < ofGetWidth()){
            
            marginX = (rectBig.width ) / 2;
            marginY = ( rectBig.height) /2;
            fontBig.drawString(currentMsg, ofGetWidth()/2 - marginX, ofGetHeight()/2 + marginY);
            
        }
        else
        {
            //TRY MEDIUM FONT
            ofRectangle rectMedium = fontMedium.getStringBoundingBox(currentMsg, 10, ofGetHeight());
            if(rectMedium.width < ofGetWidth()){
                
                marginX = (rectMedium.width ) / 2;
                marginY = ( rectMedium.height) /2;
                fontMedium.drawString(currentMsg, ofGetWidth()/2 - marginX, ofGetHeight()/2 + marginY);
                
            }
            else
            {
                //TRY SMALLER FONT
                ofRectangle rectSmall = fontSmall.getStringBoundingBox(currentMsg, 10, ofGetHeight());
                if(rectSmall.width < ofGetWidth()){
                    
                    marginX = (rectSmall.width ) / 2;
                    marginY = ( rectSmall.height) /2;
                    fontSmall.drawString(currentMsg, ofGetWidth()/2 - marginX, ofGetHeight()/2 + marginY);
                
                }
                else
                {
                    
                    //GIVE UP
                    error->setCurrentError("message too big, try to shrink it");
                }

            }

        
        
        }
    
    }
    
    if(alpha> 0){
        messageOnScreen = true;
    }else{
        messageOnScreen =false;
    }
    
    
    
}

//------------------------------------------------
void messagePlayer::setSize(int s){
    
    if(s > 12 && s < 150){
        fontSizeBig = s;
        fontSizeMedium = s-30;
        fontSizeSmall = s-60;
        
        setFont(fontName);
        
    }
    
    
}


//------------------------------------------------
void messagePlayer::setFont(string f){
    
    ofFile file = ofFile(f);
    if(file.exists()){
        
        fontBig.load(fontName, fontSizeBig);
        fontMedium.load(fontName, fontSizeMedium);
        fontSmall.load(fontName, fontSizeSmall);
        
    }else{
        
        error->setCurrentError("Font file does not exist");
        
    }
}

//------------------------------------------------
int messagePlayer::getAlpha(){
    
    return alpha;
}

//------------------------------------------------
void messagePlayer::setAlpha(int a){
    
        alpha = a;
    
}

//------------------------------------------------
void messagePlayer::setFadeIn(int duration){
    
    if(duration>0 && duration < 20){
        fadeInDuration = duration;
    }
    else{
        error->setCurrentError("Fade in, out of range value");
    }
    
}

//------------------------------------------------
void messagePlayer::setFadeOut(int duration){
    
    if(duration>0 && duration < 20){
        fadeOutDuration = duration;
    }
    else{
        error->setCurrentError("Fade out, out of range value");
    }
    
}

//-------------------------------------------------
bool messagePlayer::isMessageOnScreen(){
    
    return messageOnScreen;
    
}
