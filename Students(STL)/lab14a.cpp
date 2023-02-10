#include <iostream>
#include "student.h"

using namespace std;

template<int N>
std::vector<int> marks(const int (&m)[N])
{
    std::vector<int> r;
    r.reserve(N);
    for (int i=0; i<N; ++i)
        r.push_back(m[i]);
    return r;
}

int main()
{
    // prepare
    const int MARKS_1[] = { 7,  3,  8,  5,  6,  6, 10,  6,  3,  9 };
    const int MARKS_2[] = { 2,  2,  4,  7,  4,  3,  1,  2,  5,  7 };
    const int MARKS_3[] = { 10, 6,  7,  4,  7,  8,  6, 10,  4,  7 };
    const int MARKS_4[] = { 7,  7,  8,  9,  6, 10, 10, 10,  8,  9 };
    const int MARKS_5[] = { 3,  5,  3,  6,  7,  2,  3,  4,  2,  1 };

    // --- 1 ---

    std::list<student> s;
    s.push_back(student("Ji", "Pulver", marks(MARKS_1)));
    s.push_back(student("Troy", "Ariola", marks(MARKS_2)));
    s.push_back(student("Evelin", "Ariola", marks(MARKS_3)));
    s.push_back(student("Emile", "Mcguckin", marks(MARKS_4)));
    s.push_back(student("Shakira", "Townes", marks(MARKS_5)));

    std::cout << "1:" << std::endl;
    student test_1 = student("1", "test", marks(MARKS_4));
    student test_2 = student("2", "test", marks(MARKS_2));
    std::cout << test_1 << std::endl;
    std::cout << test_2 << std::endl;
    std::cout << std::endl;
    if (test_1 < test_2) std::cout << "test_1 < test2 - TRUE" << std::endl;
    if (!(test_2 < test_1)) std::cout << "test_2 < test1 - FALSE" << std::endl;
    std::cout << std::endl;

    // --- 2 ---

    evaluation e(s);
    std::cout << "2:" << std::endl;
    std::cout << e << std::endl;

    // --- 3 ---

    std::cout << "3:" << std::endl;
    if (test_1.is_passing()) test_1.show_is_passing(std::cout);
    std::cout << std::endl; 
    if (!test_2.is_passing()) test_2.show_is_passing(std::cout);
    std::cout << std::endl; std::cout << std::endl;

    // --- 4 ---

    std::cout << "4:" << std::endl;
    e.show_is_passing(std::cout);
    std::cout << std::endl;

    // --- 5 ---

    std::cout << "5:" << std::endl;
    evaluation e2 = e;
    e2.clear_not_passing();
    std::cout << e2 << std::endl;

    // --- 6 ---

    std::cout << "6:" << std::endl;
    int level = 2;
    if (test_1.is_leader(level)) std::cout << test_1 << " - LEADER! " << std::endl;
    if (!test_2.is_leader(level)) std::cout << test_1 << " - NOT LEADER! " << std::endl;
    std::cout << std::endl;

    // --- 7 ---

    std::cout << "7:" << std::endl;
    e2.save_to_file("leaders.txt", 2);
    std::cout << "Check file!" << std::endl;
    std::cout << std::endl;

    // --- 8 ---
/*
    std::cout << "8:" << std::endl;
    e2.histogram(std::cout);
    std::cout << std::endl;
*/
    return 0;
}

