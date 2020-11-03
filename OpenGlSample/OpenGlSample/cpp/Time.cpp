#include "../h/Time.h"

Time* Time::t_instance;

void Time::SetFrame()
{
	fixingframe = 60;
	QueryPerformanceFrequency(&frameinfo);
	QueryPerformanceCounter(&preframecount);

	perframe = frameinfo.QuadPart / (double)fixingframe;
}

bool Time::PerRenderFrame()
{
	if (firstcall == false)
	{
		firstcall = true;
		SetFrame();
	}
	QueryPerformanceCounter(&framecount);

	double timedistance = framecount.QuadPart - preframecount.QuadPart;

	if (timedistance > perframe)
	{
		preframecount = framecount;

		std::cout << "dis : " << timedistance << " frame : " <<
			(frameinfo.QuadPart / timedistance) << std::endl;
		return true;
	}
	return false;
}

void Time::TimeOff()
{
	firstcall = false;
}