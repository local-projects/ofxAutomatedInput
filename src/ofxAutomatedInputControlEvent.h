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
    enum Action
    {
        Start,
        Stop,
	};
    
    ofxAutomatedInputControlEvent()
    : ofxAutomatedInputEvent(OFX_AUTOMATED_INPUT_TYPE_CONTROL) {}
    ofxAutomatedInputControlEvent(float timeOffset, Action action)
    : ofxAutomatedInputEvent(timeOffset, OFX_AUTOMATED_INPUT_TYPE_CONTROL)
    , _action(action) {}
    
    void saveToXml(ofxXmlSettings& xml);
    void loadFromXml(ofxXmlSettings& xml, int idx);
    
    void setAction(Action action) { _action = action; }
    Action action() { return _action; }
    
protected:
    Action _action;
};
