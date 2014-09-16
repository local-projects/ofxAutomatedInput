#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofAddListener( autoInput.AUTOMATED_INPUT , this , &ofApp::automatedInputHandler ) ;
}

//--------------------------------------------------------------
void ofApp::update(){
    autoInput.update() ;
}

//--------------------------------------------------------------
void ofApp::draw(){

    autoInput.draw( ) ;
    stringstream ss ;
    string boolString ;
    if ( autoInput.getIsRecording() == true )
        boolString = " true " ;
    else
        boolString = " false " ;

    string playingString ;
    if ( autoInput.getIsPlaying() == true )
        playingString = " true " ;
    else
        playingString = " false " ;

    ss << " (T) - Is it recording ? " << boolString << endl ;
    ss << " (P) - Is it playing ? " << playingString << endl ;
    ss << " (R) - reset data" << endl ;
    ss << " (S) - save data to XML" << endl ;
    ss << " (L) - load data from XML" << endl ;
    ss << autoInput.getDebugString() << endl ;

    ofDrawBitmapStringHighlight( ss.str() , 15 , 25 ) ;
}

void ofApp::automatedInputHandler( AutomatedInputData &args )
{
    cout << " EVENT IS INPUTING ! " << endl ;
    float hue = ( args.x / ofGetWidth() ) * 255.0f ;
    float saturation = ( args.y / ofGetHeight() ) * 255.0f ;
    ofColor bg_color = ofColor::fromHsb( hue , saturation , 185.0f ) ;
    ofBackground( bg_color ) ;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    ofFileDialogResult result ;
    switch ( key )
    {
        case 't' :
        case 'T':
            autoInput.toggleRecording() ;
            break ;

        case 'r' :
        case 'R':
            autoInput.reset() ;
            break ;

        case 's' :
        case 'S':
            result = ofSystemSaveDialog( "data.xml" , "Export Input Data as XML" ) ;
            if ( result.bSuccess )
                autoInput.saveXml( result.getPath() ) ;
            break ;

        case 'l':
        case 'L':
            result = ofSystemLoadDialog( "Select an input data XML" , false ) ;
            if ( result.bSuccess )
                autoInput.loadXml( result.getPath() ) ;
            break ;

        case 'p':
        case 'P':
            autoInput.togglePlayback() ;
            break ;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    autoInput.addInput( x , y , 0 ) ;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
