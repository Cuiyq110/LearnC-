

//
// Created by cyq11 on 2023/10/9.
//

#include "string01.h"
#include "iostream"
#include "string"
#include "cstring"
using namespace std;
class Dog{
private:
    string color;
    string name;

public:
    void init()
    {
        cout << "color:" << endl;
        cin >> color;
        cout << "name:" << endl;
        cin >> name;
    }
    void spark()
    {
        cout << "hello i am:" << name << endl;
        cout << "my color" << color << endl;
    }


};
void string01()
{
    string s1,s2,s3;
    cout << "input" << endl;
    cin >> s1  >> s2 >> s3;
    cout << s1 << s2 << s3 << endl;
    cout << s1 + s2 + s3 << endl;
//   string s4 = strcat(s1,s2,s3);

    cout << "--------\n" << endl;
    Dog dog1;
    dog1.init();
    dog1.spark();
}



int main() {
//    char ch[] = {'i', 'l', 'o', 'v', 'e'};
//    int size = sizeof(ch) / sizeof(char);
//    cout << "size:" << size << endl;
    string01();
    system("pause");


    return 0;
}

