#include <cstdio>
#include <cstring>
#define N 500

using namespace std;

int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	
	int n;
	char gar;
	while(scanf("%d",&n)!=EOF)
	{
		//printf("%d\n\n",n);
		bool enter=1;
		while(n--)
		{
			int line,len;
			char s[N][N];
			
			if(!enter)	printf("\n");
			enter=0;
			
			scanf("%d%d",&line,&len);			
			scanf("%c",&gar);	//Pay attention here.
			for(int i=0;i<line;i++)
			{
				for(int j=0;j<len;j++)
				{
					scanf("%c",&s[i][j]);
					if(s[i][j]<90)	s[i][j]=s[i][j]+32;
				}
				scanf("%c",&gar);
				s[i][len]='\0';
			}
			
		//	printf("%d %d\n",line,len);
		//	for(int i=0;i<line;++i)	printf("%s\n",s[i]);	
		
			int t;
			char test[N];
			
			scanf("%d",&t);
			//printf("%d\n",t);
			while(t--)
			{
				scanf("%s",test);
				
				int tlen=strlen(test);
				
				for(int i=0;i<tlen;++i)	if(test[i]<90)	test[i]=test[i]+32;
				
				//printf("%s\n",test);	
				
				int x=10000,y=10000;
				for(int i=0;i<line;++i)
				{
					for(int j=0;j<len;++j)
					{
						bool ok=0;	
						if(test[0]==s[i][j])
						{
						//---------------------------------------------------------------
							for(int l=j,cnt=0;cnt<tlen;cnt++,l++)			//往右找 
								if(test[cnt]!=s[i][l]){ok=1;	break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;
						//----------------------------------------------------------------
							for(int l=j,cnt=0;cnt<tlen;cnt++,l--)			//往左找 
								if(test[cnt]!=s[i][l]){ok=1; break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;	
						//-----------------------------------------------------------------	
							for(int l=i,cnt=0;cnt<tlen;cnt++,l++)			//往下找 
								if(test[cnt]!=s[l][j]){ok=1;	break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;	
						//--------------------------------------------------------------------
							for(int l=i,cnt=0;cnt<tlen;cnt++,l--)			//往上找 
								if(test[cnt]!=s[l][j]){ok=1;	break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;
						//---------------------------------------------------------------------
							for(int m=i,n=j,cnt=0;cnt<tlen;cnt++,m++,n++)	//往右下	
								if(test[cnt]!=s[m][n]){ok=1;	break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;
						//---------------------------------------------------------------------
							for(int m=i,n=j,cnt=0;cnt<tlen;cnt++,m++,n--)	//往左下	
								if(test[cnt]!=s[m][n]){ok=1;	break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;
						//---------------------------------------------------------------------
							for(int m=i,n=j,cnt=0;cnt<tlen;cnt++,m--,n++)	//往右上	
								if(test[cnt]!=s[m][n]){ok=1;	break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;
						//---------------------------------------------------------------------
							for(int m=i,n=j,cnt=0;cnt<tlen;cnt++,m--,n--)	//往左上	
								if(test[cnt]!=s[m][n]){ok=1;	break;}
							if(!ok)
							{	
								if(i<x && j<y){x=i+1; y=j+1;}
								continue;
							}				
							else ok=0;
						}				
					}
				}
				printf("%d %d\n",x,y);
			}		
		}	
	}	
	return 0;		   
}
