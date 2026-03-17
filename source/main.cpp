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
int AdminCounter=0;
int StudentCourseCounter=0;


int CurrentStudentId=0;
int CurrentCourseId=0;
int CurrentAdminId=0;

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

// TODO: Show the current student name as a massage above the menu
void ShowCurrentStudentName()
{
    string name;
    int index = FindStudentIndexById(CurrentStudentId);
    if (index == -1) 
        name="User";
    else 
        name=StudentArray[index].Name;

    cout<<" "<<endl;
    cout<<"=================="<<endl;
    cout<<name<<endl;
    cout<<"=================="<<endl;
}

void ShowCurrentAdminName()
{
    string name;
    int index = FindAdminIndexById(CurrentAdminId);
    if (index == -1) 
        name="User";
    else 
        name=AdminArray[index].Name;

    cout<<" "<<endl;
    cout<<"=================="<<endl;
    cout<<name<<endl;
    cout<<"=================="<<endl;
}

void ShowStudentMenu()
{
    system("clear");
    cout << "===== Student Menu ====="<<endl;
    cout << ShowCurrentStudentName()<<endl;
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

void ShowAdminFunctionsMenu()
{
    system("clear");
    cout << "===== Admin Menu ====="<<endl;
    cout << ShowCurrentAdminName()<<endl;
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
void AddCourse(string course_name , string instructor_name , int credit_hours , int max_capacity , int current_enrolled=0 , string day = "", string time="")
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

int LoginStudent(string name , string password)
{
    int id = FindStudentIdByName(name);

    if (id == -1)
    {
        cout<<"name was not found try again"<<endl;
        return -1;
    } 

    int index = FindStudentIndexById(id);

    if (StudentArray[index].Password == password)
        return id;

    return -1;

}



// TODO: create a new student object and save it to StudentArray
int SignUpStudent(string name , string password , int level)
{
    int id = FindStudentIdByName(name);
    if (id != -1) // if student name exist use another
    {
        cout<<"name allready used try again"<<endl;
        return -1;
    }
    // make the student object
    Student student;
    student.StudentId = ReturnNextStudentId();
    student.Name = name;
    student.Password = password;
    student.level = level;

    // put the student object in the StudentArray
    StudentArray[StudentCounter]=student;
    StudentCounter++;

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

#pragma region system_functions // DONE

// TODO: read students from students.txt and increase the StudentCounter 
void LoadStudents()
{
    ifstream file("students.txt");
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
    ofstream file("students.txt");
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
    ifstream file("courses.txt");
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
    ofstream file("courses.txt");
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
    ifstream file("admins.txt");
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
    ofstream file("admins.txt");
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
    ifstream file("studentcourses.txt");
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
    ofstream file("studentcourses.txt");
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

#pragma region helper_functions // DONE

// Ask for user chios
int GetUserChios()
{
    int temp;
    cin>>temp;
    return temp;
}
// Ask for user id
int GetId()
{
    cout<<"write the id"<<endl;
    int temp;
    cin>>temp;
    return temp;
}
int GetCourseId()
{
    cout<<"write the course id"<<endl;
    int temp;
    cin>>temp;
    return temp;
}
// TODO: return index of student in StudentArray by ID
int FindStudentIndexById(int student_id)
{
    for (int i = 0 ; i < StudentCounter ; i++)
    {
        if (StudentArray[i].StudentId == student_id) return i;
    }
    return -1;
}

// TODO: return index of course in CourseArray by ID
int FindCourseIndexById(int course_id)
{
    for (int i = 0 ; i < CourseCounter ; i++)
    {
        if (CourseArray[i].CourseId == course_id) return i;
    }
    return -1;
}

// TODO: return index of admin in AdminArray by ID
int FindAdminIndexById(int admin_id)
{
    for (int i = 0 ; i < AdminCounter ; i++)
    {
        if (AdminArray[i].AdminId == admin_id) return i;
    }
    return -1;
}

// TODO: return index of student course in StudentCourseArray by ID
int FindStudentCourseIndexById(int student_id, int course_id)
{
    for (int i = 0 ; i < StudentCourseCounter ; i++)
    {
        if (StudentCourseArray[i].StudentId == student_id && StudentCourseArray[i].CourseId == course_id) return i;
    }
    return -1;
}

// TODO: check if student already registered in a course
bool IsStudentEnrolled(int student_id, int course_id)
{
    for (int i = 0 ; i < StudentCourseCounter; i++)
    {
        if (StudentCourseArray[i].StudentId == student_id && StudentCourseArray[i].CourseId == course_id)
            return true;
    }
    return false;
}

// TODO: check if course reached max capacity
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

// set the global variable NextStudentId to the biggest (id in the StudentArray + 1)
void SetNextStudentId()
{
    int TempBiggestStudentId = 0;
    for (int i = 0 ; i < StudentCounter ; i++)
    {
        if (StudentArray[i].StudentId > TempBiggestStudentId) TempBiggestStudentId = StudentArray[i].StudentId;
    }
    NextStudentId=TempBiggestStudentId + 1;
}

// set the global variable NextCourseId to the biggest (id in the CourseArray + 1)
void SetNextCourseId()
{
    int TempBiggestCourseId = 0;
    for (int i = 0 ; i < CourseCounter ; i++)
    {
        if (CourseArray[i].CourseId > TempBiggestCourseId) TempBiggestCourseId = CourseArray[i].CourseId;
    }
    NextCourseId=TempBiggestCourseId + 1;
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
string AskForName()
{
    cout<<"write your name"<<endl;
    string name;
    cin>>name;
    return name;
}
string AskForPassword()
{
    cout<<"write your password"<<endl;
    string password;
    cin>>password;
    return password;
}
int AskForLevel()
{
    cout<<"write your level"<<endl;
    int level;
    cin>>level;
    return level;
}
int FindStudentIdByName(string name)
{
    for (int i = 0 ; i < StudentCounter ; i++)
    {
        if (StudentArray[i].Name == name) 
            return StudentArray[i].StudentId;
    }
    return -1;
}

#pragma endregion

#pragma region main_functions // Student() and Admin() 

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
        default:
            cout<<"invalid choice"<<endl;
        }
    }
}

void StudentLoginFunction()
{
    while (true)
    {   ShowStudentLogInMenu();
        int LogInMenuChios = GetUserChios();

        switch (LogInMenuChios)
        {
        case 1:
            {
            string Name = AskForName();
            string Password = AskForPassword();

            CurrentStudentId = LoginStudent(Name,Password);
            if (CurrentStudentId != -1)
                StudentFunctions(CurrentStudentId);
            else
                cout<<"couldn't log in"<<endl;}
            break;
        
        case 2:
            {
            string Name = AskForName();
            string Password = AskForPassword();
            int Level = AskForLevel();

            CurrentStudentId = SignUpStudent(Name,Password,Level);
            StudentFunctions(CurrentStudentId);
            }
            break;

        case 3:
            return;

         default:
            cout<<"invalid choice"<<endl;
            break;
        }
    }
    
}

void AdminFunctions(int current_admin_id)
{

}


void AdminLogInFunction()
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

    // TODO: Set NextStudentId and NextCourseId to the next possible id 
    SetNextStudentId();
    SetNextCourseId();
    
    // TODO: main menu
    bool running = true ;
    while (running)
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
            running = false;
            break;
         default:
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