#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    w = 256;
    h = 256;

    ofSetWindowShape(w,h);

    bounds.set(0,0,5,5);

    noisepp.loadPipeline2D("test.pipeline",bounds, w ,h,true);

	gradients.addGradient (-1.0000, noisepp::utils::ColourValue (  0,   0, 128)/255.f); // deeps
    gradients.addGradient (-0.2500, noisepp::utils::ColourValue (  0,   0, 255)/255.f); // shallow
    gradients.addGradient ( 0.0000, noisepp::utils::ColourValue (  0, 128, 255)/255.f); // shore
    gradients.addGradient ( 0.0625, noisepp::utils::ColourValue (240, 240,  64)/255.f); // sand
    gradients.addGradient ( 0.1250, noisepp::utils::ColourValue ( 32, 160,   0)/255.f); // grass
    gradients.addGradient ( 0.3750, noisepp::utils::ColourValue (224, 224,   0)/255.f); // dirt
    gradients.addGradient ( 0.7500, noisepp::utils::ColourValue (128, 128, 128)/255.f); // rock
    gradients.addGradient ( 1.0000, noisepp::utils::ColourValue (255, 255, 255)/255.f); // snow

    noisepp.setup(gradients);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

    noisepp.display();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){

    noisepp.saveImage("noisepp.jpg");
    cout << "image saved in bin/data !" << endl;

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
