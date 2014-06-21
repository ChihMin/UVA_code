#include <cstdio>
#include <cstdlib>
#define N 10

using namespace std;

int visit[N][N];
int list[N];
int x,y;
int count;

void dfs(int step)
{
	if(step==9)
	{
		printf("%2d      ",count++);
		for(int i=1;i<=7;i++)	printf("%d ",list[i]);
		printf("%d\n",list[8]);	
	}	

	else if(y==step)	dfs(step+1);
	
	else
		for(int i=1;i<=8;i++)
			if(visit[i][step]==0)
			{
				list[step]=i;	
				//------------四面八方拜訪過--------------------------------------
				for(int m=i;m<=8;m++)	if(visit[m][step]==0)	visit[m][step]=step+1;	//左右 
				for(int m=i;m>=1;m--)	if(visit[m][step]==0)	visit[m][step]=step+1;	//左右 
				for(int m=step;m<=8;m++)	if(visit[i][m]==0)	visit[i][m]=step+1;	//上下 
				for(int m=step;m>=1;m--)	if(visit[i][m]==0)	visit[i][m]=step+1;	//上下 
				for(int m=i,n=step;m<=8 && n<=8;m++,n++)	if(visit[m][n]==0)	visit[m][n]=step+1;	//右上左下 
				for(int m=i,n=step;m>=1 && n>=1;m--,n--)	if(visit[m][n]==0)	visit[m][n]=step+1;	//右上左下
				for(int m=i,n=step;m>=1 && n<=8;m--,n++)	if(visit[m][n]==0)	visit[m][n]=step+1;	//左上右下
				for(int m=i,n=step;m<=8 && n>=0;m++,n--)	if(visit[m][n]==0)	visit[m][n]=step+1;	//左上右下 
				//----------------------------------------------------------------
									
				//printf("\n");
				
				dfs(step+1);
				//------------四面八方回朔過--------------------------------------
				for(int m=i;m<=8;m++)	if(visit[m][step]==step+1)	visit[m][step]=0;	//左右 
				for(int m=i;m>=1;m--)	if(visit[m][step]==step+1)	visit[m][step]=0;	//左右 
				for(int m=step;m<=8;m++)	if(visit[i][m]==step+1)	visit[i][m]=0;	//上下 
				for(int m=step;m>=1;m--)	if(visit[i][m]==step+1)	visit[i][m]=0;	//上下 
				for(int m=i,n=step;m<=8 && n<=8;m++,n++)	if(visit[m][n]==step+1)	visit[m][n]=0;	//右上左下 
				for(int m=i,n=step;m>=1 && n>=1;m--,n--)	if(visit[m][n]==step+1)	visit[m][n]=0;	//右上左下
				for(int m=i,n=step;m>=1 && n<=8;m--,n++)	if(visit[m][n]==step+1)	visit[m][n]=0;	//左上右下
				for(int m=i,n=step;m<=8 && n>=0;m++,n--)	if(visit[m][n]==step+1)	visit[m][n]=0;	//左上右下 
				//----------------------------------------------------------------
			}
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int t;
	bool ok=1;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			count=1;
			for(int i=1;i<=8;i++)	for(int j=1;j<=8;j++)	visit[i][j]=0;			
			scanf("%d%d",&x,&y);
			//------------四面八方拜訪過--------------------------------------
			for(int i=x;i<=8;i++)	visit[i][y]=1;	//左右 
			for(int i=x;i>=1;i--)	visit[i][y]=1;	//左右 
			for(int i=y;i<=8;i++)	visit[x][i]=1;	//上下 
			for(int i=y;i>=1;i--)	visit[x][i]=1;	//上下 
			for(int i=x,j=y;i<=8 && j<=8;i++,j++)	visit[i][j]=1;	//右上左下 
			for(int i=x,j=y;i>=1 && j>=1;i--,j--)	visit[i][j]=1;	//右上左下
			for(int i=x,j=y;i>=1 && j<=8;i--,j++)	visit[i][j]=1;	//左上右下
			for(int i=x,j=y;i<=8 && j>=0;i++,j--)	visit[i][j]=1;	//左上右下 
			//----------------------------------------------------------------
			
		
			if(!ok)	printf("\n");
			printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
			
			
			list[y]=x;
			dfs(1);
			ok=0;	count++;
		}	
	}
	return 0;	
}
