#include <vector>
#include <iterator>


struct student
{
	char word[8];
	double fitness;

    void getFitness(std::vector<char> keyword);
};

