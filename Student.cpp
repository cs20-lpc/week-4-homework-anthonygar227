// TODO:  Student class methods implementation here.
#include "Student.hpp"
using namespace std;

void Student::copyFrom(const Student& other) {
    id = other.id;
    name = other.name;
    gpa = other.gpa;
    head = nullptr;
    CourseNode* tail = nullptr; 

    CourseNode* curr = other.head;
    while (curr != nullptr) {
        CourseNode* node = new CourseNode(curr->data);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        curr = curr->next;
    }
}

void Student::clearCourses() {
    CourseNode* curr = head;
    while (curr != nullptr) {
        CourseNode* nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    head = nullptr;
}

Student::Student() : id(0), name(""), gpa(0.0), head(nullptr){}

Student::Student(int id, const string& name, double gpa)
: id(id), name(name), gpa(0.0), head(nullptr) {
    setGpa(gpa);
}
Student::Student(const Student& other) : id(0), gpa(0.0), head(nullptr) {
    copyFrom(other);
}
Student& Student::operator=(const Student& other) { // Do I need to use operator
    if (this != &other) {
        clearCourses();
        copyFrom(other);
    }
    return *this;
}
Student::~Student() {
    clearCourses();
}

int Student::getId() const {
    return id;
}
const string& Student::getName() const {
    return name;
}
double Student::getGpa() const {
    return gpa;
}

void Student::setId(int i) {
    id = i;
}
void Student::setName(const string& n) {
    name = n;
}
void Student::setGpa(double g) {
    if (g < 0.0 || g > 4.0) // Does this layout seem fine
    throw BadGpa();
    gpa = g;
}

void Student::addCourse(const Course& c) {
    if (c.getName().empty()) throw EmptyCourseName(); // fix this
    CourseNode* node = new CourseNode(c);
    if (head == nullptr) {
        head = node;
    } else {
        CourseNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

bool Student::hasCourses() const {
    return head != nullptr;
}
void Student::printBasic() const {
    cout << id << " " << name << " " << gpa;
}
void Student::printCourses() const {
    if (!head) {
        cout << "  Courses: None\n";
        return;
    }

    CourseNode* curr = head;
    cout << "  Courses: ";
    curr->data.print();
    cout << "\n";

    curr = curr->next;
    while (curr != nullptr) {
        cout << "           ";
        curr->data.print();
        cout << "\n";
        curr = curr->next;
    }
}
