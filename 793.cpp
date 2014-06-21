#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 2000

using namespace std;

char s[100];
int g[N];
int n;

void initialize()
{
	for(int i=0;i<=n;i++)	g[i]=i;	
}

void uni(int x,int y)
{
	if(g[x] == g[y])	return;	
	int gmax = max(g[x],g[y]) , gmin = min(g[x],g[y]);
	
	for(int i=0;i<=n;i++)	if(gmax == g[i])	g[i]=gmin;
}

bool check(int x,int y)
{
	return g[x] ==g[y];	
}

int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);

	int t,enter=1;
	
	scanf("%d",&t);
	
		while(t--)
		{
			//scanf("%c",&gar);
			while(gets(s) && !s[0]);
			sscanf(s,"%d",&n);
			//printf("%d\n",n);
			
			initialize();
			
			int sure=0,unsure=0;
			
			while(1)
			{
				int a,b;
				char c;
				
				if(!gets(s))	break;
				if(!s[0])	break;
				
				sscanf(s,"%c %d %d",&c,&a,&b);
				
				if(c=='c')	uni(a,b);
				else 
				{
					if(check(a,b))	sure++;
					else unsure++;	
				}	
			}
			
			/*
			while( gets(s) && s[0]!='\0')
			{
				int a=s[2]-'0',b=s[4]-'0';
								
				if(s[0]=='c')	uni(a,b);
				else
				{
					if(check(a,b))	sure++;
					else unsure++;
				}
			}
			
			*/	
			if(!enter)	printf("\n");
			enter=0;
			printf("%d,%d\n",sure,unsure);
		}	
	return 0;	
}
