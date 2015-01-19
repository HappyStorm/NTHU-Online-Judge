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
    int element;
    Number *first, *last, *middle;
};
typedef struct numList NumList;

void insertHead(NumList*, Number*);
void insertTail(NumList*, Number*);
void removeHead(NumList*);
void removeTail(NumList*);
Number* creatNum(int);
void Move(NumList*, Number*, Number*);
void swapList(NumList*);
//long long ct=0;
int main()
{
    int value=0;
    char input[2+5];
    memset(input, '\0', sizeof(input));
    NumList NumberList;
    NumberList.first = NULL, NumberList.last = NULL;
    NumberList.middle = NULL, NumberList.element=0;
    while(~scanf("%s", input)){
        if(!strcmp("IH", input))
            scanf("%d", &value), insertHead(&NumberList, creatNum(value)), getchar();
        else if(!strcmp("IT", input))
            scanf("%d", &value), insertTail(&NumberList, creatNum(value)), getchar();
        else if(!strcmp("RH", input))
            removeHead(&NumberList);
        else if(!strcmp("RT", input))
            removeTail(&NumberList);
        else if(!strcmp("S", input))
            swapList(&NumberList);
        memset(input, '\0', sizeof(input));
    }
    return 0;
}

void insertHead(NumList *numberList, Number *newnum)
{
    //ct++;
    if(numberList->first==NULL){
        //printf("IH, first=NULL, %d to Head\n", newnum->value);
        Number* F = (Number*) malloc(sizeof(Number));
        Number* L = (Number*) malloc(sizeof(Number));
        F->prev = NULL, F->next = newnum;
        L->prev = newnum, L->next = NULL;
        newnum->prev = F, newnum->next = L;
        numberList->first = F, numberList->last = L;
        numberList->middle = newnum;
    }
    else{
        //printf("IH, %d to Head\n", newnum->value);
        newnum->prev = numberList->first;
        newnum->next = numberList->first->next;
        numberList->first->next->prev = newnum;
        numberList->first->next = newnum;
    }
    numberList->element++;
    if((numberList->element)!=1 && (numberList->element)%2==0)
        numberList->middle = numberList->middle->prev;
}

void insertTail(NumList *numberList, Number *newnum)
{
    //ct++;
    if(numberList->first==NULL){
        //printf("IT, first=NULL, %d to Tail\n", newnum->value);
        Number* F = (Number*) malloc(sizeof(Number));
        Number* L = (Number*) malloc(sizeof(Number));
        F->prev = NULL, F->next = newnum;
        L->prev = newnum, L->next = NULL;
        newnum->prev = F, newnum->next = L;
        numberList->first = F, numberList->last = L;
        numberList->middle = newnum;
    }
    else{
        //printf("IT, %d to Tail\n", newnum->value);
        newnum->prev = numberList->last->prev;
        newnum->next = numberList->last;
        numberList->last->prev->next = newnum;
        numberList->last->prev = newnum;
    }
    numberList->element++;
    if((numberList->element)!=1 && (numberList->element)%2==1)
        numberList->middle = numberList->middle->next;
}

Number* creatNum(int v)
{
    Number* newNum = (Number*) malloc(sizeof(Number));
    newNum->value = v, newNum->next = NULL;
    return newNum;
}

void removeHead(NumList *numberList)
{
    //ct++;
    numberList->element--;
    if((numberList->element)==0){
        //printf("RH Last, ");
        //printf("CT: %lld RHL->%d\n", ct, numberList->first->next->value);
        printf("%d\n", numberList->first->next->value);
        free(numberList->first->next);
        numberList->first = NULL;
        numberList->last = NULL;
        numberList->middle = NULL;
    }
    else{
        Number* newhead = numberList->first->next->next;
        //printf("RH, ");
        //printf("CT: %lld RH->%d\n", ct, numberList->first->next->value);
        printf("%d\n", numberList->first->next->value);
        free(numberList->first->next);
        newhead->prev = numberList->first;
        numberList->first->next = newhead;
        if((numberList->element)!=1 && (numberList->element)%2==1)
            numberList->middle = numberList->middle->next;
        else if((numberList->element)==1)
            numberList->middle = newhead;
    }
}
void removeTail(NumList *numberList)
{
    //ct++;
    numberList->element--;
    if((numberList->element)==0){
        //printf("RT Last, ");
        //printf("CT: %lld RTL->%d\n", ct, numberList->last->prev->value);
        printf("%d\n", numberList->last->prev->value);
        free(numberList->last->prev);
        numberList->first = NULL;
        numberList->last = NULL;
        numberList->middle = NULL;
    }
    else{
        Number* newtail = numberList->last->prev->prev;
        //printf("RT, ");
        //printf("CT: %lld RT->%d\n", ct, numberList->last->prev->value);
        printf("%d\n", numberList->last->prev->value);
        free(numberList->last->prev);
        newtail->next = numberList->last;
        numberList->last->prev = newtail;
        if((numberList->element)!=1 && (numberList->element)%2==0)
            numberList->middle = numberList->middle->prev;
        else if((numberList->element)==1)
            numberList->middle = newtail;
    }
}

void swapList(NumList* numberList)
{
    //ct++;
    //printf("SWAP\n");
    if(numberList->element>0){
        if((numberList->element)!=1 && (numberList->element)%2==0){
            Number *newmiddle = numberList->last->prev;
            numberList->middle->next->prev = numberList->first;
            numberList->first->next->prev = numberList->last->prev;
            numberList->last->prev->next = numberList->first->next;
            numberList->first->next = numberList->middle->next;
            numberList->last->prev = numberList->middle;
            numberList->middle->next = numberList->last;
            numberList->middle = newmiddle;
        }
        else if((numberList->element)!=1 && (numberList->element)%2==1){
            Number *newmiddle = numberList->last->prev;
            numberList->middle->prev->next = numberList->last;
            numberList->last->prev->next = numberList->first->next;
            numberList->first->next->prev = numberList->last->prev;
            numberList->last->prev = numberList->middle->prev;
            numberList->first->next = numberList->middle;
            numberList->middle->prev = numberList->first;
            numberList->middle = newmiddle;
        }
    }
}
