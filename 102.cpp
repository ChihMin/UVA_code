#include <cstdio>
#define N 4

using namespace std;

struct Node
{
	long long int b;	long long int c;	long long int g; 	
};

int main()
{	
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	Node bucket[N];
	
	while(scanf("%lld%lld%lld",&bucket[1].b,&bucket[1].g,&bucket[1].c)!=EOF)
	{
		long long int sum,min=1000000000;
		char ans[N];
		for(int i=2;i<=3;i++)	scanf("%lld%lld%lld",&bucket[i].b,&bucket[i].g,&bucket[i].c);	
		
		//-----------------BCG----------------------------¡õ------------------------
		sum=bucket[1].c+bucket[1].g+bucket[2].b+bucket[2].g+bucket[3].b+bucket[3].c;
		if(sum<min)
		{
			min=sum;	
			ans[0]='B';	ans[1]='C';	ans[2]='G';	ans[3]='\0';
		}
		//-----------------BGC-------------------------------------------------------	 
		sum=bucket[1].c+bucket[1].g+bucket[2].b+bucket[2].c+bucket[3].b+bucket[3].g;
		if(sum<min)
		{
			min=sum;	
			ans[0]='B';	ans[1]='G';	ans[2]='C';	ans[3]='\0';
		}	
		//---------------CBG---------------------------------------------------------
		sum=bucket[1].b+bucket[1].g+bucket[2].g+bucket[2].c+bucket[3].b+bucket[3].c;
		if(sum<min)
		{
			min=sum;	
			ans[0]='C';	ans[1]='B';	ans[2]='G';	ans[3]='\0';
		}
		//-------------------CGB-----------------------------------------------
		sum=bucket[1].b+bucket[1].g+bucket[2].b+bucket[2].c+bucket[3].g+bucket[3].c;
		if(sum<min)
		{
			min=sum;	
			ans[0]='C';	ans[1]='G';	ans[2]='B';	ans[3]='\0';
		}
		//------------------GBC---------------------------------------------------
		sum=bucket[1].b+bucket[1].c+bucket[2].g+bucket[2].c+bucket[3].g+bucket[3].b;
		if(sum<min)
		{
			min=sum;	
			ans[0]='G';	ans[1]='B';	ans[2]='C';	ans[3]='\0';
		}
		//--------------------GCB----------------------------------------------------
		sum=bucket[1].b+bucket[1].c+bucket[2].g+bucket[2].b+bucket[3].g+bucket[3].c;
		if(sum<min)
		{
			min=sum;	
			ans[0]='G';	ans[1]='C';	ans[2]='B';	ans[3]='\0';
		}
		printf("%s %lld\n",ans,min);
	}
		
	return 0;	
}
