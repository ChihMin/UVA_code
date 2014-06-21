#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 20000

using namespace std;

char str[N];

void define_value(int n , int *ptr)
{
	for(int i=0;i<n;i++)
	{
		gets(str);
		char letter;
		int value;
					
		sscanf(str,"%c %d",&letter,&value);
		*(ptr + letter) = value;	
	}
}

int main()
{
	int t;
	gets(str);
	sscanf(str,"%d",&t);

	while(t--)
	{
		int n;
		
		gets(str);
		sscanf(str,"%d",&n);	
	
		int letter_value[N] = {0};
		define_value(n,letter_value);
		
		gets(str);
		sscanf(str,"%d",&n);
		
		double sum = 0;
		for(int i=0;i<n;i++)
		{
			unsigned char c;
			while(~scanf("%c",&c) && c!='\n')
				sum += (double)letter_value[(int)c];
		}
		
		printf("%.2lf$\n",sum/100);
	}
	return 0;	
}
