#include <cstdio>
#include <cstdlib>

using namespace std;

int n,map[10][10],q[100][2],size;
bool find;

bool check(int a,int b,int num)
{
	for(int i=0;i<n*n;i++)
	{
		if(i == b)	continue;
		if(map[a][i] == num)	return 0;
	}
	
	//printf("YAAAA\n");
	
	for(int i=0;i<n*n;i++)
	{
		if(i == a)	continue;
		if(map[i][b] == num )	return 0;
	}
	
	int tempa=a/n,tempb=b/n;
	
	tempa*=n,tempb*=n;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(map[tempa+i][tempb+j] == num && tempa+i!=a && tempb+j!=b)	
				return 0;
	return 1;
}

void dfs(int now)
{
	if(find)	return;
	
	if(now == size)
	{
		find=1;
		for(int i=0;i<n*n;i++)
		{
			for(int j=0;j<n*n-1;j++)
				printf("%d ",map[i][j]);
			
			printf("%d\n",map[i][n*n-1]);
		}
		
		return;
	}
	
	for(int num = 1 ; num <= n*n ; num++)
		if( check(q[now][0] , q[now][1],num) )
		{
			map[q[now][0]][q[now][1]]=num;
			dfs(now+1);
			map[q[now][0]][q[now][1]]=0;
		}
}

int main()
{
	//freopen("a.txt","r",stdin);	
	//freopen("b.txt","w",stdout);
	
	bool enter = 1;
	while(~scanf("%d",&n))
	{
		size=0;
		
		for(int i=0;i<n*n;i++)
			for(int j=0;j<n*n;j++)
			{
				scanf("%d",&map[i][j]);
				
				if(!map[i][j])	
					q[size][0]=i , q[size++][1]=j;
			}
		
		bool no = 0; //如果一開始就無解(對衝) 
		find=0;	//有沒有找到解法 
		
		for(int i=0;i<n*n;i++)
			for(int j=0;j<n*n;j++)
				if(map[i][j])
					if(!check(i,j,map[i][j]))	
						no=1;
		
		if(!enter)	printf("\n");
		enter = 0;
		
		if(!no)	dfs(0);
		if(!find)	printf("NO SOLUTION\n");
	
	}
	
	return 0;
}
