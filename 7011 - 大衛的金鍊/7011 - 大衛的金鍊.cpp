#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(int, vector<int>);
bool comp(int, int);

int main()
{
    int test_case, temp;
    scanf("%d", &test_case);

    while(test_case--){
        int num_chain, answer=0;
        scanf("%d", &num_chain);

        vector<int> length;

        for(int i=0 ; i<num_chain ; i++){
            scanf("%d", &temp), length.push_back(temp);
        }

        if(num_chain>2)
            answer = calculate(num_chain, length);
        else if(num_chain==1)
            answer = length.at(0);
        else
            answer = length.at(0) + length.at(1);

        printf("%d\n", answer);
        length.clear();
    }
    return 0;
}

int calculate(int num_chain, vector<int> length)
{
    int sum=0, answer=0;
    make_heap(length.begin(),length.end(), comp);

    for(int i=0 ; i<num_chain-1 ; i++){
            //vector<int>::iterator flag = length.end();
            sum = length.front();

            pop_heap(length.begin(), length.end(), comp);
            length.pop_back();

            sum = sum + length.front();

            pop_heap(length.begin(), length.end(), comp);
            length.pop_back();
            length.
            length.push_back(sum);
            push_heap(length.begin(), length.end(), comp);

            answer = answer+sum;
        }
    return answer;
}

bool comp(int a, int b)
{
    return a>b;
}
