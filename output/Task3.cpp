#include <iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
    ofstream x("welcome.txt");
    x << "Hello Everybody";
    x.close();

    ifstream y("welcome.txt");
    string line;
    getline(y, line);
    y.close();

    ofstream z("welcome.txt");
    int pos = line.find("body");
    if (pos != string::npos)
    {
        line.replace(pos, 4, "one");
    }
    z << line;
    z.close();


    return 0;
}
