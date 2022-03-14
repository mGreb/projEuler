// Almost equilateral triangles
// Problem 94
// It is easily proved that no equilateral triangle exists with integral length sides and integral area.
// However, the almost equilateral triangle 5-5-6 has an area of 12 square units.
// We shall define an almost equilateral triangle to be a triangle for which two sides are equal
// and the third differs by no more than one unit.
// Find the sum of the perimeters of all almost equilateral triangles with integral side lengths
// and area and whose perimeters do not exceed one billion (1,000,000,000).

#include <iostream>
#include <cfenv>

int main() {
	
	feenableexcept(FE_OVERFLOW);
	
	long long int res = 0;
	
	long long int h1 = 1;
	long long int h2 = 1;
	
	for (long long int a = 3;; a += 2) {
		
		long long int hh1 = a * a - (a - 1) * (a - 1) / 4;
		while (h1 * h1 < hh1)
			h1 += 1;
		if (h1 * h1 == hh1) {
			if (3 * a - 1 > 1000000000)
				break;
			std::cout << a << " " << a << " " << a - 1 << " " << 3 * a - 1 << std::endl;
			res += 3 * a - 1;
		}
		h1 -= 1;
		
		long long int hh2 = a * a - (a + 1) * (a + 1) / 4;
		while (h2 * h2 < hh2)
			h2 += 1;
		if (h2 * h2 == hh2) {
			if (3 * a + 1 > 1000000000)
				break;
			std::cout << a << " " << a << " " << a + 1 << " " << 3 * a + 1 << std::endl;
			res += 3 * a + 1;
		}
		h2 -= 1;
		
	}
	
	std::cout << "Result: " << res << "\n";
	
	return 0;
}
