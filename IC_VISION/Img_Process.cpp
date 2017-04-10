#include "stdafx.h"


Img_Process::Img_Process()
{
	threshold = 0;
	max_value = 255;

	img_Smooth_Param = new Smooth_data_Str;
	img_Canny_Param = new Canny_data_Str;
	img_TemplateMatch_Param = new TemplatMatch_data_Str;
	img_Smooth_Param->param1 = 3;
	img_Smooth_Param->param2 = 0;
	img_Smooth_Param->param3 = 0;
	img_Smooth_Param->param4 = 0;
	img_Smooth_Param->smooth_Type = CV_GAUSSIAN;
	img_TemplateMatch_Param->templateMatchMethod = CV_TM_SQDIFF+1;

	img_Canny_Param->apertureSize = 3;
	img_Canny_Param->cannyThreshold1 = 0;
	img_Canny_Param->cannyThreshold2 = 0;
	img_Canny_Param->L2gradient = FALSE;
}


Img_Process::~Img_Process()
{
}

Mat Img_Process::Img_Threshold(Mat& src)
{
	//int threshold;
	//int threshold_type;
	//int max_value;
	Mat dst = Mat(src);
	cv::threshold(src, dst, threshold, max_value, threshold_type);
	return dst;
}

Mat Img_Process::Img_Smooth(Mat&src)
{
	Mat dst = Mat(src);
	//cvSmooth()
	switch (img_Smooth_Param->smooth_Type)
	{
	case CV_BLUR: //��ֵ�˲�
	{
		//src��dst��Ȼ�ֱ�������ͼ������ͼ��sizeΪ��ֵ�˲���ģ���С��AnchorΪê�㣨����ʲôû��Դ�벻������
		//���ΪPoint(-1, -1)����ê�����˲��������ĵ㡣borderTypeΪ��Ե���ֵ���͡�
		//blur(src, dst, Size ksize, Point anchor = Point(-1, -1), int borderType = BORDER_DEFAULT);
		blur(src, dst, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	}
	break;
	case CV_MEDIAN://��ֵ�˲�
	{
		medianBlur(src, dst, 3);
	}
	break;
	case CV_GAUSSIAN://��˹�˲�
	{
		GaussianBlur(src, dst, Size(3, 3), 0, 0);
	}
	break;
	case CV_BILATERAL://˫���˲�
	{
		bilateralFilter(src, dst, 3, 3 * 2, 3 / 2);
	}
	break;
	default:
		break;
	}
	return dst;
}

Mat Img_Process::Img_Canny(Mat&src)
{
	Mat dst = Mat(src);
	Canny(src, dst, img_Canny_Param->cannyThreshold1, img_Canny_Param->cannyThreshold2, img_Canny_Param->apertureSize, img_Canny_Param->L2gradient);
	return dst;
}

Mat Img_Process::Img_TemplateMatch(Mat&src, Mat&tmp, int matchMethod)
{
	//Point matchPos, maxMatchPos;
	//double maxmax = 0.0;
	//Mat maxMatchTmpl = tmplEdge[tmplEdge.size() / 2];
	//for (int i = 0; i < tmplEdge.size(); i++)
	//{
	//	matchTemplate(edge, this->tmplEdge[i], matchResult, CV_TM_CCORR);
	//	minMaxLoc(matchResult, &min, &max, 0, &matchPos);
	//	if (max > maxmax)
	//	{
	//		maxmax = max;
	//		maxMatchPos = matchPos;
	//		maxMatchTmpl = tmplEdge[i];
	//	}
	//}
	//innerCenter.x = tmplPos.x * DOWNSAMPLE_SCALE + precTmplPos.x + centerCircleBigPosBeg + maxMatchPos.x + maxMatchTmpl.cols / 2;
	//innerCenter.y = tmplPos.y * DOWNSAMPLE_SCALE + precTmplPos.y + centerCircleBigPosBeg + maxMatchPos.y + maxMatchTmpl.rows / 2;
	//innerRadius = maxMatchTmpl.cols / 2;

	Mat dst = Mat(src);
	//matchTemplate(src, tmp, OutputArray result, int method);
	switch (matchMethod)
	{
	case CV_TM_SQDIFF:	//ƽ����ƥ�䷨����õ�ƥ��Ϊ0��ֵԽ��ƥ��Խ��
	{
	}
	break;

	case CV_TM_SQDIFF_NORMED:	//��һ��ƽ����ƥ�䷨
	{}
	break;

	case CV_TM_CCORR:// ���ƥ�䷨�����ó˷���������ֵԽ�����ƥ��Խ��
	{}
	break;

	case CV_TM_CCORR_NORMED: //��һ�����ƥ�䷨
	{}
	break;

	case CV_TM_CCOEFF:// ���ϵ��ƥ�䷨����õ�ƥ��Ϊ1�� - 1��ʾ����ƥ��
	{}
	break;

	case CV_TM_CCOEFF_NORMED:// ��һ�����ϵ��ƥ�䷨
	{}
	break;
	default:
		break;
	}
	return dst;
}