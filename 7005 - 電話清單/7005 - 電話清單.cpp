#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    int a_length = a.size(), b_length = b.size();
    if(a.compare(b)>0)
        return false;
    else if(a.compare(b)<0)
        return true;
    else{
        if(a_length>b_length)
            return false;
        else
            return true;
    }
}
bool isprefix(int, const char[], vector<string>, int);

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        vector<string> phone_num_vec;
        int phone, flag=0;
        char temp[12];
        scanf("%d", &phone);

        for(int i=0 ; i<phone ; i++)
            scanf("%s", temp), phone_num_vec.push_back((string)temp);
        sort(phone_num_vec.begin(), phone_num_vec.end(), cmp);
        //for(int i=0 ; i<phone ; i++)
        //    cout << "Now the phone["<< i << "] is = "<< phone_num_vec[i] << endl;

        for(int i=0 ; i<phone ; i++){
            const char *tempi = phone_num_vec[i].c_str();
            //tempi = phone_num_vec[i].c_str();
            //strcpy(tempi, phone_num_vec[i].c_str());
            if(isprefix(phone, tempi, phone_num_vec, i)){
                flag=1;
                break;
            }
        }

            /*for(int j=i+1 ; j<phone ; j++){
                char tempi[20]={0}, tempj[20]={0};
                strcpy(tempi, phone_num_vec[i].c_str());
                strcpy(tempj, phone_num_vec[j].c_str());

                cout << "Now the tempi is = " << tempi << endl;
                cout << "Now the tempj is = " << tempj << endl;

                int big = phone_num_vec[i].size();
                if(strncmp(tempi, tempj, big)==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;*/
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

bool isprefix(int num, const char* keyword, vector<string> phone, int self)
{
    int low=0, high=num-1, keylength = strlen(keyword);
    //printf("Keyword = %s , key No.%d  KeyLength=%d\n", keyword, self, keylength);
    while(low<high){
        int mid = (low+high)/2 + 1 ;
        if(strncmp(keyword, phone[mid].c_str(), keylength)<0){
            //printf("phone[mid=%d] = %s\n", mid, phone[mid].c_str());
            high = mid-1;
        }
        else if(strncmp(keyword, phone[mid].c_str(), keylength)>0){
            low = mid+1;
        }
        else{
            //cout << "Now the keyword[" << self << "] is = " << keyword << endl;
            //cout << "Now the phone[" << mid << "] is = " << phone[mid] << endl;
            if(self==mid)
                return false;
            else
                return true;
        }
    }
    return false;
}
