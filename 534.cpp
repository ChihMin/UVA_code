#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#define N 2000

using namespace std;

struct Node{ double x , y ;} node[N];

int n ;
int parent[N];
double d[N] , ans;
bool visit[N];
double w[N][N];
typedef pair < double , int > pii;

double D( int a , int b )
{
	double x = node[a].x - node[b].x;
	double y = node[a].y - node[b].y;
	
	return 	sqrt( x*x + y*y );
}

void ST( int source )
{
	for(int i=0;i<n;i++)
		d[i] = 1e9 , visit[i] = 0;	

	priority_queue < pii,vector<pii>,greater<pii> > PQ;
	PQ.push( make_pair( 0 , 0 ) );
	d[source] = 0;
	parent[0] = 0;
	
	while( !PQ.empty() )
	{
		pii u = PQ.top(); PQ.pop();	
		int a = u.second;
		
		//if( visit[a] )	continue;
		visit[a] = 1;
		
		for(int b=0;b<n;b++)
			if( !visit[b] && w[a][b] < d[b] )
			{
				d[b] = w[a][b];
				parent[b] = a;
				PQ.push( make_pair( d[b] , b ) );	
			}
		
	}
	
}

void find_path( int x )
{
	if( x != parent[x] )
		find_path( parent[x] );
	if( d[x] > ans )	ans = d[x];	
}

int main()
{
	int now = 0;
	while( ~scanf("%d",&n) && n != 0 )
	{		
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&node[i].x,&node[i].y);
			
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				w[i][j] = D( i, j );	
	
		ans = 0;
		
		ST( 0 );
		find_path(1);
		//printf("\n");
		
		printf("Scenario #%d\n",++now);
		printf("Frog Distance = %.3f\n\n",ans);
	}
	
	return 0;	
}
