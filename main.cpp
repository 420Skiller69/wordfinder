#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <ctime>

#include "student.h"

using namespace std;



vector<char> keyword = {'j', 'o', 'j', 'o', 'j', 'o', 'j', 'o'};


int main(int argc, char* args[])
{
	srand(time(NULL));
	vector<struct student> studs(10);



	for(auto &s: studs)
	{
		for(auto &letter: s.word)
			letter = 'a' + rand()%('z' - 'a' + 1);
		s.getFitness(keyword);
	}
	
	for(auto s: studs)
	{
		for(auto letter: s.word)
			cout << letter ;
		cout << " => " << s.fitness << endl;
	}

	return 0;
}


