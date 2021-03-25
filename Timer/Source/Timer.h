#pragma once
#include <chrono>

_STD_BEGIN
class Timer
{
private:
	std::chrono::steady_clock::time_point m_Begin, m_Start, m_End;
	float m_StopedTime = 0.0f;
	bool m_TimerStarted = false, m_IsCounting = false;
public:
	float GetElapsedTime() const;
	void start();
	void resume();
	void reset();
	void stop();
};
_STD_END
