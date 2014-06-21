#include <cstdio>
#include <cstdlib>
#define N 200

using namespace std;

int n,k;
bool linked[N][N];
bool color[N];
bool visit[N];
int cnt,max;
int num[N],ans[N];
 
void dfs(int now)
{
	for(int i=1;i<=n;i++)
	{ 
		if(linked[now][i] && !color[i] && !color[now] && visit[i]){cnt--;	color[now]=1;}	
		if(linked[now][i] && color[now] && !visit[i])
		{
			visit[i]=1;
			dfs(i);		
			printf("cnt:%d\n",cnt);
			for(int j=1;j<=n;j++)	if(!color[j])	printf("%d ",j);	printf("\n");		
			visit[i]=0;
		}
		if(linked[now][i] && !visit[i] && !color[i] && !color[now])	
		{
			color[i]=1;
			cnt--;
			visit[i]=1;
			
			dfs(i);
			printf("cnt:%d\n",cnt);
			for(int j=1;j<=n;j++)	if(!color[j])	printf("%d ",j);	printf("\n");
			cnt++;
			visit[i]=color[i]=0;	
		} 
		
	} 
}
 
int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	
	int t;
	while(scanf("%d",&t)!=EOF)
		while(t--)
		{
			scanf("%d %d",&n,&k);	//let the color=0 be black 
			for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)	linked[i][j]=visit[i]=color[i]=0;
			for(int i=0;i<k;i++)
			{
				int a,b;
				scanf("%d%d",&a,&b);
				linked[a][b]=linked[b][a]=1;	
			}
			//已知建捷沒問題
			//暴力搜索開始
			max=0;
			for(int i=1;i<=n;i++)
			{
				cnt=n;
				visit[i]=1;
				dfs(i);
				visit[i]=color[i]=0;
			}	 		
		}

	return 0;	
}
