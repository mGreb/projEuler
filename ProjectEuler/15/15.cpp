//Lattice paths
//Problem 15
//
//Starting in the top left corner of a 2×2 grid, and only being able to move to 
//the right and down, there are exactly 6 routes to the bottom right corner.
//
//How many such routes are there through a 20×20 grid?

#include <iostream>
#include <array>

static const size_t dim = 20;
std::array<std::array<size_t, dim>, dim> cache;

size_t f(
    const size_t row,
    const size_t col
){
    size_t &cache_item = cache[row][col];
    
    if((row == 0) || (col == 0))
    {
        cache_item = 1;
        return cache_item;
    }
    
    if(cache_item != 0)
    {
        return cache_item;
    }
    else
    {
        cache_item = f(row - 1, col) + f(row, col - 1);
    }
    
    return cache_item;
}

int main()
{
    for(size_t row = 0; row < cache.size(); ++row)
    {
        for(size_t col = 0; col < cache[row].size(); ++col)
        {
            cache[row][col] = 0;
        }
    }
    
    std::cout.precision(20);
    std::cout << "Result: " << f(dim, dim) << std::endl;
    
    return 0;
}
