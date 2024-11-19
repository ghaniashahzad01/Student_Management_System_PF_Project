#include<iostream>
#include<fstream>
#include<string> 
using namespace std;

string arr1[100], arr2[100], arr3[100], arr4[100], arr5[100];
int total = 0;

bool containsDigit(const string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}


bool containsAlphabet(const string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] == ' ')) || isdigit(str[i]))
        {
            return true;
        }
    }
    return false;
}


void enter()
{
    int ch=0;
    ofstream fout; // for file handling

    fout.open("studentdata.txt");
        
    cout << "How many students do you want to enter (1 to 100)? ";
    while (true) {
        string input;
        getline(cin, input);
        bool validInput = true;

        // Check if input contains only digits
        for (int i = 0; i < input.length(); ++i) {
            if (!isdigit(input[i])) {
                validInput = false;
                break;
            }
        }

        if (validInput) {
            // Convert input to integer manually
            int num = 0;
            for (int i = 0; i < input.length(); ++i) {
                num = num * 10 + (input[i] - '0');
            }
            if (num >= 1 && num <= 100) {
                ch = num;
                break;
            }
            else {
                cout << "Number must be between 1 and 100." << endl;
            }
        }
        else {
            cout << "Invalid input. Please enter again: ";
        }
    }
    if (total == 0)
    {
        total = ch + total;

        for (int i = 0; i < ch; i++)
        {
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;

            bool validName = false;
            while (!validName) {
                cout << "Enter name:";
                getline(cin, arr1[i]);
                if (containsAlphabet(arr1[i]))
                {
                    cout << "Enter a valid name." << endl;
                }
                else {
                    validName = true;  
                }
            }
            fout << arr1[i] << endl;

            bool validRollNo = false;
            while (!validRollNo) {
                cout << "Enter Roll no: ";
                getline(cin, arr2[i]);
                bool uniqueRollNo = true;
                for (int j = 0; j < i; j++) {
                    if (arr2[j] == arr2[i]) {
                        uniqueRollNo = false;
                        break;
                    }
                }
                if (!containsDigit(arr2[i]) || !uniqueRollNo)
                {
                    cout << "Must be unique and digit!" << endl;
                }
                else {
                    validRollNo = true;
                }
            }
            fout << arr2[i] << endl;

            cout << "Enter course: ";
            getline(cin, arr3[i]);
            fout << arr3[i] << endl;

            cout << "Enter class: ";
            getline(cin, arr4[i]);
            fout << arr4[i] << endl;

            bool validcontact = false;
            while (!validcontact) {
                cout << "Enter contact: ";
                getline(cin, arr5[i]);
                if (!containsDigit(arr5[i]))
                {
                    cout << "Please enter again." << endl;
                }
                else {
                    validcontact = true;
                }
            }
            fout << arr5[i] << endl;
        }
    }
    else
    {
        for (int i = total; i < ch + total; i++)
        {
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;

            bool validName = false;
            while (!validName) {
                cout << "Enter name:";
                getline(cin, arr1[i]);
                if (containsAlphabet(arr1[i]))
                {
                    cout << "Enter a valid name." << endl;
                }
                else {
                    validName = true;  // Set to false to exit the loop
                }
            }
            fout << arr1[i] << endl;

            bool validRollNo = false;
            while (!validRollNo) {
                cout << "Enter Roll no: ";
                getline(cin, arr2[i]);

                // Check if roll number is unique
                bool uniqueRollNo = true;
                for (int j = 0; j < i; j++) {
                    if (arr2[j] == arr2[i]) {
                        uniqueRollNo = false;
                        break;
                    }
                }
                if (!containsDigit(arr2[i]) || !uniqueRollNo)
                {
                    cout << "Must be unique and digit!" << endl;
                }
                else {
                    validRollNo = true;
                }
            }
            fout << arr2[i] << endl;

            cout << "Enter course: ";
            getline(cin, arr3[i]);
            fout << arr3[i] << endl;

            cout << "Enter class: ";
            getline(cin, arr4[i]);
            fout << arr4[i] << endl;

            bool validcontact = false;
            while (!validcontact) {
                cout << "Enter contact: ";
                getline(cin, arr5[i]);
                if (!containsDigit(arr5[i]))
                {
                    cout << "Please enter again." << endl;
                }
                else {
                    validcontact = true;
                }
            }
            fout << arr5[i] << endl;
        }

        total = ch + total;
    }
    fout.close();
}



