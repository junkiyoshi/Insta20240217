#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetCircleResolution(36);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	vector<glm::vec3> location_list;
	vector<ofColor> color_list;
	ofColor color;
	for (int i = 0; i < 50; i++) {

		location_list.push_back(glm::vec3(
			ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -400, 400),
			ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -400, 400),
			ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -400, 400)
		));

		color.setHsb(ofRandom(255), 230, 255);
		color_list.push_back(color);
	}

	ofNoFill();
	for (int i = 0; i < location_list.size(); i++) {

		for (float r = 30; r < 70; r += 1) {

			ofSetColor(color_list[i], ofMap(r, 30, 70, 150, 0));
			ofDrawCircle(location_list[i], r);
		}
	}

	ofFill();
	ofSetColor(239);
	for (auto& location : location_list) {

		ofDrawCircle(location, 30);
	}

	/*
	int start = 300;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}