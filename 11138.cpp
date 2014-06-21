#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 500 
using namespace std;

int n ,m ;
int match[N] ;
bool visit[N] ;
vector < int > v[N] ;

bool bipartite( int x ){
	for(int i=0;i<v[x].size();++i){
		int y = v[x][i] ;
		if( !visit[y] ){
			visit[y] = 1;
			if( !match[y] || bipartite( match[y] ) ){
				match[y] = x ;
				return true;
			}
		}
	}
	return false ;	
}
int main(){
	int T;
	cin >> T;
	for(int CASE=1;CASE<=T;++CASE){
		scanf("%d %d",&n,&m);
		for(int i=0;i<=n;++i)	v[i].clear();	
		
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int x ;
				scanf("%d",&x);
				if( x ) v[i].push_back( j ) ;
			}
		}
		memset( match , 0 ,sizeof( match ) );
		for(int i=1;i<=n;++i){
			memset( visit , 0 ,sizeof( visit ) );
			bipartite( i ); 
		}
		
		int ans = 0; 
		for(int i=1;i<=m;++i)
			if( match[i] )	ans++;
		printf("Case %d: ",CASE);
      	printf("a maximum of %d nuts and bolts ",ans);
      	printf("can be fitted together\n");
	}

	return 0 ;
}
