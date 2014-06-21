#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define N 100

using namespace std;

int n , cnt;
int d[N] , parent[N] , list[N];
int w[N][N];
bool visit[N];
typedef pair < int ,int > pii;

void ini()
{
	cnt = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j] = (int)1e9;	
}

void dijk( int source )
{
	for(int i=1;i<=n;i++)
		d[i] = (int)1e9 , visit[i] = false;
	
	d[source] = 0;
	parent[source] = source;
		
	priority_queue < pii , vector <pii> , greater <pii> > PQ;	
	PQ.push( make_pair( d[source] , source ) );
	
	while( !PQ.empty() )
	{
		pii u = PQ.top(); PQ.pop();
		int a = u.second;
		
		//if( visit[a] )	continue;
		visit[a] = true;
		
		for(int b=1;b<=n;b++)
			if( !visit[b] && d[a] + w[a][b] < d[b] )
			{
				d[b] = d[a] + w[a][b] , parent[b] = a;	
				PQ.push( make_pair( d[b] , b ) );
			}
	}
//	printf("\n");
}

void find_path( int x )
{
	if( parent[x] != x )
		find_path( parent[x] );
	printf(" %d",x);	
}

int main()
{
	
	int num = 0;
	while( ~scanf("%d",&n) && n != 0 )
	{
		ini( );
			
		for(int i=1;i<=n;i++)	
		{
			int t;
			scanf("%d",&t);
			while(t--)
			{
				int j , v;
				scanf("%d %d",&j,&v);
				w[i][j] = v;
			}
		}
		
		int op , ed;
		scanf("%d %d",&op,&ed);
		
		dijk( op );
		
		printf("Case %d: Path =",++num);
		find_path( ed );
		printf("; %d second delay\n",d[ed]);
	} 	
	
	
	return 0;	
}
