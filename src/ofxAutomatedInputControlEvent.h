//
//  ofxAutomatedInputControlEvent.h
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-19.
//
//

#pragma once

#include "ofMain.h"
#include "ofxAutomatedInputEvent.h"

//--------------------------------------------------------------
class ofxAutomatedInputControlEvent
: public ofxAutomatedInputEvent
{
public:
    enum Type
    {
        Start,
        Stop,
	};
    
    ofxAutomatedInputControlEvent()
    : ofxAutomatedInputEvent(OFX_AUTOMATED_INPUT_TYPE_CONTROL) {}
    ofxAutomatedInputControlEvent(float timeOffset, Type type)
    : ofxAutomatedInputEvent(timeOffset, OFX_AUTOMATED_INPUT_TYPE_CONTROL)
    , _type(type) {}
    
    void saveToXml(ofxXmlSettings& xml);
    void loadFromXml(ofxXmlSettings& xml, int idx);
    
    void setType(Type type) { _type = type; }
    Type type() { return _type; }
    
protected:
    Type _type;
};
