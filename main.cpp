#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


struct student
{
	char word[8];
	double fitness;
};
double getFitness(struct student stud);


vector<char> keyword = {'j', 'o', 'j', 'o', 'j', 'o', 'j', 'o'};


int main(int argc, char* args[])
{
	// struct student s;
	// s.word = keyword;
	// cout << getFitness(s) << endl;
	


	vector<int> hallal = {1,2,2,3,3,6,6,6,6,6};
	hallal[0] = 1473734876;
	for(auto i: hallal) cout << i << " ";
	
	return 0;
}

double getFitness(struct student stud)
{
	double fitness = 0;
	// for(int i = 0; i < keywordLEN; i++) fitness += stud.word[i] == keyword[i];
	return fitness;
}
