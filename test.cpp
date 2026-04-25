#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#pragma region structs

struct Student
{
    int StudentId;
    string Name;
    string Password;
    int level;
    int NumberOfRegisteredCourses=0;
};

struct Course
{
    int CourseId;
    string Name;
    string InstructorName;
    int CreditHours;
    int MaxCapacity;
    string Day;
    string Time;
    int CurrentEnrolled = 0;
};

struct Admin
{
    int AdminId;
    string Name;
    string Password;
};

struct StudentCourse
{
    int StudentId;
    int CourseId;
    int Grade;
};
#pragma endregion

#pragma region Global Variables and Arrays

// ======== Arrays =========
Student StudentArray[50];
Course CourseArray[20];
Admin AdminArray[3];
StudentCourse StudentCourseArray[500];

// ======== Variables ========
int NextStudentId=0;
int NextCourseId=0;
int NextAdminId=0;

int StudentCounter=0;
int CourseCounter=0;
int AdminCounter=0;
int StudentCourseCounter=0;


int CurrentStudentId=0;
int CurrentAdminId=0;

#pragma endregion

#pragma region system_functions // DONE

// TODO: read students from students.txt and increase the StudentCounter 
void LoadStudents()
{
    ifstream file("data/students.txt");
    if (!file.is_open())
    {
        cout<<"file students.txt could not be opened"<<endl;
        return;
    }
    Student student;
    while (file>>student.StudentId>>student.Name>>student.Password>>student.level>>student.NumberOfRegisteredCourses)
    {
        StudentArray[StudentCounter]=student;
        StudentCounter++;
    }
    file.close();
}

// TODO: save students to students.txt
void SaveStudents()
{
    ofstream file("data/students.txt");
    if (!file.is_open())
    {
        cout<<"file students.txt could not be opened"<<endl;
        return;
    }
    for (int i = 0 ; i < StudentCounter ; i++)
    {
        file << StudentArray[i].StudentId << " "
             << StudentArray[i].Name << " "
             << StudentArray[i].Password << " "
             << StudentArray[i].level << " "
             << StudentArray[i].NumberOfRegisteredCourses
             << endl;
    }
    file.close();
}

// TODO: read courses from courses.txt and increase the CourseCounter 
void LoadCourses()
{
    ifstream file("data/courses.txt");
    if (!file.is_open())
    {
        cout<<"file courses.txt could not be opened"<<endl;
        return;
    }
    Course course;
    while (file>>course.CourseId>>course.Name>>course.InstructorName>>course.CreditHours
           >>course.MaxCapacity>>course.CurrentEnrolled>>course.Day>>course.Time)
    {
        CourseArray[CourseCounter] = course;
        CourseCounter++;
    }
    file.close();
}

// TODO: save courses to courses.txt 
void SaveCourses()
{
    ofstream file("data/courses.txt");
    if (!file.is_open())
    {
        cout<<"file courses.txt could not be opened"<<endl;
        return;
    }
    for (int i = 0 ; i < CourseCounter ; i++)
    {
        file << CourseArray[i].CourseId << " "
             << CourseArray[i].Name << " "
             << CourseArray[i].InstructorName << " "
             << CourseArray[i].CreditHours << " "
             << CourseArray[i].MaxCapacity << " "
             << CourseArray[i].CurrentEnrolled << " "
             << CourseArray[i].Day << " "
             << CourseArray[i].Time << " "
             << endl;
    }
    file.close();
}

// TODO: read admins from admins.txt and increase the AdminCounter 
void LoadAdmins()
{
    ifstream file("data/admins.txt");
    if (!file.is_open())
    {
        cout<<"file admins.txt could not be opened"<<endl;
        return;
    }
    Admin admin;
    while (file>>admin.AdminId>>admin.Name>>admin.Password)
    {
        AdminArray[AdminCounter]=admin;
        AdminCounter++;
    }
    file.close();
}

// TODO: save admins to admins.txt 
void SaveAdmins()
{
    ofstream file("data/admins.txt");
    if (!file.is_open())
    {
        cout<<"file admins.txt could not be opened"<<endl;
        return;
    }
    for (int i = 0 ; i < AdminCounter ; i++)
    {
        file << AdminArray[i].AdminId << " "
             << AdminArray[i].Name << " "
             << AdminArray[i].Password << " "
             << endl;
    }
    file.close();
}

// TODO: read StudentCourse from studentcourses.txt and increase the StudentCourseCounter 
void LoadStudentCourse()
{
    ifstream file("data/studentcourses.txt");
    if (!file.is_open())
    {
        cout<<"file studentcourses.txt could not be opened"<<endl;
        return;
    }
    StudentCourse student_course;
    while (file>>student_course.StudentId>>student_course.CourseId>>student_course.Grade)
    {
        StudentCourseArray[StudentCourseCounter]=student_course;
        StudentCourseCounter++;
    }
    file.close();
}

// TODO: save StudentCourse from studentcourses.txt 
void SaveStudentCourse()
{
    ofstream file("data/studentcourses.txt");
    if (!file.is_open())
    {
        cout<<"file studentcourses.txt could not be opened"<<endl;
        return;
    }
    for (int i = 0 ; i < StudentCourseCounter ; i++)
    {
        file << StudentCourseArray[i].StudentId << " "
             << StudentCourseArray[i].CourseId << " "
             << StudentCourseArray[i].Grade << " "
             << endl;
    }
    file.close();
}


#pragma endregion

void DisplayStudents()
{
    cout << "\n=== Students List ===\n";

    for (int i = 0; i < StudentCounter; i++)
    {
        cout << "ID: " << StudentArray[i].StudentId
             << " | Name: " << StudentArray[i].Name
             << " | Password: " << StudentArray[i].Password
             << " | Courses: " << StudentArray[i].NumberOfRegisteredCourses
             << endl;
    }

    cout << "=====================\n";
}

void DisplayCourses()
{
    cout << "\n=== Courses List ===\n";

    for (int i = 0; i < CourseCounter; i++)
    {
        cout << "ID: " << CourseArray[i].CourseId
             << " | Name: " << CourseArray[i].Name
             << " | Instructor: " << CourseArray[i].InstructorName
             << " | CreditHours: " << CourseArray[i].CreditHours
             << " | Capacity: " << CourseArray[i].CurrentEnrolled
             << "/" << CourseArray[i].MaxCapacity
             << " | Day: " << CourseArray[i].Day
             << " | Time: " << CourseArray[i].Time
             << endl;
    }

    cout << "=====================\n";
}

void DisplayAdmins()
{
    cout << "\n=== Admins List ===\n";

    for (int i = 0; i < AdminCounter; i++)
    {
        cout << "ID: " << AdminArray[i].AdminId
             << " | Name: " << AdminArray[i].Name
             << " | Password: " << AdminArray[i].Password
             << endl;
    }

    cout << "===================\n";
}

int main()
{
    LoadStudents();
    LoadCourses();
    LoadAdmins();

    DisplayStudents();
    DisplayCourses();
    DisplayAdmins();

    SaveStudents();
    SaveCourses();
    SaveAdmins();

    return 0;
}