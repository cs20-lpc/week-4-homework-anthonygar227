#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include <iostream>
#include "Student.hpp"
using namespace std;

class StudentList{
    private:
    struct Node {
        Student data;
        Node* next = nullptr;
    };

    Node* head;

    public:
    StudentList() : head(nullptr) {}
    ~StudentList() { 
        clear();
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
        head = nullptr;
    }

    void insertEnd(const Student& s) {
        Node* node = new Node{s};
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    }

    bool deleteById(int id) {
        if (head == nullptr) {
            return false;
        }

        if (head->data.getId() == id) {
            Node* del = head;
            head = head->next;
            delete del;
            return true;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->data.getId() == id) {
                prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }
    Student* searchById(int id) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data.getId() == id)
            return &curr->data;
            curr = curr->next;
        }
        return nullptr;
    }
    
    void displayAll() const {
        if (head == nullptr) {
            cout << "Students in List: (empty)\n";
            return;
        }

        cout << "Students in List:\n";
        bool printNone = false;
        Node* curr = head;
        while (curr != nullptr) { 
            curr->data.printBasic();
            if (!curr->data.hasCourses()) {
                if (!printNone) {
                cout << " None";
                printNone = true;
                }
            }
            cout << "\n";
            curr = curr->next;
        }
    }

    int count() const {
        int c = 0;
        Node* curr = head;
        while (curr != nullptr) {
            c++;
            curr = curr->next;
        }
        return c;
    }

    bool addCourseToStudent(int id, const Course& c) {
        Student* s = searchById(id);
        if (s == nullptr) {
            return false;
        }
        s->addCourse(c);
        return true;
    }
};

#endif