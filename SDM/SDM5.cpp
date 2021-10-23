/*  SDM Assignment 5
*   BE IT
*   Yatish Kelkar, Mahesh Nahak, Gaurav Khairnar, Kshttij Chitnis
*/

enum years
{
    BE,
    TE,
    SE,
    FE
};

enum departments
{
    IT,
    CSE,
    ENTC,
    MECH,
    EL
};

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    string name;
    string email;
    string password;

    Person(string nameF, string emailF, string passwordF)
    {
        name = nameF;
        email = emailF;
        password = passwordF;
    }

    void printDetails();
};

// Course class
class Course
{
public:
    string title;
    string teacher;
    string courseCode;
    years year;
    departments department;

    Course() {}
    Course(string titleF, string teacherF, string courseCodeF, years yearF, departments departmentF)
    {
        title = titleF;
        teacher = teacherF;
        courseCode = courseCodeF;
        year = yearF;
        department = departmentF;
    }
};

//  Student class, extends Person
class Student : public Person
{
public:
    years year;
    departments department;

    Student(string nameF, string emailF, string passwordF, years yearF, departments departmentF) : Person(nameF, emailF, passwordF)
    {
        year = yearF;
        department = departmentF;
    }

    void printStudentDetails();
    void joinCourse(string courseCode, Student student);
};

// Teachr class
class Teacher : public Person
{

public:
    Teacher(string nameF, string emailF, string passwordF) : Person(nameF, emailF, passwordF) {}
    void createCourse(vector<Course> &, string, string, string, years, departments);
};

// Course student map
class CourseMap
{

public:
    Course course;
    vector<Student> studentsEnrolled;

    CourseMap() {}
    CourseMap(Course courseF)
    {
        course = courseF;
    }

    void addStudent(Student student)
    {
        studentsEnrolled.push_back(student);
    }
};

vector<Course> courses;
vector<CourseMap> courseMap;

// implementation of fucntions
void Person::printDetails()
{
    cout << "\nName: " << name;
    cout << "\nEmail: " << email;
}

void Student::printStudentDetails()
{
    cout << "\n----- Student Details -----";
    this->printDetails();
    cout << "\nYear: " << year;
    cout << "\nDepartment: " << department;
    cout << endl;
}

void Teacher::createCourse(vector<Course> &courses, string title, string teacher, string courseCode, years year, departments department)
{
    Course newCourse = Course(title, teacher, courseCode, year, department);
    courses.push_back(newCourse);
    courseMap.push_back(CourseMap(newCourse));
}

void Student::joinCourse(string courseCode, Student student)
{
    // cout << "\nCoursemap size is " << courseMap.at(0).course.title << endl;
    for (int i = 0; i < courseMap.size(); i++)
    {
        CourseMap currentCourseMap = courseMap.at(i);
        if (currentCourseMap.course.courseCode == courseCode)
        {
            currentCourseMap.addStudent(student);
        }
    }
}

int main()
{

    // Person p;
    // p.registerPerson("Ajay", "ajay@gmail.com", "ajay@123");

    Student s = Student("Ajay", "ajay@gmail.com", "ajay@123", BE, CSE);
    // s.printStudentDetails();

    Teacher t = Teacher("Rahul", "rahul@gmail.com", "rahul@123");
    // t.printDetails();

    t.createCourse(courses, "SDM", t.name, "WGdgAyBs", BE, CSE);

    s.joinCourse("WGdgAyBs", s);

    // for (int i = 0; i < courseMap.size(); i++)
    // {
    //     cout << "\n=====" << courseMap.at(0).course.title << endl;
    // }

    return 0;
}
