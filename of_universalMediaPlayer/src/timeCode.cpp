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
                isLoaded = false;
            }
            
        }
        else{
            isLoaded = false;
        }
        
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
                isLoaded = false;
            }
            
        }
        
        
    }
}
