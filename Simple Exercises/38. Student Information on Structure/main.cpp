#include <iostream>
#include <string>
#include <vector>


using namespace std;


struct Student{

    string name;
    string roll_number;
    vector<string> subjects;
    vector<int> marks;
    float CGPA;
};



void printStruct(Student s){

    cout << "--Student details--" << endl;

    cout << "Name: " << s.name << endl;
    cout << "Roll number: " << s.roll_number << endl;
    cout << "Enrolled subjects: { ";

    for(int i = 0; i < s.subjects.size(); i++){

        if(i != s.subjects.size() - 1)
            cout << "'" << s.subjects.at(i) << "', ";
        else
            cout << "'" << s.subjects.at(i) << "'}" << endl;

    }

    cout << "Subjects marks: { ";

    for(int i = 0; i < s.marks.size(); i++){

        if(i != s.marks.size() - 1)
            cout << "'" << s.marks.at(i) << "', ";
        else
            cout << "'" << s.marks.at(i) << "'}" << endl;

    }

    cout << "CGPA: " << s.CGPA << endl;


}


int main() {


    cout << "|-|-|-|-|-|-|-|-|-| Student Structure |-|-|-|-|-|-|-|-|-|" << endl;

    Student s;

    s.name = "Paulo Gonçalves";
    s.roll_number = "up201704148";
    s.subjects.insert(s.subjects.end(),{"ES", "II", "PM", "SA", "SC", "DS"});
    s.marks.insert(s.marks.end(),{15, 17, 14, 13, 12, 17});
    s.CGPA = 15.0;

    printStruct(s);

    return 0;
}
