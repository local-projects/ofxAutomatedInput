//
//  ofxAutomatedInputTouchEvent.h
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-16.
//
//

#pragma once

#include "ofMain.h"
#include "ofxAutomatedInputEvent.h"

//--------------------------------------------------------------
class ofxAutomatedInputTouchEvent
: public ofxAutomatedInputEvent
{
public:
    ofxAutomatedInputTouchEvent()
    : ofxAutomatedInputEvent(OFX_AUTOMATED_INPUT_TYPE_TOUCH)
    {}
    ofxAutomatedInputTouchEvent(float timeOffset, const ofTouchEventArgs& args)
    : ofxAutomatedInputEvent(timeOffset, OFX_AUTOMATED_INPUT_TYPE_TOUCH)
    , _args(args) {}
    
    void saveToXml(ofxXmlSettings& xml);
    void loadFromXml(ofxXmlSettings& xml, int idx);
    
    void setArgs(const ofTouchEventArgs& args) { _args = args; }
    ofTouchEventArgs& args() { return _args; }
    
protected:
    ofTouchEventArgs _args;
};
