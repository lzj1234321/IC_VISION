
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// IC_VISION.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
CBaslerGigEInstantCameraArray Global_GigeCameraArray(MAX_CONNECT_CAMERA_NUM);
CBaslerGigEInstantCameraArray Global_Dected_GigeCameraArray(MAX_CONNECT_CAMERA_NUM);
BOOL Global_CameraConnect_Statu[MAX_CONNECT_CAMERA_NUM];
BOOL Global_RobotConnect_Statu[MAX_CONNECT_ROBOT_NUM];
BOOL Global_Camera_Run_Record_Save[MAX_CONNECT_CAMERA_NUM];
BOOL Global_UnRecognizeImage_Save[MAX_CONNECT_CAMERA_NUM];
INT Globa_Camera_Choose[MAX_CONNECT_CAMERA_NUM];
Size Global_ShowImageSize[MAX_CONNECT_CAMERA_NUM];


Mat Global_PIC_intializeMat;
Mat Global_PIC_CurrentShowMat;
Mat Global_PIC_Original_Mat;
Mat Global_PIC_Show_Mat;
Mat Global_PIC_Size_ShowMat;

INT BEENCHOOSED_ELEMENTNUM;

//���ڿؼ���ȡ����λ����ʾ�ڴ���
CEdit* imgX;
CEdit* imgY;

CvPoint drawRectanglePosition[2];
CvPoint drawStraightLinePosition[2];
CvPoint drawCirclePosition[2];
CvPoint drawEllipsePositin[2];
CvPoint moveDistance[2];

Img_Draw imgDraw;
int drawElementFlag;//0:rectangle 1:circle 2:straight line
bool moveImgElementFlag = false;


/*�Ѿ�����Ĺ���*/
/*
1.�ƶ����ʵʱ��ʾ����
3.���������סshift�϶�������
4.���������סCtrl��Բ
5.���������סAlt����Բ
7.��ס���ֻ�ֱ��
*/


/*λ��1��Ϣ��ȡ*/
void inline position_1_DataGet(int x, int y)
{
	/*Բ����*/
	drawCirclePosition[0].x = x;
	drawCirclePosition[0].y = y;
	/*��Բ����*/
	drawEllipsePositin[0].x = x;
	drawEllipsePositin[0].y = y;
	/*��������*/
	drawRectanglePosition[0].x = x;
	drawRectanglePosition[0].y = y;

}

/*λ��2��Ϣ��ȡ*/
void inline position_2_DataGet(int x, int y)
{
	drawCirclePosition[1].x = x;
	drawCirclePosition[1].y = y;

	drawEllipsePositin[1].x = x;
	drawEllipsePositin[1].y = y;

	drawRectanglePosition[1].x = x;
	drawRectanglePosition[1].y = y;

	drawStraightLinePosition[1].x = x;
	drawStraightLinePosition[1].y = y;


}

