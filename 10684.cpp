#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 20000

using namespace std;

int a[N];

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int n;
	while(scanf("%d",&n) != EOF && n!=0)
	{
		for(int i=0;i<n;i++)	scanf("%d",&a[i]);
		
		int ans = (int)-1e5;
		int s = 0;
	
		for(int i=0;i<n;i++)
		{
			if(s>=0)	s += a[i];
			else s = a[i];
			ans = max(s , ans);	
		}
		ans > 0 ? printf("The maximum winning streak is %d.\n",ans) : printf("Losing streak.\n");
	}
	
	return 0;	
}
