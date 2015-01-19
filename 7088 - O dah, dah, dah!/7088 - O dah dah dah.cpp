#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    map<string, char> mosmap;
    mosmap[".-"]    = 'A',  mosmap["-..."]   = 'B', mosmap["-.-."]   = 'C';
    mosmap["-.."]   = 'D',  mosmap["."]      = 'E', mosmap["..-."]   = 'F';
    mosmap["--."]   = 'G',  mosmap["...."]   = 'H', mosmap[".."]     = 'I';
    mosmap[".---"]  = 'J',  mosmap["-.-"]    = 'K', mosmap[".-.."]   = 'L';
    mosmap["--"]    = 'M',  mosmap["-."]     = 'N', mosmap["---"]    = 'O';
    mosmap[".--."]  = 'P',  mosmap["--.-"]   = 'Q', mosmap[".-."]    = 'R';
    mosmap["..."]   = 'S',  mosmap["-"]      = 'T', mosmap["..-"]    = 'U';
    mosmap["...-"]  = 'V',  mosmap[".--"]    = 'W', mosmap["-..-"]   = 'X';
    mosmap["-.--"]  = 'Y',  mosmap["--.."]   = 'Z', mosmap["-----"]  = '0';
    mosmap[".----"] = '1',  mosmap["..---"]  = '2', mosmap["...--"]  = '3';
    mosmap["....-"] = '4',  mosmap["....."]  = '5', mosmap["-...."]  = '6';
    mosmap["--..."] = '7',  mosmap["---.."]  = '8', mosmap["----."]  = '9';
    mosmap[".-.-.-"]= '.',  mosmap["--..--"] = ',', mosmap["..--.."] = '?';
    mosmap[".----."]= '\'', mosmap["-.-.--"] = '!', mosmap["-..-."]  = '/';
    mosmap["-.--."] = '(',  mosmap["-.--.-"] = ')', mosmap[".-..."]  = '&';
    mosmap["---..."]= ':',  mosmap["-.-.-."] = ';', mosmap["-...-"]  = '=';
    mosmap[".-.-."] = '+',  mosmap["-....-"] = '-', mosmap["..--.-"] = '_';
    mosmap[".-..-."]= '\"', mosmap[".--.-."] = '@';

    int test, ct=1;
    scanf("%d", &test);
    getchar();
    while(test--){
        char input[2000+20]={0}, output[2000+20]={0}, temp[10]={0};

        gets(input);
        int length = strlen(input);
        map<string, char>::iterator iter;
        for(int i=0, j=0, k=0 ; i<length ; i++){
            if(input[i]!=' ' && i!=length-1)
                temp[j++] = input[i];
            else if(input[i]==' ' && j!=0){
                //printf("temp= %s\n", temp);
                iter = mosmap.find(temp);
                output[k++] = iter->second;
                memset(temp, '\0', sizeof(temp));
                j=0;
            }
            else if(input[i]==' ' && j==0)
                output[k++] = 32;
            else if(input[i]!=' ' && i==length-1){
                temp[j++] = input[i];
                //printf("temp= %s\n", temp);
                iter = mosmap.find(temp);
                output[k++] = iter->second;
                j=0;
            }
        }

        printf("Message #%d\n%s\n", ct++, output);
        if(test)
            putchar(10);
    }
    return 0;
}
