//
//  ofxAutomatedInputMouseEvent.h
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-16.
//  Based on https://github.com/HeliosInteractive/ofxAutomatedInput
//

#pragma once

#include "ofMain.h"
#include "ofxAutomatedInputEvent.h"

//--------------------------------------------------------------
class ofxAutomatedInputMouseEvent
: public ofxAutomatedInputEvent
{
public:
    ofxAutomatedInputMouseEvent()
    : ofxAutomatedInputEvent(OFX_AUTOMATED_INPUT_TYPE_MOUSE)
    {}
    ofxAutomatedInputMouseEvent(float timeOffset, const ofMouseEventArgs& args)
    : ofxAutomatedInputEvent(timeOffset, OFX_AUTOMATED_INPUT_TYPE_MOUSE)
    , _args(args) {}
    
    void saveToXml(ofxXmlSettings& xml);
    void loadFromXml(ofxXmlSettings& xml, int idx);
    
    void debug();
    
    void setArgs(const ofMouseEventArgs& args) { _args = args; }
    ofMouseEventArgs& args() { return _args; }
    
protected:
    ofMouseEventArgs _args;
};
