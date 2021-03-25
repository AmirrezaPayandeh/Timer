#include "Timer.h"

_STD_BEGIN

void Timer::start()
{
	if (m_TimerStarted)
		return;
	m_End = m_Start = m_Begin = std::chrono::high_resolution_clock::now();
	m_IsCounting = m_TimerStarted = true;
}

void Timer::resume()
{
	if (m_IsCounting && !m_TimerStarted)
		return;
	m_End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = m_End - m_Start;
	m_StopedTime += duration.count();
	m_IsCounting = true;
}

void Timer::reset()
{
	if (!m_TimerStarted)
		return;
	m_End = m_Start = m_Begin = std::chrono::high_resolution_clock::now();
	m_StopedTime = 0.0f;
	m_TimerStarted = m_IsCounting = false;
}

float Timer::GetElapsedTime() const
{
	std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
	float elapsedTime = 0.0f;
	float stopedDuration = 0.f;
	std::chrono::duration<float> duration = (now - m_Begin);
	if (!m_IsCounting)
	{
		std::chrono::duration<float> duration = (now - m_Start);
		stopedDuration = duration.count();
	}
	elapsedTime = duration.count() - m_StopedTime - stopedDuration;
	return elapsedTime;
}

void Timer::stop()
{
	if (!m_IsCounting && !m_TimerStarted)
		return;
	m_Start = std::chrono::high_resolution_clock::now();
	m_IsCounting = false;
}

_STD_END