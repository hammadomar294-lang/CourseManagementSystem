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

#pragma region functions declaration

// ================= messages_functions =================
void ShowMainMenu();
void ShowStudentLogInMenu();
void ShowCurrentStudentName();
void ShowCurrentAdminName();
void ShowStudentMenu();
void ShowAdminLogInMenu();
void ShowAdminFunctionsMenu();


// ================= admin_functions =================
int LoginAdmin();
void LogoutAdmin();
void AddAdmin();
void AddCourse();
void DeleteCourse();
void ViewAllStudents();
void ViewAllCourses();
void ViewAllCoursesOfAStudent();
void ViewAllStudentsOfACourse();
void ShowGrade();
void ChangeGrade();


// ================= student_functions =================
int LoginStudent(string name , string password);
int SignUpStudent(string name , string password , int level);
void ViewAvailableCourses();
void EnrollToCourse();
void DropCourse();
void ViewMyCourses();
void ViewGrade();


// ================= system_functions =================
void LoadStudents();
void SaveStudents();
void LoadCourses();
void SaveCourses();
void LoadAdmins();
void SaveAdmins();
void LoadStudentCourse();
void SaveStudentCourse();


// ================= helper_functions =================
int GetUserChios();
int GetUserId();
int GetCourseId();

int FindStudentIdByName(string name);
int FindCourseIdByName(string name);

int FindStudentIndexById(int student_id);
int FindCourseIndexById(int course_id);
int FindAdminIndexById(int admin_id);
int FindStudentCourseIndexById(int student_id, int course_id);

bool IsStudentEnrolled(int course_id);
bool IsCourseFull(int course_id);

void SetNextStudentId();
void SetNextCourseId();

int ReturnNextStudentId();
int ReturnNextCourseId();

string AskForCourseName();
string AskForName();
string AskForPassword();
int AskForLevel();

void UpdateStudentCourseArray(int deleteIndex);
void UpdateCourseArray(int deleteIndex);


// ================= main_functions =================
void StudentFunctions(int current_student_id);
void StudentLoginFunction();
void AdminFunctions(int current_admin_id);
void AdminLogInFunction();

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

int StudentCounter=0;
int CourseCounter=0;
int AdminCounter=0;
int StudentCourseCounter=0;


int CurrentStudentId=0;
int CurrentAdminId=0;

#pragma endregion

#pragma region masseges_functions

void ShowMainMenu()
{
    system("cls||clear");
    cout << "===== Main Menu ====="<<endl;
    cout<<"Write 1 To Enter Student Menu"<<endl;
    cout<<"Write 2 To Enter Admin Menu"<<endl;
    cout<<"Write 3 To Exit"<<endl;
}
void ShowStudentLogInMenu()
{
    system("cls||clear");
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
    system("cls||clear");
    cout << "===== Student Menu ====="<<endl;
    ShowCurrentStudentName();
    cout << "Write 1 View Available Courses"<<endl;
    cout << "Write 2 Enroll in Course"<<endl;
    cout << "Write 3 Drop Course"<<endl;
    cout << "Write 4 View My Courses"<<endl;
    cout << "Write 5 View Grades"<<endl;
    cout << "Write 6 Logout"<<endl;
}

void ShowAdminLogInMenu()
{
    system("cls||clear");
    cout << "===== Login Menu ====="<<endl;
    cout<<"Write 1 To Login"<<endl;
    cout<<"Write 2 To Go Back"<<endl;
}

