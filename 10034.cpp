#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define N 300

using namespace std;

struct Node{ double x , y; } p[N];

double d[N] , sum = 0;
double w[N][N];
int n , parent[N] ;
bool visit[N] , enter;

void MST()
{
	for(int i=0;i<n;i++)
		visit[i] = 0 , d[i] = 1e9; 	
	
	d[0] = parent[0] = 0;
	
	for(int i=0;i<n;i++)
	{
		int a = -1 , b = -1 ;
		double min = 1e9;
		
	//	printf("%f\n",min);
		
		for(int j=0;j<n;j++)
			if( !visit[j] && d[j] < min )
				min = d[j] , a = j;	
			
		if( a == -1 )	break;		
		visit[a] = 1;
		sum += min;
		//printf("%.3f\n",min);
		
		for(b=0;b<n;b++)
			if( !visit[b] && w[a][b] < d[b] )
				parent[b] = a , d[b] = w[a][b];
	}	
}


int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y );	
	
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if( i == j )	w[i][j] = 0;
				else
				{
					double x = p[i].x - p[j].x;	
					double y = p[i].y - p[j].y;	
					w[i][j] = sqrt( x*x + y*y );
				}
		/*
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				printf("%d %d : %.3f\n",i+1,j+1,w[i][j]);						
		printf("\n");
		*/
		
		sum = 0;
		MST();
		//sum = 0;
		
		//memset( visit , 0 , sizeof(visit) );
		
		/*
		for(int i=1;i<n;i++)
		{	
			if( !visit[i] )
				find_path( i );
			//printf("\n");
		}
		
		*/
		
		//for(int i=0;i<n;i++)
		//	sum += d[i];
		
		if(enter)	printf("\n");
		enter = 1;
		printf("%.2f\n",sum);
	}
	
	return 0;	
}
