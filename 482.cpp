#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int s[1000];
char v[1000][100];

int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	
	int t , enter = 1;
	char gar;
	
	scanf("%d",&t);
	while(t--)
	{
		int n = 0;
		while(~scanf("%d%c",&s[n],&gar))
		{
			n++;
			if(gar == '\n')	break;
		}
		
		for(int i=0;i<n;i++)
			scanf("%s",v[s[i]]);
			 
		sort(s,s+n);	 	
			 	
		if(!enter)	printf("\n");	 	
		enter = 0;	 	
			 	
		for(int i=0;i<n;i++)
			printf("%s\n",v[s[i]]);
		
	}
	
	return 0;	
}