void ShowAdminFunctionsMenu()
{
    system("cls||clear");
    cout << "===== Admin Menu ====="<<endl;
    ShowCurrentAdminName();
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
void LoginAdmin()
{
}

// TODO: create a new admin account
void AddAdmin()
{
}

// TODO: create a new course and add it to the system
void AddCourse()
{
    if (CourseCounter >= 20)
    {
        cout<<"can't add any new courses"<<endl;
        return;
    }
    string course_name , instructor_name , day , time;
    int credit_hours , max_capacity;

    course_name = AskForString("write course's name");
    int id = FindCourseIdByName(course_name);
    if (id != -1)
    {
        cout<<"course is allready registered"<<endl;
        return;
    }

    instructor_name = AskForString("write instructor's name");
    day = AskForString("what day is course on");
    time = AskForString("what time is the course like ( xx/xx/xxxx )");

    do 
    {
        credit_hours = AskForInt("write the credit hours");
        if (credit_hours > 6 || credit_hours < 1)
            cout<<"invalid number try again"<<endl;

    } while (credit_hours > 6 || credit_hours < 1);
    
    do 
    {
        max_capacity = AskForInt("write the max capacity");
        if (max_capacity > 60 || max_capacity <= 0)
            cout<<"invalid number try again"<<endl;
            
    } while (max_capacity > 60 || max_capacity <= 0);
    

    Course course = {ReturnNextCourseId() , course_name , instructor_name , credit_hours , max_capacity , day , time};
    CourseArray[CourseCounter++] = course;
    cout<<"course added successfully"<<endl;
}

// TODO: remove an existing course
void DeleteCourse()
{
    int course_id = GetCourseId();
    if (course_id == -1)
    {
        cout<<"course was not found"<<endl;
        return;
    }
    int course_index = FindCourseIndexById(course_id);
    if (course_index == -1)
    {
        cout<<"data was corrupted"<<endl;
        return;
    }

    int counter = 0 , student_index = 0;
    for(int i = StudentCourseCounter - 1 ; i >= 0 ; i++)
    {
        if (StudentCourseArray[i].CourseId == course_id)
        {
            student_index = FindStudentIndexById(StudentCourseArray[i].StudentId);
            UpdateStudentCourseArray(i);
            StudentArray[student_index].NumberOfRegisteredCourses--;
            counter++;
        }
    }
    cout<<counter<<" relations was deleted"<<endl;

    UpdateCourseArray(course_index);
    cout<<"course was deleted"<<endl;
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
void ViewAllCoursesOfAStudent()
{
}

// TODO: show all students registered in a specific course
void ViewAllStudentsOfACourse()
{
}

// TODO: display grades for the current student about a specific course
void ShowGrade()
{
}

// TODO: modify a student's grade
void ChangeGrade()
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
    else
        return -1;

}

// TODO: create a new student object and save it to StudentArray
int SignUpStudent(string name , string password , int level)
{
    // to make sure there is a place before adding the student
    if (StudentCounter >= 50)
    {
        cout<<"there is no empty place for you"<<endl;
        return -1;
    }

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

    return student.StudentId;
}

// TODO: display all courses that still have available seats
void ViewAvailableCourses()
{
}

// TODO: enroll the logged-in uses the global variable CurrentStudentId student in a course
void EnrollToCourse()
{
    if (StudentCourseCounter >= 500)
    {
        cout<<"can't accept any more student try again soon"<<endl;
        return;
    }

    int student_index = FindStudentIndexById(CurrentStudentId);
    if (student_index == -1)
    {
        cout<<"student was not found"<<endl;
        return;
    }

    if (StudentArray[student_index].NumberOfRegisteredCourses >= 10) 
    {
        cout<<"Limit reached! You have 10 active courses"<<endl;
        return;
    }

    int course_id = GetCourseId();
    if (course_id == -1)
    {
        cout<<"course was not found try again"<<endl;
        return;
    }
    
    if (IsStudentEnrolled(course_id) == true)
    {
        cout<<"you are allready enrolled"<<endl;
        return;
    }
    if (IsCourseFull(course_id) == true)
    {
        cout<<"course is reached try again next time"<<endl;
        return;
    }

    int course_index = FindCourseIndexById(course_id);
    if (course_id == -1)
    {
        cout<<"course data is corrupted"<<endl;
        return;
    }

    StudentCourse student_course = {CurrentStudentId,course_id};
    StudentCourseArray[StudentCourseCounter] = student_course;
    StudentCourseCounter++;
    StudentArray[student_index].NumberOfRegisteredCourses++;
    CourseArray[course_index].CurrentEnrolled++;
}

// TODO: remove a course from the student's registered courses
void DropCourse()
{
    int course_id = GetCourseId();
    if (course_id == -1)
    {
        cout<<"course was not found"<<endl;
        return;
    }

    int student_course_index = FindStudentCourseIndexById(CurrentStudentId,course_id);
    if (student_course_index == -1)
    {
        cout<<"you are not enrolled in this course"<<endl;
        return;
    }
    
    int student_index = FindStudentIndexById(CurrentStudentId);
    int course_index = FindCourseIndexById(course_id);

    StudentArray[student_index].NumberOfRegisteredCourses--;
    CourseArray[course_index].CurrentEnrolled--;

    UpdateStudentCourseArray(student_course_index);
    
    cout<<"course dropped successfully"<<endl;
}

// TODO: display all courses the student is currently enrolled in
void ViewMyCourses()
{
}

// TODO: show grade for the student's course 
void ViewGrade()
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
    int chios;
    cin>>chios;
    return chios;
}

