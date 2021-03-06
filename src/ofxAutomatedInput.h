//
//  ofxAutomatedInput.h
//  ofxAutomatedInput
//
//  Created by Elie Zananiri on 2014-07-05.
//  Based on https://github.com/HeliosInteractive/ofxAutomatedInput
//

#pragma once

#include "ofMain.h"
#include "ofxAutomatedInputEvent.h"
#include "ofxXmlSettings.h"

//--------------------------------------------------------------
enum ofxAutomatedInputMode
{
    OFX_AUTOMATED_INPUT_MODE_IDLE = 0,
    OFX_AUTOMATED_INPUT_MODE_RECORD,
    OFX_AUTOMATED_INPUT_MODE_PLAYBACK,
};

//--------------------------------------------------------------
class ofxAutomatedInput
{
public:
    ofxAutomatedInput();
    virtual ~ofxAutomatedInput();
    
    void clear();
    bool saveToXml(const string& path);
    bool loadFromXml(const string& path);

    void debug();
    
    void update(ofEventArgs& args);
    
    void mouseEventReceived(ofMouseEventArgs& args);
    void keyEventReceived(ofKeyEventArgs& args);
    void touchEventReceived(ofTouchEventArgs& args);
    
    void startRecording(int recordFlags = (OFX_AUTOMATED_INPUT_TYPE_MOUSE | OFX_AUTOMATED_INPUT_TYPE_KEY));
    void stopRecording();
    void toggleRecording();
    
    void startPlayback(int playbackFlags = OFX_AUTOMATED_INPUT_TYPE_ALL);
    void stopPlayback();
    void togglePlayback();
    
    ofxAutomatedInputMode mode() const { return _mode; }
    bool isIdle() const { return (_mode == OFX_AUTOMATED_INPUT_MODE_IDLE); }
    bool isPlaying() const { return (_mode == OFX_AUTOMATED_INPUT_MODE_PLAYBACK); }
    bool isRecording() const { return (_mode == OFX_AUTOMATED_INPUT_MODE_RECORD); }
    
    void setTriggerOFEvents(bool bTriggerOFEvents) { _bTriggerOFEvents = bTriggerOFEvents; }
    bool triggersOFEvents() const { return _bTriggerOFEvents; }
    
    void setLooping(bool bLooping) { _bLooping = bLooping; }
    bool isLooping() const { return _bLooping; }
    
    void setLoopOffsetTime(long long loopOffsetTime) { _loopOffsetTime = loopOffsetTime; }
    long long loopOffsetTime() const { return _loopOffsetTime; }
    
    ofEvent<ofMouseEventArgs> mouseInputEvent;
    ofEvent<ofKeyEventArgs> keyInputEvent;
    ofEvent<ofTouchEventArgs> touchInputEvent;
    
    ofEvent<long long> playbackStartedEvent;
    ofEvent<long long> playbackStoppedEvent;
    
protected:
    ofxAutomatedInputMode _mode;
    bool _bTriggerOFEvents;
    
    int _recordFlags;
    int _playbackFlags;
    
    long long _recordStartTime;
    long long _playbackStartTime;
    int _playbackIdx;
    
    bool _bLooping;
    long long _loopOffsetTime;
    
    vector<ofxAutomatedInputEvent *> _inputEvents;
};
