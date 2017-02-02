/*
 *  ofxTweener.h
 *  openFrameworks
 *
 *  Created by Sander ter Braak on 26-08-10.
 *
 */

#ifndef _OFXTWEEN
#define _OFXTWEEN

#include "ofMain.h"
#include "ofxTransitions.h"
#include <Poco/Timestamp.h>

#define TWEENMODE_OVERRIDE 0x01
#define TWEENMODE_SEQUENCE 0x02


class TweenCompleteListener {
public:
    virtual void tweenOnComplete(float& args){}
};


class Tween {
public:
	typedef float(ofxTransitions::* easeFunction)(float,float,float,float);
	float* _var;
	float _from, _to, _duration,_by, _useBezier;
	easeFunction _easeFunction;
	Poco::Timestamp _timestamp;
    
    TweenCompleteListener* _completeListener;
    ofEvent<float> _completeEvent;
};


class ofxTweener {

public:
	
	ofxTweener();
	
	void addTween(float &var, float to, float time, TweenCompleteListener* listener=NULL);
	void addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float), TweenCompleteListener* listener=NULL);
	void addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float), float delay, TweenCompleteListener* listener=NULL);
	void addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float), float delay, float bezierPoint, TweenCompleteListener* listener=NULL);
    
	
	void removeTween(float &var);
	void setTimeScale(float scale);
	void update();
	void removeAllTweens();	
	void setMode(int mode);
	
	int getTweenCount();	
	
	
private:
	float				_scale;
	ofxTransitions		a;
	bool				_override;
	void				addTween(float &var, float to, float time, float (ofxTransitions::*ease) (float,float,float,float), float delay, float bezierPoint, bool useBezier, TweenCompleteListener* listener=NULL);
	float				bezier(float b, float e, float t, float p);
	vector<Tween>		tweens;
};


extern ofxTweener Tweener;
#endif
