#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 500

using namespace std;

struct Node{int x;	int y;};

int stack[N][N];	//堆疊 
int back[N];	//尾巴 
Node sit[N];	//座標 

char judge1[N][N]={{'m','o','v','e','\0'},{'p','i','l','e','\0'},{'q','u','i','t','\0'}}; 	//判斷用 
char judge2[N][N]={{'o','n','t','o','\0'},{'o','v','e','r','\0'}};	//第二次判斷用字串 

void push(int a,int b)
{
	stack[sit[b].x][back[sit[b].x]]=a;	
	sit[a].x=sit[b].x;	//let the a team become the b team	
	sit[a].y=back[sit[b].x]++;		
}

void pop(int num)
{
	back[sit[num].x]--;	
}

void reset(int num)	
{
	stack[num][0]=num;	
	pop(num);	//pop the number
	sit[num].x=num;	//let the num has the x y seat
	sit[num].y=0;
	back[num]=1;	//push only one number
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			back[i]=1;	sit[i].x=i;	sit[i].y=0;	stack[i][0]=i;	//format	
		}
		
		char s[N],t[N];
		scanf("%s",s);
		while(strcmp(s,judge1[2])!=0)
		{
			int a,b;
			scanf("%d %s %d",&a,t,&b);
			
			if(sit[a].x!=sit[b].x){
				if(strcmp(s,judge1[0])==0 && strcmp(t,judge2[0])==0)	//move a onto b
				{	
					for(int i=back[sit[a].x]-1;i>sit[a].y;i--)	reset(stack[sit[a].x][i]);
					for(int i=back[sit[b].x]-1;i>sit[b].y;i--)	reset(stack[sit[b].x][i]);
					pop(a);
					push(a,b);
				}
		
				if(strcmp(s,judge1[0])==0 && strcmp(t,judge2[1])==0)	//move a over b
				{
					for(int i=back[sit[a].x]-1;i>sit[a].y;i--)	reset(stack[sit[a].x][i]);
					pop(a);
					push(a,b);
				}
		
				if(strcmp(s,judge1[1])==0 && strcmp(t,judge2[0])==0)	//pile a onto b
				{
					for(int i=back[sit[b].x]-1;i>sit[b].y;i--)	reset(stack[sit[b].x][i]);
					int count=0;
					int ans[N];
					for(int i=back[sit[a].x]-1;i>=sit[a].y;i--)
					{	
						pop(stack[sit[a].x][i]);
						ans[count++]=stack[sit[a].x][i];
					}
					for(int i=count-1;i>=0;i--)	push(ans[i],b);			
				}
		
				if(strcmp(s,judge1[1])==0 && strcmp(t,judge2[1])==0)	//pile a over b
				{
					int count=0;
					int ans[N];
					for(int i=back[sit[a].x]-1;i>=sit[a].y;i--)
					{	
						pop(stack[sit[a].x][i]);
						ans[count++]=stack[sit[a].x][i];
					}
					for(int i=count-1;i>=0;i--)	push(ans[i],b);
				}
			}	
			scanf("%s",s);
		}
		
		for(int i=0;i<n;i++)
		{
			printf("%d:",i);
			for(int j=0;j<back[i];j++)	
				printf(" %d",stack[i][j]);		
			printf("\n");
		}
	}
	system("pause");
	return 0;	
}
