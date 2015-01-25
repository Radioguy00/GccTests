/*-----------------------------------------------------------------------------
 * @file complex_integer.cpp
 *
 * Verify that the STL supports complex<int16_t> and complex<int32_t> and verify 
 * their performance
 * ---------------------------------------------------------------------------*/

#include <cstdint>
#include <complex>

int main (int argc, char ** argv)
{
	using namespace std;
	complex<int16_t> c1(123, 456);
	complex<int16_t> c2(23, 54);
	complex<int16_t> c3 = c1 + c2;
}

