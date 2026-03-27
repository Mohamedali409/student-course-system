# 🎓 Student Management System (C++)

A console-based Student Management System built using **C++**, applying Object-Oriented Programming (OOP) and Standard Template Library (STL).

---

## 🚀 Features

- ➕ Add Student
- ❌ Delete Student
- 🔍 Search Student by ID
- 📋 Display All Students
- 📚 Enroll Student in Courses
- 📖 Show Student Courses
- 📊 Sort Students by GPA
- 🧠 Input Validation Handling
- ♻️ Prevent Duplicate Courses using `set`

---

## 🛠️ Technologies Used

- C++
- OOP (Inheritance, Encapsulation)
- STL Containers:
  - `map` → Store students by ID
  - `set` → Store unique courses
  - `vector` → Used for sorting
- STL Algorithms:
  - `sort()`

---

## 🧱 System Design

### 📌 Class Structure

- `Person`
  - name

- `Student` (inherits from Person)
  - id
  - gpa
  - courses

---

## 📊 UML Class Diagram

    +----------------+
    |    Person      |
    +----------------+
    | - name: string |
    +----------------+
    | + getName()    |
    +----------------+
            ▲
            |
    +------------------------+
    |       Student          |
    +------------------------+
    | - id: int              |
    | - gpa: double          |
    | - courses: set<string> |
    +------------------------+
    | + getId()              |
    | + getGpa()             |
    | + addCourse()          |
    | + showCourses()        |
    +------------------------+

    
---

## 📋 Menu System
- Add Student
- Delete Student
- Search Student
- Display All Students
- Enroll Course
- Show Courses
- Sort Students by GPA
- Exit
  
---

## 🧠 Key Concepts Applied

- 🔹 Inheritance (`Student` extends `Person`)
- 🔹 Encapsulation (private data + getters)
- 🔹 STL usage for efficient data handling
- 🔹 Lambda functions for sorting
- 🔹 Input validation and error handling

---

## 🖥️ Example Output

```bash
============ Add Student =============
Enter ID: 101
Enter Name: Ali
Enter GPA: 3.8
Added successfully

============ Enroll Course ============
Enter Student ID: 101
Enter Course Name: Math
Course Added Successfully

============ Enroll Course ============
Enter Student ID: 101
Enter Course Name: Math
Course Added Successfully
============ Add Student =============
Enter ID: 101
Enter Name: Ali
Enter GPA: 3.8
Added successfully

============ Enroll Course ============
Enter Student ID: 101
Enter Course Name: Math
Course Added Successfully


---

## 👨‍💻 Author

- Mohamed Ali  
- C++ Developer | Full Stack (MERN)

---

## ⭐ If you like this project

Give it a ⭐ on GitHub!
