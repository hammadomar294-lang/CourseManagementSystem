
// TODO: create a new admin account
void AddAdmin()
{
    // 1. Check if there is available space (Max capacity for admins is 3)
    if (AdminCounter >= 3)
    {
        cout << "Can't add any new admins. The system is full!" << endl;
        return;
    }

    // 2. Collect the new admin's data
    string name = AskForString("Write the new admin's name: ");

    // Ensure the username is unique to avoid login conflicts
    int existingId = FindAdminIdByName(name);
    if (existingId != -1)
    {
        cout << "Admin name already exists. Try another name." << endl;
        return;
    }

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
}
//Done by Yasin

// TODO: show all students in the system
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
//Done by Yasin

// both are optional 

void AdminFunctions() // both are optional 
{

}


void AdminLogInFunction()
{

}