/*����¼�����*/
void ImageMouseClickEvent(int event, int x, int y, int flags, void* param)
{
	Mat *srcMat = new Mat;
	*srcMat = ((Mat*)param)->clone();
	int moveX=0, moveY=0;
	switch (event)
	{
	case CV_EVENT_MOUSEMOVE:
	{
		position_2_DataGet(x, y);


		//coordinateShowFunction(mousePosition, *srcMat);
		imgX->SetWindowText(INT_ToCString(x));
		imgY->SetWindowText(INT_ToCString(y));
		//if (BEENCHOOSED_ELEMENTNUM != -1&&flags== CV_EVENT_FLAG_LBUTTON)
		if (flags == CV_EVENT_FLAG_LBUTTON)
		{
			if (BEENCHOOSED_ELEMENTNUM != -1)//��ѡ�ж���ʱ�Ż�ִ���ػ����
			{
				/*�ƶ������ȡ*/
				moveDistance[1].x = x;
				moveDistance[1].y = y;
				moveImgElementFlag = true;

				moveX = moveDistance[0].x - moveDistance[1].x;
				moveY = moveDistance[0].y - moveDistance[1].y;
				*srcMat = imgDraw.reDraw(BEENCHOOSED_ELEMENTNUM, moveX, moveY).clone();
				Global_PIC_Size_ShowMat = srcMat->clone();
				//moveDistance[0] = moveDistance[1];
				imshow("view", *srcMat);
			}
		}
		if (flags == 17)//shift+leftbuttonon draw rectangle
		{
			drawElementFlag = 0;
			*srcMat = Global_PIC_Size_ShowMat.clone();
			imgDraw.drawRectangleAndShow(*srcMat, drawRectanglePosition[0], drawRectanglePosition[1], "view");
		}
		if (flags == 9)//Ctrl+lftBUttonOn draw circle
		{
			drawElementFlag = 1;
			*srcMat = Global_PIC_Size_ShowMat.clone();
			int circleRadius = (int)sqrt(pow(drawCirclePosition[0].x - drawCirclePosition[1].x, 2) + pow(drawCirclePosition[0].y - drawCirclePosition[1].y, 2));
			imgDraw.drawCircleAndShow(*srcMat, drawCirclePosition[0], circleRadius, "view");
		}
		if (flags == 33)//alt+leftbuttonon draw ellipse
		{
			drawElementFlag = 3;
			*srcMat = Global_PIC_Size_ShowMat.clone();
			CvSize ellipseRadius = (abs(drawEllipsePositin[0].y - drawEllipsePositin[1].y) / 4, abs(drawEllipsePositin[0].x - drawEllipsePositin[1].x) / 2);
			imgDraw.drawEllipseAndShow(*srcMat, drawEllipsePositin[0], ellipseRadius, 0, 30, 240, "view");
		}
		if (flags == CV_EVENT_FLAG_MBUTTON)//����
		{
			drawElementFlag = 2;
			*srcMat = Global_PIC_Size_ShowMat.clone();
			imgDraw.drawLineAndShow(*srcMat, drawStraightLinePosition[0], drawStraightLinePosition[1], "view");
		}
	}
	break;
	case CV_EVENT_LBUTTONDOWN:
	{
		drawElementFlag = 100;
		/*�ƶ������ȡ*/
		moveDistance[0].x = x;
		moveDistance[0].y = y;

		BEENCHOOSED_ELEMENTNUM = -1;
		position_1_DataGet(x, y);
		if (imgDraw.IsElementChoosed(CvPoint(x, y)))//��ѡ�ж���ʱ�Ż�ִ���ػ����
		{
			BEENCHOOSED_ELEMENTNUM = imgDraw.beenChoosedElementNum;
			*srcMat = imgDraw.reDraw().clone();
		}
		imshow("view", *srcMat);
	}
	break;

	case CV_EVENT_LBUTTONUP:
	{
		position_2_DataGet(x, y);
		Global_PIC_Size_ShowMat = srcMat->clone();
		switch (drawElementFlag)
		{
		case 0:
		{
			imgDraw.rectangleElement_PushBack(drawRectanglePosition[0], drawRectanglePosition[1]);
			imgDraw.drawRectangle(Global_PIC_Size_ShowMat, drawRectanglePosition[0], drawRectanglePosition[1], CvScalar(0, 0, 255));
		}
		break;
		case 1:
		{
			int radius = (int)sqrt(pow(drawRectanglePosition[0].x - drawRectanglePosition[1].x, 2) + pow(drawRectanglePosition[0].y - drawRectanglePosition[1].y, 2));
			imgDraw.circleElement_PushBack(drawRectanglePosition[0], radius);
			imgDraw.drawCircle(Global_PIC_Size_ShowMat, drawRectanglePosition[0], radius, CvScalar(0, 255, 0));
		}
		break;
		case 3:
		{
			CvSize ellipseRadius = (abs(drawEllipsePositin[0].y - drawEllipsePositin[1].y) / 4, abs(drawEllipsePositin[0].x - drawEllipsePositin[1].x) / 2);
			imgDraw.drawEllipse(*srcMat, drawEllipsePositin[0], ellipseRadius, 0, 30, 240, CvScalar(0, 255, 0));
			imgDraw.ellipseElement_PushBack(drawEllipsePositin[0], ellipseRadius);
		}
		break;
		default:
			break;
		}
		drawElementFlag = 100;
		if (moveImgElementFlag)
		{
			imgDraw.operationSave(BEENCHOOSED_ELEMENTNUM, moveDistance[0].x - moveDistance[1].x, moveDistance[0].y - moveDistance[1].y);
			//imgDraw.operationPushBack();
			//imgDraw.imgElementMove(BEENCHOOSED_ELEMENTNUM, moveDistance[0].x-moveDistance[1].x, moveDistance[0].y - moveDistance[1].y);
			moveImgElementFlag = false;
		}
	}
	break;

	case CV_EVENT_MBUTTONDOWN:
	{
		/*ֱ������*/
		drawStraightLinePosition[0].x = x;
		drawStraightLinePosition[0].y = y;
	}
	break;

	case CV_EVENT_MBUTTONUP:
	{
		/*ֱ������*/
		drawStraightLinePosition[1].x = x;
		drawStraightLinePosition[1].y = y;
		Global_PIC_Size_ShowMat = srcMat->clone();
		imgDraw.lineElement_PushBack(drawStraightLinePosition[0], drawStraightLinePosition[1]);
		imgDraw.drawLine(Global_PIC_Size_ShowMat, drawStraightLinePosition[0], drawStraightLinePosition[1], CvScalar(0, 255, 0));
		drawElementFlag = 100;
	}
	break;
	default:
		break;
	}
	delete srcMat;
}

