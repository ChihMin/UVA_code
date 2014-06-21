#include <cstdio>
#include <cstdlib>
#define N 500

using namespace std;

long long int bit[32] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,
16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,
16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int a , x;
	while(~scanf("%d",&a))
	{
		bool list[32] = {0} , ans[32] = {0};
		
		x = a; 
		if(a < 0)	x=~a;
		
		for(int i=32-1;i>=0;i--)
		{
			if(bit[i] > x)	continue;
			list[i] = 1;
			x -= bit[i];	
		}
		
		for(int i=0,j=24;i<8;i++,j++)
			ans[j] = list[i];
			
		for(int i=8,j=16;i<16;i++,j++)
			ans[j] = list[i];
			
		for(int i=16,j=8;i<24;i++,j++)
			ans[j] = list[i];
		
		for(int i=24,j=0;i<32;i++,j++)
			ans[j] = list[i];	
		
		int sum = 0;
		
		for(int i=31;i>=0;i--)
			if(ans[i])	sum += bit[i];
		
		printf("%d converts to %d\n",a,a < 0 ? ~sum : sum);
	}
	return 0;	
}
