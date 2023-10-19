

//
// Created by cyq11 on 2023/10/10.
//

#include "dynamic.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

using namespace std;
void A()
{
    int a;
    printf("%d\n",a);
    cout << "hello" << endl;
}
void B(void A())
{
    A();
}
void calling_function_pointer()
{
    B(A);
}

void printHello(char *name)
{
    cout << "hello:" << name << endl;
}
/**
 * 求和
 * @param a
 * @param b
 * @return
 */
int Add(int a,int b)
{
    return a + b;
}
/**
 * 函数指针
 */
 void function_pointers()
 {
     int c;
     int (*p)(int,int);
     p = Add;
     c = (*p)(3,5);
     printf("%d\n",c);

     void (*p1)(char *);
     p1 = printHello;
     p1("yy");


 }
/**
 * 函数返回指针
 */
int *add(int *a, int *b)
{
    int *c = (int *) malloc(sizeof (int *));
    *c = *a + *b;
    return c;
}

void function_return()
{
    int a = 2, b = 3;
    cout  << "address of a in Add = " << a<< endl;

    int *c = add(&a,&b);

    printf("sum:%d\n",*c);
}
class Person
{
private:
    string name;
    int age;
public:
    Person(const string &name, int age) : name(name), age(age) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Person::name = name;
//        this->name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Person::age = age;
    }

};



void dynamic_() {
    int a;
    int *p;
    p = new int;
    *p = 10;
    cout << "*p:" << endl << *p << endl;
    p = new int[20];
    p[1] = 2;
    p[2] = 2;
    p[3] = 2;
    p[4] = 2;
    for (int i = 0; i < 10; ++i) {
        cout << "p[" << i << "]:" << p[i] << endl;
    }
}


/**
 * 声明一个数组，问用户他想要多大的数组
 */
void malloc_1() {
    int n;
    cout << "ener size of array:" << endl;
    cin >> n;
    int *A = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        A[i] = i + 1;
    }
    free(A);
    A[2] = 10;
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "]:" << A[i] << endl;
    }
}


void calloc_1() {
    int n;
    cout << "ener size of array:" << endl;
    cin >> n;
    int *A = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        A[i] = i + 1;
    }
    free(A);
//    A = NULL;
    A[2] = 10;
    for (int i = 0; i < n; ++i) {

        cout << "a[" << i << "]:" << A[i] << endl;
    }

}

void realloc_1() {

    int n;
    cout << "ener size of array:" << endl;
    cin >> n;

    int *A = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        A[i] = i + 1;
    }
    int *B = (int *) realloc(A, 2 * n * sizeof(int));
    for (int i = 0; i < 2 * n; ++i) {
        printf("%d\n", B[i]);
    }
    cout << sizeof(B) / sizeof B[0] << endl;
    system("pause");
}


int cash = 100;
//"jack queen king"-computer shuffer these cards

/**
 * 赌局游戏
 * @param bet 押注
 */
void play(int bet) {

    char *ch = (char *) malloc(1000000 * sizeof (char));
    printf("shuffling\n");
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = ch[x];
        ch[x] = ch[y];
        ch[y] = temp;
    }
    int playerGuess;
    cout << "what is postion of queen:" << endl;
    cin >> playerGuess;

        if (ch[playerGuess - 1] != 'q')
        {
            cout << "猜错了" << endl;
            cash -= bet;
            printf("You wrong! Result = \"%c %c %c\" Total cash = $%d\n",ch[0],ch[1],ch[2],cash);

        } else
        {
            cash += 3 * bet;
            printf("You win! Result = \"%c %c %c\" Total cash = $%d\n",ch[0],ch[1],ch[2],cash);
            return;
        }
}
/**
 * 内存泄漏
 *
 */
void memory_leak() {
    int bet;
    while (cash > 0 )
    {
       cout << "what's your bet? " << endl;
       cin >> bet;
        if (cash < 0 || bet > cash) break;
        play(bet);
        printf("\n****************\n");
    }
}


void malloc_calloc_realloc_free() {
//   malloc_1();
//    calloc_1();
//    realloc_1();
//    memory_leak();
//    function_return();
//    function_pointers();
    calling_function_pointer();
}



int main() {

//    dynamic_();
    malloc_calloc_realloc_free();
    system("pause");
    return 0;
}
