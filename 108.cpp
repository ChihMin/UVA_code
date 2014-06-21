#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 5000

using namespace std;

int n;
int s[N];
int a[N][N];

void initialize()
{
	for(int i=0;i<n;i++)	s[i]=0;	
}

int max1D(int x[])
{
	int ans = (int)-1e9;
	int sum=0;
	
	for(int i=0;i<n;i++)
	{
		if(sum>=0)	sum += x[i];
		else sum = x[i];	
		ans = max(ans,sum);	
	}	
	return ans;
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	while(scanf("%d",&n)!=EOF)
	{
		int ans = (int)-1e9;
		
		for(int i=0;i<n;i++)	for(int j=0;j<n;j++)	scanf("%d",&a[i][j]);	
		
		for(int i=0;i<n;i++)
		{
			initialize();
			for(int j=i;j<n;j++)
			{
				for(int k=0;k<n;k++)	
					s[k] += a[j][k];	
				ans=max(ans , max1D(s));
			}
		}	
		printf("%d\n",ans);
	}
	return 0;	
}
