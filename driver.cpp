// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.
#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "StudentList.hpp"

using namespace std;

void printMenu() {
  cout << "1. Insert Student\n";
  cout << "2. Delete Student\n";
  cout << "3. Search Student\n";
  cout << "4. Display All\n";
  cout << "5. Count Students\n";
  cout << "6. Add a course\n";
  cout << "7. Exit\n";
}

int main() {
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.
  StudentList list;
  int choice = 0;

  printMenu();
  cout << "Enter choice: ";

  while(cin >> choice) {
    if (choice == 1) {
      int id;
      string name;
      double gpa;

      cout << "Enter ID: ";
      cin >> id;

      cout << "Enter Name: ";
      cin.ignore();
      getline(cin, name);

      cout << "Enter GPA: ";
      cin >> gpa;

      if (gpa < 0.0 || gpa > 4.0) {
        cout << "Bad GPA (must be 0.0 to 4.0). Student not added.\n\n";
      }
      else {
        Student s;
        s.setId(id);
        s.setName(name);
        s.setGpa(gpa);
        list.insertEnd(s);
        cout << "\n";
        }
      }
      else if (choice == 2) {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        if (list.deleteById(id)) {
          cout << "Deleted student with ID " << id << "\n\n";
        }
        else {
          cout << "No student with ID " << id << " found.\n\n";
        }
      }
      else if (choice == 3) {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        Student* s = list.searchById(id);
        if (s != nullptr) {
          cout << "Found: ";
          s->printBasic();
          cout << "\n";
          s->printCourses();
        }
        else {
          cout << "Student not found.\n";
        }
        cout << "\n";
      }
      else if (choice == 4) {
        list.displayAll();
        cout << "\n";
      }
      else if (choice == 5) {
        cout << "Total students: " << list.count() << "\n\n";
      } 
      else if (choice == 6) {
        int id;
        string cname, loc;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, cname);

        cout << "Enter location: ";
        getline(cin, loc);

        if (cname.empty()) {
          cout << "Course name cannot be empty.\n\n";
        }
        else {
          if (list.addCourseToStudent(id, Course(cname,loc))) {
            cout << "\n";
          } 
          else {
            cout << "Student " << id << " not found.\n\n";
        }
      }
    }
    else if (choice == 7) {
      cout << "Goodbye!\n";
      break;
    }
    else {
      cout << "Invalid choice. Try again.\n\n";
    }
    cout << "Enter choice: ";
  }
  return 0;
}