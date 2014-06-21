#include <cstdio>
#include <cstdlib>
#define N 100000

using namespace std;

long long int pow(int x,int t)
{
	long long int sum=1;
	while(t--)	sum=sum*x;
	return sum;	
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	long long int height,last;
	while(scanf("%lld %lld",&height,&last)!=EOF && height!=0 && last!=0)
	{
		bool ok=1;
		int n,count,ans[N];
		ans[0]=1;
		
		long long int sum=0,qk=0;
		
		
		if(height!=1 || last!=1)
		{
			for(int i=1;;i++)
			{
				if(!ok)	break;
				for(int j=1;pow(i,j)<=last && pow(i+1,j)<=height;j++)
				{
					ans[j]=pow(i,j);
					if(pow(i+1,j)==height && pow(i,j)==last)
					{
						ok=0;	n=i;	count=j;	break;
					}
				}
			}
		
			for(int i=0;i<count;i++)
			{
				qk+=ans[i];
				sum+=ans[i]*height;		
				height/=(n+1);
			}
		}
		printf("%lld %lld\n",qk,sum+last);
	}				
	return 0;	
}
