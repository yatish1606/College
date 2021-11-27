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
#include <fstream>
#include <iomanip>

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
    void listStudents();
    void listStudyMaterialAssignments();
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
    void createStudyMaterial(string title, fstream *filePtr, string desciption, string courseCode);
    void createAssignment(string title, fstream *filePtr, string desciption, string courseCode, string dueDate, int maxMarks);
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

class StudyMaterialAssignment
{
public:
    bool isStudyMaterial;
    string title;
    string *dueDate;
    string description;
    fstream *file;
    Course course;
    int *maxMarks;
};

vector<Course> courses;
vector<CourseMap> courseMap;
vector<StudyMaterialAssignment> studyMaterialsAssignments;

/*



    IMPLEMENTATION OF FUNCTIONS FOR ALL CLASSES



*/
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
            courseMap.at(i).addStudent(student);
        }
    }
}

void Teacher::createStudyMaterial(string title, fstream *filePtr, string description, string courseCode)
{
    StudyMaterialAssignment studyMaterial;
    studyMaterial.title = title;
    studyMaterial.description = description;
    studyMaterial.file = filePtr;
    studyMaterial.isStudyMaterial = true;
    studyMaterial.dueDate = NULL;
    studyMaterial.maxMarks = NULL;

    for (int i = 0; i < courses.size(); i++)
    {
        if (courseCode == courses.at(i).courseCode)
        {
            studyMaterial.course = courses.at(i);
            break;
        }
    }
    studyMaterialsAssignments.push_back(studyMaterial);
    cout << "Study material created successfully by " << name << " in classroom " << studyMaterial.course.title << endl;
}

void Teacher::createAssignment(string title, fstream *filePtr, string description, string courseCode, string dueDate, int maxMarks)
{
    StudyMaterialAssignment studyMaterial;
    studyMaterial.title = title;
    studyMaterial.description = description;
    studyMaterial.file = filePtr;
    studyMaterial.isStudyMaterial = true;
    studyMaterial.dueDate = &dueDate;
    studyMaterial.maxMarks = &maxMarks;

    for (int i = 0; i < courses.size(); i++)
    {
        if (courseCode == courses.at(i).courseCode)
        {
            studyMaterial.course = courses.at(i);
            break;
        }
    }
    studyMaterialsAssignments.push_back(studyMaterial);
    cout << "Assignment created successfully by " << name << " in classroom " << studyMaterial.course.title << endl;
}

void Course::listStudents()
{
    CourseMap map;
    bool flag = false;
    for (int i = 0; i < courseMap.size(); i++)
    {
        if (courseMap.at(i).course.courseCode == courseCode)
        {
            map = courseMap.at(i);
            flag = true;
            cout << endl
                 << "Students in this course are : " << endl
                 << "Count : "
                 << map.studentsEnrolled.size() << endl;
            for (int j = 0; j < map.studentsEnrolled.size(); j++)
            {
                cout << (j + 1) << ". " << map.studentsEnrolled.at(j).name << endl;
            }
            cout << endl;
        }
    }
    if (!flag)
    {
        cout << endl
             << "Error listing students";
    }
}

void Course::listStudyMaterialAssignments()
{
    StudyMaterialAssignment sma;
    cout << "=============================================================================================" << endl;
    cout << left << setw(20) << setfill(' ') << "Name" << left << setw(20) << setfill(' ') << "Description" << left << setw(20) << setfill(' ') << "Type" << left << setw(12) << setfill(' ') << "Due Date" << left << setw(20) << setfill(' ') << "Max Marks" << endl;
    cout << "=============================================================================================" << endl;
    for (int i = 0; i < studyMaterialsAssignments.size(); i++)
    {
        if (courseCode == studyMaterialsAssignments.at(i).course.courseCode)
        {
            sma = studyMaterialsAssignments.at(i);
            cout << left << setw(20) << setfill(' ') << sma.title
                 << left << setw(20) << setfill(' ') << sma.description
                 << left << setw(20) << setfill(' ') << (sma.isStudyMaterial ? "Study Material" : "Assignment")
                 << left << setw(12) << setfill(' ') << (sma.isStudyMaterial ? "-" : sma.dueDate->c_str())
                 << left << setw(20) << setfill(' ') << (sma.isStudyMaterial ? 0 : *sma.maxMarks)
                 << endl;
        }
    }
}

int main()
{

    // Person p;
    // p.registerPerson("Ajay", "ajay@gmail.com", "ajay@123");

    fstream file;
    fstream *filePtr;

    file.open("sample.txt", ios::in);
    filePtr = &file;

    Student ajay = Student("Ajay", "ajay@gmail.com", "ajay@123", BE, CSE);
    Student ellen = Student("Ellen", "ellen@gmail.com", "ellen@123", BE, CSE);
    // s.printStudentDetails();

    Teacher t = Teacher("Rahul", "rahul@gmail.com", "rahul@123");
    // t.printDetails();

    t.createCourse(courses, "SDM", t.name, "WGdgAyBs", BE, CSE);

    ajay.joinCourse("WGdgAyBs", ajay);
    ellen.joinCourse("WGdgAyBs", ellen);

    // courseMap.at(0).course.listStudents();

    t.createStudyMaterial("Study material 1", filePtr, "description", "WGdgAyBs");
    t.createAssignment("Assignment 1", filePtr, "description", "WGdgAyBs", "2021-10-05", 20);
    // for (int i = 0; i < courseMap.size(); i++)
    // {
    //     cout << "\n=====" << courseMap.at(0).course.title << endl;
    // }

    courseMap.at(0).course.listStudyMaterialAssignments();

    return 0;
}
