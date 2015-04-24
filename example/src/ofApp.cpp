#include "ofApp.h"

int current_hue;
int current_saturation;
int current_brightness;
bool current_lightOn;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(colorSlider.setup("color",ofColor(100,100,100),ofColor(0,0),ofColor(255,255)));
    gui.add(light.setup("light", true));
    gui.add(getLightState.setup("get light state"));
    
    hue1.setup("192.168.100.130", "newdeveloper");
    
}

//--------------------------------------------------------------
// http://www.peko-step.com/tool/hsvrgb.html
int getHue(float r, float g, float b) {
    float max = MAX(MAX(r, g), b);
    float min = MIN(MIN(r, g), b);
    
    float h;
    
    if (min == max) {
        return 0;
    } else if (max == r) {
        h = 60 * ((g - b) / (max - min));
    } else if (max == g) {
        h = 60 * ((b - r) / (max - min)) + 120;
    } else if (max == b) {
        h = 60 * ((r - g) / (max - min)) + 240;
    }
                
    if (h < 0) {
        h += 360;
    }
    return (int)h;

}

int getSaturation(float r, float g, float b) {
    float min = MIN(MIN(r, g), b);
    float max = MAX(MAX(r, g), b);
    return int((max - min) / max * 255);
}

int getBrightness(float r, float g, float b) {
    return MAX(MAX(r,g),b);
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    color = colorSlider;
    
    ofxJSONElement lightState = hue1.getLightAttributesAndState(1);
    
    if (getLightState) {
        ofDrawBitmapString(lightState.getRawString(), 250, 14);

    }
    
    if (current_hue != ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535) ||
        current_brightness != color->getBrightness() ||
        current_saturation != (int)getSaturation(color->r, color->g, color->b) ||
        (light && !lightState["state"]["on"].asBool()) ||
        (!light && lightState["state"]["on"].asBool())
        ) {

        ofLog(OF_LOG_NOTICE, "red: %d", color->r);
        ofLog(OF_LOG_NOTICE, "green: %d", color->g);
        ofLog(OF_LOG_NOTICE, "blue: %d", color->b);

        int hoge = ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535);
        ofLog(OF_LOG_NOTICE, "hue: " + ofToString(hoge));


        hue1.setLightState(
                           1,
                           light,
                           color->getBrightness(),
                           ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535),
                           getSaturation(color->r, color->g, color->b)
                           );
        
        current_hue = ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535);
        current_lightOn = light;
        current_brightness = color->getBrightness();
        current_saturation = getSaturation(color->r, color->g, color->b);
    
    }

    gui.draw();

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

