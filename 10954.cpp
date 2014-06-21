#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue < int , vector< int > , greater< int > > PQ;

int main()
{
	int n;
	while( ~scanf("%d",&n) && n )
	{
		long long int x;
		while( n-- )
		{
			scanf("%lld",&x);
			PQ.push( x );
		}
		
		long long int sum = 0;
		while( !PQ.empty() )
		{
			//printf("%d\n",PQ.top());	PQ.pop();	
			long long int a = PQ.top(); PQ.pop();
			long long int b = PQ.top(); PQ.pop();
		
			sum += ( a + b );
			if( !PQ.empty() )	PQ.push( a + b );	
		}	
		printf("%lld\n",sum);
	}
	
	
	return 0;	
}
