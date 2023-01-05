#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

float value(int num,int a[][num],int b[][num]);
int random32(){
    
    int i, n, d, r;
    for (i = 0; i < 32; i++)
    {
        n = clock();
        d = n & 1;
        r = r + d * (1 << i);
    }
    return r%10;
}
int main(){
    int n,i,j;
    printf("enter the number of column=");
    scanf("%d",&n);
    int arr1[2][n];
    int arr2[2][n];
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
            arr1[i][j]=random32();
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
            arr2[i][j]=random32();
    
    printf("value=%.16f",value(n,arr1,arr2));

    
}
float value(int num,int a[][num],int b[][num]){
    int i;
    float sum=0.0;
    for(i=0;i<num;i++){
        sum+=sqrt(abs(((a[1][i]-a[0][i])*(a[1][i]-a[0][i])-(b[1][i]-b[0][i])*(b[1][i]-b[0][i]))));
    }
    return((sum)/(float)num);
}
