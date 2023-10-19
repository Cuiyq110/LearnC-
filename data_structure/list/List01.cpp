//
// Created by cyq11 on 2023/10/8.
//

#include "List01.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

using namespace std;

struct Node {
    int data;
    Node *link;
};

Node *head;
/*插入数据*/
void list_input(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->link = head;
    head = temp;
}
/*打印链表*/
void list_print() {
    Node *temp = head;
    cout << "list is: ";
    while (temp != NULL)
    {
        cout << "  " << temp->data;
        temp = temp->link;
    }
    cout << endl;
}

/*链表实现*/
void list_implement() {
    head = NULL;
    int n,i,x;
    cout << "how many numbers?" << endl;
    cin >> n;
    for ( i = 0; i < n; ++i) {
        cout << "enter the number:" <<endl;
        cin >> x;
        list_input(x);
        list_print();
    }
}

int main() {

    list_implement();

    system("pause");

}
