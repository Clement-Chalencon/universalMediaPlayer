//
//  errorManager.cpp
//  Radiologic
//
//  Created by Admin Mac on 28/07/2019.
//

#include "errorManager.hpp"

//------------------------------------------------------
// Error Manager print verbose info and error directly on the screen
//------------------------------------------------------
errorManager::errorManager(){
    
    marginX = 20;
    marginY = 50;
    
    for(int i=0; i<MAX_MSG; i++){
        
        timeLastError[i] = ofGetElapsedTimef();
        timeLastInfo[i] = ofGetElapsedTimef();
        currentError[i] = "";
        currentInfo[i] = "INFO";
        
    }
    
    errorDuration = 7;
    infoDuration = 7;
	isHidden = true;

}


//------------------------------------------------------
void errorManager::draw(){
    
    ofSetColor(255);
    
    //PRINT ERROR
    
    for(int i=0; i<MAX_MSG; i++){
        
        if(ofGetElapsedTimef() - timeLastError[i] < errorDuration)
            ofDrawBitmapStringHighlight(currentError[i], marginX, marginY + (MAX_MSG - i)*30);
        else{
            //TOO OLD, delete it
            currentError[i] = "";
        }
        
        if(ofGetElapsedTimef() - timeLastInfo[i] < infoDuration)
            ofDrawBitmapStringHighlight(currentInfo[i], ofGetWidth()/2 + marginX, marginY+ (MAX_MSG -i)*30, ofColor::black, ofColor::green);
        else{
            //TOO OLD DELETE IT
            currentInfo[i] = "";
        }
    }
}

//------------------------------------------------------
void errorManager::setCurrentError( string s){
    
    //CHECK IF THERE IS EMPTY MESSAGE
    for(int i=0; i<MAX_MSG; i++){
    
       if(currentError[i] == ""){
           //EMPTY MESSAGE - WRITE INTO IT
           currentError[i] = s;
           timeLastError[i] = ofGetElapsedTimef();
           break;
           
       }
       
   }
    // IF NOT DELETE OLDEST MESSAGE
    for(int i=0; i<(MAX_MSG-1); i++){
        currentError[i] = currentError[i+1];
        timeLastError[i] = timeLastError[i+1];
    }
    currentError[(MAX_MSG-1)]=s;
    timeLastError[(MAX_MSG-1)] = ofGetElapsedTimef();

}

//------------------------------------------------------
void errorManager::setCurrentInfo( string s){
    
    //CHECK IF THERE IS EMPTY MESSAGE
    for(int i=0; i<MAX_MSG; i++){
        
        if(currentInfo[i] == ""){
            //EMPTY MESSAGE - WRITE INTO IT
            currentInfo[i] = s;
            timeLastInfo[i] = ofGetElapsedTimef();
            break;
            
        }
        
    }
    // IF NOT DELETE OLDEST MESSAGE
    for(int i=0; i<(MAX_MSG-1); i++){
        currentInfo[i] = currentInfo[i+1];
        timeLastInfo[i] = timeLastInfo[i+1];
    }
    currentInfo[(MAX_MSG-1)]=s;
    timeLastInfo[(MAX_MSG-1)] = ofGetElapsedTimef();
    
}

