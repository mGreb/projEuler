// Non-abundant sums
// Problem 23
//
// A perfect number is a number for which the sum of its proper divisors is
// exactly equal to the number. For example, the sum of the proper divisors
// of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
// A number n is called deficient if the sum of its proper divisors is less
// than n and it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the
// smallest number that can be written as the sum of two abundant numbers is 24.
// By mathematical analysis, it can be shown that all integers greater than
// 28123 can be written as the sum of two abundant numbers. However, this
// upper limit cannot be reduced any further by analysis even though it is
// known that the greatest number that cannot be expressed as the sum of two
// abundant numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the
// sum of two abundant numbers.

#include <iostream>
#include <vector>

bool is_abundant(
    const size_t a
) {
    size_t acc = 0;
    const size_t limit = a / 2;
    for (size_t i = 1; i <= limit; ++i) {
        if (a % i == 0)
            acc += i;
        if (acc > a)
            return true;
    }
    return false;
}

int main(
) {
    // find all abundant numbers from 1 to 28123
    std::vector<size_t> abundants;
    for (size_t i = 1; i <= 28123; ++i)
        if (is_abundant(i))
            abundants.push_back(i);
    
    // find sum of all numbers
    size_t total_numbers_sum = 0;
    for (size_t i = 1; i <= 28123; ++i)
        total_numbers_sum += i;
    
    // mark all numbers that can be presented as sum of two abundant numbers
    std::vector<bool> sums(abundants.back() * 2, false);
    for (size_t i = 0; i < abundants.size(); ++i)
        for (size_t j = 0; j < abundants.size(); ++j)
            sums[abundants[i] + abundants[j]] = true;
    
    // sum them
    size_t sum = 0;
    for (size_t i = 0; i <= 28123; ++i)
        if (sums[i])
            sum += i;
    
    // subtract one from another to get result
    std::cout << "Result: " << total_numbers_sum - sum << "\n";
    
    return 0;
}
