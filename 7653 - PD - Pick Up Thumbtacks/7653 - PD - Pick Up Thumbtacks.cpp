#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class bomb{
  public:
      bomb(int a, int b, int c, int d){
          no = a, mx = b, my = c, distance = d;
      }
      int no;
      int mx;
      int my;
      int distance;
};
bool cmp(bomb b1, bomb b2)
{
    if(b1.distance<b2.distance)
        return b1.distance<b2.distance;
    else if(b1.distance>b2.distance)
        return b1.distance<b2.distance;
    else{
        if(b1.no>b2.no)
            return b1.no<b2.no;
        else
            return b1.no<b2.no;
    }
}
int main()
{
    int test, flag=0;
    scanf("%d", &test);
    while(test--){
        vector<bomb> allmine;
        int px, py;
        scanf("%d %d", &px, &py);
        int mine;
        scanf("%d", &mine);
        for(int i=0 ; i<mine ; i++){
            int mx, my, distance;
            scanf("%d %d", &mx, &my);
            distance = (mx-px)*(mx-px) + (my-py)*(my-py);
            bomb b = bomb(i+1, mx, my, distance);
            allmine.push_back(b);
        }
        sort(allmine.begin(), allmine.end(), cmp);
        for(int i=0 ; i<mine ; i++)
            printf("#%d: %d %d\n", allmine[i].no, allmine[i].mx, allmine[i].my);
        if(test)
            printf("\n");
    }
    return 0;
}
