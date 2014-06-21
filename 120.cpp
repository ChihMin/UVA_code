#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 5000

using namespace std;

int target[N];
int stack[N];
int ans[N];
int back;
int head;

bool cmp(int x,int y)
{
	return x>y;	
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	target[0]=10000;
	
	char input[N];
	while(gets(input))
	{	
		sscanf("%s",input);
		back=0;
		for(int i=0,j=1;i<strlen(input);i=i+2,j++)	target[++back]=stack[back]=input[i]-48;
		
		sort(target,target+(back+1),cmp);
		int count=0;
		for(int j=1;j<=back;j++)	ans[++count]=stack[j];
		for(int j=count,k=1;j>=1;j--,k++)	stack[k]=ans[j];
		
		printf("%c",input[0]);
		for(int i=2;i<strlen(input);i=i+2)	printf(" %c",input[i]);		
		printf("\n");
		
		head=1;
		while(head<=back)
		{
			if(target[head]==stack[head])	head++;	
			else
			{
				for(int i=head;i<=back;i++)
				{
					count=0;
					if(target[head]==stack[i] && i!=back)
					{
						printf("%d ",i);
						for(int j=i;j<=back;j++)	ans[++count]=stack[j];
						for(int j=count,k=i;j>=1||k<=back;j--,k++)	stack[k]=ans[j];	
						break;
					}	
				}	
				count=0;			
				for(int j=1;j<=back;j++)	ans[++count]=stack[j];
				for(int j=count,k=head;j>=head;j--,k++)	stack[k]=ans[j];
				printf("%d ",head++);	
			}
		}		
		printf("0\n");
	}
	return 0;	
}
