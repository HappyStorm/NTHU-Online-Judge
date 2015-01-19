#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <cstring>
#include <cctype>
#include <set>
using namespace std;
char pre[30], in[30];
struct node{
    char  value;
    node *left, *right;
};

void recover(char*, char*, int);
int main()
{
    memset(pre, '\0', sizeof(pre));
    memset(in, '\0', sizeof(in));
    while(~scanf("%s %s", pre, in)){
        recover(in, pre, strlen(pre));
        putchar(10);
        memset(pre, '\0', sizeof(pre));
        memset(in, '\0', sizeof(in));
    }
	return 0;
}

void recover(char* inorder, char* preorder, int len)
{
    if(len==0)
	  return;
    node* newnode = (node*) malloc(sizeof(node));
    newnode->value = preorder[0];
    int index = 0;
    for( ; index<len ; index++)
        if(inorder[index] == preorder[0])
            break;
    recover(inorder, preorder+1, index);
    recover(inorder+index+1, preorder+index+1, len-(index+1));
    putchar(newnode->value);
    return;
}
