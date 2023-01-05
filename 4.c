#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define len 10

void initializearr(int a[])
{
    for(int i=0;i<len;i++)
    {
        a[i]=rand()%99;

    }
}

void printarr(int a[])
{
    for(int i=0; i<len; i++)
    {
        printf("%d ",a[i]);
    }
}

float mean(int a[])
{
    float ans=0;
    for(int i=0 ; i< len; i++)
    {
        ans += a[i];
    }
    return (float)(ans/len);
}

float variance(int a[])
{
    float mu=mean(a);
    float sum=0;
    for(int i=0; i < len; i++)
    {
        sum += ((a[i] - mu) * (a[i] - mu));
    }
    return (float)(sum/len);
}

float stddev(int a[])
{
    float sig= sqrt( variance(a) );
    return sig;
}

void main()
{
    int arr[len];
    float std,var,mea;
    srand(time(NULL));
    initializearr(arr);
    printarr(arr);
    printf("\n");
    mea= mean(arr);
    var= variance(arr);
    std= stddev(arr);
    printf("mean is : %.3f\n",mea);
    printf("variance is : %.3f\n",var);
    printf("standard deviation is : %.3f\n",std);
}
