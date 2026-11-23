#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
struct Student {
    char name[20];
    int id;
    float grade;
    char delim = '$';
};
void SaveData(Student& s) {
    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open()) {
      outFile << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << "\n";
    }
    outFile.close();
}

int main()
{
   char choice;
    do {
        Student s;

        cout << "Enter student name: ";
        cin.getline(s.name, 20);

        cout << "Enter student ID: ";
        cin >> s.id;

        cout << "Enter student grade: ";
        cin >> s.grade;

        SaveData(s);

        cout << "Do you want to add another record? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
