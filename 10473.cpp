#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 100000

using namespace std;

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	char s[N];
	while(scanf("%s",s)!=EOF&&s[0]!='-')
	{
		int len=strlen(s);	
		if(s[1]!='x')	//process the 10 to 16
		{
			char ans[N];
			char st[N];
			ans[0]='0';	ans[1]='x';
			
			int sum=0;
			int els=0;
			int cnt=2;
			
			for(int i=0;i<len;++i)	sum=sum*10+s[i]-48;
			
		//	printf("%d ",sum);
			
			while(sum!=0)
			{
				els=sum%16;
				if(els<=9&&els>=0)	st[cnt++]=els+48;				
				else
				{
					if(els==10)	st[cnt++]='A';	
					if(els==11)	st[cnt++]='B';
					if(els==12)	st[cnt++]='C';
					if(els==13)	st[cnt++]='D';
					if(els==14)	st[cnt++]='E';
					if(els==15)	st[cnt++]='F';
				}
				sum=sum/16;	
			}		
			
			for(int k=cnt-1,j=2;k>=0;k--,j++)	ans[j]=st[k];
			ans[cnt]='\0';	
			printf("%s\n",ans);
		}
		
		else
		{
			long long int ans=0;
			for(int i=2;i<len;++i)
			{
				
				if(s[i]<='9')	ans=ans*16+(long long int)(s[i]-48);
				else
				{
					if(s[i]=='A'||s[i]=='a')	ans=ans*16+10;
					if(s[i]=='B'||s[i]=='b')	ans=ans*16+11;
					if(s[i]=='C'||s[i]=='c')	ans=ans*16+12;
					if(s[i]=='D'||s[i]=='d')	ans=ans*16+13;
					if(s[i]=='E'||s[i]=='e')	ans=ans*16+14;
					if(s[i]=='F'||s[i]=='f')	ans=ans*16+15;	
				}	
			}
			printf("%lld\n",ans);		
		}	
	
	}
	return 0;
}	
