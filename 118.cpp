#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 200

using namespace std;

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF)
	{		
		int nowx,nowy;
		char to;
		char s[N];
		bool drop[N][N];
		
		for(int i=0;i<=x;i++)	for(int j=0;j<=y;j++)	drop[i][j]=0;
		
		while(scanf("%d %d %c ",&nowx,&nowy,&to)!=EOF)
		{
			if(to=='N')	to=0;	if(to=='E')	to=1;	if(to=='S')	to=2;	if(to=='W')	to=3;
			
			bool find=0;
			
			scanf("%s",s);
			for(int i=0;i<strlen(s);i++)
			{
				//printf("nowx:%d nowy:%d to:%d\n",nowx,nowy,to);
				
				int nextx,nexty;
				
				if(s[i]=='R'){to+=1;	to%=4;}
				if(s[i]=='L'){to-=1;	if(to<0)	to+=4;}
				if(s[i]=='F')
				{
						
					//printf("nextx:%d nexty:%d\n",nextx,nexty);
					if(to==0){nextx=nowx;	nexty=nowy+1;}	
					if(to==1){nexty=nowy;	nextx=nowx+1;}
					if(to==2){nextx=nowx;	nexty=nowy-1;}
					if(to==3){nexty=nowy;	nextx=nowx-1;}		
				
					if((nextx>x || nextx<0 || nexty>y || nexty<0) && !drop[nowx][nowy])	
					{
						drop[nowx][nowy]=1;	
					
						char ansc;
						if(to==0)	ansc='N';	
						if(to==1)	ansc='E';
						if(to==2)	ansc='S';
						if(to==3)	ansc='W';
								
						printf("%d %d %c LOST\n",nowx,nowy,ansc);
						find=1;
						break;
					}					
					if((nextx>x || nextx<0 || nexty>y || nexty<0) && drop[nowx][nowy])	continue;	
					nowx=nextx;	nowy=nexty;	
				}
			}
			char ansc;
			if(to==0)	ansc='N';	
			if(to==1)	ansc='E';
			if(to==2)	ansc='S';
			if(to==3)	ansc='W';
			
			if(!find)	printf("%d %d %c\n",nowx,nowy,ansc);
		}	
	}
	return 0;	
}
