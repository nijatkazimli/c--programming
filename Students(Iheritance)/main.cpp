#include <iostream>
#include <iomanip>
#include "Individual.h"
#include "Person.h"
#include "Student.h"

using namespace std;
const int N = 10;

//-------------------------------------------
int main()
{
	//-------------------------------------------------------
	Individual *ind;
	cout << "Output formating test" << endl;
	cout << setw(10) << left << "This" << setw(13) << right << "long line" << "|" << setw(5) << setprecision(2) << 1.23 << endl;
	cout << setw(10) << left << "Wheras" << setw(13) << right << "short" << "|" << setw(5) << setprecision(2) << 3.89 << endl;


	cout << "-------- PART 1-2 --------" << endl;
	{
		cout << " Class Person test:" << endl;

		Person os("Mike", "Onesmith", 20);
		ind = &os;
		cout << "os: " << *ind << endl;

		Person os1 = os;
		ind = &os1;
		cout << "os1: " << *ind << endl;

		Person os2;
		os2 = os;
		ind = &os2;
		cout << "os2: " << *ind << endl;
	}

	//-------------------------------------------------------
	cout << "-------- PART 3 --------" << endl;
	cout << endl << "Class Student test" << endl;

	{

		Student st("Mike", "Onesmith", 20, "5/5/5/4.5/5/4/3/5");
		ind = &st;
		cout << "st: " << *ind << endl;

		Student st1 = st;
		ind = &st1;
		cout << "st1: " << *ind << endl;

		Student st2;
		st2 = st;
		ind = &st2;
		cout << "st2: " << *ind << endl;
	}
	
/*	cout << "-------- PART 4 --------" << endl;
	Student group[N] = {
			 Student("Jack","One",20,"5/5/5/4.5/5/4/3/5"),
			 Student("Tom","Two",23,"3.5/4/2"),
			 Student("Adam","Tree",21),
			 Student("John","Four",22,"5/3.5/4.5/3.5/4/2"),
			 Student("Nathan","Five",24,"3.5/4/4/3/2"),
			 Student("Andrew","Tree",20),
			 Student("Jack","Seven",30,"2/5/4/5/3.5/4/2"),
			 Student("Mark","Three",25),
			 Student("Jacky","Nine",28,"3.5/4/5/2/2/2.5"),
			 Student("Tom","Nine",23,"4/4.5/5/3/3.5/4/2/2")
	};
	cout << "GROUP - STUDENTS:" << endl;
	printlist(N, group);

	Student st = group[0];
	group[0] = group[1];
	group[1] = st;

	cout << "GROUP - STUDENTS after swap:" << endl;
	printlist(N, group);

	//-------------------------------------------------------
	cout << endl << "SORTING" << endl;
	sortStudents(N, group);
	cout << "GROUP - STUDENTS:" << endl;
	printlist(N, group);

	cout << "GROUP - STUDENTS: sorted by average score" << endl;
	sortStudents(N, group, compare_average);
	printlist(N, group);

	cout << "GROUP - STUDENTS: sorted by age : " << endl;
	sortStudents(N, group, compare_age);
	printlist(N, group);


	cout << "GROUP - STUDENTS: sorted by average, last first:" << endl;
	sortStudents(N, group, compare_average_last_first);
	printlist(N, group);
	cout << endl;
*/
}