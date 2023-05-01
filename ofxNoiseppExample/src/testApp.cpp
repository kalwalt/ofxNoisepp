#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

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
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

    noisepp.display();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 's'){

    noisepp.saveImage("noisepp.jpg");
    cout << "image saved in bin/data !" << endl;

    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
