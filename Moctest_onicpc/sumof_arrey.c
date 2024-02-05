#include <stdio.h>

int find(int *arr,int n,int a,int b,int i,int count){

    int sum=0;

    if(n==i){return count;}

     for(int p = 0; p < n; p++){
               sum = arr[i] + arr[p];
                if((sum >= a) && (sum <= b)){
                    count++;
                }
            
        }

        find(arr,n,a,b,i+1,count);
        

         



}

int main(){
    int t, n, a, b;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%d", &n);
        scanf("%d %d", &a, &b);

        int arr[n];
        int count = 0;

        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        int i=0;
        find(arr,n,a, b,i,count);

        printf("Case %d: %d\n", i, count);
    }

return 0;
}