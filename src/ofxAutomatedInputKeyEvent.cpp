//
//  ofxAutomatedInputKeyEvent.cpp
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-16.
//  
//

#include "ofxAutomatedInputKeyEvent.h"

//--------------------------------------------------------------
void ofxAutomatedInputKeyEvent::saveToXml(ofxXmlSettings& xml)
{
    int tagIdx = xml.addTag("event");
    xml.addAttribute("event", "event_type", (int)_type, tagIdx);
    xml.pushTag("event", tagIdx);
    {
        xml.addValue("time_offset", _timeOffset);
        
        xml.addValue("type", (int)_args.type);
        xml.addValue("key", _args.key);
        xml.addValue("keycode", _args.keycode);
        xml.addValue("scancode", _args.scancode);
        xml.addValue("codepoint", (int)_args.codepoint);
    }
    xml.popTag();
}

//--------------------------------------------------------------
void ofxAutomatedInputKeyEvent::loadFromXml(ofxXmlSettings& xml, int idx)
{
    setType((ofxAutomatedInputType)xml.getAttribute("event", "event_type", (int)OFX_AUTOMATED_INPUT_TYPE_KEY, idx));
    
    xml.pushTag("event", idx);
    {
        _timeOffset = xml.getValue("time_offset", 0);
        
        _args.type = (ofKeyEventArgs::Type)xml.getValue("type", (int)ofKeyEventArgs::Pressed);
        _args.key = xml.getValue("key", 32);
        _args.keycode = xml.getValue("keycode", 0);
        _args.scancode = xml.getValue("scancode", 0);
        _args.codepoint = (unsigned int)xml.getValue("codepoint", 0);
    }
    xml.popTag();
}
