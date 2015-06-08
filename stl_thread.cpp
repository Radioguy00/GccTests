
#include <iostream>
#include <chrono>
#include <thread>
#include <exception>
#include <future>

void my_thread_function(int);


int main()
{

	int my_value{10};
	std::cout << "Hello this is the start of my program \n";
	std::thread t(my_thread_function, my_value);

	std::cout << "Thread has been created" << std::endl;

	std::cout << std::boolalpha << "Joinable ? " << t.joinable() << std::endl;

	try
	{
	if (t.joinable())
		t.join();
	}
	catch(std::system_error &e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
	std::cout << "End of the program \n";
}

void test_packaged_task()
{
	std::packaged_task<void(int)>  pt(my_thread_function);
	auto f = pt.get_future();
	// Starts the task
//	std::thread t(std::move(pt), 23);
	f.get();

}


void my_thread_function(int value)
{
	//std::cout << "This is from the other thread";
	//std::cout << value;
	//std::this_thread::yield();
}
