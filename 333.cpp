#include <cstdio> 
#include <cstdlib>
#include <cstring>
#define N 1000

using namespace std;

char str[N],gar;
int s1[N],s2[N];

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int n;
	gets(str);
	sscanf(str,"%d",&n);
		
	while(n--)
	{
		gets(str);
		sscanf("%s",str);
		
		int num[N];
		bool space=0,ok=0;
		int count=0;	
		int head=0,back=0;
		
		//if(str[0]=='\0')	ok=1;
		
		for(int i=0;i<(int)strlen(str);i++)	if(str[i]!=32 && str[i]!='\t'){head=i;	break;}		//處理輸出字串 
		for(int i=(int)strlen(str)-1;i>=0;i--)	if(str[i]!=32 && str[i]!='\t'){back=i;	break;}
		
		for(int i=0;i<=back;i++)
		{	
			if(count==0)	space=0;
			if(count>10){	ok=1;	break;}
			if(!space && (str[i]==32 || str[i]=='\t'))	continue;	//若沒有找到頭，而且又是空白建，就讓它繼續找
			if(str[i]=='-')	continue;	//若是 '-'  就讓他continue 
				
			if(str[i]>='0' && str[i]<='9')
			{
				if(count==0){s1[0]=s2[0]=str[i]-'0';}	
				space=1; 
				num[count++]=str[i]-48; 
				continue;
			}
			if(str[i]=='X' && count==9)
			{
				space=1;	
				num[count++]=10; 
				continue;
			}	
			if(space && (str[i]==32 || str[i]=='\t')){ok=1;	break;}  //若已經找到開頭，而且又掃到空白，就為非法 		
			else if(space){	ok=1;	break;}		
		}		
		
		if(!ok)
		{
			if(count==10)
			{
				for(int i=1;i<10;i++)
				{
					s1[i]=s1[i-1]+num[i];	
					s2[i]=s2[i-1]+s1[i];
				}
				if(s2[9]%11!=0)	ok=1;	
				//printf("%d     		",s2[9]);
			}
			else ok=1;
		}
		
		if(!ok)
		{
			for(int i=head;i<=back;i++)	printf("%c",str[i]);
			printf(" is correct.\n");	 
		}
		
		else
		{ 
			if((str[0]=='\0' && back==head) || str[head]==32 || str[head]=='\t')	printf(" is incorrect.\n");
			else
			{
				for(int i=head;i<=back;i++)	printf("%c",str[i]);
				printf(" is incorrect.\n");
			}
		}
	}
	//system("pause");
	return 0;	
}
