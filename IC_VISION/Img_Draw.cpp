#include "stdafx.h"
//using namespace cv;


Img_Draw::Img_Draw()
{
	beenChoosedElementNum = -1;
	beenClickedColour = COLOUR_RED;
	generalColour = COLOUR_GREEN;
	headNode->Vec_operationList =Vec_imgElement;
}
Img_Draw::~Img_Draw()
{
}
bool Img_Draw::IsElementChoosed(CvPoint mouseClickPosition)
{

	beenChoosedElementNum = -1;
	int i;
	if (currentPointToNode != NULL)
	{
		vector<struct imgElement>::iterator imgElementIterator = currentPointToNode->Vec_operationList.begin();
		for (i = 0; imgElementIterator != currentPointToNode->Vec_operationList.end(); imgElementIterator++, i++)
		{
			switch (imgElementIterator->elementType)
			{
			case 0:
			{
				if (isRectangleBeenClick(mouseClickPosition, *imgElementIterator))
				{
					beenChoosedElementNum = i;
					return true;
				}
			}
			break;
			case 1:
			{
				if (isCircleBeenClick(mouseClickPosition, *imgElementIterator))
				{
					beenChoosedElementNum = i;
					return true;
				}
			}
			break;
			case 2:
			{
				if (isLineBeenClick(mouseClickPosition, *imgElementIterator))
				{
					beenChoosedElementNum = i;
					return true;
				}
			}
			break;
			default:
				break;
			}
		}
	}
	return false;
}

void Img_Draw::moveCircle(INT redrawElementNum, INT moveX, INT moveY)
{
	currentPointToNode->Vec_operationList[redrawElementNum].elementCenter.x -= moveX;
	currentPointToNode->Vec_operationList[redrawElementNum].elementCenter.y -= moveY;
	//Vec_imgElement[redrawElementNum].elementCenter.x -= moveX;
	//Vec_imgElement[redrawElementNum].elementCenter.y -= moveY;

}
void Img_Draw::moveLine(INT redrawElementNum, INT moveX, INT moveY)
{
	//Vec_imgElement[redrawElementNum].startingPoint.x -= moveX;
	//Vec_imgElement[redrawElementNum].endingPoint.x -= moveX;
	//Vec_imgElement[redrawElementNum].startingPoint.y -= moveY;
	//Vec_imgElement[redrawElementNum].endingPoint.y -= moveY;
	currentPointToNode->Vec_operationList[redrawElementNum].startingPoint.x -= moveX;
	currentPointToNode->Vec_operationList[redrawElementNum].startingPoint.y -= moveY;
	currentPointToNode->Vec_operationList[redrawElementNum].endingPoint.x -= moveX;
	currentPointToNode->Vec_operationList[redrawElementNum].endingPoint.y -= moveY;

}
void Img_Draw::moveRectangle(INT redrawElementNum, INT moveX, INT moveY)
{
	//Vec_imgElement[redrawElementNum].startingPoint.x -= moveX;
	//Vec_imgElement[redrawElementNum].endingPoint.x -= moveX;
	//Vec_imgElement[redrawElementNum].startingPoint.y -= moveY;
	//Vec_imgElement[redrawElementNum].endingPoint.y -= moveY;
	currentPointToNode->Vec_operationList[redrawElementNum].startingPoint.x -= moveX;
	currentPointToNode->Vec_operationList[redrawElementNum].startingPoint.y -= moveY;
	currentPointToNode->Vec_operationList[redrawElementNum].endingPoint.x -= moveX;
	currentPointToNode->Vec_operationList[redrawElementNum].endingPoint.y -= moveY;
}
void Img_Draw::moveEllipse(INT redrawElementNum, INT moveX, INT moveY)
{
}

