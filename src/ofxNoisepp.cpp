#include "ofxNoisepp.h"


ofxNoisepp::ofxNoisepp(){}

ofxNoisepp::~ofxNoisepp(){}

void ofxNoisepp::loadPipeline2D(string filename, ofVec4f bounds ){


    FileInStream f(filename.c_str());
	if (!f.isOpen())
	{
		cerr << "Can't open file for reading: " << filename << endl;
		//return 1;
		//exit;
	}
	 cout << "fileloaded!"  << endl;


		// read data
		Reader reader(f);
		if (reader.getModule() == NULL)
		{
			cerr << "File in wrong format or corrupted: " << filename << endl;
			delete[] data;
			//return 1;
			//exit;
		}
        cout << "readModule" << endl;

		m_builder.setModule (reader.getModule());


		m_builder.setBounds (bounds.x, bounds.y, bounds.z, bounds.w);
		//builder.setSeamless(true);
		//builder.setDestination (data);
		m_builder.build ();

}


 void ofxNoisepp::loadPipeline2D( string filename, ofVec4f bounds, int w, int h, bool seamless ){

    _w = w;
    _h = h;

    FileInStream f(filename.c_str());
	if (!f.isOpen())
	{
		cerr << "Can't open file for reading: " << filename << endl;
		//return 1;
		//exit;
	}
	 cout << "fileloaded!"  << endl;

     //Real *data = new Real[w*h];
     data = new Real[w*h];

		// read data
		Reader reader(f);
		if (reader.getModule() == NULL)
		{
			cerr << "File in wrong format or corrupted: " << filename << endl;
			delete[] data;
			//return 1;
			//exit;
		}
        cout << "readModule" << endl;
		//noisepp::utils::PlaneBuilder2D builder;
		m_builder.setModule (reader.getModule());

		m_builder.setSize (w, h);
		m_builder.setBounds (bounds.x, bounds.y, bounds.z, bounds.w);
		m_builder.setSeamless(seamless);
		m_builder.setDestination (data);
		m_builder.build ();


 }

void ofxNoisepp::bindPipeline2D(PlaneBuilder2D builder){

    builder = m_builder;


}

void ofxNoisepp::saveImage(string filename){

unsigned char *pixels = (unsigned char *)malloc(_w*_h*3);

	noisepp::utils::Image img;
	img.create (_w, _h);


}

 void ofxNoisepp::setup(){

      unsigned char *pixels = (unsigned char *)malloc(_w*_h*3);

	noisepp::utils::Image img;
	img.create (_w, _h);

	noisepp::utils::GradientRenderer gradients;
	//gradients.addGradient (-1.0, noisepp::utils::ColourValue(0.0f, 0.0f, 0.0f));
	//gradients.addGradient ( 1.0, noisepp::utils::ColourValue(1.0f, 1.0f, 1.0f));

	gradients.addGradient (-1.0000, noisepp::utils::ColourValue (  0,   0, 128)/255.f); // deeps
    gradients.addGradient (-0.2500, noisepp::utils::ColourValue (  0,   0, 255)/255.f); // shallow
    gradients.addGradient ( 0.0000, noisepp::utils::ColourValue (  0, 128, 255)/255.f); // shore
    gradients.addGradient ( 0.0625, noisepp::utils::ColourValue (240, 240,  64)/255.f); // sand
    gradients.addGradient ( 0.1250, noisepp::utils::ColourValue ( 32, 160,   0)/255.f); // grass
    gradients.addGradient ( 0.3750, noisepp::utils::ColourValue (224, 224,   0)/255.f); // dirt
    gradients.addGradient ( 0.7500, noisepp::utils::ColourValue (128, 128, 128)/255.f); // rock
    gradients.addGradient ( 1.0000, noisepp::utils::ColourValue (255, 255, 255)/255.f); // snow

	gradients.renderImage (img, data);

    std::memcpy (pixels, img.getPixelData(), _w*_h*3);

	m_image.setFromPixels(pixels,_w,_h,OF_IMAGE_COLOR,true);

    m_image.reloadTexture();

    delete[] data;
	data = 0;




 }

void ofxNoisepp::display(){



    m_image.draw(0,0);
}
