#ifndef STUDENT_H
#define STUDENT_H

#include <ostream>
#include <string>
#include <vector>
#include <list>
#include <map>

class student
{
public:
    // Prat 1
    student(const std::string &name, const std::string &surname, const std::vector<int> &marks);
    friend bool operator <(const student &a, const student &b);
    friend std::ostream &operator << (std::ostream &s, const student &st);
    // Part 3
    bool is_passing() const;
    void show_is_passing(std::ostream &s) const;
    // Part 6
    bool is_leader(int level) const;
    // Part 8
    void histogram(std::map<int, int> &m) const;

private:
    std::string m_name, m_surname;
    std::vector<int> m_marks;
};

class evaluation
{
public:
    // Part 2
    evaluation(const std::list<student> &students);
    friend std::ostream &operator <<(std::ostream &s, const evaluation &e);
    // Part 4
    void show_is_passing(std::ostream &s) const;
    // Part 5
    void clear_not_passing();
    // Part 7
    void save_to_file(std::string filename, int level);
    // Part 8
    void histogram(std::ostream &s) const;
 
private:
    std::list<student> m_students;
};

#endif // STUDENT_H
