#pragma once

#include "ofMain.h"
#include "ofxRGBDRenderer.h"
#include "ofxRGBDVideoDepthSequence.h"
#include "ofxDepthImageRecorder.h"
#include "ofxGameCamera.h"
#include "ofxTimeline.h"
#include "ofxTLVideoPlayer.h"
#include "ofxTLDepthImageSequence.h";
#include "ofxMSAInteractiveObjectDelegate.h"
#include "ofxSimpleGuiToo.h"
#include "ofxCameraRecorder.h"

typedef struct {
	ofxMSAInteractiveObjectWithDelegate* load;
	ofxMSAInteractiveObjectWithDelegate* toggle;
	string fullCompPath;
	bool batchExport;
	bool wasRenderedInBatch;
	string name;
} Comp;

class testApp : public ofBaseApp, public ofxMSAInteractiveObjectDelegate {

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
 	
	void updateRenderer(ofVideoPlayer& fromPlayer);
	void processDepthFrame();
	
	bool loadNewProject();
	bool loadDepthSequence(string path);
	bool loadVideoFile(string path);
	bool loadAlignmentMatrices(string path);
	bool loadMarkerFile(string markerPath);
	
	ofxXmlSettings projectsettings;
	ofxXmlSettings compositions;
	void loadCompositions();
	void newComposition();
	void saveComposition();
	bool loadCompositionAtIndex(int i);
	void refreshCompButtons();
	
	//MSA Object delegate
	ofxMSAInteractiveObjectWithDelegate* newCompButton;
	ofxMSAInteractiveObjectWithDelegate* saveCompButton;	
	vector<Comp*> comps;
	
	bool playerElementAdded;
	
 	void objectDidRollOver(ofxMSAInteractiveObject* object, int x, int y);
    void objectDidRollOut(ofxMSAInteractiveObject* object, int x, int y);
	void objectDidPress(ofxMSAInteractiveObject* object, int x, int y, int button);	
	void objectDidRelease(ofxMSAInteractiveObject* object, int x, int y, int button);	
	void objectDidMouseMove(ofxMSAInteractiveObject* object, int x, int y);
	
	void finishRender();
	void stopCameraPlayback();
	void startCameraPlayback();
	void toggleCameraPlayback();
	
	void startCameraRecord();
	void stopCameraRecord();
	void toggleCameraRecord();
	
	int currentCompIndex;
	string currentCompositionDirectory;
	string mediaBinDirectory;
//	string currentMediaFolder;
	ofVideoPlayer* hiResPlayer;
	ofVideoPlayer* lowResPlayer;
//	ofxFCPMarker markers;
	int currentMarker;
	ofxCameraRecorder cameraRecorder;
	bool sampleCamera;
	bool playbackCamera;
	
	ofxRGBDRenderer renderer;
	ofxRGBDVideoDepthSequence sequencer;
	
	unsigned short* depthPixelDecodeBuffer;

	bool allLoaded;

	ofxGameCamera cam;

	string videoThumbsPath;
	string videoPath;
	ofxTimeline timeline;
	ofxTLVideoPlayer videoTimelineElement;
	ofxTLDepthImageSequence depthSequence;
	
	ofRectangle fboRectangle;
	ofFbo fbo;
	ofImage savingImage;
	string saveFolder;
	
	float currentXShift;
	float currentYShift;
	float farClip;
	float currentEdgeCull;
	bool shouldSaveCameraPoint;
	bool shouldClearCameraMoves;
	
	bool drawPointcloud;
	bool drawWireframe;
	bool drawMesh;
	int pointSize;
	int lineSize;
	int currentSimplify;

	bool startRenderMode;
	bool currentlyRendering;
	int currentRenderFrame;
	int lastRenderFrame;
	int numFramesToRender;
	int numFramesRendered;
	ofImage testImageOne;
	ofImage testImageTwo;
	
	ofVec3f lightpos;
	ofLight light;
};
