// TODO: show all courses a specific student is registered in
void ViewAllCoursesOfAStudent()
{
    // 1. Ask the admin for the student's name and get their ID
    string name = AskForString("enter the name");
    int id = 
    
    // If the student doesn't exist, GetUserId will print an error and return -1
    if (targetStudentId == -1) 
    {
        AskForInt("Write 0 To Go Back: "); // Wait so the error message is read
        return; 
    }

    int choice;
    do 
    {
        system("cls||clear");
        cout << "===== Registered Courses =====" << endl;
        bool hasCourses = false; 

        // 2. Loop through the relation array (StudentCourseArray)
        for (int i = 0; i < StudentCourseCounter; i++) // Changed to ++i
        {
            if (StudentCourseArray[i].StudentId == targetStudentId)
            {
                int courseIndex = FindCourseIndexById(StudentCourseArray[i].CourseId);
                
                if (courseIndex != -1) 
                {
                    cout << "- Course ID   : " << CourseArray[courseIndex].CourseId << endl;
                    cout << "  Course Name : " << CourseArray[courseIndex].Name << endl;
                    cout << "  Instructor  : " << CourseArray[courseIndex].InstructorName << endl;
                    cout << "------------------------------" << endl;
                    hasCourses = true;
                }
            }
        }

        if (!hasCourses)
        {
            cout << "This student is not enrolled in any courses right now." << endl;
        }

        choice = AskForInt("Write 0 To Go Back: ");
    } while (choice != 0);
}
// TODO: modify a student's grade
void ChangeGrade()
{
    // 1. Get the target student's ID
    int studentId = GetUserId();
    if (studentId == -1)
    {
        AskForInt("Write 0 To Go Back: ");
        return; 
    }

    // 2. Get the target course's ID
    int courseId = GetCourseId();
    if (courseId == -1)
    {
        AskForInt("Write 0 To Go Back: ");
        return; 
    }

    // 3. Find the specific enrollment record linking this student to this course
    int studentCourseIndex = FindStudentCourseIndexById(studentId, courseId);

    // 4. Check if the student is actually enrolled in this course
    if (studentCourseIndex == -1)
    {
        cout << "Error: This student is not enrolled in the specified course." << endl;
        AskForInt("Write 0 To Go Back: ");
        return;
    }

    // 5. Ask the admin for the new grade
    int newGrade = AskForInt("Enter the new grade for the student (0 - 100): ");

    // Basic validation to ensure the grade makes sense
    if (newGrade < 0 || newGrade > 100)
    {
        cout << "Invalid grade! The grade must be between 0 and 100." << endl;
        AskForInt("Write 0 To Go Back: ");
        return;
    }

    // 6. Update the grade in the array
    StudentCourseArray[studentCourseIndex].Grade = newGrade;
    
    cout << "Success: Grade has been updated to " << newGrade << "." << endl;
    AskForInt("Write 0 To Go Back: "); // Wait before clearing the screen
}


// both are optional 

void AdminFunctions() // both are optional 
{

}


void AdminLogInFunction()
{

}