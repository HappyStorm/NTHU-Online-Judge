#include<stdio.h>

int arr[1000010],a[1000010],count[1000010],size;
long long int ans;

int main(){
    int x,y;
    int i,j;
    scanf("%d",&x);
    while(x>0){
        scanf("%d",&y);
        for(i=0 ; i<y ; i++)
            scanf("%d",&arr[i]);
        for(i=0, ans=0, size=0 ; i<y ; i++){
            while(size>0 && a[size-1]<arr[i]){
                ans+=count[--size];
				if(size>0)
                    ans++;
				if(count[size]>1)
                    count[size++]--;
			}
			if(size>0 && a[size-1] == arr[i])
				count[size-1]++;
			else
			{
				a[size++]=arr[i];
				count[size-1]=1;
			}
        }
        while (size>0)
		{
			ans+=count[--size]-1;
			if (size>0) ans++;
			if (count[size]>1)
                count[size++]--;
		}
        printf("%lld\n",ans);
        x--;
    }
    return 0;
}
