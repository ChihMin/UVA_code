#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define N 50

using namespace std;

vector < int > v[N*N] ; 
int h , w , n ; // n is the number of X pt's , m is the number of Y pt's  
int number;	// number is the number point of MAP 
int TotalPoint ;
int xlist[N*N] ;
int NumTable[N*N][N*N];
char MAP[N*N][N*N];

int sum ; 
int match[N*N] ;
bool visit[N*N] ;

void initialize( ){
	TotalPoint = number = 0;
	for(int i=0;i<h;++i)	
		for(int j=0;j<w;++j)
			NumTable[i][j] = ++number ;	
	for(int i=0;i<=number;++i)	v[i].clear() , match[i] = 0;
	n = sum = 0;
}

bool check( int a , int b ){
	if( a >=0 && a < h )
		if( b >= 0 && b < w ) 
			if( MAP[a][b] == '*' )
				return true;
	return false ;
} 

void find_even_pt(){	
	for(int i=0;i<h;++i)
		for(int j=0;j<w;++j){
			if( MAP[i][j] == '*' )	TotalPoint++;
			if( MAP[i][j] == '*' && ( i + j ) % 2 ){
				int a = NumTable[i][j] ;
				int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
				
				for(int k=0;k<4;++k){
					int xx = i + d[k][0] ;
					int yy = j + d[k][1] ;
					
					if( check( xx , yy ) ){	
						int b = NumTable[xx][yy] ;
						v[a].push_back( b );
					}
				}
				xlist[n++] = a ;
			}
		}
	
}

bool bipartite( int x ){
	for(int i=0;i<v[x].size();++i){
		int y = v[x][i] ;
		
		if( !visit[y] ){
			visit[y] = 1 ;
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
	scanf("%d",&T);
	while( T-- ){
		scanf("%d %d",&h,&w);
		for(int i=0;i<h;++i)	
			scanf("%s",MAP[i]);
		
		initialize(  );
		find_even_pt( );
		
		for(int i=0;i<n;++i){
			int x = xlist[i] ;
			memset( visit , 0 , sizeof( visit ) );
			bipartite( x );			
		}
		
		int BMP = 0;
		for(int i=1;i<=number;++i)	if( match[i] )	BMP++;
		printf("%d\n", TotalPoint - BMP);		
	}

	return 0; 
}
