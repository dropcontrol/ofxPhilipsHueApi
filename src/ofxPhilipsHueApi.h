//
//  ofxPhilipsHueApi.h
//  
//
//  Created by hiroshi yamato on 4/22/15.
//
//

#ifndef ____ofxPhilipsHueApi__
#define ____ofxPhilipsHueApi__

//#include <stdio.h>

#include "ofMain.h"
#include "ofxHttpUtilsPlus.h"
#include "ofxJSONElement.h"

class ofxPhilipsHueApi {
    string apiUrl;
    ofxHttpUtilsPlus httpUtils;

    
public:
    void setup(string ipAddress, string userName);
    
    // http://www.developers.meethue.com/documentation/lights-api
    void setLightState(int lightId, bool on, int bri, int hue, int sat);
    ofxJSONElement getLightAttributesAndState(int lightId);
    
    
private:
    
};

#endif /* defined(____ofxPhilipsHueApi__) */
