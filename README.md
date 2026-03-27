Student Management System – Documentation
1️⃣ Overview

A C++ program for managing students with support for:

Adding, deleting, and displaying students
Searching for a student by ID
Enrolling students in courses and displaying their courses
Simple menu interface for all operations
Ready for data storage in a text file for persistence

Technologies used:

STL containers: map<int, Student>, set<string>
Object-Oriented Programming (OOP)
File I/O (for future storage)
2️⃣ Classes
Class Person
Base class representing any person
Attributes:
string name → Person’s name
Methods:
Person(string name) → Constructor
string getName() → Returns the name
Class Student : public Person
Represents a student, inherits from Person
Attributes:
int id → Student ID
double gpa → Grade Point Average
set<string> courses → Courses enrolled in
Methods:
Student() → Default constructor
Student(int id, string name, double gpa) → Constructor with data
int getId() → Returns ID
double getGpa() → Returns GPA
void addCourse(string course) → Adds a course
void showCourses() → Displays all courses
3️⃣ Functions
void addStudent(map<int, Student>& students)
Adds a new student to the map
Checks if the ID already exists
Prompts the user for: ID, Name, GPA
Validates GPA (0.0–4.0)
Adds the student if valid
void displayStudents(map<int, Student>& students)
Displays all students in the map
Shows: ID, Name, GPA
void searchStudent(map<int, Student>& students)
Searches for a student by ID
If found → displays student info
If not found → prints "Student Not Found"
void deleteStudent(map<int, Student>& students)
Deletes a student by ID
If found → removes from the map
If not found → prints "Student Not Found"
void enrollCourse(map<int, Student>& students)
Adds a course to a specific student by ID
Prompts for course name
Adds it to the student’s set of courses
void showCourse(map<int, Student>& students)
Displays the courses for a specific student by ID
If student not found → prints "Student Not Found"
4️⃣ Menu

Main menu using loop + switch-case:

Menu Options:

Add Student
Delete Student
Search Student
Display Students
Enroll Course
Show Courses
Exit
Each choice calls its respective function
Prints separator "******************************" after each operation
5️⃣ Data Store (Optional)
Save students data in a text file students.txt
Format:
ID|Name|GPA|Course1,Course2,Course3
Load: Read file at program start and populate the map
Save: Write map to file after any change (Add/Delete/Enroll)
6️⃣ Example Run
====================== Menu ======================
1. Add Student
2. Delete Student
3. Search Student
4. Display Students
5. Enroll Course
6. Show Courses
7. Exit
Enter choice : 1
============ Add Student =============
Enter ID : 101
Enter name : Ali Mohamed
Enter gpa : 3.8
Added successfully
******************************

Enter choice : 5
============ Enroll Course ============
Enter Student ID : 101
Enter Course Name : Math
Course Added Successfully
*******************************
7️⃣ Notes
Uses map<int, Student> for fast lookup and deletion by ID
Uses set<string> to avoid duplicate courses
Easily expandable to support persistent storage with files
