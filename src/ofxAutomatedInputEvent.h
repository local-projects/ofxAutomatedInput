//
//  ofxAutomatedInputEvent.h
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-16.
//  Based on https://github.com/HeliosInteractive/ofxAutomatedInput
//

#pragma once

#include "ofxXmlSettings.h"

//--------------------------------------------------------------
enum ofxAutomatedInputType
{
    OFX_AUTOMATED_INPUT_TYPE_NONE  = 0x0000,
    OFX_AUTOMATED_INPUT_TYPE_MOUSE = 0x0001,
    OFX_AUTOMATED_INPUT_TYPE_KEY   = 0x0010,
    OFX_AUTOMATED_INPUT_TYPE_TOUCH = 0x0100,
    OFX_AUTOMATED_INPUT_TYPE_ALL   = 0x1111,
};

//--------------------------------------------------------------
class ofxAutomatedInputEvent
{
public:
    ofxAutomatedInputEvent(ofxAutomatedInputType type = OFX_AUTOMATED_INPUT_TYPE_NONE)
    : _type(type) {}
    ofxAutomatedInputEvent(float timeOffset, ofxAutomatedInputType type = OFX_AUTOMATED_INPUT_TYPE_NONE)
    : _type(type)
    , _timeOffset(timeOffset) {}
    virtual ~ofxAutomatedInputEvent() {}
    
    virtual void saveToXml(ofxXmlSettings& xml) = 0;
    virtual void loadFromXml(ofxXmlSettings& xml, int idx) = 0;
    
    virtual void debug() {}
    
    void setType(ofxAutomatedInputType type) { _type = type; }
    ofxAutomatedInputType type() const { return _type; }
    
    void setTimeOffset(long timeOffset) { _timeOffset = timeOffset; }
    long timeOffset() const { return _timeOffset; }
    
protected:
    ofxAutomatedInputType _type;
    
    float _timeOffset;
};
