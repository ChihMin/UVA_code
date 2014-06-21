#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define N 5000

using namespace std;

int dp[N];
int song[N];
int list[N];
bool put[N][N];

int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);

	int len,n;
	while(scanf("%d%d",&len,&n)!=EOF)
	{
		for(int i=0;i<n;i++)	scanf("%d",&song[i]);
		
		for(int i=0;i<=n;i++)	for(int j=0;j<=len;j++)	dp[j]=list[i]=put[i][j]=0;
		
		for(int i=n-1;i>=0;i--){
			for(int j=len;j>=song[i];j--)
				if((dp[j-song[i]]+song[i])>dp[j])
				{	
					
					dp[j]=dp[j-song[i]]+song[i];		
					put[i][j]=1;
					for(int i=0;i<=len;i++)	printf("%2d ",dp[i]);
					printf("\n");
				}
			printf("\n");
		}		
		
		for(int i=0,j=len;i<n;i++)	
			if(put[i][j])
			{
				printf("%d ",song[i]);
				j-=song[i];
			}
		printf("sum:%d\n",dp[len]);
	}
	return 0;	
}
