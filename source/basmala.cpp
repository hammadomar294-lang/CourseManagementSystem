// TODO: show all courses in the system
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

// TODO: display grades for the current student about a specific course
void ShowGrade()
{
string course=AskForString("Enter course name:");

int cId = FindCourseIdByName(course);
int index = FindStudentCourseIndexById ( CurrentStudentId , cId);

if(index !=-1){
    cout<<"Grade: "<<StudentCourseArray[index].Grade<<endl;
}
else{
    cout<<"Course not found or not registered!"<<endl;
}
AskForString("Pressany key to go back...");
}


// both are optional 

void AdminFunctions() // both are optional 
{

}


void AdminLogInFunction()
{

}