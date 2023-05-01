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
			delete[] m_data;
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

    m_w = w;
    m_h = h;

    FileInStream f(ofToDataPath(filename.c_str()));
	if (!f.isOpen())
	{
		cerr << "Can't open file for reading: " << filename << endl;
		//return 1;
		//exit;
	}
	 cout << "fileloaded!"  << endl;

     //Real *data = new Real[w*h];
     m_data = new Real[w*h];

		// read data
		Reader reader(f);
		if (reader.getModule() == NULL)
		{
			cerr << "File in wrong format or corrupted: " << filename << endl;
			delete[] m_data;
			//return 1;
			//exit;
		}
        cout << "readModule" << endl;
		//noisepp::utils::PlaneBuilder2D builder;
		m_builder.setModule (reader.getModule());

		m_builder.setSize (w, h);
		m_builder.setBounds (bounds.x, bounds.y, bounds.z, bounds.w);
		m_builder.setSeamless(seamless);
		m_builder.setDestination (m_data);
		m_builder.build ();


 }

void ofxNoisepp::bindPipeline2D(PlaneBuilder2D builder){

     m_builder = builder;


}

void ofxNoisepp::saveImage(string filename){


	m_image.saveImage(filename);


}

 void ofxNoisepp::setup(GradientRenderer gradients){

    unsigned char *pixels = (unsigned char *)malloc(m_w*m_h*3);

	noisepp::utils::Image img;
	img.create (m_w, m_h);

	gradients.renderImage (img, m_data);

    std::memcpy (pixels, img.getPixelData(), m_w*m_h*3);

	m_image.setFromPixels(pixels,m_w,m_h,OF_IMAGE_COLOR,true);

    m_image.reloadTexture();

    delete[] m_data;
	m_data = 0;




 }

void ofxNoisepp::display(){


    m_image.draw(0,0);
}

unsigned char 	*	ofxNoisepp::getPixels(){

    unsigned char * getPix = (unsigned char *)malloc(m_w*m_h*3);
   if( m_image.isAllocated() ){

    getPix = m_image.getPixels().getData();


   }
   return getPix;



}
