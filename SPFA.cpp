#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define N 100001
using namespace std;

struct Node{
	int b , v ;
} ;

const int INF = 2147483647 ;

vector < Node > linked[N+10] ; 
queue < int > Q; 
int n ,m ; 
int d[N+10] ; 
int par[N+10] ;
bool visit[N+10] ;

void ini(){
	for(int i=0;i<=n;++i){
		linked[i].clear();
		d[i] = INF ; 
	}
	memset( visit , 0 , sizeof( visit ) ) ;
	memset( par , 0 , sizeof( par ) ) ;
	while( !Q.empty() ) Q.pop() ;
}

void find_path( int x , int s ){
	while( x != par[x] ){
		printf("%d->",x)  ;
		x = par[x] ; 
	}printf("%d\n",s);
}

void SPFA( int s , int  e ){
	
	d[s] = 0 ;
	Q.push( s ) ; 
	visit[s] = 1 ;
	par[s] = s ;
	
	while( !Q.empty() ){
		int a = Q.front() ; Q.pop(); 
		visit[a] = 0 ;
		
		for(int i=0;i<linked[a].size();++i){
			int b = linked[a][i].b ; 
			int v = linked[a][i].v ;
			
			if( d[b] > (d[a] + v) ){ 
				d[b] = d[a] + v ;
				par[b] = a ;
				
				if( !visit[b] ){	
					Q.push( b ) ;
					visit[b] = 1; 
				}
			
			}
			if( d[b] == ( d[a] + v ) ){ // ¦r¨å§Ç³Ì¤p 
				if( par[b] > a ){	
					par[b] = a ; 			
				}
			}
		}
	}
	find_path( e , s );
		
}
int main(){
	int T;
	cin >> T;
	
	while( T-- ){
		int s ,e ;
		cin >> n >> m >> s >> e ;
		
		ini();	
		
		while( m-- ){
			int a , b , v ; 
			cin >> a >> b >> v ;
			
			linked[a].push_back( (Node){ b , v } ) ;
			linked[b].push_back( (Node){ a , v } ) ;
		}
		
		SPFA( e , s );	
	}


	return 0 ;
}
