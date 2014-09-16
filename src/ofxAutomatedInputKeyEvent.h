//
//  ofxAutomatedInputKeyEvent.h
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-16.
//
//

#pragma once

#include "ofMain.h"
#include "ofxAutomatedInputEvent.h"

//--------------------------------------------------------------
class ofxAutomatedInputKeyEvent
: public ofxAutomatedInputEvent
{
public:
    ofxAutomatedInputKeyEvent()
    : ofxAutomatedInputEvent(OFX_AUTOMATED_INPUT_TYPE_KEY)
    {}
    ofxAutomatedInputKeyEvent(float timeOffset, const ofKeyEventArgs& args)
    : ofxAutomatedInputEvent(timeOffset, OFX_AUTOMATED_INPUT_TYPE_KEY)
    , _args(args) {}
    
    void saveToXml(ofxXmlSettings& xml);
    void loadFromXml(ofxXmlSettings& xml, int idx);
    
    void setArgs(const ofKeyEventArgs& args) { _args = args; }
    ofKeyEventArgs& args() { return _args; }
    
protected:
    ofKeyEventArgs _args;
};
