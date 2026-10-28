#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    ifstream Myfile("fruit.txt");
    if (Myfile.is_open())
    {
        string line;
        while (getline(Myfile, line))
        {

            cout << line << endl;
        }
    }
    else
    {
        cout << "ERROR\n";
    }
    Myfile.close();

    ofstream myfile("fruit.txt", ios::app);
    if (myfile.is_open())
    {
        myfile << "\nFresh Fruits";
    }
    else
    {
        cout << "ERROR\n";
    }
    myfile.close();
    return 0;
}

