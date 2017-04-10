
// stdafx.h : 标准系统包含文件的包含文件
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展
#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT
// 功能区和控件条的 MFC 支持


#include"conf_Load_Save.h"
#include"CameraBase.h"
#include"Camera.h"
#include <afxcontrolbars.h>
#include"CameraChooseDlg.h"
#include"Pylon_Camera.h"
#include"CameraSettingsDialog.h"
#include"Socket_Communicate.h"
#include"RobotSettingsDlg.h"
#include"ThresholdSettingsDlg.h"
#include"CannySettingsDlg.h"
#include"TemplateSettingsDlg.h"
#include"SmoothSettingsDlg.h"
#include"Robot.h"
//#include "tisudshl.h"
#include "DoubleLinked_List.h"
#include <math.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<opencv.hpp>
#include<cv.h>
#include<highgui.h>
#include <cxcore.hpp>
#include"Img_Draw.h"
#include"Img_Process.h"


using namespace Pylon;
using namespace cv;
using namespace std;


#define PI 3.1415926




//MAX connect camera and MAX connect robot
#define MAX_CONNECT_ROBOT_NUM 5
#define MAX_CONNECT_CAMERA_NUM 5



//every connect cam number
#define CAM1 1
#define CAM2 2
#define CAM3 3
#define CAM4 4
#define CAM5 5

//every connect robot number
#define ROBOT1 1
#define ROBOT2 2
#define ROBOT3 3
#define ROBOT4 4
#define ROBOT5 5

extern CBaslerGigEInstantCameraArray Global_GigeCameraArray;
extern BOOL Global_CameraConnect_Statu[MAX_CONNECT_CAMERA_NUM];
extern BOOL Global_RobotConnect_Statu[MAX_CONNECT_ROBOT_NUM];
extern INT Globa_Camera_Choose[MAX_CONNECT_CAMERA_NUM];
extern Size Global_ShowImageSize[MAX_CONNECT_CAMERA_NUM];
extern BOOL Global_Camera_Run_Record_Save[MAX_CONNECT_CAMERA_NUM];
extern BOOL Global_UnRecognizeImage_Save[MAX_CONNECT_CAMERA_NUM];
extern CBaslerGigEInstantCameraArray Global_Dected_GigeCameraArray;


extern Mat Global_PIC_intializeMat;
extern Mat Global_PIC_Size_ShowMat;
extern Mat Global_PIC_Original_Mat;
extern Mat Global_PIC_Show_Mat;

extern INT BEENCHOOSED_ELEMENTNUM;
extern CvPoint moveDistance[2];

extern Img_Draw imgDraw;

void position_2_DataGet(int x, int y);
void position_1_DataGet(int x, int y);
void ImageMouseClickEvent(int event, int x, int y, int flags, void* param);

//窗口控件获取坐标位置显示在窗口
extern CEdit* imgX;
extern CEdit* imgY;



/*鼠标事件处理*/
void ImageMouseClickEvent(int event, int x, int y, int flags, void* param);

void coordinateShowFunction(CvPoint ButtonDownPosition, Mat& image);



typedef struct robotStruct
{
	CString robotIP;
	int robotPort;
}robotStruct,*robotStructPtr;

typedef struct PylonGIGECamerStruct
{
	CString cameraSerialNum;
	CString camerIP;
	CString camerSubMask;
	CString cameraUserDefineID;
	bool saveRunRecord;
	bool saveUnRecognizerImage;
	Mat* grabImageMat;
}PylonGIGECamerStruct,*PylonGIGECamerStructPtr;

typedef struct PylonImageFormat
{
	INT width;
	INT height;
	EPixelType pixFormat;
	INT bufferSize;
	INT exposeTime;
};

typedef struct imgElement
{
	enum
	{
		circle = 1,
		line = 2,
		rectangle=0,
		ellipse=3,
	};
	CvPoint elementCenter;
	CvPoint startingPoint;
	CvPoint endingPoint;
	double elementRadius;
	int elementWidth;
	int elementHeight;
	int elementType;//(0:rectangle)
	Scalar elementColour;
	CvSize size;
};


struct STRU_doubleLinked_List
{
	//T param;
	vector<imgElement> Vec_operationList;
	STRU_doubleLinked_List* Next;
	STRU_doubleLinked_List* Prev;
};


INT CStringToINT(CString str);
CHAR* CStringToCHAR(CString str);
CString INT_ToCString(INT x);


//img processing struct

typedef struct Smooth_data_Str
{
	int smooth_Type;
	int param1;
	int param2;
	double param3;
	double param4;
}Smooth_data_Str;
typedef struct Canny_data_Str 
{
	int cannyThreshold1;
	int cannyThreshold2;
	int apertureSize;
	BOOL L2gradient;
};

typedef struct TemplatMatch_data_Str
{
	int templateMatchMethod;
}TemplatMatch_data_Str;

extern Img_Draw imgDraw;

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif



