// TO DO:  Student class definition 
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "Course.hpp"
using namespace std;

class Student {
    private:
    struct CourseNode {
        Course data;
        CourseNode* next;
        CourseNode(const Course& c, CourseNode* n=nullptr):data(c), next(n){} // n = nullptr
    };
    int id;
    string name;
    double gpa;
    CourseNode* head;

    void copyFrom(const Student& other);
    void clearCourses();

    public:
    class BadGpa{};
    class EmptyCourseName{};

    Student();
    Student(int id, const string& name, double gpa);
    Student(const Student& other);
    Student& operator=(const Student& other); // Do I need to use operator
    ~Student();

    int getId() const;
    const string& getName() const;
    double getGpa() const;

    void setId(int i);
    void setName(const string& n);
    void setGpa(double g);

    void addCourse(const Course& c);
    bool hasCourses() const;

    void printBasic() const; // id name gpa
    void printCourses() const; // prints each course on its own indented line
};

#endif