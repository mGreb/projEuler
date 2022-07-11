// Reciprocal cycles
// Problem 26
// A unit fraction contains 1 in the numerator.
// The decimal representation of the unit fractions
// with denominators 2 to 10 are given:
// 1/2	= 	0.5
// 1/3	= 	0.(3)
// 1/4	= 	0.25
// 1/5	= 	0.2
// 1/6	= 	0.1(6)
// 1/7	= 	0.(142857)
// 1/8	= 	0.125
// 1/9	= 	0.(1)
// 1/10	= 	0.1
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
// It can be seen that 1/7 has a 6-digit recurring cycle.
// Find the value of d < 1000 for which 1/d contains the longest
// recurring cycle in its decimal fraction part.

#include <vector>
#include <cstddef>
#include <iostream>
#include <cmath>

typedef std::vector<size_t> number;

number long_invert(size_t x, size_t digits) {
  number res;
  size_t top = 1;
  size_t cnt = 0;
  while (top != 0 && res.size() < digits) {
    if (top < x) {
      top *= 10;
      if (top < x)
        res.push_back(0);
    } else {
      res.push_back(top / x);
      top = top - res.back() * x;
    }
    ++cnt;
  }
  return res;
}

bool check_equal(const number& x, size_t start1, size_t end1, size_t start2) {
  while (start1 != end1) {
    if (x[start1] != x[start2])
      return false;
    ++start1;
    ++start2;
  }
  return true;
}

bool check_if_window_applies(const number& x, size_t start_pos, size_t window_size) {
  const size_t start = start_pos;
  const size_t end = start_pos + window_size;
  size_t next_start = start_pos + window_size;
  
  const size_t next_end = next_start + window_size;
  if (next_end >= x.size())
    return false;
  
  while (next_start + window_size < x.size()) {
    if (!check_equal(x, start, end, next_start))
      return false;
    next_start += window_size;
  }
  
  return true;
}

size_t calc_reciprocal_cycle_length(const number& x) {
  for (size_t window_size = 1; window_size < x.size(); ++window_size)
    for(size_t start_pos = 0; start_pos < x.size(); ++start_pos)
      if (check_if_window_applies(x, start_pos, window_size))
        return window_size;
  return 0;
}

bool is_prime(size_t x) {
  for (size_t i = 2; i < std::sqrt(x) + 1; ++i)
    if (x % i == 0)
      return false;
  return true;
}

int main() {
  size_t num_max_cycle = 1;
  size_t max_cycle_len = 1;
  const size_t digits = 2000;
  for (size_t i = 2; i <= 999; ++i) {
    if (is_prime(i)) {
      const number n = long_invert(i, digits);
      if (n.size() > digits / 2) {
        const auto cycle_len = calc_reciprocal_cycle_length(n);
        if (cycle_len >= max_cycle_len) {
          max_cycle_len = cycle_len;
          num_max_cycle = i;
        }
      }
    }
  }
  std::cout << "Longest reciprocal cycle from 1/2 to 1/999 is 1/" << num_max_cycle << "\n";
  return 0;
}
