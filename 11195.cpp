#include <cstdio>
#define illegal(c) ( x&c || z&(c<<now) || s&(c<<(n-now-1)) || c&r[now] )
#define lb(x) ( x&-x )

int r[15];
int n,z,s,x;
int ans;

void dfs(int now){
	
	if( now==n-1 ){
		int c = (1<<n) - 1 - x;
		if( !illegal(c) ) ++ans;
	}
	
	else {
		int less = (1<<n)-1-x;
		while( less ){
			int c = lb(less);
			less-=c;
			if( illegal(c) ) continue;
			else {	
				x+=c;
				z+=c<<now;
				s+=c<<(n-now-1);
				dfs(now+1);
				x-=c;
				z-=c<<now;
				s-=c<<(n-now-1);	
			}
		}	
	}
}


int main(){
	
	char in[16];
	int cnt=1;
	
	while(1){
		
		scanf("%d",&n);
		if( !n ) break;
		
		for(int i=0;i<n;++i) r[i]=0;
		
		for(int i=0;i<n;++i){
			scanf("%s",in);
			for(int j=0;j<n;++j)
				if( in[j]=='*' ) r[i]+=1<<j;
		}
		
		ans = 0;
		dfs(0);	
		
		printf("Case %d: %d\n",cnt++,ans);
	}
	
	return 0;	
}
