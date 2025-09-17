// TODO:  Course class definitions go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>
using namespace std;

class Course {
    private:
    string name;
    string location;

    public:
    Course();
    Course(const string& name, const string& location);

    const string& getName() const;
    const string& getLocation() const;

    void setName(const string& n);
    void setLocation(const string& l);

    void print() const; 
};

#endif