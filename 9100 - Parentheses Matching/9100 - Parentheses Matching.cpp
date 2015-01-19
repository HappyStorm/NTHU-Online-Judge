#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;


int main()
{
    int test, flag=1;
    scanf("%d", &test), getchar();
    while(test--){
        char input[1000+10];
        gets(input);
        int len = strlen(input);
        if(len==0)
            printf("Case %d: Yes\n", flag++);
        else{
            int check=1;
            stack<char> paren;
            for(int i=0 ; i<len ; i++){
                if(input[i]=='(' || input[i]=='[' || input[i]=='{' || input[i]=='<')
                   paren.push(input[i]);
                else if(input[i]==')'){
                    if(paren.size()<1 || paren.top()!='('){
                        check=0;
                        break;
                    }
                    else if(paren.top()=='(')
                        paren.pop();
                }
                else if(input[i]==']'){
                    if(paren.size()<1 || paren.top()!='['){
                        check=0;
                        break;
                    }
                    else if(paren.top()=='[')
                        paren.pop();
                }
                else if(input[i]=='}'){
                    if(paren.size()<1 || paren.top()!='{'){
                        check=0;
                        break;
                    }
                    else if(paren.top()=='{')
                        paren.pop();
                }
                else if(input[i]=='>'){
                    if(paren.size()<1 || paren.top()!='<'){
                        check=0;
                        break;
                    }
                    else if(paren.top()=='<')
                        paren.pop();
                }
            }
            if(paren.size()>0)
                check=0;
            if(check)
                printf("Case %d: Yes\n", flag++);
            else
                printf("Case %d: No\n", flag++);
        }
    }
    return 0;
}

