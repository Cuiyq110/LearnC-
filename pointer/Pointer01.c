//
// Created by cyq11 on 2023/10/8.
//
#include <malloc.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int total;

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
    int *c = add(&a,&b);
    printf("sum:%d\n",*c);
}

/**
 * 指向指针的指针
 */
void zhizhendezhizhen() {
    int x = 5;
    int *p = &x;

    printf("%d\n", x);
    printf("%d\n", p);
    printf("%d\n", *p);
    printf("------\n");
    *p = 6;
    printf("%d\n", x);
    printf("%d\n", p);
    printf("%d\n", *p);
    int **p1 = &p;

    printf("*p1:%d\n", *p1);
    printf("p1:%d\n", p1);
    printf("&p:%d\n", &p);
    printf("**p1:%d\n", *(*p1));
    printf("-----\n");

    int ***p2 = &p1;
    printf("p2:%d\n", p2);
    printf("&p1:%d\n", &p1);
    printf("*p2:%d\n", *p2);
    printf("&p:%d\n", &p);
    printf("*(*p2):%d\n", *(*p2));
    printf("&x:%d\n", &x);
    printf("***p2:%d\n", *(*(*p2)));
    printf("x:%d", x);
//    printf("hello");
}

/**
 * 指针函数
 */
//void increament(int a) {
//    a = a + 1;
//    printf("increament:&a:%d\n", &a);
//    printf("increament:a:%d\n", a);
//}
void increament(int *p) {
    printf("p:%d\n", p);
    *p = (*p) + 1;
}

void pointer_function() {
    int a = 3;
    printf("a:%d\n", a);
    printf("&a:%d\n", &a);
    increament(&a);
    printf("a:%d\n", a);
}

/**
 *数组作为函数参数
 * 传的是数组的首地址， A[] 和*A 是一样的
 * @return
 */
// int sumofElements(int *A,int size)
//{
//    int i,sum = 0;
//    for(i = 0;i < size; i++)
//    {
//        sum += A[i];
//    }
//    return sum;
//}
void sumofElements(int *A, int size) {
    int i, sum = 0;
    for (i = 0; i < size; ++i) {
        A[i] = 2 * A[i];
    }
}

void array_function() {
//    int A[] = {1,2,3,4,5};
//    int size = sizeof(A) / sizeof(A[0]);
//    printf("size:%d\n",size);
//    printf("----\n");
//    printf("sum of elements: %d\n",sumofElements(A,size));

    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    sumofElements(A, size);
    for (int i = 0; i < size; ++i) {
        printf("%d\n", A[i]);
    }
}

/**
 * 指针和字符数组
 * @return
 */
void printf_(const char *s) {

    while (*s != '\0') {
        printf("%c", *s);
        s++;
    }
    printf("\n");

}


void character_arrays_pointer() {
    char c[4];
    c[0] = 'j';
    c[1] = 'O';
    c[2] = 'H';
    c[3] = 'N';
    c[4] = '\0';
//    for (int i = 0; i < sizeof(c) / sizeof(char); ++i) {
//        printf("%c",c[i]);
//    }
//    printf("\n----\n");
    printf("%s\n", c);
    int len = strlen(c);
    printf("%d", len); //4

    printf("----\n");
    char c1[] = "hello";
    char *c2;
    c2 = c1;
    printf("sizeof(c1):%d\n", sizeof(c1));
    printf("strlen(c1):%d\n", strlen(c1));
    printf("sizeof(c2):%d\n", sizeof(c2));
    printf("strlen(c2):%d\n", strlen(c2));

    char s[20] = "hello";
    printf("sizeof(s):%d\n", sizeof(s));
    printf("strlen(s):%d\n", strlen(s));
    printf_(s);

//     char *c4 = "hello";
//     printf_(c4);

}

void Multidimensional_Arrays() {
    int A[5] = {2, 4, 6, 8, 10};
//    int *p = A;
    printf("p:%d\n", A);
    printf("*p:%d\n", *A);
    printf("*(p+2):%d\n", *(A + 2));
    printf("p+2:%d\n", A + 2);
    printf("-----\n");

    int B[2][3] = {2, 4, 6,
                   8, 7, 9};
//    int B[2][3];
    int (*p)[3] = B;
//    printf("B:%d,&B[0]:%d\n",B,&B[1]);
//    printf("*B:%d,B[0]:%d",*B,B[1]);
    printf("p:%d,&B[0]:%d\n", p, &B[1]);
    printf("*p:%d,B[0]:%d,B[0][0]:%d\n", *(*p), B[0], &B[0][0]);
    int (*p1) = B;
    printf("p1:%d,&B[0]:%d,B[1]:%d\n", p1, &B[1], B[1]);
    printf("*p1:%d,B[0]:%d\n", *p1, B[0]);
    printf("----\n");
    printf("*(B+1):%d\n", *(B + 1));
    printf("*(*(B+1) + 1)):%d\n,", *(*(B + 1) + 1));
    printf("------\n");

}


void dynamic_memeory() {
    /**
     * malloc 函数理解
     */
    int a;
    int *p;
    p = (int *) malloc(4 * sizeof(int));
    p[0] = 1;
    *p = 0;
    *(p + 1) = 3;
    *(p + 2) = 2;
    *(p + 3) = 4;

    for (int i = 0; i < 4; ++i) {
//        printf("%d:\n",*(p+i));
        printf("%d:\n", p[i]);
    }
    free(p);
}

int main() {
//    zhizhendezhizhen();
//    pointer_function();
//    array_function();
//    character_arrays_pointer();
//    Multidimensional_Arrays();
//    dynamic_memeory();
    function_return();
    system("pause");
    return 0;
}

