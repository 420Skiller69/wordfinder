#include "Student.h"

using namespace std;

double Student::getFitness(vector<char> keyword)
{
	double temp_fitness = 0;
	for(vector<char>::size_type i = 0; i < keyword.size(); i++) 
		temp_fitness += word[i] == keyword[i];

    temp_fitness = exp(temp_fitness);
	fitness = temp_fitness;
    return temp_fitness;
}