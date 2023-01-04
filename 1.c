#include <stdio.h>

void SieveOfEratosthenes(int n)
{	
	int prime[n];
	for(int i=0;i<n;i++)
		prime[i]=1;
	prime[0]=0;
	for (int p = 2; p * p <= n; p++) 
	{
		if (prime[p-1] == 1) 
		{
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
