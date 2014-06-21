#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node{
	int a, b;	
} 

list[20000000];

int main()
{
	int cnt = 0;
	for(int i=1;;++i)
	{
		for(int j=1,k=i;j<=i;++j,--k)
		{
			if( cnt > 10000000 )
				break;
			if( i % 2 )
			{
				list[++cnt].a = k;
				list[cnt].b = j;	
			}
			
			else
			{
				list[++cnt].a = j;
				list[cnt].b = k;	
			}
		}
		if( cnt > 10000000) break;
	}
	
	int n;
	while( ~scanf("%d",&n) )
		printf("TERM %d IS %d/%d\n",n,list[n].a,list[n].b);
	
	return 0;	
}
