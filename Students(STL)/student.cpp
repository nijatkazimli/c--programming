#include "student.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>



// Part 1 (1 pts)

student::student(const std::string& name, const std::string& surname, const std::vector<int>& marks): m_name(name), m_surname(surname), m_marks(marks)
{
}



bool operator<(const student& a, const student& b)
{
	if(a.m_surname != b.m_surname)
	{
		if (a.m_surname.compare(b.m_surname) < 0)
			return true;

	}
	

	else
	{
		if (a.m_name.compare(b.m_name) < 0)
			return true;
	}
	return false;

	
}

std::ostream& operator<<(std::ostream& s, const student& st)
{
	
	std::cout << st.m_surname << " " << st.m_name << ": ";
	for (auto mark : st.m_marks)
	{
		std::cout << mark << " ";
	}
	std::cout << std::endl;

	return s;
}



// Part 2 (1 pts)

evaluation::evaluation(const std::list<student>& students): m_students(students)
{
}


std::ostream& operator<<(std::ostream& s, const evaluation& e)
{
	
	std::list<student> temp_list = e.m_students;
	temp_list.sort();
//	std::sort(temp_list.begin(), temp_list.end(), [](const student& a, const student& b) {return a < b; });

	
	for (auto student : temp_list)
	{
		std::cout << student;
	}


	return s;
}



// Part 3 (1 pts)

bool student::is_passing() const
{
	int i = 0;
	int sum = 0;
	auto lambda = [&i, &sum](const int& a) mutable { sum += a; };
	for_each(m_marks.begin(), m_marks.end(), lambda);

	if (sum > m_marks.size() * 5)
		return true;

	return false;
}

void student::show_is_passing(std::ostream& s) const
{

	if (is_passing())
		s << m_surname << m_name << ": passing";
	else
		s << m_surname << m_name << ": not passing";
	
}




// Part 4 (1 pts)

void evaluation::show_is_passing(std::ostream& s) const
{
	for (auto stu : m_students)
	{
		stu.show_is_passing(s);
		s << std::endl;
	}
		


}




// Part 5 (1 pts)

void evaluation::clear_not_passing()
{
	for (auto it = m_students.begin(); it != m_students.end(); )
	{
		if (!(*it).is_passing())
		{
			it = m_students.erase(it);

		}
		else
			it++;
	}
}






// Prat 6 (0,5 pts)

bool student::is_leader(int level) const
{

	auto lambda = [](const int& a) { return a ==10; };

	int num_of_max = std::count_if(m_marks.begin(), m_marks.end(), lambda);

	if (num_of_max >= level)
		return true;

	return false;
}

// Prat 7 (1 pts)

void evaluation::save_to_file(std::string filename, int level)
{
	std::ofstream file;
	file.open(filename);
	if (file.is_open())
	{
		for (auto stu : m_students)
			file << stu;
	}
	file.close();
}


// Part 8 (1,5 pts)


