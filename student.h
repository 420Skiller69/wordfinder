#include <vector>
#include <iterator>
#include <cmath>


struct Student
{
	char word[8];
	double fitness;

    double getFitness(std::vector<char> keyword);
};

