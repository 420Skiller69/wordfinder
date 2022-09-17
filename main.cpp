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


	vector<struct Student> studs(popSize);
	vector<struct Student> studs_mirror(popSize);

	for(auto &s: studs)
		for(auto &letter: s.word)
			letter = 'a' + rand()%('z' - 'a' + 1);

	

	for(int generation = 0; generation < 1000; generation++)
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

			int parentBias = rand()%keyword.size();
			for(vector<char>::size_type i = 0; i < keyword.size(); i++)
			{
				if( i <= parentBias) child.word[i] = (*parent1).word[i];
				else				 child.word[i] = (*parent2).word[i];
			}
			if(rand()/(double)RAND_MAX < 0.2)
			{
				child.word[rand()%keyword.size()] = 'a' + rand()%('z' - 'a' + 1);
			}
		}
		// cout << generation << "--------------------------" << endl;
		// for(auto s: studs)
		// {
		// 	for(auto letter: s.word)
		// 		cout << letter ;
		// 	cout << " => " << s.fitness << endl;
		// }
		swap(studs, studs_mirror);
	}


	for(auto s: studs)
	{
		for(auto letter: s.word)
			cout << letter ;
		cout << " => " << s.getFitness(keyword) << endl;
	}


	return 0;
}


