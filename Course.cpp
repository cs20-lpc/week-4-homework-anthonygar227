// TODO:  Course class methods implementation here.
#include "Course.hpp"
using namespace std;

Course::Course() : name(""), location(""){}

Course::Course(const string& name, const string& location)
: name(name), location(location) {}

const string& Course::getName() const {
    return name;
}
const string& Course::getLocation() const {
    return location;
}
void Course::setName(const string& n) {
    name = n;
}
void Course::setLocation(const string& l) {
    location = l;
}
void Course::print() const {
    cout << name << " " << location; 
}
