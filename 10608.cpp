#include <cstdio>
#include <cstdlib>
#define N 60000

using namespace std;

int n,m;
int man[N],num[N];
int cntmax;

void initialize()
{
	for(int i=0;i<n;i++)
	{
		man[i]=i;	num[i]=1;
	}
}

int find(int x)
{
	return x == man[x] ? x : (man[x] = find(man[x]));	
}

void uni(int x , int y)
{
	x = find(x) , y = find(y) ;	
	if(x == y)	return ;
	
	num[y] += num[x];
	num[x] = 0;	
	man[x] = y;
	
	if(num[y] > cntmax)	cntmax = num[y];
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		initialize();
		cntmax=0;
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			uni(a,b);	
		}
		printf("%d\n",cntmax);	
	}
	return 0;	
}
