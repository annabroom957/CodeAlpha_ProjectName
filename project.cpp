#include <iostream>
#include <string>
using namespace std;

double getGradePoint(const string &grade) {

    if (grade == "A" || grade == "A+") return 4.0;
    else if (grade == "A-") return 3.7;
    else if (grade == "B+" ) return 3.3;
    else if (grade == "B" ) return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+" ) return 2.3;
    else if (grade == "C" ) return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D" ) return 1.0;
    else return 0.0;
}

string getLetterGrade(double marks) {
    if (marks < 0 || marks > 100) {
        return "Invalid";
    }
    else if (marks >= 90) {
        return "A";
    }
    else if (marks >= 85) {
        return "A-";
    }
    else if (marks >= 80) {
        return "B+";
    }
    else if (marks >= 75) {
        return "B";
    }
    else if (marks >= 70) {
        return "B-";
    }
    else if (marks >= 65) {
        return "C+";
    }
    else if (marks >= 60) {
        return "C";
    }
    else if (marks >= 55) {
        return "C-";
    }
    else if (marks >= 50) {
        return "D";
    }
    else {
        return "F";
    }
}

int main() {
    int numberOfCourses;
    cout << "Enter the number of courses taken: ";
    cin >> numberOfCourses;

    double totalCreditHours = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numberOfCourses; i++) {
        string courseName;
        double marks;
        double creditHours;

        cout << "Enter the name of course " << (i+1) << ": ";
        cin >> courseName;

        cout << "Enter the marks (0-100): ";
        cin >> marks;

        cout << "Enter the credit hours for this course: ";
        cin >> creditHours;

        string letterGrade = getLetterGrade(marks);
        if (letterGrade == "Invalid") {
            cout << "Invalid marks entered for course " << courseName << ". Exiting.\n";
            return 1;
        }

        double gradePoint = getGradePoint(letterGrade);
        double earnedGradePoints = gradePoint * creditHours;

        cout << "Course: " << courseName
             << ", Marks: " << marks
             << ", Grade: " << letterGrade
             << ", Grade Point: " << gradePoint << "\n";


        totalCreditHours += creditHours;
        totalGradePoints += earnedGradePoints;
    }

    if (totalCreditHours > 0) {
        double gpa = totalGradePoints / totalCreditHours;
        cout << "Your GPA is: " << gpa << "\n";
    }
    else {
        cout << "No credit hours entered, cannot compute GPA.\n";
    }

    return 0;
}
