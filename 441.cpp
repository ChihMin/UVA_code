#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
                                                                                
using namespace std;

int step,n,s[1000],list[1000];
bool linked[1000][1000],v1[10000],v2[100][10000];

bool cmp(int x,int y){
	return x<y;	
}

void dfs(int now,int step){
	if(step==6){
		//sort(list,list+6,cmp);	
		for(int i=0;i<5;i++)
			printf("%d ",list[i]);

		printf("%d\n",list[5]);
	}
	
	else{
		for(int i=0;i<n;i++){
			if(!v1[i]&&!v2[now][i]&&linked[now][i]){
				v1[i]=v2[now][i]=v2[i][now]=1;
				list[step]=s[i];
				dfs(i,step+1);
				v1[i]=v2[now][i]=v2[i][now]=0;	
			}	
		}	
	}	
}

int main(){
	
int d=1;
	
while(scanf("%d",&n)!=EOF){
 	
 	if(n==0)	break;
 	
		 
	for(int i=0;i<n;i++)	scanf("%d",&s[i]);
	
	if(!d)	printf("\n");
	if(d==1)	d=0;
 	
 	for(int i=0;i<n;i++)
 		for(int j=i+1;j<n;j++)
 			linked[i][j]=1;
 	
 	for(int i=0;i<=n-6;++i){
        for(int j=0;j<n;j++)  v1[j]=0;
        for(int j=0;j<n;j++)  list[j]=0;
        list[0]=s[i];
        v1[i]=1;
        dfs(i,1);
    }
    
    //printf("\n");
}	
	//system("pause");
	return 0;	
}
