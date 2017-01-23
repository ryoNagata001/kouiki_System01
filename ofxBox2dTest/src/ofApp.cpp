#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //描画の基本設定
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    //ボールがゴールに入っていない状態にする
    circle_in = false;
    
    //box2Dの物理世界のパラメーターを設定
    box2d.init();
    box2d.setGravity(0,5);
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight());
    box2d.setFPS(30);
    
    //ゴールを作る
    ofPtr<ofxBox2dRect> r1 = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
    r1.get()->setup(box2d.getWorld(), ofGetWidth()/2-50,ofGetHeight()-25, 2, 70);
    rects.push_back(r1);
    ofPtr<ofxBox2dRect> r2 = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
    r2.get()->setup(box2d.getWorld(), ofGetWidth()/2+50,ofGetHeight()-25, 2, 70);
    rects.push_back(r2);
    ofPtr<ofxBox2dRect> r3 = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
    r3.get()->setup(box2d.getWorld(), ofGetWidth()/2,ofGetHeight()-150, 300, 2);
    rects.push_back(r3);
}

//--------------------------------------------------------------
void ofApp::update(){
    //物理演算
    box2d.update();
    //ボールが入ったか否かを判断(ネストが深すぎる)
    for(int i = 0; i < circles.size(); i++){
        if (circles[i]->getPosition().x <= ofGetWidth()/2+50){
            if(circles[i]->getPosition().x >= ofGetWidth()/2-50){
                if(circles[i]->getPosition().y >= ofGetHeight()-50){
                    circle_in = true;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //円を一つづつ描画
    for (int i = 0; i < circles.size(); i++){
        ofFill();
        ofSetColor(0, 127, 255);
        circles[i].get()->draw();
        // circles[i].draw();
    }
    
    //ゴールを描画
    for(int i = 0; i < 3; i++){
        ofFill();
        ofSetColor(255, 255, 255);
        rects[i].get()->draw();
        // circles[i].draw();
    }
    //ゴールに色付け
    ofSetColor(255, 0, 0, 125);
    ofDrawRectangle(ofGetWidth()/2-50, ofGetHeight()-25, 100, 50);
    
    //ルールの記述
    ofDrawBitmapString( "reset: r, ball: click", 30, 30);
    
    //クリア判定
    if(circle_in){
        string thresholdMsg = "CLEAR!!!";
        ofDrawBitmapString( thresholdMsg, ofGetWidth()/2, ofGetHeight()/2);
    }

    box2d.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //ゲームのリセット
    if (key == 'r'){
        for(int i = 0; i < circles.size(); i++){
            circles[i].get()->destroy();
        }
        circles.clear();
        circle_in = false;
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
    
    //ゴールより上の部分でボールを落とせる
    if(y <= ofGetHeight()-150){
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
