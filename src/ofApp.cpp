#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(999, 666);
    
    x = 0;
    y = 0;
    r = 0;
    
    color.setHsb(0,255,255);
    bInfo = false;
    
    ofHideCursor();
    
    ofSetCircleResolution(360);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (x >= ofGetWidth()/30){
        x = 0;
    }else{
        x += .5;
    }
    
    if (y >= ofGetHeight()/20){
        y = 0;
    }else{
        y += .5;
    }
    
    float randam = rand()%15-7;
    r = rr + randam;
    r2 = rr/5 + randam;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    ofSetColor(100);
    for (float i = 0; i < 30; i ++){
        ofLine(i*ofGetWidth()/30 + x, 0, i*ofGetWidth()/30 + x, ofGetHeight());
    }
    for (float i = 0; i < 20; i ++){
        ofLine(0, i*ofGetHeight()/20 + y, ofGetWidth(), i*ofGetHeight()/20 + y);
    }
    
    ofPushStyle();
        ofSetColor(100);
        ofSetLineWidth(2);
        ofLine(mouseX, 0, mouseX, ofGetHeight());
        ofLine(0, mouseY, ofGetWidth(), mouseY);
        ofLine(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY);
        ofNoFill();
        ofSetColor(color);
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, r);
        ofFill();
        ofSetLineWidth(0);
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, r2);
        ofSetColor(100);
        ofCircle(mouseX, mouseY, 5);
        ofSetColor(255);
        ofCircle(mouseX, mouseY, 3);
    ofPopStyle();
    
    if (bInfo == true) {
        sector.set(30, 30, 30, 100);
        text.set(255);
    }else{
        sector.set(0,0,0,0);
        text.set(0,0,0,0);
    }
    
    ofPushStyle();
    ofSetColor(sector);
        ofFill();
        ofBeginShape();
        for (float i = 0; i < d; i += .1){
            ofVertex(ofGetWidth()/2+cos(ofDegToRad(-i))*rr,
                     ofGetHeight()/2+sin(ofDegToRad(-i))*rr);
        }
        ofVertex(ofGetWidth()/2,ofGetHeight()/2);
    ofEndShape();
    ofPopStyle();
    
    ofPushStyle();
        ofSetColor(sector);
        ofFill();
        ofRect(mouseX + 5, mouseY + 5, 140, 38);
    ofPopStyle();
    
    ofPushStyle();
        ofSetColor(text);
        info = "radius: " + ofToString(rr) + "\n" + "deg: " + ofToString(d);
        ofDrawBitmapString( info, mouseX + 15, mouseY + 20);
    ofPopStyle();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            bInfo = !bInfo;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    float xx = x-ofGetWidth()/2;
    float yy = ofGetHeight()/2-y;
    rr = sqrt(xx*xx + yy*yy);
    
    if (asin(yy/rr) >= 0) {
        d = acos(xx/rr)*180/M_PI;
    }else{
        d = 360-acos(xx/rr)*180/M_PI;
    }
    color.setHueAngle(d);
    
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

//--------------------------------------------------------------
