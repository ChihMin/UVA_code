#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 100

using namespace std;

struct Node{char x , y;} linked[N];

bool cvisit[N] , clink[N][N] , visit[N];
char str[N] , s[N] , ans[N];
int w[N][N] , list[N];
int back , link_back , ansmin;

void dfs(int step)
{
	if(step == back)
	{
		int locate[N];
		
		for(int i=0;i<back;i++)
		{
			locate[(int)s[list[i]]] = i;
			//printf("%c ",s[list[i]]);
		}
		//printf("\n");
		
		int d , pmax = 0;
		for(int i=0;i<link_back;i++)
		{
			int a = locate[(int)linked[i].x] , b = locate[(int)linked[i].y];	
			d = a-b >0 ? a-b : b-a;
			//printf("%d,",d);
			pmax = max( pmax , d );
		}
		//printf("\n");
		
		if(pmax < ansmin)
		{
			for(int i=0;i<8;i++)
				ans[i] = s[list[i]];
			
			ansmin = pmax;	
		}
		
		
	}
	
	else
		for(int i=0;i<back;i++)
			if(!visit[i])
			{
				list[step] = i;	
				visit[i] = 1;
				dfs(step + 1);
				visit[i] =0;
			}	
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);

	while(gets(str) && str[0] != '#')
	{
		int len = strlen(str);	
		back =  link_back = 0 , ansmin = (int)1e5;
		
		memset(cvisit , 0 , sizeof(cvisit));
		memset(clink , 0 ,sizeof(clink));
		
		bool hp = 0;
		char c = 0;
		for(int i=0;i<len;i++)
		{
		 	if(str[i] == ':')
		 	{
				hp = 1;
				continue;	
			}
			
			if(str[i] == ';')
			{
				hp = 0;
				continue;	
			}
			
			if(!hp)	
			{
				if(!cvisit[(int)str[i]])
				{
					cvisit[(int)str[i]] = 1;
					s[back++] = str[i];
				}
				c = str[i];
			}
			
			if(hp)
			{
				if(!cvisit[(int)str[i]])
				{
					cvisit[(int)str[i]] = 1;
					s[back++] = str[i];
				}
				if(!clink[(int)c][(int)str[i]])
				{
					linked[link_back].x = c , linked[link_back++].y = str[i];
					clink[(int)c][(int)str[i]] = 1;
				}
			}	
		}
		
		sort(s , s+back);
		
		for(int i=0;i<back;i++)
		{
			visit[i] = 1;
			list[0] = i;
			dfs(1);
			visit[i] = 0;	
		}
		for(int i=0;i<back;i++)
			printf("%c ",ans[i]);
		printf("-> %d\n",ansmin);
	}
	
	return 0;	
}
