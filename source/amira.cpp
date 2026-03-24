#include <iostream>
#include <string>

using namespace std;

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
    int CurrentEnrolled;
    string Day;
    string Time;
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
StudentCourse StudentCourseArray[1000];

// ======== Variables ========
int NextStudentId=0;
int NextCourseId=0;

int StudentCounter=0;
int CourseCounter=0;
int AdminCounter=0;
int StudentCourseCounter=0;


int CurrentStudentId=0;
int CurrentCourseId=0;
int CurrentAdminId=0;

#pragma endregion

bool IsCourseFull(int course_id)
{
    int index = FindCourseIndexById(course_id);
    // if index == -1 that means the course does not exist 
    if (index == -1) return true;
    if (CourseArray[index].CurrentEnrolled >= CourseArray[index].MaxCapacity)
        return true;
    else 
        return false;
}


#pragma region myfunctions

void ViewAvailableCourses()
{
    // loop over the array 

    for (int i=0 ; i<CourseCounter ; i++)
    {
        if (IsCourseFull(CourseArray[i].CourseId) == false)
            cout<<CourseArray[i].Name<<endl;
    }
    // make sure there is an available place 
    // cout the available courses
}

// both are optional 

void AdminFunctions(int current_admin_id) // both are optional 
{

}


void AdminLogInFunction()
{

}


// TODO: remove a course from the student's registered courses
void DropCourse(int current_student_id,int course_id)
{
    
}

#pragma endregion

int main()
{

    return 0;
}