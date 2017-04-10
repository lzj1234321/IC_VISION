#pragma once
//colour
#define COLOUR_BLUE Scalar(255,0,0)
#define COLOUR_GREEN Scalar(0,255,0)
#define COLOUR_RED Scalar(0,0,255)

#include<opencv.hpp>
#include<cv.h>
#include<highgui.h>
#include <cxcore.hpp>
using namespace cv;
using namespace std;


class Img_Draw:public DoubleLinked_List
{
public:
	Mat drawMat;
	Mat originalMat;
	Scalar beenClickedColour;
	Scalar generalColour;
	Scalar drawElementColour;
	Size defaultMatShowSize;
	vector<struct imgElement> Vec_imgElement;
	Img_Draw();
	~Img_Draw();
	bool isAnyElementBeenChoosed;
	INT beenChoosedElementNum;
	bool IsElementChoosed(CvPoint mouseClickPosition);
	Mat move();
	Mat elementRemove();
	Mat reDraw(Mat&);
	Mat reDraw();
	Mat reDraw(INT redrawElementNum,INT,INT);
	Mat reDraw(vector<struct imgElement>::iterator);
	Mat reSize();
	Mat recovery();
	INT matShow(const Mat&);
	INT matShow(const  string, const Mat&);
	INT matShow(const string, const Mat&,Size matShowSize);
	bool isCircleBeenClick(CvPoint mouseClickPosition, imgElement srcImgElement);
	bool isRectangleBeenClick(CvPoint mouseClickPosition,imgElement srcImgElement);
	bool isLineBeenClick(CvPoint mouseClickPosition, imgElement srcImgElement);
	bool isEllipseBeenClick(CvPoint mouseClickPosition);

	INT drawRectangleAndShow(Mat&,CvPoint,CvPoint,const string);
	INT drawCircleAndShow(Mat&,CvPoint,double, const string);
	INT drawEllipseAndShow(Mat&,CvPoint,CvSize,double,double,double ,const string);
	INT drawLineAndShow(Mat&,CvPoint,CvPoint, const string);

	INT drawRectangle(Mat&, CvPoint, CvPoint,Scalar);
	INT drawCircle(Mat&, CvPoint, double,Scalar);
	INT drawEllipse(Mat&, CvPoint, CvSize, double, double, double ,Scalar);
	INT drawLine(Mat&, CvPoint, CvPoint,Scalar);

	INT lineElement_PushBack(CvPoint startingPoint, CvPoint endingPoint);
	INT rectangleElement_PushBack(CvPoint startingPoint, CvPoint endingPoint);
	INT circleElement_PushBack(CvPoint center, INT radius);
	INT ellipseElement_PushBack(CvPoint center, CvSize size);

	void moveCircle(INT redrawElementNum, INT moveX, INT moveY);
	void moveLine(INT redrawElementNum, INT moveX, INT moveY);
	void moveRectangle(INT redrawElementNum, INT moveX, INT moveY);
	void moveEllipse(INT redrawElementNum, INT moveX, INT moveY);

	BOOL operationPushBack();
	Mat UNDO();
	Mat REDO();
};

