//
//  ofxAutomatedInputTouchEvent.cpp
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-09-16.
//
//

#include "ofxAutomatedInputTouchEvent.h"

//--------------------------------------------------------------
void ofxAutomatedInputTouchEvent::saveToXml(ofxXmlSettings& xml)
{
    int tagIdx = xml.addTag("event");
    xml.addAttribute("event", "event_type", (int)_type, tagIdx);
    xml.pushTag("event", tagIdx);
    {
        xml.addValue("time_offset", _timeOffset);
        
        xml.addValue("type", (int)_args.type);
        xml.addValue("id", _args.id);
        xml.addValue("x", _args.x);
        xml.addValue("y", _args.y);
        xml.addValue("time", _args.time);
        xml.addValue("num_touches", _args.numTouches);
        xml.addValue("width", _args.width);
        xml.addValue("height", _args.height);
        xml.addValue("angle", _args.angle);
        xml.addValue("minoraxis", _args.minoraxis);
        xml.addValue("majoraxis", _args.majoraxis);
        xml.addValue("pressure", _args.pressure);
        xml.addValue("xspeed", _args.xspeed);
        xml.addValue("yspeed", _args.yspeed);
        xml.addValue("xaccel", _args.xaccel);
        xml.addValue("yaccel", _args.yaccel);
    }
    xml.popTag();
}

//--------------------------------------------------------------
void ofxAutomatedInputTouchEvent::loadFromXml(ofxXmlSettings& xml, int idx)
{
    setType((ofxAutomatedInputType)xml.getAttribute("event", "event_type", (int)OFX_AUTOMATED_INPUT_TYPE_TOUCH, idx));
    
    xml.pushTag("event", idx);
    {
        _timeOffset = xml.getValue("time_offset", 0);
        
        _args.type = (ofTouchEventArgs::Type)xml.getValue("type", (int)ofTouchEventArgs::move);
        _args.id = xml.getValue("id", 0);
        _args.x = xml.getValue("x", 0.0f);
        _args.y = xml.getValue("y", 0.0f);
        _args.time = xml.getValue("time", 0);
        _args.numTouches = xml.getValue("num_touches", 0);
        _args.width = xml.getValue("width", 0.0f);
        _args.height = xml.getValue("height", 0.0f);
        _args.angle = xml.getValue("angle", 0.0f);
        _args.minoraxis = xml.getValue("minoraxis", 0.0f);
        _args.majoraxis = xml.getValue("majoraxis", 0.0f);
        _args.pressure = xml.getValue("pressure", 0.0f);
        _args.xspeed = xml.getValue("xspeed", 0.0f);
        _args.yspeed = xml.getValue("yspeed", 0.0f);
        _args.xaccel = xml.getValue("xaccel", 0.0f);
        _args.yaccel = xml.getValue("yaccel", 0.0f);
    }
    xml.popTag();
}

//--------------------------------------------------------------
void ofxAutomatedInputTouchEvent::debug()
{
    ofPushStyle();
    
    const static float kMinTouchSize = 16.0f;
    
    ofSetLineWidth(2);
    ofNoFill();
    ofSetColor(255, 255);
    ofDrawEllipse(_args.x * ofGetWidth(), _args.y * ofGetHeight(), MAX(kMinTouchSize, _args.width), MAX(kMinTouchSize, _args.height));
    
    ofFill();
    ofSetColor(255, 127);
    ofDrawEllipse(_args.x * ofGetWidth(), _args.y * ofGetHeight(), MAX(kMinTouchSize, _args.width), MAX(kMinTouchSize, _args.height));
    
    ofPopStyle();
}
