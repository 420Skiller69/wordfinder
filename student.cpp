#include "student.h"

using namespace std;

void student::getFitness(vector<char> keyword)
{
	double temp_fitness = 0;
	for(vector<char>::size_type i = 0; i < keyword.size(); i++) 
		temp_fitness += word[i] == keyword[i];
	fitness = temp_fitness;
}