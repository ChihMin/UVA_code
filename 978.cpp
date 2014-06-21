#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#define N 1000000

using namespace std;

priority_queue < int >  b , g ;
int bf , nb , ng;
int tmpg[N] , tmpb[N];

int main()
{
	int T;
	scanf("%d",&T);
	
	bool enter = 0;
	while( T-- )
	{			
		scanf("%d %d %d",&bf,&ng,&nb);
		for(int i=0;i<ng;i++)
		{
			int x;
			scanf("%d",&x);
			g.push( x );		
		}	
		
		for(int i=0;i<nb;i++)
		{
			int x;
			scanf("%d",&x);
			b.push( x );	
		}
		
		if( enter )	printf("\n");
		
		while( !g.empty() && !b.empty() )
		{
			
			int tnb = 0 , tng = 0;	
			for(int i=0;i<bf;i++)
			{
				if( g.empty() )		break;			
				tmpg[tng++] = g.top(); g.pop();
			}
			
			for(int i=0;i<bf;i++)
			{
				if( b.empty() )		break;		
				tmpb[tnb++] = b.top(); b.pop();
			}
		
			int cnt = 0 , tcnt = 0;
			if( tng > tnb )
			{
				cnt = tng - tnb;
				tcnt = tnb;
				for(int i=0;i<cnt;i++)
					g.push( tmpg[--tng] );
			}
			
			else if( tng < tnb )
			{				
				cnt = tnb - tng;
				tcnt = tng;
				for(int i=0;i<cnt;i++)
					b.push( tmpb[--tnb] );	
			}
			
			else	tcnt = tnb;
			
			for(int i=0;i<tcnt;i++)
			{
				int x = tmpg[i] , y = tmpb[i];
				if( x > y ) 	g.push( x - y ) ;
				if( x < y )	b.push( y - x ) ;
			}			
		}
		
		if( g.size() )
		{
			printf("green wins\n");
			while( !g.empty() )
			{
				printf("%d\n",g.top()); 
				g.pop();
			}
		}
				
		else if( b.size() )
		{
			printf("blue wins\n");
			while( !b.empty() )
			{
				printf("%d\n",b.top()); 
				b.pop();			
			}
		}	
		
		else
			printf("green and blue died\n");
	
		enter = 1;
	}
	
	return 0;	
}
