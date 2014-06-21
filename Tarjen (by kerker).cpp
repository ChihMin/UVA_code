#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

vector <int> v[105];
int dfs_c,clk[105],ap[105],low[105];
char s[1000005];

int tarjan(int x,int par){
    int lowx = clk[x] = ++dfs_c, child = 0;
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        if(clk[y]==0){
            child++;
            int lowy = tarjan(y,x);
			lowy = low[y];
            lowx = min(lowx,lowy);
            if(lowy>=clk[x]){
                ap[x] = 1;
            }
        }else if(y!=par && clk[y] < clk[x]){
            lowx = min(lowx,clk[y]);
        }
    }
    if(par<0 && child==1)    ap[x] = 0;
    low[x] = lowx;
    return lowx;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    for(int N,a,b;scanf(" %d",&N)==1 && N!=0;){
		gets(s);
		for(int i=0;i<=N;i++)
			v[i].clear();
		while(gets(s)){
			if(s[0]=='0')	break;
			char *ptr = strtok(s," ");
			sscanf(ptr," %d",&a);
			while((ptr=strtok(NULL," "))!=NULL){
				sscanf(ptr," %d",&b);
				v[a].push_back(b);
				v[b].push_back(a);
			}
		}
		memset(clk,0,sizeof(clk));
        memset(ap,0,sizeof(ap));
        dfs_c = 0;
        for(int i=1;i<=N;i++)
            if(clk[i]==0)
                tarjan(i,-1);
        int ans = 0;
        for(int i=1;i<=N;i++)
            if(ap[i]==1)
				ans++;
		printf("%d\n",ans);
	}
    
    return 0;
}