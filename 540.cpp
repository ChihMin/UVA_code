#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define N 2000
#define M 1000000

using namespace std;

int n , appear_cnt;
int team[M] , appear[M];
int q_team[N] , q_mate[N][N];
int team_size , team_front , mate_size[N] , mate_front[N];
bool t_visit[M] , m_visit[M];

void initialize()
{
	for(int i=0;i<appear_cnt;i++)
		team[appear[i]] = m_visit[appear[i]] = t_visit[team[appear[i]]] = 0;
	
	//memset(m_visit , 0 ,sizeof(m_visit));
	//memset(t_visit , 0 ,sizeof(t_visit));
	memset(mate_size , 0 , sizeof(mate_size));
	memset(mate_front , 0 , sizeof(mate_front));	
	
	appear_cnt = team_size = team_front = 0;	
}

void push(int x)
{
	if(!m_visit[x])
	{
		m_visit[x] = 1;			
		
		int group = team[x];	
		
		//printf("x:%d team:%d\n",x,team[x]);
		
		if(!t_visit[group])
		{
			t_visit[group] = 1;
			q_team[(team_size++)%N] = team[x];
		}
		q_mate[group][(mate_size[group]++)%N] = x;	
	}	
}


int pop()
{
	int now = q_team[team_front] ; 
	
	if(mate_size[now] == mate_front[now])
	{
		t_visit[now] = 0;
		now = q_team[(++team_front)%N];		
		//printf("transfer~ohya\n");
	}	
	
	int x = q_mate[now][mate_front[now]];	
	m_visit[x] = 0;
	
	return q_mate[now][(mate_front[now]++)%N];	
}

int main()
{	
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int cnt = 1;
	while(~scanf("%d",&n) && n != 0)
	{
		initialize();
		
		//printf("n:%d\n",n);
		
		for(int i=1;i<=n;i++)
		{		
			int t;
			scanf("%d",&t);
			
			//printf("t:%d\n",t);
			
			while(t--)
			{
				int num;
				scanf("%d",&num);		
				team[num] = i;
				appear[appear_cnt++] = num;
			}			
			/*
			for(int i=0;i<appear_cnt;i++)
				printf("%d ",appear[i]);
			printf("\n");
			*/
		}	
		printf("Scenario #%d\n",cnt++);
		char input[100];
		while(~scanf("%s",input) && input[0] != 'S')
		{
			if(input[0] == 'E')
			{
				int num;
				scanf("%d",&num);
			//	printf("%s %d\n",input,num);	
				push(num);
			}
		
			else
			{
				printf("%d\n",pop());	
				//printf("%s\n",input);	
			}	
		}
		printf("\n");
	}
	
	return 0;	
}
