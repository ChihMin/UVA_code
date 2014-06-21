#include <cstdio>
#include <cstdlib>
#define N 5000 

using namespace std;


struct Node
{
	int last;
	int next;	
	int value;
}; 

bool ok[N];
Node list[N];

void format(int n,int k)
{
	for(int i=1;i<=n;i++)
	{	
		list[i].value=i;
		list[i].next=i+1;
		if(list[i].next>n)	list[i].next%=n;	
		list[i].last=i-1;
		if(list[i].last<1)	list[i].last+=n;
	}
}

int kill(int now,int k)
{
	//int last=now;
	//---------------------------------------------------------------------
	int temp=k;		//temp跑回圈					
	while(temp--)	now=list[now].next;		//讓現在的點指向被殺的人的位置 	
	//----------以下是讓現在這個位置的左邊右邊互相鍵結-------------------- 
	int nownext=list[now].next;		//現在位置的左邊 
	int nowlast=list[now].last;		//現在位置的右邊 
	list[nownext].last=list[now].last;	//現在位置的左邊的右邊  =  現在位置的右邊 
	list[nowlast].next=list[now].next;	//現在位置的右邊的左邊  =  現在位置的左邊 	
	//----------------------------------------------------------------------
	int next=now;							
	while(k--)	next=list[next].next;	//尋找要埋葬的人 
	//----------------------------------------------------------------------
	list[now].value=list[next].value;	//埋葬者站到被殺者的位置 
	list[next].value=0;
	//---------------以下為還原被殺者位置的左邊和右邊-----------------------
	list[nowlast].next=now;
	list[nownext].last=now;
	//---------------以下動作為跳過埋葬者的位置-----------------------------
	int nextlast=list[next].last;		 
	list[nextlast].next=list[next].next;

	int nextnext=list[next].next;
	list[nextnext].last=list[next].last;
	//----------------------------------------------------------------------
	return now;
}

int main()
{
	//freopen("a.txt","r",stdin);
   	//freopen("b.txt","w",stdout);
	
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF && (n!=0&&k!=0))
	{
		
		if(n==1)	printf("1\n");
		else
		{	
			for(int i=1;i<=n;i++)
			{
				format(n,k);
				int now;
			
				if(i==1)	now=n;
				else now=i-1;
			
				int cnt=n-1;	
				while(cnt--)	now=kill(now,k);
				
				if(list[now].value==1){printf("%d\n",i);	break;}
			}
		}
	}
	return 0;	
}
