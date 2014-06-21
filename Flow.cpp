#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define N 120
using namespace std;

struct Node{
	int b , c ;
};

const int INF = 999999999;

queue < int > Q ;
int MAP[N][N];
int r[N] , par[N] ;
int flow[N][N] ;
int n , s , t  , m;
int f , CASE;

void MAX_FLOW(){
	while( 1 ){
		memset( r , 0 , sizeof( r ) );
		r[s] = INF ;
		Q.push( s ) ;
		while( !Q.empty() ){
			int a = Q.front() ; Q.pop();
			for(int b=1;b<=n;++b){
				int c = MAP[a][b];
		
				if( !r[b] && c > flow[a][b] ){
					par[b] = a ;	Q.push( b ) ;
					
					int Min = min( c - flow[a][b] , r[a] );
					r[b] = Min ; 
				} 
			}
		}
		if( r[t] == 0 ) break;
		for(int u = t ; u != s ; u = par[u] ){
			flow[par[u]][u] += r[t] ;
			flow[u][par[u]] -= r[t] ;
		} f += r[t] ;
	}
	printf("The bandwidth is %d.\n\n",f);
}

int main(){
	
	while( cin >> n && n ){
		cin >> s >> t >> m ;
		
		for(int i=0;i<=n;++i)	 par[i] = i ;
		memset( flow , 0 , sizeof( flow ) );
		memset( MAP , 0 , sizeof( MAP ) );
		f = 0;
		
		while( m-- ){
			Node tmp ;
			int a , b,  c ;
			cin >> a >> b >> c ;
			
			MAP[a][b] += c ;
			MAP[b][a] += c ;
		}
		printf("Network %d\n",++CASE);
		MAX_FLOW();
	}

	return 0 ;
}
