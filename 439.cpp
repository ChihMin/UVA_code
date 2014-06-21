#include <cstdio>
#include <cstring>
#define N 800

using namespace std;

bool visit[N][N];
int qx[N],qy[N];
int step[N][N];
int back,head;

void push(int x,int y)
{
	qx[back]=x;
	qy[back++]=y;
	visit[x][y]=1;
}

void pop()
{
	head++;	
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	char a1,b1,gar,a2,b2;
	while(scanf("%c%c%c%c%c%c",&a1,&b1,&gar,&a2,&b2,&gar)!=EOF)
	{		
		int x1,y1,x2,y2;
		x1=a1-96;	y1=b1-48;
		x2=a2-96;	y2=b2-48; 	
		
		head=back=0;
		for(int i=1;i<=8;i++)	for(int j=1;j<=8;j++)	visit[i][j]=step[i][j]=0;
		
		push(x1,y1);
		while(head<back)
		{
			bool ok=1;
			
			int nowx,nowy;
			nowx=qx[head];	nowy=qy[head];
			if(nowx==x2 && nowy==y2)	break;
			
			
			int d[8][2]={{2,1},{1,2},{1,-2},{2,-1},{-1,-2},{-2,-1},{-1,2},{-2,1}};
			for(int i=0;i<8;i++)
			{
				int x,y;
				
				x=nowx+d[i][0];
				y=nowy+d[i][1];	
				
				if((x>=1 && x<=8) && (y>=1 && y<=8) && !visit[x][y])
				{	
					push(x,y);	
					step[x][y]=step[nowx][nowy]+1;
					if(x==x2 && y==y2){ok=0;	break;}				
				}
			}
			
			if(!ok)	break;
			head++;
		}
	
		printf("To get from %c%c to %c%c takes %d knight moves.\n",a1,b1,a2,b2,step[x2][y2]);
	}
	return 0;	
}
