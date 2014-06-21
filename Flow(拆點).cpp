#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define N 120

using namespace std;

const long long int INF = (long long int)99999999999999999;

int n , m;
long long int flow ;
long long int c[N][N];
long long int f[N][N] ;
long long int r[N] ; 
int par[N] ; 
queue < int > Q; 

void Max_Flow( int s , int t ){
	while( 1 ){
		memset( r , 0 , sizeof( r ) ); 
		r[s] = INF ; 
		Q.push( s ) ;
		while( !Q.empty() ){
			int a = Q.front();	Q.pop();
			
			for(int b=1;b<=2*n;++b){	
				if( !r[b] && c[a][b] > f[a][b] ){
					par[b] = a ; 
					Q.push( b ) ;
					r[b] = min( r[a] , c[a][b] - f[a][b] ) ;
				}		
			}
		}
		if( !r[t] )	break;  
		
		for(int u = t ; u != s ; u = par[u] ){
			f[par[u]][u] += r[t] ;
			f[u][par[u]] -= r[t] ;
		}
		flow += r[t] ; 
	}
	
	printf("%lld\n",flow);
}

int main(){
	while( ~scanf("%d %d",&n,&m ) ){
		if( !n & !m ) 	break; 
		
		flow = 0;
		memset( c , 0 , sizeof( c ) ) ;
		memset( f , 0 , sizeof( f ) );
	
		for(int i=0;i<n-2;++i){
			int id ;
			long long int cap ;
			scanf("%d %lld",&id,&cap) ; 
			c[id][id+n] = cap;
		}
		
		for(int i=0;i<m;++i){
			int a , b ;
			long long int v ;
			scanf("%d %d %lld",&a,&b,&v);
			c[a+n][b] = c[b+n][a] = v ;
		}
		
		Max_Flow( 1+n , n );
	}

	return 0;
}
