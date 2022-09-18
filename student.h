#include <vector>
#include <iterator>
#include <cmath>
#include <iostream>


class Student
{
	char word[8];

	public:
		Student()
		{
			for(auto &letter: word)
				letter = 'a' + rand()%('z' - 'a' + 1);
		}
		double fitness;
		double getFitness(std::vector<char> keyword);
		void mutate(double probability, double strength);
		friend void interpolate(const class Student &parent1, const class Student &parent2, class Student &child, double bias);
		void display();
};

