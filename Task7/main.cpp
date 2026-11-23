#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    vector<string> students = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    ofstream file1("students.txt");
    for (string s : students) {
        file1 << s << endl;
    }
    file1.close();

    ifstream inFile("students.txt");
    vector<string> sortedStudents;
    string name;
    while (getline(inFile, name)) {
        if (!name.empty()) sortedStudents.push_back(name);
    }
    inFile.close();

    sort(sortedStudents.begin(), sortedStudents.end());

    ofstream file2("sorted_students.txt");
    for (string s : sortedStudents) {
        file2 << s << endl;
    }
    file2.close();
    return 0;
}
