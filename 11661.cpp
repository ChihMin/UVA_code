#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	char s[10000];
	int n;
	int d[10000];	
	
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		
		scanf("%s",s);
		int j=0;
		for(int i=0;i<n;++i)	if(s[i]=='R'||s[i]=='Z')	d[j++]=i;
		
		int min=100000;
		for(int i=0;i<j;++i){
			int a=0,b=0,ok=1;
			for(int k=d[i];k>=0;k--){
				if(s[k]=='D'||s[k]=='Z'){ok=0;	break;}
				a++;
			}
			
			if(a<min&&!ok)	min=a;
			
			ok=1;		
			for(int k=d[i];k<n;++k){
				if(s[k]=='D'||s[k]=='Z'){ok=0;	break;}
				b++;	
			}
			if(b<min&&!ok)	min=b;
		}
		printf("%d\n",min);
	}
	
	//system("pause");
	return 0;	
}
