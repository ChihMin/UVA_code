#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 5000

using namespace std;

char list[N];
char s[N];
int len;
bool visit[N];


bool charcmp(char a,char b)
{
    int ta,tb;
    if( a>='a' ) ta=a-'a';
    else ta=a-'A';
    if( b>='a' ) tb=b-'a';
    else tb=b-'A';
    if( ta!=tb ) return ta<tb;
    else return a<b;
}

void dfs(int now,int step)
{
	if(step==len)
	{
		list[len]='\0';
		printf("%s\n",list);
	}	
	
	else
		for(int i=0;i<len;i++)
			if(!visit[i] && list[step]!=s[i])
			{
				list[step]=s[i];
				visit[i]=1;
				dfs(i,step+1);	
				visit[i]=list[step+1]=0;
			}
}

int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%s",s);
			len=strlen(s);
			sort(s,s+len,charcmp);
			
			list[0]=0;
			for(int i=0;i<len;i++)
			{
				for(int j=0,k=1;j<len;j++,k++)	visit[j]=list[k]=0;	
				visit[i]=1;
				
				if(list[0]!=s[i])
				{
					list[0]=s[i];	
					dfs(i,1);
				}				
			}	
		}	
	}
	
	return 0;		
}
