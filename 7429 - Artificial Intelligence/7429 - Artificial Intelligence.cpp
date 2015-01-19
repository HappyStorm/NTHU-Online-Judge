#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;

int iskeyUnit(char);

int main()
{
    int test, flag=1;
    scanf("%d", &test), getchar();
    while(test--){
        char question[1000], temp[1000], value[100];
        memset(question, '\0', sizeof(question));
        gets(question);
        int length = strlen(question);
        double current=0, volt=0, watt=0;
        int flagA=0, flagV=0, flagW=0;
        for(int i=0, j=0 ; i<length ; i++){
            memset(temp, '\0', sizeof(temp));
            memset(value, '\0', sizeof(value));
            if(i!=i-1){
                if(iskeyUnit(question[i])){
                    if(question[i+1]=='='){
                        while(question[i]!=' ')
                            temp[j++] = question[i++];
                        int len = strlen(temp);
                        switch(iskeyUnit(temp[0])){
                            case 1:{
                                for(int k=0, m=0 ; k<len ; k++){
                                    if(temp[k]=='='){
                                        while(!isalpha(temp[++k]))
                                            value[m++] = temp[k];
                                        current = atof(value);
                                        if(temp[k]=='m')
                                            current/=1000;
                                        else if(temp[k]=='k')
                                            current*=1000;
                                        else if(temp[k]=='M')
                                            current*=1000000;
                                        break;
                                    }
                                }
                                flagA=1, j=0;
                                break;
                            }
                            case 2:{
                                for(int k=0, m=0 ; k<len ; k++){
                                    if(temp[k]=='='){
                                        while(!isalpha(temp[++k]))
                                            value[m++] = temp[k];
                                        volt = atof(value);
                                        if(temp[k]=='m')
                                            volt/=1000;
                                        else if(temp[k]=='k')
                                            volt*=1000;
                                        else if(temp[k]=='M')
                                            volt*=1000000;
                                        break;
                                    }
                                }
                                flagV=1, j=0;
                                break;
                            }
                            case 3:{
                                for(int k=0, m=0 ; k<len ; k++){
                                    if(temp[k]=='='){
                                        while(!isalpha(temp[++k]))
                                            value[m++] = temp[k];
                                        watt = atof(value);
                                        if(temp[k]=='m')
                                            watt/=1000;
                                        else if(temp[k]=='k')
                                            watt*=1000;
                                        else if(temp[k]=='M')
                                            watt*=1000000;
                                        break;
                                    }
                                }
                                flagW=1, j=0;
                                break;
                            }
                            default:
                                break;
                        }
                    }
                }
            }
            if(flagA+flagV+flagW>=2)
                break;
        }
        if(flagA==1 && flagV==1)
            watt = current*volt, printf("Problem #%d\nP=%.2fW\n", flag++, watt);
        else if(flagA==1 && flagW==1)
            volt = watt/current, printf("Problem #%d\nU=%.2fV\n", flag++, volt);
        else if(flagV==1 && flagW==1)
            current = watt/volt, printf("Problem #%d\nI=%.2fA\n", flag++, current);
        putchar(10);
    }
    return 0;
}

int iskeyUnit(char a)
{
    if(a=='I')
        return 1;
    else if(a=='U')
        return 2;
    else if(a=='P')
        return 3;
    else
        return 0;
}
