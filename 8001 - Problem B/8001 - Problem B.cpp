#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    char element[][3] = {"H", "He", "Li", "Be", "B", "C",
                         "N", "O", "F", "Ne", "Na", "Mg",
                         "Al", "Si", "P", "S", "Cl", "Ar",
                         "K", "Ca", "Sc", "Ti", "V", "Cr",
                         "Mn", "Fe"};
    int input;
    while(EOF!=scanf("%d", &input))
        printf("%s\n", element[input-1]);

    return 0;
}
