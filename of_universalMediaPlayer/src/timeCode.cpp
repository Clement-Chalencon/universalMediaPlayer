//
//  timeCode.cpp
//  of_universalMediaPlayer
//
//  Created by Admin Mac on 24/02/2020.
//

#include "timeCode.hpp"

#include "ofMain.h"

timeCode::timeCode(){
    
    isEnabled = true;
    isLoaded = false;
    doPrintTimeCode = false;
    index = 0;
    listOfFrame.clear();
    listOfMemory.clear();
    
}

void timeCode::loadFile(string f){
    
    ofFile file;
    //CHECK IF FILE EXIST
    if(file.doesFileExist(f) ){
        
        if(csv.load(f)){
            if(csv.getNumRows()>0 &&  csv.getNumCols()>1){
                listOfFrame.clear();
                listOfMemory.clear();
                isLoaded = true;
                
                 for(int i = 0; i < csv.getNumRows(); i++) {
                     
                     listOfFrame.push_back(ofToInt(csv[i][0]));
                     listOfMemory.push_back(ofToInt(csv[i][1]));
                     index = 0;

                 }
                
            }
            else{
                // MISSING ROW OR COLUMNS
                unload();
            }
            
        }
        else{
            //ERROR LOADING CSV FILE
            unload();
        }
        
    }
    else{
        //FILE DOES NOT EXSIT
        unload();
        
    }
    
    
}

void timeCode::update(int fps){
    
    if(isEnabled && isLoaded){
     
        if(fps > listOfFrame[index]){
            
            oscsender->send("/light/memory", listOfMemory[index]);
            //SEND OSC message listOfMemory[index]
            
            if(index < (listOfFrame.size()-1)){
                
                index++;
            }
            else{
                //END OF CSV FILE , unload it
                unload();
            }
            
        }
        
        
    }
}

void timeCode::printTimeCode(){
    
    string title;
    if(isLoaded){
        title = "timeCode : LOADED";
    }else{
        title = "timeCode : NOT loaded";
    }
    ofDrawBitmapString(title, 20, ofGetHeight()*0.75 - 12);
    for(int i=0; i<listOfFrame.size(); i++){
        if(i == index) ofSetColor(ofColor::red);
        else ofSetColor(255);
        ofDrawBitmapString(ofToString(i)+") "+ofToString(listOfFrame[i])+ " :: "+ofToString(listOfMemory[i]), 20, ofGetHeight()*0.75 + i*12);
        
    }
    
}

void timeCode::unload(){
    
    isLoaded = false;
    listOfMemory.clear();
    listOfFrame.clear();
    index = 0;
    
}
