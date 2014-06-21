#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

bool vis[1000000000];

bool cmp1( char a , char b )
{
	return a > b;	
}

bool cmp2( char a , char b )
{
	return a < b ;	
}

stack <int> st;

int main()
{
	int x ;
	while( ~scanf("%d",&x) && x )
	{
		while( !st.empty() )
		{
			vis[ st.top() ] = 0; st.pop();
		}
		
		//memset( hash , 0 , sizeof( hash ));
		
		int cnt = 0;	
		int now = x;
		int a , b;
		
		printf("Original number was %d\n",x);
		
		while( 1 )
		{
			char s1[100] , s2[100];
			sprintf( s1 , "%d" , now );
			sprintf( s2 , "%d" , now );
			
			int len = (int)strlen(s1);
			
			sort( s1 , s1 + len , cmp1 );
			sort( s2 , s2 + len , cmp2 );
			
			sscanf(s1,"%d",&a);
			sscanf(s2,"%d",&b);
		
		//	printf("%d %d\n",a,b);
			
			now = a - b;
			++cnt;
			
			printf("%d - %d = %d\n",a,b,now);
			
			if( vis[now] )
			{
				printf("Chain length %d\n\n",cnt);
				break;	
			}
			
			else
			{
				vis[now] = 1;
				st.push( now );
			}
		}
	
		
	}
	
	
	return 0;	
}
