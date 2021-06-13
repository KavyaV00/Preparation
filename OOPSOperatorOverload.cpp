/*
    In Object Oriented Programming, we can overload operators ==, *, + to work on class objects. 

    Here, overloading of the equality operator is shown.
*/

#include <iostream>
#include <string>
using namespace std;

class student {
    string name;
    
    public:
        int age;
        char gender;
    
    // Default constructor
    student() {
        cout<< "Default constructor" << endl;
    } 

    // Parameterized constructor
    student(string _name, int _age, char _gender) {
        cout<< "Parameterized constructor" << endl;
        name = _name;
        age = _age;
        gender = _gender;
    }

    // Copy constructor
    student(student &s) {
        cout<< "Copy constructor" <<endl;
        name = s.name;
        age = s.age;
        gender = s.gender;
    }

    void setName(string _name) {
        name = _name;
    }

    void getName() {
        cout<< name << endl;
    }

    void display() {
        cout<< "Name: " << name << endl;
        cout<< "Age: " << age << endl;
        cout<< "Gender: " << gender << endl;
    }

    bool operator == (student &s) {
        if(name == s.name && age == s.age && gender == s.gender) 
            return true;
        return false;
    }

    ~student() {
        cout<< "Destructor" << endl;
    }
};



int main() {

    student s1;
    s1.setName("Mukti");
    s1.age = 25;
    s1.gender = 'F';
    student s2("Sam", 24, 'M');
    student s3 = s2;
    s3.display();
    if(s3 == s2) 
        cout<< "Same" << endl;
    else
        cout<< "Not same" << endl;
    if(s1 == s2) 
        cout<< "Same" << endl;
    else    
        cout<< "Not same" << endl;
    return 0;
}