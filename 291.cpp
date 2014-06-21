#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

bool visit[6][6];
int linked[6][6];
int list[9]={1},c=0;


void dfs(int now,int step){
    if(step==9){
       for(int i=0;i<9;i++)  printf("%d",list[i]); 
       printf("\n");
	}
    else{
		for(int i=1;i<=5;++i){
			if(!visit[now][i]&&linked[now][i]){
				visit[now][i]=visit[i][now]=1;
				list[step]=i;
				dfs(i,step+1);
			//	visit[now][i]=visit[i][now]=0;	
			}
		}		
	}
                                        
}

int main(){
    linked[1][2]=linked[1][3]=linked[1][5]=
    linked[2][1]=linked[2][3]=linked[2][5]=
    linked[3][1]=linked[3][2]=linked[3][4]=linked[3][5]=
    linked[4][3]=linked[4][5]=
    linked[5][1]=linked[5][2]=linked[5][3]=linked[5][4]=1;  
    
    dfs(1,1);
    
    printf("%d",c);
    
    system("pause");
    return 0;    
}
