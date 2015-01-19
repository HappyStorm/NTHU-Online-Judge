#include<stdio.h>
#include<string.h>
#include<math.h>

int town[800][2], map[800][800], vis[800], d[800], parent[800], num, n;
void prim()
{
    int i, u, v;
    for(i=0 ; i<=n ; ++i)
        d[i] = 999999999, parent[i] = -1;
    d[1] = 0;
    for(u=0 ; u<n ; ++u){
        int mi = 999999999;
        for(i=1 ; i<=n ; ++i)
            if(!vis[i] && d[i] < mi)
                v = i, mi = d[i];
        vis[v] = 1;
        if(mi>0){
            printf("%d %d\n", v, parent[v]);
            num++;
        }
        for(i=1 ; i<=n ; ++i)
            if(!vis[i] && d[i]>map[v][i])
                d[i] = map[v][i], parent[i] = v;
    }
}
int main(){
    int time, i, j,m;
    scanf("%d", &time);
    while (time--) {
        num=0;
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        // town = city's   x & y
        for(i=1 ; i<=n ; i++)
            scanf("%d %d", &town[i][0], &town[i][1]);
        // map = a pair of cities' distance
        for(i=1 ; i<=n ; i++)
            for(j=i+1 ; j<=n ; ++j)
                map[j][i] = map[i][j] = (pow(town[i][0]-town[j][0],2) + pow(town[i][1]-town[j][1],2));
        scanf("%d", &m);
        // if the road has been built, then this pair of cities' distance = 0, or see it as the cost of the road = 0
        while(m--){
            int a, b;
            scanf("%d%d", &a, &b);
            map[a][b] = map[b][a] = 0;
        }
        prim();
        if (num == 0) printf("No new highways need\n");
        if (time > 0) printf("\n");
    }
}
