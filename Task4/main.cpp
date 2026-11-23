#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
struct person
{
    string name;
    int age;
};
void saveDatatofile(vector<person>&persons_write)
{
    fstream personFile;
    personFile.open("person.txt",ios::out);
    if(personFile.is_open())
    {
        for(person &line:persons_write)
        {
            if(!line.name.empty())
            {
                personFile<<line.name<<" "<<line.age<<endl;
            }
        }
        personFile.close();
    }
}
void loadDatafromfile(vector<person>&persons_read)
{
    fstream personFile;
    personFile.open("person.txt",ios::in);
    if(personFile.is_open())
    {
        person line;
        while (personFile >> line.name >> line.age)
        {
            persons_read.push_back(line);
        }
        personFile.close();
    }
}
void saveResulttofile(person &younger, person &older)
{
    fstream result;
    result.open("result.txt",ios::out);
    if(result.is_open())
    {
       result << "Younger person: " << younger.name << " (" << younger.age << ")" << endl;
        result << "Older person: " << older.name << " (" << older.age << ")" << endl;
        result.close();
    }
}
int main()
{
    int num;
    cout<<" how many persons you want to add to the file? ";
    cin>>num;
    vector<person>persons_write(num);
    for(int i=0;i<num;i++)
    {
        cin>>persons_write[i].name>>persons_write[i].age;
    }
    saveDatatofile(persons_write);
    vector<person>persons_read;
    loadDatafromfile(persons_read);
    if (!persons_read.empty())
    {
        person younger = persons_read[0];
        person older = persons_read[0];
        for (size_t i = 1; i < persons_read.size(); i++)
        {
            if (persons_read[i].age < younger.age)
            {
                younger = persons_read[i];
            }
            if (persons_read[i].age > older.age)
            {
                older = persons_read[i];
            }
        }
        saveResulttofile(younger,older);
    }
    return 0;
}