Mat Img_Draw::reDraw()
{
	int i;
	Scalar drawElementColour = generalColour;
	Mat reDrawMat = originalMat.clone();
	if(currentPointToNode!=NULL)
	{ 
	vector<struct imgElement>::iterator imgElementIterator = currentPointToNode->Vec_operationList.begin();
	for (i = 0; imgElementIterator != currentPointToNode->Vec_operationList.end(); imgElementIterator++, i++)
	{
		if (i == beenChoosedElementNum)
		{
			drawElementColour = beenClickedColour;
		}
		else
			drawElementColour = generalColour;
		switch (imgElementIterator->elementType)
		{
		case 0:
		{
			drawRectangle(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 1:
		{
			drawCircle(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->elementRadius, drawElementColour);
		}
		break;
		case 2:
		{
			drawLine(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 3:
		{
			drawEllipse(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->size, 10, 0, 360, drawElementColour);
		}
		break;
		default:
			break;
		}
	}
	}
	//beenChoosedElementNum = -1;
	return reDrawMat;
}
Mat Img_Draw::reDraw(INT redrawElementNum, INT moveX, INT moveY)
{
	Scalar drawElementColour = generalColour;
	Mat reDrawMat = originalMat.clone();
	vector<struct imgElement>::iterator imgElementIterator=currentPointToNode->Vec_operationList.begin();
	for (int i = 0; imgElementIterator != currentPointToNode->Vec_operationList.end(); imgElementIterator++, i++)
	{

		//line = 0,
		//	circle = 1,
		//	rectangle = 2,
		//	ellipse = 3,
		if (i == redrawElementNum)
		{
			drawElementColour = beenClickedColour;
			switch (imgElementIterator->elementType)
			{
			case 0:
			{
				moveRectangle(redrawElementNum, moveX, moveY);
				drawRectangle(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
			}
			break;
			case 1:
			{
				moveCircle(redrawElementNum, moveX, moveY);
				drawCircle(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->elementRadius, drawElementColour);
			}
			break;
			case 2:
			{
				moveLine(redrawElementNum, moveX, moveY);
				drawLine(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
			}
			break;
			case 3:
			{

			}
			break;
			default:
				break;
			}
			continue;
		}
		else
			drawElementColour = generalColour;
		switch (imgElementIterator->elementType)
		{
		case 0:
		{
			drawRectangle(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 1:
		{
			drawCircle(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->elementRadius, drawElementColour);
		}
		break;
		case 2:
		{
			drawLine(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 3:
		{
			drawEllipse(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->size, 10, 0, 360, drawElementColour);
		}
		break;
		default:
			break;
		}
	}
	beenChoosedElementNum = -1;
	return reDrawMat;
}
Mat Img_Draw::reDraw(Mat& srcMat)
{
	Mat reDrawMat = srcMat.clone();
	int i;
	Scalar drawElementColour = generalColour;
	vector<struct imgElement>::iterator imgElementIterator;
	for (imgElementIterator = currentPointToNode->Vec_operationList.begin(), i = 0; imgElementIterator != currentPointToNode->Vec_operationList.end(); imgElementIterator++, i++)
	{
		if (i != -1 && i == beenChoosedElementNum)
			drawElementColour = beenClickedColour;
		else
			drawElementColour = generalColour;
		switch (imgElementIterator->elementType)
		{
		case 0:
		{
			drawRectangle(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 1:
		{
			drawCircle(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->elementRadius, drawElementColour);
		}
		break;
		case 2:
		{
			drawLine(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 3:
		{
			drawEllipse(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->size, 10, 0, 360, drawElementColour);
		}
		break;
		default:
			break;
		}
	}
	//beenChoosedElementNum = -1;
	return reDrawMat;
}
Mat Img_Draw::reDraw(vector<struct imgElement>::iterator imgElementIterator)
{
	int i;
	Scalar drawElementColour = generalColour;
	Mat reDrawMat = originalMat.clone();
	for (i = 0; imgElementIterator != currentPointToNode->Vec_operationList.end(); imgElementIterator++, i++)
	{
		if (i == beenChoosedElementNum)
		{
			drawElementColour = beenClickedColour;
		}
		else
			drawElementColour = generalColour;
		switch (imgElementIterator->elementType)
		{
		case 0:
		{
			drawRectangle(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 1:
		{
			drawCircle(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->elementRadius, drawElementColour);
		}
		break;
		case 2:
		{
			drawLine(reDrawMat, imgElementIterator->startingPoint, imgElementIterator->endingPoint, drawElementColour);
		}
		break;
		case 3:
		{
			drawEllipse(reDrawMat, imgElementIterator->elementCenter, imgElementIterator->size, 10, 0, 360, drawElementColour);
		}
		break;
		default:
			break;
		}
	}
	//beenChoosedElementNum = -1;
	return reDrawMat;
}
Mat Img_Draw::reSize()
{
	Mat test;
	return test;
}

bool Img_Draw::isCircleBeenClick(CvPoint mouseClickPosition, imgElement srcImgElement)
{
	int circleRadius = (int)sqrt(pow(mouseClickPosition.x - srcImgElement.elementCenter.x, 2) + pow(mouseClickPosition.y - srcImgElement.elementCenter.y, 2));
	if (abs(circleRadius - srcImgElement.elementRadius) < 5)
		return true;
	else
		return false;
}
bool Img_Draw::isRectangleBeenClick(CvPoint mouseClickPosition, imgElement srcImgElement)
{
	if (mouseClickPosition.y <= srcImgElement.startingPoint.y + 2 && mouseClickPosition.y >= srcImgElement.startingPoint.y - 2)
		if (mouseClickPosition.x > srcImgElement.startingPoint.x)
			if (mouseClickPosition.x < srcImgElement.endingPoint.x)
				return true;
	if (mouseClickPosition.y <= srcImgElement.endingPoint.y + 2 && mouseClickPosition.y >= srcImgElement.endingPoint.y - 2)
		if (mouseClickPosition.x > srcImgElement.startingPoint.x)
			if (mouseClickPosition.x < srcImgElement.endingPoint.x)
				return true;
	if (mouseClickPosition.x <= srcImgElement.endingPoint.x + 2 && mouseClickPosition.x >= srcImgElement.endingPoint.x - 2)
		if (mouseClickPosition.y > srcImgElement.startingPoint.y)
			if (mouseClickPosition.y < srcImgElement.endingPoint.y)
				return true;
	if (mouseClickPosition.x <= srcImgElement.startingPoint.x + 2 && mouseClickPosition.x >= srcImgElement.startingPoint.x - 2)
		if (mouseClickPosition.y > srcImgElement.startingPoint.y)
			if (mouseClickPosition.y < srcImgElement.endingPoint.y)
				return true;
	return false;
}
bool Img_Draw::isLineBeenClick(CvPoint mouseClickPosition, imgElement srcImgElement)
{
	int biggerX = srcImgElement.endingPoint.x >= srcImgElement.startingPoint.x ? srcImgElement.endingPoint.x : srcImgElement.startingPoint.x;
	int smallX = srcImgElement.endingPoint.x < srcImgElement.startingPoint.x ? srcImgElement.endingPoint.x : srcImgElement.startingPoint.x;
	int biggerY = srcImgElement.endingPoint.y >= srcImgElement.startingPoint.y ? srcImgElement.endingPoint.y : srcImgElement.startingPoint.y;
	int smallY = srcImgElement.endingPoint.y < srcImgElement.startingPoint.y ? srcImgElement.endingPoint.y : srcImgElement.startingPoint.y;

	if (mouseClickPosition.x >= smallX&&mouseClickPosition.x <= biggerX&&mouseClickPosition.y >= smallY&&mouseClickPosition.y <= biggerY)
	{
		int a = srcImgElement.endingPoint.y - srcImgElement.startingPoint.y;
		int b = srcImgElement.startingPoint.x - srcImgElement.endingPoint.x;
		int c = (srcImgElement.endingPoint.x*srcImgElement.startingPoint.y) - (srcImgElement.startingPoint.x*srcImgElement.endingPoint.y);
		double divisor, dividend;
		dividend = abs(a*mouseClickPosition.x + b*mouseClickPosition.y + c);
		divisor = sqrt(a*a + b*b);
		double distance = dividend / divisor;
		if (distance < 5)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Img_Draw::isEllipseBeenClick(CvPoint mouseClickPosition)
{
	return true;
}

INT Img_Draw::matShow(const Mat&src)
{
	imshow("view", src);
	return 1;
}
INT Img_Draw::matShow(const string windowsName, const Mat&src)
{
	imshow(windowsName, src);
	return 1;
}
INT Img_Draw::matShow(const string windowsName, const Mat&src, Size matShowSize)
{
	Mat dst;
	resize(src, dst, matShowSize);
	matShow(windowsName, dst);
	return 1;
}

INT Img_Draw::drawRectangleAndShow(Mat& src, CvPoint point1, CvPoint point2, const string windowsName)
{
	rectangle(src, point1, point2, drawElementColour, 1, 8, 0);
	matShow(windowsName, src);
	return 1;
}
INT Img_Draw::drawRectangle(Mat&src, CvPoint point1, CvPoint point2, Scalar rectangleColour)
{
	rectangle(src, point1, point2, rectangleColour, 1, 8, 0);
	return 1;
}
INT Img_Draw::drawCircleAndShow(Mat& src, CvPoint circleCenter, double circleRadius, const string windowsName)
{
	circle(src, circleCenter, circleRadius, drawElementColour, 1, 8, 0);
	matShow(windowsName, src);
	return 1;
}
INT Img_Draw::drawCircle(Mat& src, CvPoint circleCenter, double circleRadius, Scalar circleColour)
{

	circle(src, circleCenter, circleRadius, circleColour, 1, 8, 0);
	return 1;
}
INT Img_Draw::drawLineAndShow(Mat&src, CvPoint point1, CvPoint point2, const string windowsName)
{
	line(src, point1, point2, drawElementColour, 1, 8, 0);
	matShow(windowsName, src);
	return 1;
}
INT Img_Draw::drawLine(Mat&src, CvPoint point1, CvPoint point2, Scalar lineColour)
{
	line(src, point1, point2, lineColour, 1, 8, 0);
	return 1;
}
INT Img_Draw::drawEllipseAndShow(Mat&src, CvPoint center, CvSize size, double, double, double, const string windowsName)
{
	ellipse(src, center, size, 10, 0, 360, drawElementColour, 1, 8, 0);
	matShow(windowsName, src);
	return 1;
}
INT Img_Draw::drawEllipse(Mat&src, CvPoint center, CvSize size, double, double, double, Scalar ellipseColour)
{
	ellipse(src, center, size, 10, 0, 360, ellipseColour, 1, 8, 0);
	return 1;
}

Mat Img_Draw::recovery()
{
	Mat test;
	return test;
}
Mat Img_Draw::move()
{
	Mat test;
	return test;
}
Mat Img_Draw::elementRemove()
{
	Mat test;
	return test;
}

INT Img_Draw::lineElement_PushBack(CvPoint StartingPoint, CvPoint EndingPoint)
{

	imgElement line;
	line.startingPoint = StartingPoint;
	line.endingPoint = EndingPoint;
	line.elementType = 2;
	imgDraw.Vec_imgElement.push_back(line);

	currentPointToNode->Vec_operationList.push_back(line);

	operationPushBack();
	return 1;
}
INT Img_Draw::rectangleElement_PushBack(CvPoint StartingPoint, CvPoint EndingPoint)
{

	imgElement rectangle;
	rectangle.startingPoint = StartingPoint;
	rectangle.endingPoint = EndingPoint;
	rectangle.elementType = 0;
	imgDraw.Vec_imgElement.push_back(rectangle);	

	currentPointToNode->Vec_operationList.push_back(rectangle);

	operationPushBack();
	return 1;
}
INT Img_Draw::circleElement_PushBack(CvPoint center, INT radius)
{

	imgElement circle;
	circle.elementCenter = center;
	circle.elementRadius = radius;
	circle.elementType = 1;
	imgDraw.Vec_imgElement.push_back(circle);

	currentPointToNode->Vec_operationList.push_back(circle);


	operationPushBack();
	return 1;
}
INT Img_Draw::ellipseElement_PushBack(CvPoint center, CvSize size)
{
	imgElement ellipse;
	ellipse.elementCenter = center;
	ellipse.elementType = 3;
	ellipse.size = size;
	imgDraw.Vec_imgElement.push_back(ellipse);
	operationPushBack();
	return 1;
}

BOOL Img_Draw::operationPushBack()
{
	STRU_doubleLinked_List* node = new STRU_doubleLinked_List;
	node->Vec_operationList = currentPointToNode->Vec_operationList;
	node->Next = NULL;
	nodeAdd(node);
	return  true;
}

Mat Img_Draw::UNDO()
{
	if (currentPointToNode != NULL&&currentPointToNode->Prev!=NULL)
	{
		currentPointToNode = currentPointToNode->Prev;
		vector<struct imgElement>::iterator imgElementIterator = currentPointToNode->Vec_operationList.begin();
		current_NodeNum--;
		return 	reDraw(imgElementIterator);
	}
	else
		return originalMat;
}
Mat Img_Draw::REDO()
{
	if (currentPointToNode != NULL&&currentPointToNode->Next!=NULL)
	{
		currentPointToNode = currentPointToNode->Next;
		vector<struct imgElement>::iterator imgElementIterator = currentPointToNode->Vec_operationList.begin();
		current_NodeNum++;
		return 	reDraw(imgElementIterator);
	}
	else
		return originalMat;
}