/*��ʾ����*/
void inline coordinateShowFunction(CvPoint ButtonDownPosition, Mat& image)
{
	Mat tmp = image.clone();
	if (ButtonDownPosition.x < image.cols&&ButtonDownPosition.y < image.rows)
	{
		CvPoint textPosition(ButtonDownPosition.x, ButtonDownPosition.y);
		/*�ĵ����ڵ������ĵ���ʾλ�õ���*/
		if (ButtonDownPosition.y < 20)
			textPosition.y += 20;
		if (ButtonDownPosition.y > (image.rows - 25))
			textPosition.y -= 25;
		if (ButtonDownPosition.x > (image.cols - 170))
			textPosition.x -= 165;

		if (Global_ShowImageSize[CAM1 - 1].width != 0)
		{
			double widthMulti = (double)Global_ShowImageSize[CAM1 - 1].width / image.cols;
			double heightMulti = (double)Global_ShowImageSize[CAM1 - 1].height / image.rows;

			ButtonDownPosition.x *= widthMulti;
			ButtonDownPosition.y *= heightMulti;
		}
		CvFont font;
		cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1, CV_AA);
		char positinonText[50];
		sprintf_s(positinonText, "Position:(%d,%d)", ButtonDownPosition.x, ButtonDownPosition.y);
		putText(tmp, positinonText, textPosition, 1, 1, CV_RGB(255, 200, 100));
		textPosition.y = textPosition.y + 20;
		imshow("view", tmp);
	}
}

INT CStringToINT(CString str)
{
	char* ch;
	INT x;
	int len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	ch = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, str, -1, ch, len, NULL, NULL);
	x = atoi(ch);
	return x;
}

CHAR* CStringToCHAR(CString str)
{
	char* ch;
	INT x;
	int len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	ch = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, str, -1, ch, len, NULL, NULL);
	return ch;
}

CString INT_ToCString(INT x)
{
	CString str;
	str.Format(_T("%d"), x);
	return str;
}


