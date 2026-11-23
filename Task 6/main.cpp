#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {

    ofstream outFile("grades.txt");
    outFile << 85 << endl;
    outFile << 90 << endl;
    outFile << 78 << endl;
    outFile << 92 << endl;
    outFile << 88 << endl;
    outFile.close();


    ifstream inFile("grades.txt");
    int grade;
    cout << "Current Grades:\n";
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();


    int gradeToDelete;
    cout << "\nEnter a grade to delete: ";
    cin >> gradeToDelete;

    inFile.open("grades.txt");
    ofstream tempFile("temp.txt");

    while (inFile >> grade) {
        if (grade != gradeToDelete) {
            tempFile << grade << endl;
        }
    }
    inFile.close();
    tempFile.close();


    if (remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0) {
        cout << "Grade deleted and file updated successfully.\n";
    } else {
        cout << "Error updating the file.\n";
    }

    return 0;
}
