#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string name = "") { this->name = name; }
    string getName() { return name; }
};

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;
public:
    Student() : Person(""), id(0), gpa(0.0) {}
    Student(int id, string name, double gpa) : Person(name), id(id), gpa(gpa) {}

    int getId() { return id; }
    double getGpa() { return gpa; }

    void addCourse(string course) { courses.insert(course); }

    void showCourses() {
        if (courses.empty()) {
            cout << "No courses enrolled\n";
            return;
        }
        for (auto c : courses) cout << c << " ";
        cout << endl;
    }
};

void addStudent(map<int, Student>& students) {
    cout << "\n============ Add Student =============\n";
    int id; string name; double gpa;

    cout << "Enter ID: "; cin >> id;
    if (students.count(id)) { cout << "Student already exists\n"; return; }

    cout << "Enter Name: "; cin.ignore(); getline(cin, name);
    cout << "Enter GPA: "; cin >> gpa;
    if (gpa < 0.0 || gpa > 4.0) { cout << "Invalid GPA\n"; return; }

    students[id] = Student(id, name, gpa);
    cout << "Added successfully\n*********\n";
}

void displayStudents(const map<int, Student>& students) {
    cout << "\n========== All Students ==========\n";
    if (students.empty()) { cout << "No students available\n"; return; }
    for (auto x : students) {
        cout << "ID: " << x.first << "\nName: " << x.second.getName()
            << "\nGPA: " << x.second.getGpa() << "\n---------------------------\n";
    }
}

void searchStudent(map<int, Student>& students) {
    cout << "\n=========== Search Student ===========\n";
    if (students.empty()) { cout << "No students available\n"; return; }

    int id; cout << "Enter ID: "; cin >> id;
    auto it = students.find(id);
    if (it != students.end()) {
        cout << "ID: " << it->first << "\nName: " << it->second.getName()
            << "\nGPA: " << it->second.getGpa() << endl;
    }
    else cout << "Student Not Found\n";
    cout << "*********\n";
}

void deleteStudent(map<int, Student>& students) {
    cout << "\n=========== Delete Student ===========\n";
    if (students.empty()) { cout << "No students available\n"; return; }

    int id; cout << "Enter ID: "; cin >> id;
    auto it = students.find(id);
    if (it != students.end()) {
        students.erase(it);
        cout << "Deleted Successfully\n";
    }
    else cout << "Student Not Found\n";
    cout << "*********\n";
}

void enrollCourse(map<int, Student>& students) {
    cout << "\n============ Enroll Course ============\n";
    if (students.empty()) { cout << "No students available\n"; return; }

    int id; string course;
    cout << "Enter Student ID: "; cin >> id;
    auto it = students.find(id);
    if (it == students.end()) { cout << "Student Not Found\n"; return; }

    cout << "Enter Course Name: "; cin.ignore(); getline(cin, course);
    it->second.addCourse(course);
    cout << "Course Added Successfully\n*********\n";
}

void showCourses(map<int, Student>& students) {
    cout << "\n============ Show Courses ============\n";
    if (students.empty()) { cout << "No students available\n"; return; }

    int id; cout << "Enter Student ID: "; cin >> id;
    auto it = students.find(id);
    if (it == students.end()) { cout << "Student Not Found\n"; return; }

    cout << "Courses: "; it->second.showCourses();
    cout << "*********\n";
}

void sortByGPA(map<int, Student>& students) {
    cout << "\n============ Students Sorted by GPA ============\n";
    if (students.empty()) { cout << "No students available\n"; return; }

    vector<Student> studentList;
    for (auto x : students) studentList.push_back(x.second);

    sort(studentList.begin(), studentList.end(),
        []( Student& a,  Student& b) { return a.getGpa() > b.getGpa(); });

    for (auto s : studentList) {
        cout << "ID: " << s.getId() << "\nName: " << s.getName()
            << "\nGPA: " << s.getGpa() << "\n---------------------------\n";
    }
}


int main() {
    map<int, Student> students;
    int choice;

    while (true) {
        cout << "\n====================== Menu ======================\n";
        cout << "1. Add Student\n2. Delete Student\n3. Search Student\n4. Display All Students\n";
        cout << "5. Enroll Course\n6. Show Courses\n7. Sort Students by GPA\n8. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid Input\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1: addStudent(students); break;
        case 2: deleteStudent(students); break;
        case 3: searchStudent(students); break;
        case 4: displayStudents(students); break;
        case 5: enrollCourse(students); break;
        case 6: showCourses(students); break;
        case 7: sortByGPA(students); break;
        case 8: cout << "Goodbye\n"; return 0;
        default: cout << "Invalid Choice\n";
        }
    }
}