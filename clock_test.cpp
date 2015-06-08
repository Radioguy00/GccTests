/***********************************************************************//**
@file

Tests the different clocks available on the system

@author Thierry Guichon
@date 2015
@copyright ORBCOMM

***************************************************************************/

#include <chrono>
#include <iostream>
#include "unistd.h"
#include "time.h"


int main()
{

	auto st1 = std::chrono::system_clock::now();
	auto hr1 = std::chrono::high_resolution_clock::now();
	//auto sc1 = std::chrono::steady_clock::now();
	
	sleep(1);
	
	auto st2 = std::chrono::system_clock::now();
	auto hr2 = std::chrono::high_resolution_clock::now();
	//auto sc2 = std::chrono::steady_clock::now();
	
	std::cout << "System Clock: " << std::chrono::duration_cast<std::chrono::nanoseconds>(st2-st1).count() << '\n';
	std::cout << "High Resolution Clock: " << std::chrono::duration_cast<std::chrono::nanoseconds>(hr2-hr1).count()  << '\n';
	//std::cout << "System Clock: " << "Is steady: " << std::boolalpha << std::chrono::system_clock::is_steady << '\n';
	//std::cout << "High Resolution Clock: " << "Is steady: " << std::boolalpha << std::chrono::high_resolution_clock::is_steady << '\n';
	//std::cout << "Steady Clock: " << duration_cast<double>(sc2-sc1).count()  << '\n';
	
	// Try Linux clock clock_gettime()
	
	timespec res;
	
	if (!clock_getres(CLOCK_MONOTONIC, &res))
	{
		std::cout << "clock_getres " << res.tv_sec << " seconds " << res.tv_nsec << " nanoseconds " << '\n';
	
	}
	else
	{
		std::cout << " Error while calling clock_getres\n";
	
	}
	if (!clock_gettime(CLOCK_MONOTONIC, &res))
	{
		std::cout << "clock_gettime " << res.tv_sec << " seconds " << res.tv_nsec << " nanoseconds " << '\n';
	
	}
	else
	{
		std::cout << " Error while calling clock_gettime\n";
	
	}


}