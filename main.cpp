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
int StudentCourseCounter=0;


int CurrentStudentId=0;
int CurrentCourseId=0;

#pragma endregion

#pragma region masseges_functions

void ShowMainMenu()
{
    system("clear");
    cout << "===== Main Menu ====="<<endl;
    cout<<"Write 1 To Enter Student Menu"<<endl;
    cout<<"Write 2 To Enter Admin Menu"<<endl;
    cout<<"Write 3 To Exit"<<endl;
}
void ShowStudentLogInMenu()
{
    system("clear");
    cout << "===== Login Menu ====="<<endl;
    cout<<"Write 1 To Login"<<endl;
    cout<<"Write 2 To Sign Up"<<endl;
    cout<<"Write 3 To Go Back"<<endl;
}

void ShowStudentMenu()
{
    system("clear");
    cout << "===== Student Menu ====="<<endl;
    cout << "Write 1 View Available Courses"<<endl;
    cout << "Write 2 Enroll in Course"<<endl;
    cout << "Write 3 Drop Course"<<endl;
    cout << "Write 4 View My Courses"<<endl;
    cout << "Write 5 View Grades"<<endl;
    cout << "Write 6 Logout"<<endl;
}

void ShowAdminLogInMenu()
{
    system("clear");
    cout << "===== Login Menu ====="<<endl;
    cout<<"Write 1 To Login"<<endl;
    cout<<"Write 2 To Go Back"<<endl;
}

void ShowAdminLogInMenu()
{
    system("clear");
    cout << "===== Admin Menu ====="<<endl<<endl;
    cout << "===== Admin Menu ====="<<endl;
    cout << "Write 1 Add Admin Account"<<endl;
    cout << "Write 2 Add New Course"<<endl;
    cout << "Write 3 Delete Course"<<endl;
    cout << "Write 4 View All Students"<<endl;
    cout << "Write 5 View All Courses"<<endl;
    cout << "Write 6 View All Courses Of A Student"<<endl;
    cout << "Write 7 View All Students Of A Course"<<endl;
    cout << "Write 8 Show Student Grade"<<endl;
    cout << "Write 9 Change Student Grade"<<endl;
    cout << "Write 10 to Logout "<<endl;
}
#pragma endregion

#pragma region admin_functions
// TODO: verify admin and show admin menu and takes current admin id by reference id an assign it to CurrentAdminId variable
void LoginAdmin(int current_admin_id)
{
}

// TODO: go back to the main menu and current admin id by reference id an assign it back to 0
void LogoutAdmin(int current_admin_id)
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
void ShowGrade(int student_id , int course_id)
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
int LoginStudent(int current_student_id)
{
    
}



// TODO: create a new student account and save it and make new empty array of id of Studentcourses and the NumberOfRegisteredCourses = 0
int SignUpStudent(string name , string password , int level)
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
    ifstream file("students.txt");
    if (!file.is_open())
    {
        cout<<"file could not be opened"<<endl;
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
    ofstream file("student.txt");
    if (!file.is_open())
    {
        cout<<"file could not be opened"<<endl;
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

// Ask for user chios
int GetUserChios()
{
    int temp;
    cin>>temp;
}
// Ask for user id
int GetId()
{
    cout<<"write the id"<<endl;
    int temp;
    cin>>temp;
}
int GetCourseId()
{
    cout<<"write the course id"<<endl;
    int temp;
    cin>>temp;
}
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
// TODO: loop over the student array to find the student with the given id
bool IsStudentExists(int student_id)
{

}
bool IsAdminExists(int student_id)
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

#pragma region main_functions // Student() and Admin() 

void StudentLoginFunction()
{
    while (true)
    {   ShowStudentLogInMenu();
        int LogInMenuChios = GetUserChios();

        switch (LogInMenuChios)
        {
        case 1:
            int id = GetId();
            CurrentStudentId = LoginStudent(id);
            if (CurrentStudentId != -1)
                StudentFunctions(CurrentStudentId);
            else
                cout<<"couldn't log in"<<endl;
            break;
        
        case 2:
            CurrentStudentId = SignUpStudent();
            StudentFunctions(CurrentStudentId);
            break;

        case 3:
            return;
         default
            cout<<"invalid choice"<<endl;
        }
    }
    
}

//Functions بالجمع بها s
void StudentFunctions(int current_student_id)
{
    while (true)
    {
        ShowStudentMenu();
        int StudentChios = GetUserChios();

        switch (StudentChios)
        {
        case 1:
            ViewAvailableCourses(current_student_id);
            break;
        case 2:
            {int course_id = GetCourseId();
            EnrollToCourse(current_student_id,course_id);
            break;}
        case 3:
            {int course_id = GetCourseId();
            DropCourse(current_student_id,course_id);
            break;}
        case 4:
            ViewMyCourses(current_student_id);
            break;
        case 5:
            {int course_id = GetCourseId();
            ViewGrade(current_student_id,course_id);
            break;}
        case 6:
            return;
        default
            cout<<"invalid choice"<<endl;
        }
    }
}

void AdminLogInFunction()
{

}



void AdminFunctions(int current_admin_id)
{

}

#pragma endregion
int main()
{
    // TODO: load data from files
    LoadStudents();
    LoadCourses();
    LoadAdmins();
    LoadStudentCourse();

    // TODO: main menu
    while (true)
    {
        ShowMainMenu();
        int UserChios = GetUserChios();

        switch (UserChios)
        {
        case 1:
            // calls the StudentLoginFunction which in turn calls the student functions like enroll and view courses
            StudentLoginFunction();
            break;

        case 2:
            // calls the AdminLogInFunction which in turn calls the admin functions like add course and show student grade
            AdminLogInFunction();
            break;
        
        case 3:
            return;
         default
            cout<<"invalid choice"<<endl;
        }
    }
    


    // TODO: save data to files
    SaveStudents();
    SaveCourses();
    SaveAdmins();
    SaveStudentCourse();
    return 0;
}