#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	
	while( t-- )
	{
		int a , b;
		scanf("%d%d",&a,&b);
		
		int max = 0 , num = -1;
		for(int i=a;i<=b;i++)
		{
			int x = i;
			int cnt = 0;
			for(int j=1;j<=(int)sqrt( x );++j)
			{
				if( x % j == 0 )
				{
					if( x/j != j )
						cnt += 2;
					
					else
						cnt += 1;	
				}	
			}		
			if( cnt > max )	max = cnt , num = i;
		}	 
		
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,num,max);
	}
	
	
	
	return 0;	
}
