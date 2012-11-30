#pragma once

#include "ofMain.h"
#include "Noise.h"
#include "NoiseUtils.h"

using namespace std;
using namespace noisepp;
using namespace noisepp::utils;

class ofxNoisepp {

public:

        ofxNoisepp();
        ~ofxNoisepp();

        void loadPipeline2D( string filename, ofVec4f bounds );
        void loadPipeline2D( string filename, ofVec4f bounds, int w, int h, bool seamless );
        void bindPipeline2D(PlaneBuilder2D builder);
        void setup(GradientRenderer gradients);
        void saveImage(string filename);
        void display();

        ///getters

        unsigned char 	*	getPixels();


private:


        ofImage m_image;
        PlaneBuilder2D m_builder;

        Real *m_data;

        int m_w;
        int m_h;


};

