#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int pcnt;
int prime[1000] , cnt[1000];

void ini()
{
	for(int i=2;i<=100;i++)
	{
		bool ok = 1;
		for(int j=2;j<i;++j)
			if( !(i % j) )
			{
				ok = 0;	
				break;
			}
		
		if( ok )
			prime[pcnt++] = i;		
	}	
}

int main()
{
	ini();
	
//	for(int i=0;i<pcnt;i++)
//		printf("%d ",prime[i]);
//		printf("\n");
	
	int n;
	while( ~scanf("%d",&n) && n != 0 )
	{
		memset( cnt , 0 ,sizeof(cnt) );
		for(int i=2;i<=n;++i)
		{
			
		//	printf("%d ---> ",i);
			
			int tmp = i;
			for(int j=0;prime[j] <= tmp && j < pcnt;++j)
			{
				if( !( tmp % prime[j] ) )
				{	
				//	printf("p%d&",prime[j]);
					tmp /= prime[j];
				//	printf("%d  ",tmp);
					cnt[prime[j]]++;
					j--;
				}
			}	
		//	printf("\n");
		}
		
	
		printf("%3d! =",n);
		
	//	int tcnt = 0;
		for(int i=0;prime[i] <= n && i < pcnt;i++)
		{
			if( !(i % 15) & i != 0 )	printf("\n      ");
			printf("%3d",cnt[prime[i]]);
		}
		printf("\n");
	}	
	return 0;	
}
