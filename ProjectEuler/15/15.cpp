//Lattice paths
//Problem 15
//
//Starting in the top left corner of a 2×2 grid, and only being able to move to 
//the right and down, there are exactly 6 routes to the bottom right corner.
//
//How many such routes are there through a 20×20 grid?
#include <iostream>
#include <cstdlib>
using namespace std;

double f(double row, double col) {
	if(row == 0 && col == 0)
		return 1.;
	double result = 0;
	if(row > 0)
		result += f(row - 1, col);
	if(col > 0)
		result += f(row, col - 1);
	return result;
}

int main() {
	double gridDim = 20;
	cout.precision(20);
	cout << "Result: " << f(gridDim, gridDim) << endl; 
	system("pause"); 
}
