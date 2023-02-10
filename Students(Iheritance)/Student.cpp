#include <iomanip>
#include <cstring>
#include "Student.h"
   
//-----------------------------------------------------------------
void Student::init_scores(int number_of_scores, double* _scores)
{
	this->scores_size=0;
	this->scores=nullptr;

	if (number_of_scores>0)
	{
		this->scores_size=number_of_scores;
		this->scores=new (nothrow) double[number_of_scores];
		if (!this->scores) return;

		for (int i=0;i<number_of_scores;i++)
			this->scores[i]=_scores? _scores[i]:0;
	}
}
//--------------------------------------------------------------------

void Student::convert_scores(const string &in ){

	int j = 0;
	int slash_instance =0;
	int no_of_slashes = 0;
	for (int i = 0; i < in.length(); i++) {
		if (in[i] == '/')
			no_of_slashes++;
	}

	double* local_scores = new double[no_of_slashes + 1];
	for (int i = 0; i < in.length(); i++) {
		if (in[i] == '/') {
			std::string local_string = "";
			local_string = in.substr(slash_instance+1, 0);
			local_scores[j] = std::stod(local_string);
			j++;
			slash_instance++;
		}

	}

	scores = local_scores;
	
}

Student::Student(string first, string last, int age, const string& scores) : Person(first, last, age)
{
	convert_scores(scores);

}

Student::Student(const Student& obj)
{
	first = obj.first;
	last = obj.last;
	age = obj.age;
	sign = obj.sign;
	init_scores(obj.scores_size,obj.scores);
}

Student::~Student()
{
	delete[] scores;
}

Student Student::operator=(Student& obj2)
{
	if (this == &obj2) {
		return *this;
	}

	first = obj2.first;
	last = obj2.last;
	age = obj2.age;
	sign = obj2.sign;
	init_scores(obj2.scores_size, obj2.scores);



	return *this;
}

double Student::average()
{
	double score_sum = 0;
	for (int i = 0; i < scores_size; i++) {
		score_sum += scores[i];
	}


	return score_sum/scores_size;
}

void Student::signature()
{
	if (first != "" && last != "")
		sign = first.substr(0, 8);

}
