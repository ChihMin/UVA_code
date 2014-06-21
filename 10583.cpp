#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 50000+10

using namespace std;

int n,m;
int g[N],groups;

int find(int x)
{
	return x == g[x] ? x : (g[x] = find(g[x]));	
}

void uni(int x,int y)
{
	x=find(x) , y=find(y);
	if(x==y)	return;
	
	groups--;
	g[x]=y;
}

void initialize()
{
	for(int i=0;i<=n;i++)	g[i]=i;	
	groups=n;
}

int main()
{
	int cnt=1;
	while(scanf("%d %d",&n,&m)!=EOF && n!=0)
	{
		initialize();
		
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			uni(a,b);	
		}	
		printf("Case %d: %d\n",cnt++,groups);	
	}
	return 0;	
}
