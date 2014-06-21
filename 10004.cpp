#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 205

using namespace std;

int queue[N];
int head;
int top;
bool linked[N][N];
bool visit[N];
bool color[N];
bool bw=0;

void push(int x)
{
	queue[top++]=x;  //push in queue
	color[x]=bw;  //push the point's color
	visit[x]=1;	//has visited
}

void cmpush(int x)
{
	queue[top++]=x;	
	visit[x]=1;
}

int main(){
	
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		head=0; top=0;
		
		for(int i=0;i<n;++i){	
			for(int j=0;j<n;++j)
				color[i]=linked[i][j]=linked[j][i]=0;	//let the lined fause	
			visit[i]=0;	//let the point true    	
		}
		
		//visit[N]	use the '!'   
		
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			linked[a][b]=linked[b][a]=1;	//let 'a' vs 'b' road true	
		}			
		
		push(0);
		bw=1-bw;
		
		while(head<top)
		{
			for(int i=0;i<n;++i)	
				if(linked[queue[head]][i] && !visit[i])
				{
					printf("%d %d %d\n",queue[head],i,top);	
					push(i);
				}
				
			head++; //pop
			bw=1-bw;   //change the color	
		}
		
		for(int i=0;i<n;++i)	printf("%d ",color[i]);
		printf("\n");
			
		head=top=0;
		bool ok=0;
		for(int i=0;i<n;++i)	visit[i]=0;
		cmpush(0);
			
		while(head<top)
		{
			for(int i=0;i<n;++i)
			{	
				if(linked[queue[head]][i] && !visit[i] && color[queue[head]]!=color[i])	cmpush(i);	
				else if(linked[queue[head]][i] && !visit[i] && color[queue[head]]==color[i]){ok=1;	break;}
			}
			if(ok)	break; 
			head++;
		}
		if(!ok)	printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");			
	}	
	
	return 0;
}

