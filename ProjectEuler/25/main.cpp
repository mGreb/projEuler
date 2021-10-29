#include <array>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>

static const int len = 1000;

typedef std::array<char, len> long_num;

void print(const long_num &a) {
	for (size_t i = 0; i < a.size(); ++i)
		std::cout << (int)a[i];
	std::cout << std::endl;
}

void add(const long_num &a, const long_num &b, long_num &c) {
	for (size_t i = 0; i < c.size(); ++i)
		c[i] = a[i] + b[i];
	
	for (size_t i = a.size() - 1; i > 0; --i)
		if (c[i] > 9) {
			++c[i-1];
			c[i] -= 10;
		}
}

int main() {
	
	long_num a, b, c;
	std::fill(begin(a), end(a), 0);
	std::fill(begin(b), end(b), 0);
	std::fill(begin(c), end(c), 0);
	a.back() = 0;
	b.back() = 1;
	
	int i = 1;
	
	while (c[0] == 0) {
		add(a, b, c);
		a = b;
		b = c;
		// print(c);
		++i;
	}
	
	std::cout << i << std::endl;
	
	return 0;
}
