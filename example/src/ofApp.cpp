#include "ofApp.h"

static void _onComplete(float* arg) {
    ofLogNotice() << "on complete: " << arg;
};

//--------------------------------------------------------------
void ofApp::setup(){
    radius = 5;
}

//--------------------------------------------------------------
void ofApp::update(){
    Tweener.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(position.x, position.y, radius);
    ofDrawBitmapString("Click anywhere to start tween", 10,10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // simple fast implementation
//    Tweener.addTween(position.x, x, 5);
//    Tweener.addTween(position.y, y, 5);
    
    // custom ease
//    Tweener.addTween(position.x, x, 5, &ofxTransitions::easeOutElastic);
//    Tweener.addTween(position.y, y, 5, &ofxTransitions::easeOutElastic);
    
    // adding delay
//    Tweener.addTween(position.x, x, 5, &ofxTransitions::easeOutElastic, 1);
//    Tweener.addTween(position.y, y, 5, &ofxTransitions::easeOutElastic, 0.5);
    
    // bezier tweening
//    Tweener.addTween(position.x, x, 1, &ofxTransitions::easeOutCubic, 0, 1024/2);
//    Tweener.addTween(position.y, y, 1, &ofxTransitions::easeOutCubic, 0, 768/2);
    
    // complete event
    Tweener.addTween(position.x, x, 5, this);
    Tweener.addTween(position.y, y, 3, this);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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


void ofApp::tweenOnComplete(float& args){
    if(&args == &position.x) ofLogNotice() << "on complete x: " << position.x;
    if(&args == &position.y) ofLogNotice() << "on complete y: " << position.y;
}



