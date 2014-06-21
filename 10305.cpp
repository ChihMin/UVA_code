#include <cstdio>
#include <cstdlib>
#define N 500

using namespace std;

int m,n;
int ref[N];
bool adj[N][N];

int main()
{
	while(~scanf("%d%d",&n,&m) && (n!=0 || m!=0))
	{
		for(int i=0;i<=n;i++)	//initialzie
		{
			for(int j=0;j<=n;j++)
				adj[i][j] = 0;	
			ref[i] = 0;
		}
		
		for(int i=1;i<=m;i++)
		{
			int a,b;	
			scanf("%d%d",&a,&b);
			
			adj[a][b] = 1;
			ref[b]++;
		}
		
		bool space = 1;
		for(int i=0;i<n;i++)
		{
			int s = 1;	
			while(s<=n && ref[s]!=0) ++s;
			
			if(s == n+1)	break;
			
			ref[s] = -1;
			
			if(!space)	printf(" ");
			space = 0;
			
			printf("%d",s);
		
			for(int j=0;j<=n;j++)
				if(adj[s][j])
					ref[j]--;
		}
		printf("\n");
	}
	
	return 0;	
}
