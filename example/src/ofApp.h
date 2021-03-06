//
//  ofApp.h
//  ofxAutomatedInputExample
//
//  Created by Elie Zananiri on 2014-09-16.
//
//

#pragma once

#include "ofMain.h"
#include "ofxAutomatedInput.h"

//--------------------------------------------------------------
class ofApp
: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
//    void windowResized(int w, int h);
//    void dragEvent(ofDragInfo dragInfo);
//    void gotMessage(ofMessage msg);
    
    void automatedInputPlaybackStarted(long long& duration);
    void automatedInputPlaybackStopped(long long& duration);
    
    ofxAutomatedInput automatedInput;
    bool bDebug;
    string typedKeys;
};
