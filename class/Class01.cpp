

//
// Created by cyq11 on 2023/10/11.
//

#include "Class01.h"

#include "iostream"

using namespace std;

class Student {
private:
    string name = "????";
    int age = 3;

public:
    void show() {
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;

    }


} ;

void Class_() {
    Student student1;
    student1.show();

}

int main() {
    Class_();
    return 0;
}