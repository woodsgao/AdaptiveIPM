// AdaptiveIPM.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "AdaptiveIPM.h"

using namespace std;
using namespace cv;

int main()
{

	
	string strImg = "./000024.jpg";
	Mat srcImg = imread(strImg.c_str());
	
	//设定灭点
	Point ptVP = Point(1671.8, 2784.4);
	
	//设定相机模型
	Camera cam;
	cam.SetFx(1695.11);
	cam.SetFy(1699.32);
	cam.SetCx(1651.52);
	cam.SetCy(2496.88);
	cam.SetHeight(3000);

	cam.SetK1(0);
	cam.SetK2(0);
	cam.SetK3(0);
	cam.SetK4(0);
	cam.SetP1(0);
	cam.SetP2(0);

	cam.SetPitch(-8.5 * DEG2RAD);
	cam.SetRoll(0);
	cam.SetYaw(0 * DEG2RAD);

	//动态反投影变换
	AdaptiveIPM AdpIpm;

	AdpIpm.SetCamera(cam);
	AdpIpm.SetVp(ptVP);
	AdpIpm.SetImage(srcImg);
	AdpIpm.ipm_based_on_vp(); //进行自适应反投影变换

	imshow("result", AdpIpm.GetIpm());
	waitKey(0);

    return 0;
}

