#include <stdio.h>

void SieveOfEratosthenes(int n)
{	
	//int prime[100]={1};->works
	//int prime[n]={1};->doesnot work
	int prime[n];
	for(int i=0;i<n;i++)
		prime[i]=1;
	prime[0]=0;
	/*
	Logic: Same as prime numbers where we check if the number is divisible by any number till its square root because
	after that all factors will already be accounted for
	For example: 16
	Factors:1X16,2X8,4X4,8X2,16X1.
	Here 8X2 hasalready been accounted for in 2X8 hence we run the loop only till square root that is 4(here)
	*/
	for (int p = 2; p * p <= n; p++) 
	{
		if (prime[p-1] == 1) 
		{
			// Numbers before pXp have already been crossed
			for (int i = p * p; i <= n; i += p)
	 			prime[i-1] = 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(prime[i]==1)
			printf("%d ",(i+1));
	}
}

void main()
{
	printf("Enter the number upto which all the prime numbers are to be printed:");
	int n;
	scanf("%d",&n);
	printf("The prime numbers upto %d are:\n", n);
	SieveOfEratosthenes(n);
}
