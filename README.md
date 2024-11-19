# Student Management System

A simple Student Management System that allows users to input, display, search, and update student data. The system stores student details in a file and validates input data to ensure accuracy and consistency. It provides basic functionalities such as adding student records, displaying records, searching for a student by roll number, and updating student data.

## Table of Contents
1. [Features](#features)
2. [Files](#files)
3. [How to Run](#how-to-run)
4. [Functions](#functions)
    1. [enter()](#enter)
    2. [show()](#show)
    3. [search()](#search)
    4. [update()](#update)
5. [Code Explanation](#code-explanation)
    1. [Input Validation](#input-validation)
    2. [File Handling](#file-handling)
6. [Data Validation Details](#data-validation-details)
    1. [Name Validation](#name-validation)
    2. [Roll Number Validation](#roll-number-validation)
    3. [Contact Validation](#contact-validation)
7. [Known Issues](#known-issues)
8. [Future Enhancements](#future-enhancements)
9. [License](#license)

## Features
- **Enter Student Data**: Input details like name, roll number, course, class, and contact for students (with validation).
- **Display Student Data**: View the data of all students stored in the file.
- **Search Student Data**: Search for a student by roll number and display their details.
- **Update Student Data**: Update student details based on roll number.
- **Data Validation**: Ensures valid input for names, roll numbers, and contacts. Ensures roll numbers are unique and numeric.

## Files
- **studentdata.txt**: A text file used to store student data.
- **student_management.cpp**: The C++ source code that implements the system.

## How to Run
Ensure you have a C++ compiler (e.g., GCC) installed.
Save the code in a .cpp file (e.g., student_management.cpp).

## Functions

### enter()
This function allows the user to input student data. It includes checks for valid input, ensuring that:
- Names do not contain digits.
- Roll numbers are unique and numeric.
- Contacts are numeric.

### show()
Displays all student data stored in the file `studentdata.txt`. If no data is entered, it prompts the user that the data is empty.

### search()
Prompts the user to enter a roll number and searches for the corresponding student. If the student is found, their details are displayed. Otherwise, it notifies the user that the student was not found.

### update()
Allows the user to update a student's details by entering their roll number. If the roll number is found, the existing data is displayed, and the user can enter new data. The system validates the updated input.

## Code Explanation

### Input Validation
- **containsDigit()**: Checks if the input string contains only digits.
- **containsAlphabet()**: Ensures the input string contains only alphabets and spaces.

### File Handling
The student data is written to `studentdata.txt`. The system opens the file in write mode to input new student records and in read mode to display or search for student records.

## Data Validation Details

### Name Validation
Ensures that the student’s name does not contain any digits.

### Roll Number Validation
Ensures the roll number is numeric and unique.

### Contact Validation
Ensures that the contact number contains only digits.

## Known Issues
- The code does not handle errors or exceptions when opening files.
- The program only supports up to 100 students (fixed size).

## Future Enhancements
- Implement a dynamic way to store data instead of using a fixed array.
- Add more functionality, such as deleting student records.
- Enhance the user interface and error handling for better usability.

## License
This project is open-source and available under the MIT License. Feel free to contribute or modify it for your needs.
