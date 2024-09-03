#include <iostream>
#include <utility>

using namespace std;

class schoolStaff{

    public:
        string name;
        int age = 0;
        int phone_number = 0;

    public:
        void setInfo(string input_name, int input_age, int input_phone){

            name = std::move(input_name);
            age = input_age;
            phone_number = input_phone;

        }



        virtual string getRole() = 0;

};


class teacher: public schoolStaff{


    public:
        string getRole() override{

            return "Teacher";
        }
};

class cook: public schoolStaff{


public:
    string getRole() override{

        return "Cook";
    }
};

int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Interface |-|-|-|-|-|-|-|-|-|" << endl;

    teacher t;
    cook c;

    t.setInfo("Antony",47,999111222);
    c.setInfo("Julian", 65, 920111222);

    cout << "--Staff Info--" << endl;
    cout << "| " << t.getRole() << " | " << t.name << " | " << t.age << " | " << t.phone_number << endl;
    cout << "| " << c.getRole() << " | " << c.name << " | " << c.age << " | " << c.phone_number << endl;


    return 0;
}
