//
//  ofxAutomatedInputMouseEvent.cpp
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-16.
//  Based on https://github.com/HeliosInteractive/ofxAutomatedInput
//

#include "ofxAutomatedInputMouseEvent.h"

//--------------------------------------------------------------
void ofxAutomatedInputMouseEvent::saveToXml(ofxXmlSettings& xml)
{
    int tagIdx = xml.addTag("event");
    xml.addAttribute("event", "event_type", (int)_type, tagIdx);
    xml.pushTag("event", tagIdx);
    {
        xml.addValue("time_offset", _timeOffset);
        
        xml.addValue("type", (int)_args.type);
        xml.addValue("button", _args.button);
        xml.addValue("x", _args.x);
        xml.addValue("y", _args.y);
    }
    xml.popTag();
}

//--------------------------------------------------------------
void ofxAutomatedInputMouseEvent::loadFromXml(ofxXmlSettings& xml, int idx)
{
    setType((ofxAutomatedInputType)xml.getAttribute("event", "event_type", (int)OFX_AUTOMATED_INPUT_TYPE_MOUSE, idx));
    
    xml.pushTag("event", idx);
    {
        _timeOffset = xml.getValue("time_offset", 0);
        
        _args.type = (ofMouseEventArgs::Type)xml.getValue("type", (int)ofMouseEventArgs::Moved);
        _args.button = xml.getValue("button", 0);
        _args.x = xml.getValue("x", 0.0f);
        _args.y = xml.getValue("y", 0.0f);
    }
    xml.popTag();
}
