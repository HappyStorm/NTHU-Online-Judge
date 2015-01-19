#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

struct number{
    struct number *prev;
    struct number *next;
    int value;
};
typedef struct number Number;

struct numList{
    Number *first, *last;
};
typedef struct numList NumList;

void insertAfter(NumList*, Number*);
Number* creatNum(int);
void Move(NumList*, Number*, Number*);
void show(NumList*);

int main()
{
    int num;
    scanf("%d", &num), getchar();
    NumList NumberList;
    NumberList.first = NULL, NumberList.last = NULL;
    Number* index[num];
    for(int i=1 ; i<=num ; i++){
        Number *temp = creatNum(i);
        index[i] = temp;
        insertAfter(&NumberList, temp);
    }
    int a, b;
    char input[10+5]={0};
    while(scanf("%s", input)){
        if(!strcmp("Exit", input))
            break;
        else if(!strcmp("Move", input)){
            scanf("%d %d", &a, &b), getchar();
            Move(&NumberList, index[a], index[b]);
        }
    }
    show(&NumberList);
    return 0;
}

void insertAfter(NumList *numberList, Number *newnum)
{
    if(numberList->first==NULL){
        Number* F = (Number*) malloc(sizeof(Number));
        Number* L = (Number*) malloc(sizeof(Number));
        F->prev = NULL, F->next = newnum;
        L->prev = newnum, L->next = NULL;
        newnum->prev = F, newnum->next = L;
        numberList->first = F, numberList->last = L;
    }
    else{
        newnum->prev = numberList->last->prev;
        newnum->next = numberList->last;
        numberList->last->prev->next = newnum;
        numberList->last->prev = newnum;
    }
}

Number* creatNum(int v)
{
    Number* newNum = (Number*) malloc(sizeof(Number));
    newNum->value = v, newNum->next = NULL;
    return newNum;
}

void Move(NumList *numberList, Number* A, Number* B)
{
    if(A->next!=B && A!=B){
        B->prev->next = numberList->first->next;
        A->next->prev = numberList->first;
        numberList->first->next->prev = B->prev;
        numberList->first->next = A->next;
        A->next = B;
        B->prev = A;
    }
}

void show(NumList* numList)
{
    Number* now = numList->first->next;
    while(now->next!=NULL){
        if(now->next!=numList->last)
            printf("%d ", now->value);
        else
            printf("%d\n", now->value);
        now = now->next;
    }
}
