/* ----------------------------------------------------------------------------
 * @file float_integer_speed.cpp
 *
 * Routines to benchmark the speed of floating point operations compared to 
 * integer operation
 * ---------------------------------------------------------------------------*/

#include <vector>
#include <ctime>
#include <iostream>
#include <cstdint>
#include <complex>

template<class T>
void speed_test(size_t nbr)
{
	const int nbrRef = 200;
	std::vector<T> v(nbr);
	std::vector<T> vref(nbrRef);
	// Initialization of the vector
	for (unsigned i = 0; i < v.size(); ++i)
	       v[i] = static_cast<T>(i);
	// Initialization of the reference vector
	for (unsigned i = 0; i < vref.size(); ++i)
	       vref[i] = static_cast<T>(i);
	// Computation test
	for (unsigned i = 0; i < v.size() - vref.size(); i++)
	{	
		T tmp = 0;
		for(unsigned j = 0; j < vref.size(); ++j)
			 tmp += v[i+j] * vref[j]; 
		v[i] = tmp;
	}
		

}

int main (int argc, char ** argv)
{
	using namespace std;
	
	// 32 bits integers  test
	{
		clock_t t;
		t = clock();
		cout << "Testing 32 bits integers...\n";
		speed_test<uint32_t>(500000);	
		t = clock()- t;
		cout << " : " << ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}

	// 16 bits integer test
	{
		clock_t t;
		t = clock();
		cout << "Testing 16 bits integers...\n";
		speed_test<uint16_t>(500000);	
		t = clock()- t;
		cout << " : " << ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}

	// Floating point test
	{
		clock_t t;
		t = clock();
		cout << "Testing floats...\n";
		speed_test<float>(500000);	
		t = clock()- t;
		cout << " : " << ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}
	// Double  test
	{
		clock_t t;
		t = clock();
		cout << "Testing doubles...\n";
		speed_test<double>(500000);	
		t = clock()- t;
		cout << " : " << ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}

	size_t complex_test_duration = 100000;
	
	// Complex Double Test 
	{
		clock_t t;
		t = clock();
		cout << "Testing complex doubles...\n";
		speed_test<std::complex<double>>(complex_test_duration);	
		t = clock()- t;
		cout << " : " << ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}
	// Complex Float Test
	{
		clock_t t;
		t = clock();
		cout << "Testing complex floats...\n";
		speed_test<std::complex<float>>(complex_test_duration);	
		t = clock()- t;
		cout << " : " << ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}
	// Complex int32 Test
	{
		clock_t t;
		t = clock();
		cout << "Testing complex int32...\n";
		speed_test<std::complex<int32_t>>(complex_test_duration);	
		t = clock()- t;
		cout << " : "  << ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}
	// Complex int16  Test
	{
		clock_t t;
		t = clock();
		cout << "Testing complex int16...\n";
		speed_test<std::complex<int16_t>>(complex_test_duration);	
		t = clock()- t;
		cout << " : " <<  ((float)t) / CLOCKS_PER_SEC << " seconds" << '\n';
	}

	return 0;
}

