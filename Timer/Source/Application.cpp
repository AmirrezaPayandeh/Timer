// Testing Timer.h

#include <iostream>
#include <thread>

#include "Timer.h"

#define LOG(x) std::cout << x << std::endl
#define Sleep(x) std::this_thread::sleep_for(x)

typedef std::Timer Timer;
typedef Timer::TimingMode TimingMode;

using namespace std::literals::chrono_literals;

void Function()
{
	Timer timer(TimingMode::ObjectLifeTimeMode);
	Sleep(3s);
	LOG("Time Elapsed: " << timer.GetElapsedTime());
	timer.stop();
	Sleep(1s);
	LOG("Time Elapsed: " << timer.GetElapsedTime());
	Sleep(2s);
}

int main()
{
	Function();
	std::cout << "========================================\n";
	{
		Timer timer(TimingMode::FreeMode);
		timer.start();
		LOG("Timer Started: " << timer.GetElapsedTime());
		Sleep(1s);

		timer.stop();
		LOG("Timer Stoped: " << timer.GetElapsedTime());
		Sleep(2s);

		LOG(timer.GetElapsedTime());

		timer.resume();
		LOG("Timer Resumed: " << timer.GetElapsedTime());
		Sleep(2s);

		LOG("Elapsed Time: " << timer.GetElapsedTime());

		timer.reset();
		LOG("Timer Was Reset: " << timer.GetElapsedTime());
		Sleep(2s);

		LOG(timer.GetElapsedTime());

		timer.start();
		LOG("Timer Started: " << timer.GetElapsedTime());
		Sleep(3s);
	}
	std::cout << "Program ended\n";
	std::cin.get();
}