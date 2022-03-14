//1000-digit Fibonacci number
//Problem 25
//The Fibonacci sequence is defined by the recurrence relation:
//Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
//Hence the first 12 terms will be:
//F1 = 1
//F2 = 1
//F3 = 2
//F4 = 3
//F5 = 5
//F6 = 8
//F7 = 13
//F8 = 21
//F9 = 34
//F10 = 55
//F11 = 89
//F12 = 144
//The 12th term, F12, is the first term to contain three digits.
//What is the index of the first term in the Fibonacci sequence to contain 1000 digits?


#include <array>
#include <iostream>
#include <cstdio>
#include <algorithm>

static const int len = 1000;

typedef std::array<char, len> long_num;

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
		++i;
	}
	
	std::cout << "Result: " << i << "\n";
	
	return 0;
}