void show()
{
    ifstream fin1;
    if (total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else
    {
        fin1.open("studentdata.txt");

        for (int i = 0; i < total; i++)
        {
            getline(fin1, arr1[i]);
            cout << "\nData of Student " << i + 1 << endl << endl;
            cout << "Name :" << arr1[i] << endl;

            getline(fin1, arr2[i]);  // Read roll no from the file
            cout << "Roll no: " << arr2[i] << endl;

            getline(fin1, arr3[i]);  // Read course from the file
            cout << "Course: " << arr3[i] << endl;

            getline(fin1, arr4[i]);  // Read class from the file
            cout << "Class: " << arr4[i] << endl;

            getline(fin1, arr5[i]);  // Read contact from the file
            cout << "Contact: " << arr5[i] << endl;
        }
    }
    fin1.close();  // Close the file after reading
}

// Function to search for a student by roll number
void search()
{
    ifstream fin1;
    bool found = false;

    fin1.open("studentdata.txt");

    if (total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else
    {
        string rollno;
        bool validRollNo = false;
        while (!validRollNo) {
            cout << "Enter the roll no of the student you want to delete: " << endl;
            cin >> rollno;
            if (!containsDigit(rollno)) {
                cout << " Must be digit." << endl;
            }
            else {
                validRollNo = true;
            }
        }
        cin.ignore();
        for (int i = 0; i < total; i++)
        {
            getline(fin1, arr1[i]);
            getline(fin1, arr2[i]);
            getline(fin1, arr3[i]);
            getline(fin1, arr4[i]);
            getline(fin1, arr5[i]);
        }
        for (int i = 0; i < total; i++)
        {
            if (rollno == arr2[i])
            {
                cout << "Name: " << arr1[i] << endl;
                cout << "Roll no: " << arr2[i] << endl;
                cout << "Course: " << arr3[i] << endl;
                cout << "Class: " << arr4[i] << endl;
                cout << "Contact: " << arr5[i] << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "ROLL NO NOT FOUND!";
    }
}
void update()
{
    ifstream fin1;
    bool found = false;
    fin1.open("studentdata.txt");

    if (total == 0)
    {
        cout << "No data is entered!" << endl;
    }
    else
    {
        string rollno;

        bool validRollNo = false;
        while (!validRollNo) {
            cout << "Enter the roll no of the student you want to delete: " << endl;
            cin >> rollno;
            if (!containsDigit(rollno)) {
                cout << " Must be digit." << endl;
            }
            else {
                validRollNo = true;
            }
        };
        cin.ignore();
        for (int i = 0; i < total; i++)
        {
            getline(fin1, arr1[i]);
            getline(fin1, arr2[i]);
            getline(fin1, arr3[i]);
            getline(fin1, arr4[i]);
            getline(fin1, arr5[i]);
        }
        for (int i = 0; i < total; i++)
        {
            if (rollno == arr2[i])
            {
                cout << "\nPrevious data" << endl << endl;
                cout << "Data of Student " << i + 1 << endl;
                cout << "Name " << arr1[i] << endl;
                cout << "Roll no " << arr2[i] << endl;
                cout << "Course " << arr3[i] << endl;
                cout << "Class " << arr4[i] << endl;
                cout << "Contact " << arr5[i] << endl;

                cout << "\nEnter new data" << endl << endl;
                bool validName = false;
                while (!validName) {
                    cout << "Enter name:";
                    getline(cin, arr1[i]);
                    if (containsAlphabet(arr1[i]))
                    {
                        cout << "Please enter a valid name." << endl;
                    }
                    else {
                        validName = true;
                    }
                }
                bool validRollNo = false;
                while (!validRollNo) {
                    cout << "Enter Roll no: ";
                    getline(cin, arr2[i]);
                    bool uniqueRollNo = true;
                    for (int j = 0; j < total; j++) {
                        if (arr2[j] == arr2[i] && j != i) {
                            uniqueRollNo = false;
                            break;
                        }
                    }
                    if (!containsDigit(arr2[i]) || !uniqueRollNo)
                    {
                        cout << " Must be unique and digit." << endl;
                    }
                    else {
                        validRollNo = true;
                    }
                }
                cout << "Enter course: ";
                getline(cin, arr3[i]);
                cout << "Enter class: ";
                getline(cin, arr4[i]);

                bool validcontact = false;
                while (!validcontact) {
                    cout << "Enter contact: ";
                    getline(cin, arr5[i]);
                    if (!containsDigit(arr5[i]))
                    {
                        cout << "Please enter again." << endl;
                    }
                    else {
                        validcontact = true;
                    }
                }
                found = true;
            }
        }
        fin1.close();  // Close the file before re-opening for writing

        // Re-open the file to update the data
        ofstream fout_temp;
        fout_temp.open("temp.txt", ios::trunc);
        for (int i = 0; i < total; i++)
        {
            fout_temp << arr1[i] << endl;
            fout_temp << arr2[i] << endl;
            fout_temp << arr3[i] << endl;
            fout_temp << arr4[i] << endl;
            fout_temp << arr5[i] << endl;
        }
        fout_temp.close();

        remove("studentdata.txt");
        rename("temp.txt","studentdata.txt");
    }
    if (!found) {
        cout << "ROLL NO NOT FOUND!";
    }
}


void deleterecord()
{
    ifstream fin1;
    fin1.open("studentdata.txt");
    bool found = false;
    if (total == 0)
    {
        cout << "No data is entered!" << endl;
    }
    else
    {
        int a=0;
        while (a!=1&&a!=2)
        {
            cout << "Press 1 to delete all records." << endl;
            cout << "Press 2 to delete a specific record." << endl;
            cout << "Option: ";
            while (!(cin >> a)) {
                cin >> a;
                cout << "Invalid input." << endl;
                cin.clear();
                while (cin.get() != '\n')
                    continue;
            }
        }

        if (a == 1)
        {
            found = true;
            total = 0;
            cout << "All records are deleted..!!" << endl;

            ofstream fout;
            fout.open("studentdata.txt", ios::trunc);
            fout.close();
        }
        else if (a == 2)
        {
            string rollno;


            bool validRollNo = false;
            while (!validRollNo) {
                cout << "Enter the roll no of the student you want to delete: " << endl;
                cin >> rollno;
                if (!containsDigit(rollno)){
                    cout << " Must be digit." << endl;
                }
                else {
                    validRollNo = true;
                }
            }
            for (int i = 0; i < total; i++)
            {
                getline(fin1, arr1[i]);
                getline(fin1, arr2[i]);
                getline(fin1, arr3[i]);
                getline(fin1, arr4[i]);
                getline(fin1, arr5[i]);
            }

            for (int i = 0; i < total; i++)
            {
                if (rollno == arr2[i])
                {
                    for (int j = i; j < total; j++)
                    {
                        arr1[j] = arr1[j + 1];
                        arr2[j] = arr2[j + 1];
                        arr3[j] = arr3[j + 1];
                        arr4[j] = arr4[j + 1];
                        arr5[j] = arr5[j + 1];
                    }
                    total--;

                    ofstream fout_temp;
                    fout_temp.open("temp.txt", ios::trunc);

                    for (int k = 0; k < total; k++)
                    {
                        fout_temp << arr1[k] << endl;
                        fout_temp << arr2[k] << endl;
                        fout_temp << arr3[k] << endl;
                        fout_temp << arr4[k] << endl;
                        fout_temp << arr5[k] << endl;
                    }

                    fout_temp.close();

                    // Remove the original file and rename the temporary file
                    remove("studentdata.txt");
                    rename("temp.txt", "studentdata.txt");

                    cout << "THE REQUIRED RECORD IS DELETED." << endl;
                    found = true;
                }
            }
        }
        else
        {
            cout << "INVALID INPUT!";
        }
    }
    if (!found) {
        cout << "NO DATA FOUND!";   // can be changes with no roll no found
    }
    fin1.close();
}


int main()
{
    int value;

    while (true)
    {
        cout << endl;
        cout << "\t\t_" << endl;
        cout << "\t\t| > Enroll new student -------------(1) |" << endl;
        cout << "\t\t| > Show existing data -------------(2) |" << endl;
        cout << "\t\t| > Search data of a student -------(3) |" << endl;
        cout << "\t\t| > Update data of a student -------(4) |" << endl;
        cout << "\t\t| > Delete data (Choice) -----------(5) |" << endl;
        cout << "\t\t| > Exit ---------------------------(6) |" << endl;
        cout << "\t\t_" << endl;
        cout << "Option: ";
        while (!(cin >> value))
        {
            cin >> value;
            cout << "Invalid input."<<endl;
            cout << "enter again:";
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        switch (value)
        {
        case 1:
            enter();
            break;

        case 2:
            show();
            break;

        case 3:
            search();
            break;

        case 4:
            update();
            break;

        case 5:
            deleterecord();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "INVALID INPUT!" << endl;
            break;
        }
    }
    return 0;
}
