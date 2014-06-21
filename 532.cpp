#include <cstdio>
#define N 32

using namespace std;

char map[N][N][N];
bool visit[N][N][N];
int step[N][N][N];
int qx[N*N*N],qy[N*N*N],qz[N*N*N];
int back,head;

void push(int x,int y,int z)
{
	qx[back]=x;
	qy[back]=y;
	qz[back++]=z;
	visit[x][y][z]=1;	
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int l,r,c;
	
	while(scanf("%d%d%d",&l,&r,&c)!=EOF)
	{
		back=head=0;
		int ansx,ansy,ansz;
		
		if(l==0 && r==0 && c==0)	break;
		for(int i=0;i<l;i++)	
			for(int j=0;j<r;j++){	
				scanf("%s",map[i][j]);
				for(int k=0;k<c;k++)
				{
					visit[i][j][k]=step[i][j][k]=0;
					if(map[i][j][k]=='#')	visit[i][j][k]=1;
					if(map[i][j][k]=='S')	push(i,j,k);
					if(map[i][j][k]=='E')
					{
						ansx=i;	ansy=j;	ansz=k;	
					}
				}
			}		
		bool ok=1;
		while(head<back)
		{
			int nowx,nowy,nowz;
			nowx=qx[head];	nowy=qy[head];	nowz=qz[head];
			int d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};	
			
			for(int i=0;i<6;i++)
			{
				int x,y,z;
				x=nowx+d[i][0];	y=nowy+d[i][1]; z=nowz+d[i][2];					
				if((x>=0 && x<l) && (y>=0 && y<r) && (z>=0 && z<c) && !visit[x][y][z])
				{
					push(x,y,z);
					step[x][y][z]=step[nowx][nowy][nowz]+1;
					if(map[x][y][z]=='E'){ok=0;	break;}	
				}	
			}
			if(!ok)	break;
			head++;
		}	
		if(!ok)	printf("Escaped in %d minute(s).\n",step[ansx][ansy][ansz]);
		else printf("Trapped!\n");
	}	
	return 0;
}
