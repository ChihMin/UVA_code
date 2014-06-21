#include <cstdio>
#include <cstdlib>
#define N 500

using namespace std;

int n,max;
int count=0;
int visit[N][N];
char map[N][N];

void dfs(int x,int y,int step)
{
	if(step>max)	max=step;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(visit[i][j]==0)
			{
				for(int m=i;m>=0;m--)	if(visit[m][j]==-1)	break;	else if(visit[m][j]==0) visit[m][j]=step+1;	//�V����					
				for(int m=i;m<n;m++)	if(visit[m][j]==-1)	break;	else if(visit[m][j]==0)	visit[m][j]=step+1;	//�V�k��
				for(int m=j;m>=0;m--)	if(visit[i][m]==-1)	break;	else if(visit[i][m]==0) visit[i][m]=step+1;	//�V�U��
				for(int m=j;m<n;m++)	if(visit[i][m]==-1)	break;	else if(visit[i][m]==0) visit[i][m]=step+1;	//�V�W��	
			
				dfs(i,j,step+1);
				
				for(int m=i;m>=0;m--)	if(visit[m][j]==-1)	break;	else if(visit[m][j]==step+1)	visit[m][j]=0;	//�V����					
				for(int m=i;m<n;m++)	if(visit[m][j]==-1)	break;	else if(visit[m][j]==step+1)	visit[m][j]=0;	//�V�k��
				for(int m=j;m>=0;m--)	if(visit[i][m]==-1)	break;	else if(visit[i][m]==step+1)	visit[i][m]=0;	//�V�U��
				for(int m=j;m<n;m++)	if(visit[i][m]==-1)	break;	else if(visit[i][m]==step+1)	visit[i][m]=0;	//�V�W�� 	
	
			}
}

int main()
{	
	while(scanf("%d",&n)!=EOF && n!=0)
	{	
		max=0;
		for(int i=0;i<n;i++)	
		{	
			scanf("%s",map[i]);	
			for(int j=0;j<n;j++)	
				if(map[i][j]=='.')	visit[i][j]=0;	
				else visit[i][j]=-1;
		}
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(visit[i][j]==-1)	continue;
					
				for(int m=i;m>=0;m--)	if(visit[m][j]==-1)	break;	else visit[m][j]=1;	//�V����					
				for(int m=i;m<n;m++)	if(visit[m][j]==-1)	break;	else visit[m][j]=1;	//�V�k��
				for(int m=j;m>=0;m--)	if(visit[i][m]==-1)	break;	else visit[i][m]=1;	//�V�U��
				for(int m=j;m<n;m++)	if(visit[i][m]==-1)	break;	else visit[i][m]=1;	//�V�W�� 	
			
				if(1>max)	max=1;
				dfs(i,j,1);
				
				for(int m=i;m>=0;m--)	if(visit[m][j]==-1)	break;	else visit[m][j]=0;	//�V����					
				for(int m=i;m<n;m++)	if(visit[m][j]==-1)	break;	else visit[m][j]=0;	//�V�k��
				for(int m=j;m>=0;m--)	if(visit[i][m]==-1)	break;	else visit[i][m]=0;	//�V�U��
				for(int m=j;m<n;m++)	if(visit[i][m]==-1)	break;	else visit[i][m]=0;	//�V�W�� 					
			}
		printf("%d\n",max);	 
	}
	return 0;	
} 
