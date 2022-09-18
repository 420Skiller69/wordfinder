#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <ctime>

#include "Student.h"

using namespace std;



vector<char> keyword = {'j', 'o', 'j', 'o', 'j', 'o', 'j', 'o'};
int popSize = 10;

int main(int argc, char* args[])
{
	srand(time(NULL));


	vector<class Student> studs(popSize);
	vector<class Student> studs_mirror(popSize);

	

	for(int generation = 0; generation < 10; generation++)
	{
		double totalFitness = 0; // calc fitness / totalfitness ------------------------------------------------------
		for(auto &s: studs)
			totalFitness += s.getFitness(keyword);
	
		for(auto &child: studs_mirror) // generate child in studs_mirror ---------------------------------------------
		{
			auto parent1 = begin(studs), parent2 = begin(studs); // get parents ---------------------------
			if(totalFitness == 0)
			{
				parent1 += rand()%studs.size();
				parent2 += rand()%studs.size();
			}
			else
			{
				double randVal = totalFitness * rand()/(double)RAND_MAX - 0.0000001;
				while(randVal > 0)
				{
					randVal -= parent1->fitness;
					parent1++;
				}
				parent1--;
				randVal = totalFitness * rand()/(double)RAND_MAX - 0.0000001;
				while(randVal > 0)
				{
					randVal -= parent2->fitness;
					parent2++;
				}
				parent2--;
			}

			interpolate(*parent1, *parent2, child, rand()/(double)RAND_MAX);
			child.mutate(0.2, 1);
		}
		cout << generation << "--------------------------" << endl;
		for(auto s: studs) 	s.display();
	
		swap(studs, studs_mirror);
	}



	return 0;
}


