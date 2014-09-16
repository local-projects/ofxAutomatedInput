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
    
    ofAddListener(automatedInput.playbackFinishedEvent, this, &ofApp::automatedInputPlaybackFinished);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
//
//    autoInput.draw( ) ;
//    string boolString ;
//    if ( autoInput.getIsRecording() == true )
//        boolString = " true " ;
//    else
//        boolString = " false " ;
//
//    string playingString ;
//    if ( autoInput.getIsPlaying() == true )
//        playingString = " true " ;
//    else
//        playingString = " false " ;
//

    stringstream ss;
    ss << "ofxAutomatedInput" << endl;
    ss << " [R]ecording? " << (automatedInput.isRecording()? "YES":"NO") << endl;
    ss << " [P]laying? " << (automatedInput.isPlaying()? "YES":"NO") << endl;
    ss << " [C]lear data" << endl;
    ss << " [S]ave data to XML" << endl;
    ss << " [L]oad data from XML" << endl;
    ofDrawBitmapStringHighlight(ss.str(), 15, 25);
}

//void ofApp::automatedInputHandler( AutomatedInputData &args )
//{
//    cout << " EVENT IS INPUTING ! " << endl ;
//    float hue = ( args.x / ofGetWidth() ) * 255.0f ;
//    float saturation = ( args.y / ofGetHeight() ) * 255.0f ;
//    ofColor bg_color = ofColor::fromHsb( hue , saturation , 185.0f ) ;
//    ofBackground( bg_color ) ;
//}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    ofFileDialogResult result;
    switch (key) {
        case 'r':
        case 'R':
            ofBackground(0);
            automatedInput.toggleRecording();
            break;
            
        case 'p':
        case 'P':
            ofBackground(0);
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
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    ofSetColor(255);
    ofCircle(x, y, 25);
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
void ofApp::automatedInputPlaybackFinished(unsigned long long& duration)
{
    ofBackground(0);
}
