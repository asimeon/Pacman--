
#ifndef TIMER_H_
#define TIMER_H_

#include <windows.h>

//******************************************************************************
// Written by Matthew Dodd

class Timer
{
public:
	Timer()
	{
		//Call Reset timer to set our start time
		ResetTimer();
	}

	void ResetTimer()
	{
		//Reset our start time to the current time
		//We set prevTime here too to make sure we don't get weird values
		m_dStartTime = GetTime();
		m_dprevTime = m_dStartTime;
	}

	double GetTotalTime()
	{
		//Total time is simply current time - the start time
		double dCurrTime = GetTime();
		return dCurrTime - m_dStartTime;
	}

	double GetDeltaTime()
	{
		//Returns the time difference between now and the last time this function was called
		double dCurrTime = GetTime();
		double dDelta = dCurrTime - m_dprevTime;

		m_dprevTime = dCurrTime;

		return dDelta;
	}

	double GetTime()
	{
		LARGE_INTEGER kCurrTime;
		LARGE_INTEGER kFreq;

		QueryPerformanceFrequency(&kFreq);
		QueryPerformanceCounter(&kCurrTime);

		return ((double)kCurrTime.QuadPart / (double)kFreq.QuadPart);
	}

	double m_dStartTime;
	double m_dprevTime;
};

#endif // TIMER_H_
