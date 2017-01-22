#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    box2d.init();
    box2d.setGravity(0,5);
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight());
    box2d.setFPS(30);
    
//    for (int i = 0; i < 100; i++){
//        ofPtr<ofxBox2dRect> r = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
//        float w = 2;
//        float h = 2;
//        float x = ofRandom(50, ofGetWidth() - 50);
//        float y = ofRandom(50, ofGetHeight() - 50);
//        //r.get()->setPhysics(1000, 1, 0);
//        r.get()->setup(box2d.getWorld(), x, y, w, h);
//        
//        rects.push_back(r);
//    }
    
    ofPtr<ofxBox2dRect> r1 = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
    r1.get()->setup(box2d.getWorld(), ofGetWidth()/2-50,ofGetHeight()-25, 2, 50);
    rects.push_back(r1);
    ofPtr<ofxBox2dRect> r2 = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
    r2.get()->setup(box2d.getWorld(), ofGetWidth()/2+50,ofGetHeight()-25, 2, 50);
    rects.push_back(r2);
    ofPtr<ofxBox2dRect> r3 = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
    r3.get()->setup(box2d.getWorld(), ofGetWidth()/2,ofGetHeight()-100, 100, 2);
    rects.push_back(r3);
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < circles.size(); i++){
        ofFill();
        ofSetColor(0, 127, 255);
        circles[i].get()->draw();
        // circles[i].draw();
    }
    
    for(int i = 0; i < 3; i++){
        ofFill();
        ofSetColor(255, 255, 255);
        rects[i].get()->draw();
        // circles[i].draw();
    }
    ofSetColor(255, 0, 0, 125);
    ofDrawRectangle(ofGetWidth()/2-50, ofGetHeight()-25, 100, 50);

    
    box2d.draw();
//    for (int i = 0; i < circles.size(); i++){
//        ofFill();
//        ofSetColor(0, 127, 255);
//        circles[i].draw();
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'r'){
        for(int i = 0; i < circles.size(); i++){
            circles[i].get()->destroy();
        }
        circles.clear();
    }
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
    if(y <= ofGetHeight()-100){
    float r = ofRandom(10, 40);
    ofPtr<ofxBox2dCircle> circle = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
    circle.get()->setPhysics(1.0, 0.8, 0.5);
    circle.get()->setup(box2d.getWorld(), mouseX, mouseY, r);
    
    circles.push_back(circle);
    }
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
