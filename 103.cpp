#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define N 40 
using namespace std;

struct Node{
	int d[N] , num ;
} box[N] ;

int n , m ;
int list[N] ;
int par[N] ;
int dp[N];

bool cmp( int x , int y ){
	return x < y ;
}

bool cmp2( Node A , Node B ){
	for(int i=0;i<m;++i){
		if( A.d[i] == B.d[i] )
			continue;
		return A.d[i] < B.d[i] ;	
	}return A.num < B.num ;
}

bool judge( int i , int j ){
	Node A = box[i] , B = box[j] ;
	for(int k=0;k<m;++k){
		if( A.d[k] <= B.d[k] )
			return false ;
	} return true ;
}

void find_path( int x , int step ){
	list[step] = x ;
	if( x == par[x] ){
		for(int i=step;i>0;--i){
			cout << box[list[i]].num <<  ' ';
		}cout << box[list[0]].num << endl ;
		return ;
	}
	find_path( par[x] , step + 1 ) ;
}

int main(){
	
	while( cin >> n >> m  ){
		for(int i=1;i<=n;++i){
			for(int j=0;j<m;++j)
				cin >> box[i].d[j] ; 
			box[i].num = i ;
			sort( box[i].d , box[i].d + m , cmp ) ;
		}
		
		sort( box+1 , box + 1 + n , cmp2 ) ;
	
		for(int i=1;i<=n;++i)	par[i] = i  , dp[i] = 1 ;
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
				if( judge( i , j ) ){ 
					if( dp[i] < (dp[j] + 1) ) 	par[i] = j ;
					dp[i] = max( dp[i] , dp[j] + 1 );
				}
				
		int start = -1 ;
		int ans_max = -1 ;
		for(int i=n;i>0;i--){
			if( ans_max < dp[i] ){
				start = i ;
				ans_max = dp[i] ;
			}	
		}
		cout << ans_max << endl;
		find_path( start , 0 );
	}
	return 0; 
}
