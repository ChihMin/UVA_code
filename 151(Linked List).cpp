#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node
{
	int next , last;	
} q[200];

int n , m;
bool ok[200];

void ini(  )
{
	for(int i=0;i<n;i++)
	{
		ok[i] = 0;
		q[i].next = (i + 1) % n;
		q[(i+1)%n].last = i;
	}
}

int p;
void go( int now , int step )
{
	int next = q[now].next;
	int last = q[now].last;
	
	if( step == m )
	{
		ok[now] = 1;
		if( last == next )
			return ;
		
	//	printf("%d ",now+1);
		
		q[next].last = last;
		q[last].next = next;
		
		return go( next , 1 );
	}
	
	else		
		return go( q[now].next , step + 1 ) ;	
	
}	

int main()
{
	while( ~scanf("%d",&n) && n )
	{
		//	for(int i=0;i<n;i++)
		for(m=1;m<n;++m)
		{
			ini( );			
			go( 0 , m );
			//printf("\n");
			
			if( !ok[12] )
			{	
				printf("%d\n",m);
				break;
			}
		}
		/*
		for(int i=0;i<n;i++)
		{
			printf("%d next:%d  last:%d\n",i,q[i].next,q[i].last);	
		}*/
		
	}
	
	return 0;	
}
