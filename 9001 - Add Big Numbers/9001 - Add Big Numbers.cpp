#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define END_INT 999

void string_to_int(char *str, int num[]);
void show_big_int(int *num);
void add(int num1[], int num2[], int num3[]);

int main(void)
{
    char str1[100], str2[100];
    int A[100] = {0, END_INT};
    int B[100] = {0, END_INT};
    int C[101] = {0, END_INT};

    while(scanf("%s", str1)!=EOF)
    {

    }

    fscanf(fin, "%99s", str);
    string_to_int(str, A);

    fscanf(fin, "%99s", str);
    string_to_int(str, B);

    show_big_int(A);
    printf("\n");

    show_big_int(B);
    printf("\n");

    add(A, B, C);

    show_big_int(C);
    printf("\n");

    return 0;
}

void string_to_int(char *str, int num[])
{
    int i;
    for(i=0; i<strlen(str); i++)
		{
	        num[i] = str[strlen(str)-i-1] -'0';
	    }
    num[strlen(str)] = END_INT;
}

void show_big_int(int *num)
{
    if(*num!=END_INT)
		{
	        show_big_int(num+1);
	        printf("%d", *num);
	    }
}

void add(int num1[], int num2[], int num3[])
{
    /*
        考慮進位的問題
        以及當兩數的長度不同要如何處理
        ???
    */
    int i,j,temp=0;

    i=0;
    while(num1[i]!=END_INT && num2[i]!=END_INT)
    	{
    		if(num1[i]+num2[i]+temp<10)
    			{
    				num3[i] =  num1[i]+num2[i]+temp;
    				temp = 0;
    			}
    		else
    			{
    				num3[i] = (num1[i]+num2[i]+temp) %10;
    				temp = 1;
    			}
    		i++;
    	}

    if(num1[i]==END_INT)
		{
			while(num2[i]!=END_INT)
				{
					if(temp+num2[i]<10)
				    	{
				    		num3[i] = temp+num2[i];
				    		temp=0;
				    	}
				    else
				    	{
				    		num3[i] = (num2[i]+temp) %10;
		    				temp = 1;
				    	}
				    i++;
				}
			if(temp==1)
				{
				    num3[i] = 1;
				    num3[i+1] = END_INT;
				}
			else
				{
				    num3[i] = END_INT;
				}
		}
	else if(num2[i]==END_INT)
		{
			while(num1[i]!=END_INT)
				{
					if(temp+num1[i]<10)
				    	{
				    		num3[i] = temp+num1[i];
				    		temp=0;
				    	}
				    else
				    	{
				    		num3[i] = (num1[i]+temp) %10;
		    				temp = 1;
				    	}
				    i++;
				}
			if(temp==1)
				{
				    num3[i] = 1;
				    num3[i+1] = END_INT;
				}
			else
				{
				    num3[i] = END_INT;
				}
		}
}
