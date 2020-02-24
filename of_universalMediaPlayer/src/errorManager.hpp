//
//  errorManager.hpp
//  Radiologic
//
//  Created by Admin Mac on 28/07/2019.
//

#ifndef errorManager_hpp
#define errorManager_hpp

#include <stdio.h>
#include "ofMain.h"

#define MAX_MSG 10

class errorManager{
    
public:
    errorManager();
    
    void draw();
    void clear();
    void setCurrentError( string s);
    void setCurrentInfo( string s);
    
    //BASIC
    bool isHidden;
    
    //ERROR MESSAGE
    float timeLastError[MAX_MSG];
    float errorDuration;
    string currentError[MAX_MSG];
    
    //INFO MESSAGE
    float timeLastInfo[MAX_MSG];
    float infoDuration;
    string currentInfo[MAX_MSG];
    
    int size;
    int marginX;
    int marginY;
    
    
    
};

#endif /* errorManager_hpp */
