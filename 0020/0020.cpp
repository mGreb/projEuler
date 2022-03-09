//Factorial digit sum
//Problem 20
//
//n! means n * (n - 1) * ... * 3 * 2 * 1
//
//For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
//and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
//Find the sum of the digits in the number 100!

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

void shift_right(std::vector<int> &v, int num_pos)
{
	if (num_pos == 0)
		return;
	
	v.resize(v.size() + num_pos);
	for (int i = v.size() - 1; i >= num_pos; --i)
	{
		v[i] = v[i - num_pos];
		v[i - num_pos] = 0;
	}
	
	for (int i = 0; i < num_pos; ++i)
		v[i] = 0;
}

void make_correction(std::vector<int> &v)
{
	for (size_t i = 0; i < v.size() - 1; ++i)
		if (v[i] > 9)
		{
			v[i + 1] += v[i] / 10;
			v[i] %= 10;
		}
	
	if (v.back() > 9)
	{
		v.push_back(v.back() / 10);
		v[v.size() - 2] %= 10;
	}
}

void long_add(std::vector<int> &a, const std::vector<int> &b)  // a += b
{
	if (a.size() < b.size())
		a.resize(b.size());
	for (size_t i = 0; i < b.size(); ++i)
		a[i] += b[i];
	make_correction(a);
}

void multuply_by_digit(std::vector<int> &a, int x)
{
	std::transform(a.begin(), a.end(), a.begin(), [x](int a) -> int{ a *= x; return a;});
	make_correction(a);
}

// why not Karatsuba?
void long_mult(std::vector<int> &a, const std::vector<int> &b)  // a *= b
{
	std::vector<int> res;
	
	for (size_t i = 0; i < b.size(); ++i)
	{
		if (b[i] == 0)
			continue;
		
		std::vector<int> temp = a;
		
		// multiply temp by b[i] and shift it by i digits
		multuply_by_digit(temp, b[i]);
		shift_right(temp, i);
		
		long_add(res, temp);
		make_correction(res);
	}
	
	a = std::move(res);
}

int main()
{
	std::vector<int> fact = {1};
	
	std::vector<int> x = {2};
	
	for (int i = 0; i < 99; ++i)
	{
		long_mult(fact, x);
		long_add(x, {1});
	}
	
	std::cout << "Result: " << std::accumulate(fact.begin(), fact.end(), 0) << "\n";
	return 0;
}
