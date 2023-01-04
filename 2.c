#include <stdio.h>
#include <time.h>

int randomRange(int lower,int upper)
{
	return (clock()%(upper-lower+1))+lower;	
}

char smallLetter()
{
	return randomRange(97,122);
}

char capitalLetter()
{
	return randomRange(65,90);
}

char digits()
{
	return randomRange(48,57);
}

char symbols()
{
	char sym[]={'~','`','!','@','#','$','%','^','&','*','(',')','-','_','+','=','{','}','[',']','|','\\',':',';','"','<','>',',','.','/','?','\''};
	return sym[randomRange(0,31)];
}

void shuffle(char str[])
{
	for(int i=0;str[i]!='\0';i++)
		{
			int c=randomRange(0,7);
			if (i!=c)
			{
				str[i]=str[i]^str[c];
				str[c]=str[i]^str[c];
				str[i]=str[i]^str[c];
			}
		}
}	

void password(char s[])
{
	s[0]=smallLetter();
	s[1]=capitalLetter();
	s[2]=digits();
	s[3]=symbols();
	for(int i=4;i<8;i++)
	{
		int c=randomRange(1,4);
		if(c==1)
			s[i]=smallLetter();
		else if(c==2)
			s[i]=capitalLetter();
		else if(c==3)
			s[i]=digits();
		else if(c==4)
			s[i]=symbols();
	}
	shuffle(s);
	s[8]='\0';
}

void main()
{
	char pass[9];

	password(pass);
	printf("Generated password: %s",pass);
}
