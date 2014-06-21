#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 40000

using namespace std;

char str[4];
int g[N];
int n;
int groups;

void initialize()
{
	for(int i=1;i<=n;i++)	g[i]=i;
	groups=n;
}

void uni(int x,int y)
{
	if(g[x]==g[y])	return;	
	groups--;
	
	int gmax=max(g[x],g[y]),gmin=min(g[x],g[y]);
	
	for(int i=1;i<=n;i++)	if(g[i]==gmax)	g[i]=gmin;
				
}

int main()
{
	bool enter=1;
	while(gets(str))
	{
		char gar;
		int t;
		
		sscanf(str,"%d",&t);
		scanf("%c",&gar);
		
		while(t--)
		{
			gets(str);
			n=str[0]-'A'+1;
			
			initialize();
			
			while(gets(str) && str[0]!='\0')	
			{
				int a=str[0]-'A'+1;
				int b=str[1]-'A'+1;
				uni(a,b);
			}	
			
			if(!enter)	printf("\n");
			enter=0;
			printf("%d\n",groups);
		}
	
	}
	return 0;	
}
