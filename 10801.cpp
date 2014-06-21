#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
#define N 500

using namespace std;

int n , k; 
int t[N];
int d[10][N];
int linked[10][N][N] , elinked[N][10][10];
bool visit[10][N];
stack < int > elevator[N];

void initialize()
{
	for(int i=0;i<=5;i++)
		for(int j=0;j<=100;j++)
		{
			d[i][j] = (int)1e9;
			for(int l=0;l<=100;l++)
				linked[i][j][l] = (int)1e9;	
		}
	for(int i=0;i<=100;i++)
		for(int j=0;j<=5;j++)
			for(int l=0;l<=5;l++)
				elinked[i][j][l] = (int)1e9;
	
	memset( visit , 0 , sizeof(visit) );
}

int input_num(char *str , int *ptr)
{
	int sum = 0 , back = 0;
	bool ok = 1;
	for( ; *str ; ++str )
	{
		if(*str == ' ' && !ok)
		{
			*(ptr++) = sum , ++back;
			sum = 0 , ok = 1;
			continue;	
		}
		
		else if(*str != ' ')
		{	
			sum = sum * 10 + *str - '0';	
			ok = 0;
		}
	}
	
	if(!ok) *(ptr++) = sum , ++back;
	return back; 
}

void dijkstra( int now )
{
	d[now][0] = 0;
	
	for(int o=0;o<100;o++)
		for(int p=0;p<100;p++)
		{
			int x = -1 , y = -1 , z = -1 , min = (int)1e9;
			
			for(int i=0;i<n;i++)
				for(int j=0;j<100;j++)
					if(!visit[i][j] && d[i][j] < min) 
						x = i , y = j  , min = d[i][j];	
			
			if(x == -1)	 break;
			visit[x][y] = 1;
				
			for( z=0; z<100 ; z++ ) 
				if( !visit[x][z] && d[x][y] + linked[x][y][z] < d[x][z] )
					d[x][z] = d[x][y] + linked[x][y][z];	
				
			for( z=0 ; z<n ; z++)
				if(!visit[z][y] && d[x][y] + elinked[y][x][z] < d[z][y])
					d[z][y] = d[x][y] + elinked[y][x][z] ;						
		}
}


int main()
{
	char input[N];

	while(gets(input))
	{			
		
		initialize();
		
		sscanf(input,"%d %d",&n,&k);
	
		gets(input);
		int back = input_num( input , t );
		
		for(int i=0;i<n;i++)
		{
			int e[N];
			
			gets(input);
			back = input_num( input , e );
		
			for(int a=0;a<back;a++)
			{
				elevator[e[a]].push(i);
				for(int b=0;b<back;b++)
				{
					int x = (e[a] - e[b]);
					x = x < 0 ? x * (-1) : x ;									
					linked[i][e[a]][e[b]] = x * t[i]; 
				}
			}
	
		}
	
		for(int i=0;i<100;i++)
		{
			int s[N] ; back = 0;
			while( !elevator[i].empty() )
			{	
				s[back++] = elevator[i].top() ;
				elevator[i].pop();
			}
					
			for(int a=0;a<back;a++)
				for(int b=0;b<back;b++)
				{
					if( s[a] == s[b] )	continue;	
					elinked[i][s[a]][s[b]] = elinked[i][s[b]][s[a]] = 60;
				}
		}
	
		for(int i=0;i<n;i++)	dijkstra(i); 
		
		int ans = (int)1e9;
		bool ok = 1;
		
		for(int i=0;i<n;i++)
			if(visit[i][k])
			{	
				ans = min( ans , d[i][k] );
				ok = 0;
			}
	
		!ok ? printf("%d\n",ans) : printf("IMPOSSIBLE\n");
	}
	
	return 0;	
}
