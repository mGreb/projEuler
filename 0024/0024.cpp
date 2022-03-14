// Lexicographic permutations
//
// Problem 24
//
// A permutation is an ordered arrangement of objects.
// For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
// If all of the permutations are listed numerically or alphabetically,
// we call it lexicographic order.
// The lexicographic permutations of 0, 1 and 2 are:
//
// 012   021   102   120   201   210
//
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

// I will use Narayana`s algorithm

#include <array>
#include <iostream>
#include <numeric>

static const int total_perm = 999999;
static const int n = 10;

template <typename T>
void swap(T &a, T &b) {
	const T t = a;
	a = b;
	b = t;
}

template <typename T>
void reverse(T &a, int i, int j) {
	while (i < j) {
		swap(a[i], a[j]);
		++i;
		--j;
	}
}

void print(const std::array<char, n> &a) {
	for (int i = 0; i < n; ++i)
		std::cout << (int)a[i];
	std::cout << "\n";
}

int main() {
	
	std::array<char, n> a;
	std::iota(begin(a), end(a), 0);
	
	for (size_t perm = 0; perm < total_perm; ++perm) {
		
		int j = n - 2;
		while (a[j] >= a[j + 1] && j > 0)
			--j;
		
		int l = n - 1;
		while (a[j] >= a[l] && l > j && l > 0)
			--l;
		
		swap(a[j], a[l]);
		reverse(a, j + 1, n - 1);
	}
	
	print(a);
	
	return 0;
}
