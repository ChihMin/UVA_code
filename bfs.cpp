#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;


string in ;
int INF = 9999999 ;
bool linked[300][300] ;
bool visit[300] ;
int d[300][300] ;
int par[300][300] ;
queue < int > q ;

void bfs( int source ){
	while( !q.empty() )	q.pop();
	for(int i=0;i<=200;++i){
		d[source][i] = INF ;
		par[source][i] = i ;
	}

	visit[source] = 1 ;
	q.push( source ) ;
	par[source][source] = source ;
	while( !q.empty() ){
		int a = q.front() ; q.pop() ;
		for(int b=0;b<=200;++b){
			if( !visit[b] && linked[a][b] ){
				visit[b] = 1 ;
				par[source][b] = a ;
				d[source][b] = 1 ;
				q.push( b ) ;
			}
		}
	}

}


void trace( int s , int x ){
	if( par[s][x] ==x ){
		printf("%d",x);
		return ;
	}
	trace( s,  par[s][x] );
	printf(" %d",x);
}

int main(){
    while( getline( cin , in ) ){
        memset( linked , 0 , sizeof( linked ) ) ;

        stringstream ss( in ) ;
        int a ;
        ss >> a ;
        int b ;
        while( ss >> b )	linked[a][b] = 1 ;
        while( getline( cin , in ) ){
            if( in == "*" )	break;

            stringstream tt( in ) ;
            tt >> a ;
			while( tt >> b )	linked[a][b] = 1 ;
        }
/*
		for(int i=0;i<=12;++i)
			for(int j=0;j<=12;++j){
				if( linked[i][j] )
					printf("%d to %d is good\n",i,j);
			}
*/
		memset( visit, 0 , sizeof( visit ) ) ;
		for(int i=0;i<=200;++i){
			memset( visit , 0 , sizeof( visit ) ) ;
			bfs( i ) ;
		}

		printf("*****\n");
		while( getline( cin , in ) ){
			if( in == "*" )	break;
			if( in.length() == 0 )	continue;

			stringstream tt( in ) ;
			tt >> a ;
			while( tt >> b ){
				//printf("%d->%d is \n",a,b);
				if( d[a][b] == INF ){
					printf("not exists\n");
				}
				else{
					trace( a , b ) ;
					printf("\n");
				}
			}
		}
    }
    return 0;
}
