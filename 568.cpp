#include <cstdio>
#include <cstdlib>
#define N 20000

using namespace std;

int s[N];
int tmp[N];
int ans[N];

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		tmp[0]=tmp[1]=1;
		//long long int sum=1;
		
		for(int i=1;i<=10000;i++)
		{
			tmp[i]=tmp[i-1]*i;
			//sum*=i;
			
			while(tmp[i]%10==0){	tmp[i]=tmp[i]/10;}
			tmp[i]%=100000;
			ans[i]=tmp[i];
		}	
		printf("%5d -> %d\n",n,ans[n]%10);
		//printf("sum:%I64d\n",sum);
	}
	
	return 0;	
}
