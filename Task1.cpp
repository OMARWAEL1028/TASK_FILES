#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    string fullName, grade;
    int id;
    cout << "please enter the full name : ";
    getline(cin, fullName);
    cout << "enter the id : ";
    cin >> id;
    cout << "enter the grade : ";
    cin >> grade;

    ofstream MyFile("file.txt");
    if (MyFile.is_open())
    {
        MyFile << "Student name : " << fullName << endl;
        MyFile << "Id : " << id << endl;
        MyFile << "Grade : " << grade << endl;
    }
    else
    {
        cout << "ERROR\n";
    }
    MyFile.close();
    return 0;
}

