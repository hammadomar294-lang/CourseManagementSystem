#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#pragma region Structs

struct Student
{
    int StudentId;
    string Name;
    string Password;
    int level;
    int NumberOfRegisteredCourses;
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
int StudentCourseCounter=0;


int CurrentStudentId=0;
int CurrentCourseId=0;

#pragma endregion

#pragma region admin_functions
// TODO: verify admin and show admin menu and takes current admin id by reference id an assign it to CurrentAdminId variable
void LoginAdmin(int &current_admin_id)
{
}

// TODO: go back to the main menu and current admin id by reference id an assign it back to 0
void LogoutAdmin(int &current_admin_id)
{
}

// TODO: create a new admin account
void AddAdmin(string name , string password)
{
}

// TODO: create a new course and add it to the system
void AddCourse(string course_name , string instructor_name , int credit_hours , int max_capacity , int current_enrolled=0 , string day , string time)
{
}

// TODO: remove an existing course
void DeleteCourse(int course_id)
{
}

// TODO: show all students in the system
void ViewAllStudents()
{
}

// TODO: show all courses in the system
void ViewAllCourses()
{
}

// TODO: show all courses a specific student is registered in
void ViewAllCoursesOfAStudent(int student_id)
{
}

// TODO: show all students registered in a specific course
void ViewAllStudentsOfACourse(int course_id)
{
}

// TODO: display grades for the current student about a specific course
void ShowGrades(int student_id , int course_id)
{
}

// TODO: modify a student's grade
void ChangeGrade(int student_id , int course_id)
{
}

#pragma endregion

#pragma region student_functions
// TODO: verify student and show student menu
// needs to take the current student id   by reference and assign it to CurrentStudentId variable 
void LoginStudent(int &current_student_id)
{
}

// TODO: return to main menu
// needs to take the CurrentStudentId by reference and assign back to 0
void LogoutStudent(int &current_student_id)
{
}

// TODO: create a new student account and save it and make new empty array of id of Studentcourses and the NumberOfRegisteredCourses = 0
void SignUpStudent(string name , string password , int level)
{
}

// TODO: display all courses that still have available seats
void ViewAvailableCourses(int current_student_id)
{
}

// TODO: enroll the logged-in student in a course
void EnrollToCourse(int current_student_id,int course_id)
{
}

// TODO: remove a course from the student's registered courses
void DropCourse(int current_student_id,int course_id)
{
}

// TODO: display all courses the student is currently enrolled in
void ViewMyCourses(int current_student_id)
{
}

// TODO: show grades for the student's courses | ال function دي محتاجة اذن
void ViewGrade(int current_student_id,int course_id)
{
}
#pragma endregion

#pragma region system_functions

// TODO: read students from students.txt and increase the StudentCounter 
void LoadStudents()
{
}

// TODO: save students to students.txt
void SaveStudents()
{
}

// TODO: read courses from courses.txt and increase the CourseCounter 
void LoadCourses()
{
}

// TODO: save courses to courses.txt 
void SaveCourses()
{
}

// TODO: read admins from admins.txt and increase the AdminCounter 
void LoadAdmins()
{
}

// TODO: save admins to admins.txt 
void SaveAdmins()
{
}

// TODO: read StudentCourse from studentcourses.txt and increase the StudentCourseCounter 
void LoadStudentCourse()
{
}

// TODO: save StudentCourse from studentcourses.txt 
void SaveStudentCourse()
{
}


#pragma endregion

#pragma region helper_functions
// TODO: return index of student in StudentArray by ID
int FindStudentIndexById(int student_id)
{
}

// TODO: return index of course in CourseArray by ID
int FindCourseIndexById(int course_id)
{
}

// TODO: return index of admin in AdminArray by ID
int FindAdminIndexById(int admin_id)
{
}

// TODO: return index of student course in StudentCourseArray by ID
int FindStudentCourse(int student_id, int course_id)
{
}

// TODO: check if student already registered in a course
bool IsStudentEnrolled(int student_id, int course_id)
{
}

// TODO: check if course reached max capacity
bool IsCourseFull(int course_index)
{
}

// TODO: generate next student ID and increase it after using it
int ReturnNextStudentId()
{
    return NextStudentId++;
}

// TODO: generate next course ID and increase it after using it
int ReturnNextCourseId()
{
    return NextCourseId++;
}

#pragma endregion


int main()
{
    // TODO: load data from files

    // TODO: main menu


    // TODO: save data to files
    return 0;
}