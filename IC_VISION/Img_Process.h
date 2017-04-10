#pragma once

class Img_Process:public Img_Draw
{
public:
	Img_Process();
	int threshold;
	int threshold_type;
	int max_value;

	struct Smooth_data_Str* img_Smooth_Param;
	struct Canny_data_Str* img_Canny_Param;
	struct TemplatMatch_data_Str* img_TemplateMatch_Param;
	

	Mat Img_Threshold(Mat&);
	Mat Img_Smooth(Mat&);
	Mat Img_Canny(Mat&);
	Mat Img_TemplateMatch(Mat&, Mat&tmp,int matchMethod);
	virtual ~Img_Process();
};

