#include "Student.h"
extern std::vector<char> keyword;

using namespace std;


double Student::getFitness(std::vector<char> keyword)
{
	double temp_fitness = 0;
	for(vector<char>::size_type i = 0; i < keyword.size(); i++) 
		temp_fitness += word[i] == keyword[i];

    temp_fitness = exp(temp_fitness);
	fitness = temp_fitness;
    return temp_fitness;
}

void Student::display()
{
	for(auto letter: word)
		std::cout << letter ;
	std::cout << " => " << getFitness(keyword) << std::endl;
}

void interpolate(const class Student &parent1, const class Student &parent2, class Student &child, double bias)
{
	int parentBias = round(bias * keyword.size());

	for(std::vector<char>::size_type i = 0; i < keyword.size(); i++)
	{
		if( i <= parentBias) child.word[i] = parent1.word[i];
		else				 child.word[i] = parent2.word[i];
	}
}

void Student::mutate(double probability, double strength)
{
	if(rand()/(double)RAND_MAX < probability)
	{
		for(int i = 0; i <= strength; i++)
			word[rand()%keyword.size()] = 'a' + rand()%('z' - 'a' + 1);
	}
}