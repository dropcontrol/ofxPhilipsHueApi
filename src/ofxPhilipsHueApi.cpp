//
//  ofxPhilipsHueApi.cpp
//  
//
//  Created by hiroshi yamato on 4/22/15.
//
//

#include "ofxPhilipsHueApi.h"

void ofxPhilipsHueApi::setup(string ipAddress, string userName) {
    apiUrl = "http://" + ipAddress + "/api/" + userName;
    httpUtils.start();
}

void ofxPhilipsHueApi::setLightState(int lightId, bool on, int bri, int hue, int sat) {
    string url = apiUrl + "/lights/" + ofToString(lightId) + "/state/";

    ofxJSONElement responce = getLightAttributesAndState(lightId);

    std::stringstream jsonValue;
    
    ofLog(OF_LOG_NOTICE, "hue2: " + ofToString(hue));

    
    if (on == true) {
        responce["state"]["on"] = true;
    } else if (on == false){
        responce["state"]["on"] = false;
    }
    
    if (bri) {
        responce["state"]["bri"] = ofToString(bri);
    }
    
    if (hue) {
        responce["state"]["hue"] = hue;
    }
    
    if (sat) {
        responce["state"]["sat"] = ofToString(sat);
    }

    string data = ofToString(responce["state"]);
    
    ofBuffer buff;
    buff.set(data.c_str(), data.size());
    
    httpUtils.putData(url, buff, "application/json");
}

ofxJSONElement ofxPhilipsHueApi::getLightAttributesAndState(int lightId) {
    string url = apiUrl + "/lights/" + ofToString(lightId);
 
    ofxJSONElement responce;
    responce.open(url);
    return responce;
}