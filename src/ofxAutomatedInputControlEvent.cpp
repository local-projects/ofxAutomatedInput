//
//  ofxAutomatedInputControlEvent.cpp
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-19.
//
//

#include "ofxAutomatedInputControlEvent.h"

//--------------------------------------------------------------
void ofxAutomatedInputControlEvent::saveToXml(ofxXmlSettings& xml)
{
    int tagIdx = xml.addTag("event");
    xml.addAttribute("event", "event_type", (int)_type, tagIdx);
    xml.pushTag("event", tagIdx);
    {
        xml.addValue("time_offset", _timeOffset);
        
        xml.addValue("action", (int)_action);
    }
    xml.popTag();
}

//--------------------------------------------------------------
void ofxAutomatedInputControlEvent::loadFromXml(ofxXmlSettings& xml, int idx)
{
    setType((ofxAutomatedInputType)xml.getAttribute("event", "event_type", (int)OFX_AUTOMATED_INPUT_TYPE_CONTROL, idx));
    
    xml.pushTag("event", idx);
    {
        _timeOffset = xml.getValue("time_offset", 0);
        
        _action = (ofxAutomatedInputControlEvent::Action)xml.getValue("action", (int)ofxAutomatedInputControlEvent::Start);
    }
    xml.popTag();
}
