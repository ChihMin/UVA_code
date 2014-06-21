#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 50

using namespace std;

int dp[N][N] , prev[N][N];
int c[N] , r[N] , t[N] ,v[N];
int n;

void print()
{
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			printf("%d ",dp[i][j]);	
		printf("\n");
	}
}

void initialize( int *ptr )
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j] = 0 ;	
	*ptr = 0;
}

int LCS(int cnt , int x[] , int y[])
{	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(x[i] == y[j])
			{	
				dp[i][j] = dp[i-1][j-1] + 1;
				prev[i][j] = 1;
			}
			else 
			{
				if(dp[i-1][j] > dp[i][j-1])
				{
					dp[i][j] = dp[i-1][j];
					prev[i][j] = 2; //from top	
				}	
				else
				{
					dp[i][j] = dp[i][j-1];
					prev[i][j] = 3; //from left	
				}
			}
		}
		
	return  dp[n][n];
}	

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);	
		t[c[i]] = i;
	}
	
	while(~scanf("%d",&r[1]))
	{
		v[r[1]] = 1;
		
		int cnt;
		
		for(int i=2;i<=n;i++)
		{		
			scanf("%d",&r[i]);
			v[r[i]] = i;
		}
		initialize( &cnt );
		cnt = LCS( cnt , v , t );
		
		printf("%d\n",cnt);
	}
	
	return 0;	
}
