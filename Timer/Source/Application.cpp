#include <iostream>
#include <thread>

#include "Timer.h"

#define LOG(x) std::cout << x << std::endl
#define Sleep(x) std::this_thread::sleep_for(x)

int main()
{
	// Testing Timer.h
	using namespace std::literals::chrono_literals;
	typedef std::Timer Timer;

	Timer timer;
	timer.start();
	LOG("Timer Started: " << timer.GetElapsedTime());
	Sleep(1s);

	timer.stop();
	LOG("Timer Stoped: " << timer.GetElapsedTime());
	Sleep(1s);
	Sleep(1s);

	LOG(timer.GetElapsedTime());

	timer.resume();
	LOG("Timer Resumed: " << timer.GetElapsedTime());
	Sleep(1s);
	Sleep(1s);

	LOG("Elapsed Time: " << timer.GetElapsedTime());

	timer.reset();
	LOG("Timer Was Reset: " << timer.GetElapsedTime());
	Sleep(1s);
	Sleep(1s);

	LOG(timer.GetElapsedTime());

	timer.start();
	LOG("Timer Started: " << timer.GetElapsedTime());
	Sleep(1s);
	LOG(timer.GetElapsedTime());


	std::cin.get();
}