string AskForString(string msg)
{
    cout<<msg<<endl;
    string s;
    cin.ignore();
    getline(cin,s);
    return s;
}
int AskForInt(string msg)
{
    cout<<msg<<endl;
    int x;
    cin>>x;
    return x;
}

// Ask for user id
int GetUserId()
{
    string name = AskForName();
    int id = FindStudentIdByName(name);
    if (id == -1)
    {
        cout<<"user name was not found try again"<<endl;
        return -1;
    }
    return id;
}
int GetCourseId()
{
    string name = AskForCourseName();
    int id = FindCourseIdByName(name);
    if (id == -1)
    {
        cout<<"course was not found"<<endl;
        return -1;
    }
    return id;

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

int FindCourseIdByName(string name)
{
    for (int i = 0 ; i < CourseCounter ; i++)
    {
        if (CourseArray[i].Name == name) return CourseArray[i].CourseId;
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

// TODO: check if student already registered in a course this functions use the global variable CurrentStudentId
bool IsStudentEnrolled(int course_id)
{
    for (int i = 0 ; i < StudentCourseCounter; i++)
    {
        if (StudentCourseArray[i].StudentId == CurrentStudentId && StudentCourseArray[i].CourseId == course_id)
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

string AskForCourseName()
{
    cout<<"write course's name"<<endl;
    string name;
    cin.ignore();
    getline(cin, name);
    return name;
}

string AskForName()
{
    cout<<"write your name"<<endl;
    string name;
    cin.ignore();
    getline(cin, name);
    return name;
}
string AskForPassword()
{
    cout<<"write your password"<<endl;
    string password;
    cin.ignore();
    getline(cin, password);
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
// to update the array which holds the relations between the student and the course when the student drops a course
void UpdateStudentCourseArray(int deleteIndex)
{
    for (int i = deleteIndex; i < StudentCourseCounter - 1; i++)
    {
        StudentCourseArray[i] = StudentCourseArray[i + 1];
    }

    StudentCourseCounter--;
}

void UpdateCourseArray(int deleteIndex)
{
    for (int i = deleteIndex; i < CourseCounter - 1; i++)
    {
        CourseArray[i] = CourseArray[i + 1];
    }

    CourseCounter--;
}

#pragma endregion

#pragma region main_functions // Student() and Admin() 

//Functions
void StudentFunctions()
{
    while (true)
    {
        ShowStudentMenu();
        int StudentChios = GetUserChios();

        switch (StudentChios)
        {
        case 1:
            ViewAvailableCourses();
            break;
        case 2:
            EnrollToCourse();
            break;
        case 3:
            DropCourse();
            break;
        case 4:
            ViewMyCourses();
            break;
        case 5:
            ViewGrade();
            break;
        case 6:
            return;
        default:
            cout<<"invalid choice"<<endl;
        }
    }
}

void StudentLoginFunction() // StudentLoginFunction => StudentFunctions => any function view courses view grade 
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
                StudentFunctions();
            else
                cout<<"couldn't log in"<<endl;}
            break;
        
        case 2:
            {
            string Name = AskForName();
            string Password = AskForPassword();
            int Level = AskForLevel();

            CurrentStudentId = SignUpStudent(Name,Password,Level);
            StudentFunctions();
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
    bool running = true;
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