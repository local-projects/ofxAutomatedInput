//
//  ofApp.cpp
//  ofxAutomatedInputExample
//
//  Created by Elie Zananiri on 2014-09-16.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_NOTICE);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
    ofBackground(0);
    bDebug = false;
    typedKeys = "";
    
    ofAddListener(automatedInput.playbackStartedEvent, this, &ofApp::automatedInputPlaybackStarted);
    ofAddListener(automatedInput.playbackStoppedEvent, this, &ofApp::automatedInputPlaybackStopped);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    if (automatedInput.isPlaying() && bDebug) {
        ofBackground(0);
        automatedInput.debug();
    }
    
    stringstream ss;
    ss << "ofxAutomatedInput" << endl;
    ss << " [R]ecording? " << (automatedInput.isRecording()? "YES":"NO") << endl;
    ss << " [P]laying? " << (automatedInput.isPlaying()? "YES":"NO") << endl;
    ss << " [D]ebug view? " << (bDebug? "YES":"NO") << endl;
    ss << " [C]lear data" << endl;
    ss << " [S]ave data to XML" << endl;
    ss << " [L]oad data from XML" << endl;
    ss << endl;
    ss << "Typed keys: " << typedKeys << endl;
    ofDrawBitmapStringHighlight(ss.str(), 15, 25);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (automatedInput.isIdle()) {
        ofFileDialogResult result;
        switch (key) {
            case 'r':
            case 'R':
                ofBackground(0);
                typedKeys = "";
                automatedInput.startRecording();
                break;
                
            case 'p':
            case 'P':
                ofBackground(0);
                typedKeys = "";
                automatedInput.startPlayback();
                break;
                
            case 'c':
            case 'C':
                automatedInput.clear();
                break ;
                
            case 's' :
            case 'S':
                result = ofSystemSaveDialog("data.xml", "Export input data to XML" );
                if (result.bSuccess) {
                    automatedInput.saveToXml(result.getPath());
                }
                break;
                
            case 'l':
            case 'L':
                result = ofSystemLoadDialog("Select an input data XML file", false);
                if (result.bSuccess) {
                    automatedInput.loadFromXml(result.getPath());
                }
                break;
                
            case 'd':
            case 'D':
                bDebug ^= 1;
                break;
        }

    }
    else if (automatedInput.isPlaying()) {
        if (key == 'p' || key == 'P') {
            automatedInput.stopPlayback();
        }
        else if (key == 'r' || key == 'R') {
            // Ignore, as this toggles recording.
        }
        else if (key == 'd' || key == 'D') {
            ofBackground(0);
            bDebug ^= 1;
        }
        else if (key == OF_KEY_BACKSPACE || key == OF_KEY_DEL) {
            if (typedKeys.size()) {
                typedKeys.substr(0, typedKeys.size() - 1);
            }
        }
        else if (key >= 32 && key <= 126) {
            typedKeys += key;
        }
    }
    else if (automatedInput.isRecording()) {
        if (key == 'r' || key == 'R') {
            automatedInput.stopRecording();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    if (!bDebug) {
        ofSetColor(255);
        ofCircle(x, y, 25);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::automatedInputPlaybackStarted(unsigned long long& duration)
{
    ofLog() << "ofApp::automatedInputPlaybackStarted";
    
    ofBackground(0);
    typedKeys = "";
}

//--------------------------------------------------------------
void ofApp::automatedInputPlaybackStopped(unsigned long long& duration)
{
    ofLog() << "ofApp::automatedInputPlaybackStopped";
}
