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

#pragma region helper_functions // DONE

int FindCourseIdByName(string name)
{
    for (int i = 0 ; i < CourseCounter ; i++)
    {
        if (CourseArray[i].Name == name) return CourseArray[i].CourseId;
    }
    return -1;
}

string AskForCourseName()
{
    cout<<"write course's name"<<endl;
    string name;
    getline(cin, name);
    return name;
}

string AskForName()
{
    cout<<"write your name"<<endl;
    string name;
    getline(cin, name);
    return name;
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

// Ask for user choice
int GetUserchoice()
{
    int choice;
    cin>>choice;
    return choice;
}

string AskForString(string msg)
{
    cout<<msg<<endl;
    string s;
    getline(cin >> ws,s);
    return s;
}
int AskForInt(string msg)
{
    cout << msg << endl;

    int x;

    while(!(cin >> x))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid input. Try again:\n";
    }

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

// TODO: return index of admin in AdminArray by ID
int FindAdminIndexById(int admin_id)
{
    for (int i = 0 ; i < AdminCounter ; i++)
    {
        if (AdminArray[i].AdminId == admin_id) return i;
    }
    return -1;
}

int FindAdminIdByName(string name)
{
    for (int i = 0 ; i < AdminCounter ; i++)
    {
        if (AdminArray[i].Name == name) return AdminArray[i].AdminId;
    }
    return -1;
}

// TODO: return index of student course in StudentCourseArray by ID
int FindStudentCourseIndexById(int student_id, int course_id)
{
    for (int i = 0 ; i < StudentCourseCounter ; i++)
    {
        if (StudentCourseArray[i].StudentId == student_id && StudentCourseArray[i].CourseId == course_id)
        {
            return i;
        }
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

void SetNextAdminId()
{
    int TempBiggestAdminId = 0;
    for (int i = 0 ; i < AdminCounter ; i++)
    {
        if (AdminArray[i].AdminId > TempBiggestAdminId) TempBiggestAdminId = AdminArray[i].AdminId;
    }
    NextAdminId=TempBiggestAdminId + 1;
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

int ReturnNextAdminId()
{
    return NextAdminId++;
}

string AskForPassword()
{
    cout<<"write your password"<<endl;
    string password;
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
    cout<<"      "<<name<< "'s profile" <<endl;
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
    cout<<"current admin is "<<name<<endl;
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

// Done by abd_elrahman
// TODO: verify admin and show admin menu and takes current admin id by reference id an assign it to CurrentAdminId variable
int LoginAdmin(string name , string password)
{
    int id = FindAdminIdByName(name);
    if (id == -1)
    {
        cout<<"admin name was not found"<<endl;
        AskForInt("write 0 to go back");
        return -1;
    }
    int index = FindAdminIndexById(id);
    if (index == -1)
        return -1;
    if (AdminArray[index].Password != password)
    {
        cout<<"password is incorrect"<<endl;
        AskForInt("write 0 to go back");
        return -1;
    }
    return id;
}   

// TODO: create a new admin account
//Done by Yasin
void AddAdmin()
{
    // 1. Check if there is available space (Max capacity for admins is 3)
    if (AdminCounter >= 3)
    {
        cout << "Can't add any new admins. The system is full!" << endl;
        AskForInt("write 0 to go back");
        return;
    }

    // 2. Collect the new admin's data
    string name = AskForString("Write the new admin's name: ");

    // Ensure the username is unique to avoid login conflicts
    bool correct = true;
    int existingId;
    do
    {
        existingId = FindAdminIdByName(name);
        if (existingId != -1)
            cout << "Admin name already exists. Try another name." << endl;
        else
            correct = false;

    } while (correct);
    
    string password = AskForString("Write the new admin's password: ");
    // 3. Store the new admin in the system
    Admin newAdmin;

    // Generate a new ID based on the counter 
    newAdmin.AdminId = ReturnNextAdminId();
    newAdmin.Name = name;
    newAdmin.Password = password;

    AdminArray[AdminCounter] = newAdmin;

    // 4. Update the admins counter
    AdminCounter++;

    cout << "Admin account added successfully." << endl;
    AskForInt("write 0 to go back");
}

// TODO: create a new course and add it to the system
void AddCourse()
{
    if (CourseCounter >= 20)
    {
        cout<<"can't add any new courses"<<endl;
        AskForInt("write 0 to go back");
        return;
    }
    string course_name , instructor_name , day , time;
    int credit_hours , max_capacity , current_enrolled;

    course_name = AskForString("write course's name");
    int id = FindCourseIdByName(course_name);
    if (id != -1)
    {
        cout<<"course is allready registered"<<endl;
        AskForInt("write 0 to go back");
        return;
    }

    instructor_name = AskForString("write instructor's name");
    day = AskForString("what day is course on");
    time = AskForString("what time is the course like (xx:xx) ");

    do 
    {
        credit_hours = AskForInt("write the credit hours");
        if (credit_hours > 6 || credit_hours < 1)
            cout<<"invalid number try again"<<endl;

    } while (credit_hours > 6 || credit_hours < 1);
    
    do 
    {
        max_capacity = AskForInt("write the max capacity");
        if (max_capacity > 1000 || max_capacity <= 0)
            cout<<"invalid number try again"<<endl;
            
    } while (max_capacity > 1000 || max_capacity <= 0);
    
    do
    {
        current_enrolled = AskForInt("write the number student current enrolled ");
        if (current_enrolled > max_capacity || current_enrolled < 0)
            cout<<"invalid number try again"<<endl;

    } while(current_enrolled > max_capacity || current_enrolled < 0);

    Course course = {ReturnNextCourseId() , course_name , instructor_name , credit_hours , max_capacity , day , time , current_enrolled};
    CourseArray[CourseCounter++] = course;
    cout<<"course added successfully"<<endl;
    AskForInt("write 0 to go back");

}

// TODO: remove an existing course
void DeleteCourse()
{
    string name = AskForString("write course's name");
    int course_id = FindCourseIdByName(name);
    if (course_id == -1)
    {
        cout<<"course was not found"<<endl;
        AskForInt("write 0 to go back");
        return;
    }
    int course_index = FindCourseIndexById(course_id);
    if (course_index == -1)
    {
        cout<<"data was corrupted"<<endl;
        AskForInt("write 0 to go back");
        return;
    }

    int counter = 0 , student_index = 0;
    for(int i = 0 ; i < StudentCourseCounter ;)
    {
        if (StudentCourseArray[i].CourseId == course_id)
        {
            student_index = FindStudentIndexById(StudentCourseArray[i].StudentId);
            if (student_index != -1)
                StudentArray[student_index].NumberOfRegisteredCourses--;
            UpdateStudentCourseArray(i); // changes StudentCourseCounter so i made length
            counter++;
        }
        else
            {i++;}
    }

    UpdateCourseArray(course_index);

    cout<<counter<<" relations was deleted"<<endl;
    cout<<"course was deleted"<<endl;

    AskForInt("write 0 to go back");
}

// TODO: show all students in the system
// Done by yasin
void ViewAllStudents()
{
    // 1. Check if the system has any students
    if (StudentCounter == 0)
    {
        cout << "There are no students registered in the system." << endl;
        // Wait for user input before returning so the message isn't skipped
        AskForInt("Write 0 To Go Back: "); 
        return; 
    }

    int choice;
    // 2. Wrap the output in a do-while loop to keep it on screen
    do
    {
        // Clear screen for a clean view
        system("cls||clear"); 

        cout << "===== Enrolled Students List =====" << endl;

        // 3. Loop through the array and print only the number and name
        for (int i = 0; i < StudentCounter; ++i)
        {
            // Printing 'i + 1' so the list starts from 1 instead of 0
            cout <<  i + 1 << ". " <<StudentArray[i].Name << endl;
        }
        cout << "----------------------------------" << endl;
        
        // Ask the user if they want to go back
        choice = AskForInt("Write 0 To Go Back: ");

    } while (choice != 0); // Keep repeating until the user enters 0
}

// TODO: show all courses in the system
// Done by basmala
void ViewAllCourses()
{
if (CourseCounter==0) {
    cout << "No courses found in the system." << endl;
    AskForString("Press any key to go back...");
    return;
}

cout << "list of all courses" << endl;
for(int i=0;i<CourseCounter;i++){

    cout<<"CourseId: "<< 
     CourseArray[i].CourseId << "\t"
    <<"| Name: "<<
     CourseArray[i].Name << "\t"
    <<"| Instructor: "<<
     CourseArray[i].InstructorName << "\t"
    <<"| Capacity: "<<
     CourseArray[i].CurrentEnrolled << "\t"
     <<"/"<<
     CourseArray[i].MaxCapacity << "\t"
     <<" | Day: "<<
     CourseArray[i].Day << "\t"
     <<" | Time: "<<
     CourseArray[i].Time << "\t" <<endl;
}
AskForString("Press any key to go back...");
}

// Done by ibrahem
void ViewAllCoursesOfAStudent()
{
    // 1. Ask the admin for the student's name and get their ID
    string name = AskForString("enter the student's name");

    // If the student doesn't exist, GetUserId will print an error and return -1
    int id = FindStudentIdByName(name);
    if (id == -1)
    {
        cout<<"student was not found"<<endl;
        AskForInt("write 0 to go back");
        return;
    }

    int choice;
    do 
    {
        system("cls||clear");
        cout << "===== Registered Courses =====" << endl;
        int counter = 0;

        // 2. Loop through the relation array (StudentCourseArray)
        for (int i = 0; i < StudentCourseCounter; i++) 
        {
            if (StudentCourseArray[i].StudentId == id)
            {
                int courseIndex = FindCourseIndexById(StudentCourseArray[i].CourseId);
                
                if (courseIndex != -1) 
                {
                    cout << "  Course Name : " << CourseArray[courseIndex].Name << endl;
                    cout << "  Instructor  : " << CourseArray[courseIndex].InstructorName << endl;
                    cout << "------------------------------" << endl;
                    counter++;
                }
            }
        }

        if (counter == 0)
        {
            cout << "This student is not enrolled in any courses right now." << endl;
        }

        choice = AskForInt("Write 0 To Go Back: ");
    } while (choice != 0);
}

void ViewStudentGrade()
{
    string student_name = AskForString("enter student name;");
    int sId = FindStudentIdByName(student_name);
    if (sId == -1)
    {
        cout<<"course was not found try again"<<endl;
        AskForInt("write 0 to go back");
        return;
    }

    string course_name=AskForString("Enter course name:");
    int cId = FindCourseIdByName(course_name);
    if (cId == -1)
    {
        cout<<"course was not found try again"<<endl;
        AskForInt("write 0 to go back");
        return;
    }
        
    int index = FindStudentCourseIndexById ( sId , cId);

    if(index !=-1)
    {
        cout<<"Grade: "<<StudentCourseArray[index].Grade<<endl;
    }
    else{
        cout<<"Course not found or not registered!"<<endl;
    }
    AskForInt("write 0 to go back");
}

// Done by abd_elrahman
// TODO: show all students registered in a specific course
void ViewAllStudentsOfACourse()
{
    string course_name = AskForString("enter course name");
    int course_id = FindCourseIdByName(course_name);

    if (course_id == -1)
    {
        cout<<"couldn't find course try again"<<endl;
        AskForInt("Write 0 To Go Back: ");
        return;
    }
    int counter = 0;
    int index = 0;
    for (int i = 0 ; i < StudentCourseCounter ; i++)
    {
        if (StudentCourseArray[i].CourseId == course_id)
        {
            index = FindStudentIndexById(StudentCourseArray[i].StudentId);
            if (index != -1)
            {
                counter++;
                cout<<StudentArray[index].Name<<endl;
            }
                
        }
    }
    if (counter == 0)
        cout<<"No students enrolled in this course"<<endl;
    AskForInt("write 0 to go back");
}
// Done by ibrahem
// TODO: modify a student's grade
void ChangeGrade()
{
    // 1. Get the target student's ID
    int studentId;
    int choice1;
    do
    {
        string name = AskForString("Enter the student name: ");

        studentId = FindStudentIdByName(name);

        if (studentId == -1)
        {
            cout << "Student was not found.\n";
            choice1 = AskForInt("Write 0 to go back or 1 to try again: ");
        }

    } while (studentId == -1 && choice1 != 0);

    if (choice1 == 0)
        return;
        
    int choice2;
    int courseId;
    do
    {
        string courseName = AskForString("Enter course name: ");

        courseId = FindCourseIdByName(courseName);

        if (courseId == -1)
        {
            cout << "Course was not found.\n";
            choice2 = AskForInt("Write 0 to go back or 1 to try again: ");
        }

    } while (courseId == -1 && choice2 != 0);

    if (choice2 == 0)
        return;
    
    // 3. Find the specific enrollment record linking this student to this course
    int studentCourseIndex = FindStudentCourseIndexById(studentId, courseId);

    // 4. Check if the student is actually enrolled in this course
    if (studentCourseIndex == -1)
    {
        cout << "Error: This student is not enrolled in the specified course." << endl;
        AskForInt("Write 0 To Go Back: ");
        return;
    }

    int newGrade;
    do
    {
        // 5. Ask the admin for the new grade
        newGrade = AskForInt("Enter the new grade for the student (0 - 100): ");

        // Basic validation to ensure the grade makes sense
        if (newGrade < 0 || newGrade > 100)
        {
            cout << "Invalid grade! The grade must be between 0 and 100." << endl;
        }
    }while(newGrade < 0 || newGrade > 100);

    // 6. Update the grade in the array
    StudentCourseArray[studentCourseIndex].Grade = newGrade;
    cout << "Success: Grade has been updated to " << newGrade << endl;
    AskForInt("Write 0 To Go Back: "); // Wait before clearing the screen
}

#pragma endregion

#pragma region student_functions

// TODO: verify student and show student menu
int LoginStudent(string name , string password)
{
    int id = FindStudentIdByName(name);

    if (id == -1)
        return -1;

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
        AskForInt("write 0 to go back");
        return -1;
    }

    int id = FindStudentIdByName(name);

    if (id != -1) // if student name exist use another
    {   
        cout<<"name allready used try again"<<endl;
        AskForInt("write 0 to go back");
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
    
    cout<<"acount was created successfully"<<endl;
    AskForInt("write 0 to continue");
    return student.StudentId;

}
// Done by amira
// TODO: display all courses that still have available seats
void ViewAvailableCourses()
{           
   int counter = 0;

       for (int i = 0; i < CourseCounter; i++)
       {
           if (IsCourseFull(CourseArray[i].CourseId) == false && IsStudentEnrolled(CourseArray[i].CourseId) == false)
           {

                cout << "Name: " << CourseArray[i].Name << endl;
                counter++;
           }
       }
       if (counter == 0)
           cout << "No Available Courses" << endl; 
       AskForInt("write 0 to go back");
}

// TODO: enroll the logged-in uses the global variable CurrentStudentId student in a course
void EnrollToCourse()
{
    
    if (StudentCourseCounter >= 500)
    {
        cout<<"can't accept any more student try again soon"<<endl;
        AskForString("write 0 to go back");
        return;
    }

    int student_index = FindStudentIndexById(CurrentStudentId);
    if (student_index == -1)
    {
        cout<<"student was not found"<<endl;
        AskForString("write 0 to go back");
        return;
    }

    if (StudentArray[student_index].NumberOfRegisteredCourses >= 10) 
    {
        cout<<"Limit reached! You have 10 active courses"<<endl;
        AskForString("write 0 to go back");
        return;
    }
    string course_name = AskForString("enter course name");
    int course_id = FindCourseIdByName(course_name);
    if (course_id == -1)
    {
        cout<<"course was not found try again"<<endl;
        AskForString("write 0 to go back");
        return;
    }
    
    if (IsStudentEnrolled(course_id) == true)
    {
        cout<<"you are allready enrolled"<<endl;
        AskForString("write 0 to go back");
        return;
    }
    if (IsCourseFull(course_id) == true)
    {
        cout<<"course is reached try again next time"<<endl;
        AskForString("write 0 to go back");
        return;
    }

    int course_index = FindCourseIndexById(course_id);
    if (course_index == -1)
    {
        cout<<"course data is corrupted"<<endl;
        AskForString("write 0 to go back");
        return;
    }

    StudentCourse student_course = {CurrentStudentId,course_id};
    StudentCourseArray[StudentCourseCounter] = student_course;
    StudentCourseCounter++;
    StudentArray[student_index].NumberOfRegisteredCourses++;
    CourseArray[course_index].CurrentEnrolled++;
    cout<<"courses was added to your courses successfully"<<endl;
    AskForInt("write 0 to go back");
}

// TODO: remove a course from the student's registered courses
void DropCourse()
{
    string course_name = AskForString("enter course name");
    int course_id = FindCourseIdByName(course_name);
    if (course_id == -1)
    {
        cout<<"course was not found"<<endl;
        AskForInt("enter 0 to go back");
        return;
    }

    int student_course_index = FindStudentCourseIndexById(CurrentStudentId,course_id);
    if (student_course_index == -1)
    {
        cout<<"you are not enrolled in this course"<<endl;
        AskForInt("enter 0 to go back");
        return;
    }
    
    int student_index = FindStudentIndexById(CurrentStudentId);
    int course_index = FindCourseIndexById(course_id);

    StudentArray[student_index].NumberOfRegisteredCourses--;
    CourseArray[course_index].CurrentEnrolled--;
    StudentCourseCounter--;

    UpdateStudentCourseArray(student_course_index);
    
    cout<<"course dropped successfully"<<endl;
    AskForInt("enter 0 to go back");
}

// Done by amira
// TODO: display all courses the student is currently enrolled in
void ViewMyCourses()
{
      int counter = 0;

        for (int i = 0; i < StudentCourseCounter; i++)
        {
            if (StudentCourseArray[i].StudentId == CurrentStudentId)
            {
                int courseIndex = FindCourseIndexById(StudentCourseArray[i].CourseId);
                if (courseIndex != -1)
                {
                    cout << "Name: " << CourseArray[courseIndex].Name << endl;
                    counter++;
                }
            }
        }
        if (counter == 0)
        {
            cout << "You are not enrolled in any courses." << endl;
        }
        AskForInt("enter 0 to go back");
}

// TODO: show grade for the student's course 
// Done by basmala
void ViewMyGrade()
{
    string course_name=AskForString("Enter course name:");

    int cId = FindCourseIdByName(course_name);
    if (cId == -1)
    {
        cout<<"course was not found try again"<<endl;
        AskForInt("write 0 to go back");
        return;
    }
        
    int index = FindStudentCourseIndexById ( CurrentStudentId , cId);

    if(index !=-1)
    {
        cout<<"Grade: "<<StudentCourseArray[index].Grade<<endl;
    }
    else{
        cout<<"Course not found or not registered!"<<endl;
    }
    AskForInt("write 0 to go back");
}
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

#pragma region main_functions // Student() and Admin() 

//Functions
void StudentFunctions()
{
    while (true)
    {
        ShowStudentMenu();
        int Studentchoice = GetUserchoice();

        switch (Studentchoice)
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
            ViewMyGrade();
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
        int LogInMenuchoice = GetUserchoice();

        switch (LogInMenuchoice)
        {
        case 1:
            {
                string Name = AskForString("enter you name");
                string Password = AskForString("enter you password");

                CurrentStudentId = LoginStudent(Name,Password);
                if (CurrentStudentId != -1)
                    StudentFunctions();
                else
                {
                    cout<<"couldn't log in"<<endl;
                    AskForInt("write 0 to go back");
                }
            }
            break;
        
        case 2:
            {
            string Name = AskForString("enter your name");
            string Password = AskForString("enter your password");
            int Level = AskForInt("enter your level");

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

void AdminFunctions()
{
    while (true)
    {  
        ShowAdminFunctionsMenu();
        int choice = GetUserchoice();
        switch (choice)
        {
        case 1:
            AddAdmin();
            break;
        case 2:
            AddCourse();
            break;
        case 3:
            DeleteCourse();
            break;
        case 4:
            ViewAllStudents();
            break;
        case 5:
            ViewAllCourses();
            break;
        case 6:
            ViewAllCoursesOfAStudent();
            break;
        case 7:
            ViewAllStudentsOfACourse();
            break;
        case 8:
            ViewStudentGrade();
            break;
        case 9:
            ChangeGrade();
            break;
        case 10:
            return;
        default:
            cout<<"invalid choice"<<endl;
            break;
        }
    }
}


void AdminLogInFunction()
{
    while (true)
    {
        ShowAdminLogInMenu();
        int choice = GetUserchoice();

        switch (choice)
        {
        case 1:
            {
                string name = AskForString("enter user name");
                string password = AskForString("enter you password");

                int id = LoginAdmin(name,password);
                if (id != -1)
                {
                    CurrentAdminId = id;
                    AdminFunctions();
                }
                else
                {
                    cout<<"couldn't log in"<<endl;
                    AskForInt("write 0 to go back");
                }
                break;
            }
        case 2 :
            return;
        default:
            cout<<"invalid choice try again"<<endl;
            break;
        }
    }
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
    SetNextAdminId();
    
    // TODO: main menu
    bool running = true;
    while (running)
    {
        ShowMainMenu();
        int Userchoice = GetUserchoice();

        switch (Userchoice)
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