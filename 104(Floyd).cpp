#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 100

using namespace std;

int n;
int end[100] , ecnt;
int path[100][100][100];
double w[100][100][100];

void find_path( int i ,int j , int s )
{
	if( s == 0 )	return ;
	
	find_path( i , path[i][j][s] , s-1);
	printf("%d ",path[i][j][s] + 1);
//	find_path( path[i][j][s] , j , s-1);
	
}

int main()
{
	while( ~scanf("%d",&n) )
	{
		memset(w,0,sizeof(w));
				
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				path[i][j][1] = i;
				if( i == j )
				{	
					w[i][j][1] = 1;
					continue;
				}
				scanf("%lf",&w[i][j][1]);
			}
	/*	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%.3lf ",w[i][j][1]);	
			printf("\n");
		}
		printf("\n");
	*/
	
		for(int step=2;step <=n;step++)
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
					{
						double tmp = w[i][k][step-1] * w[k][j][1] ;
						if( tmp > w[i][j][step] )
						{
							w[i][j][step] = tmp;
							path[i][j][step] = k;	
						}
					}
		
		bool find = 0;
		for(int s=1;s<=n;s++)
		{
			for(int i=0;i<n;i++)
				if( w[i][i][s] > 1.01 )
				{
					find_path( i , i , s );
					printf("%d\n",i+1);
					find = 1;
					break;	
				}
			if( find )	break;
		}
		
		if( !find )	printf("no arbitrage sequence exists\n");
	}
	return 0;	
} 
