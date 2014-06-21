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
	int temp=k;		//temp�]�^��					
	while(temp--)	now=list[now].next;		//���{�b���I���V�Q�����H����m 	
	//----------�H�U�O���{�b�o�Ӧ�m������k�䤬���䵲-------------------- 
	int nownext=list[now].next;		//�{�b��m������ 
	int nowlast=list[now].last;		//�{�b��m���k�� 
	list[nownext].last=list[now].last;	//�{�b��m�����䪺�k��  =  �{�b��m���k�� 
	list[nowlast].next=list[now].next;	//�{�b��m���k�䪺����  =  �{�b��m������ 	
	//----------------------------------------------------------------------
	int next=now;							
	while(k--)	next=list[next].next;	//�M��n�I�����H 
	//----------------------------------------------------------------------
	list[now].value=list[next].value;	//�I���̯���Q���̪���m 
	list[next].value=0;
	//---------------�H�U���٭�Q���̦�m������M�k��-----------------------
	list[nowlast].next=now;
	list[nownext].last=now;
	//---------------�H�U�ʧ@�����L�I���̪���m-----------------------------
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
