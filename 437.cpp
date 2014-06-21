#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 4000

using namespace std;

struct Node{int w[3];} sq[N] ;

int n , back , hmax ,sum;
int visit[N] , list[N] , s[N] , array[N];

bool cmp(const Node& x , const Node& y)
{	
	if(x.w[0] == y.w[0])
		return x.w[1] <= y.w[1];		
	return x.w[0] <= y.w[0];
}

void push_dfs(int step)
{
	if(step == 3)
	{
		for(int i=0;i<3;i++)
			sq[back].w[i] = list[i];	
		back++;
	}
	
	else
		for(int i=0;i<3;i++)
			if(!visit[i] &&  list[step] != s[i])
			{
				list[step] = s[i];
				visit[i] = 1;
				push_dfs(step+1);	
				visit[i] = 0;
			}
}

void initialize()
{
	for(int i=0;i<back;i++)
		array[i] = sq[i].w[2] ;
}

void DP()
{
	initialize();
	
	for(int i=0;i<back;i++)
		for(int j=i+1;j<back;j++)
			if((sq[j].w[0] > sq[i].w[0] && sq[j].w[1] > sq[i].w[1] ))
				array[j] = max( array[j] , sq[j].w[2] + array[i] );				
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int cnt = 1;
	while(~scanf("%d",&n) && n!=0)
	{
		back =  hmax = 0;
		for(int i=0;i<3;i++)	list[i] = 0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)	
				scanf("%d",&s[j]);
			
			for(int j=0;j<3;j++)
			{
				visit[j] = 1;
				list[0] = s[j];
				push_dfs(1);
				visit[j] = 0;	
			}
		}
		
		sort(sq , sq + back ,cmp);

		DP();
		
		for(int i=0;i<back;i++)
			hmax = max( array[i] , hmax );
		
		printf("Case %d: maximum height = %d\n",cnt++,hmax);
	}	
	
	return 0;	
}
