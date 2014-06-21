#include <cstdio>
#include <cstdlib>
#include <algorithm> 
#include <ctime> 

int *s , n ; 

void sort( int l , int r  ){
	
	if( 0 <= l && l <= r && r < n  ){ 
	
		int x = l + (rand() % ( r - l + 1 )) ;
		int tar = s[x] ; 
		std::swap( s[x] , s[r] ) ; 
		
		x = r ;
		int i = l - 1   ;
		
		for(int j=l;j<r;++j){
			if( s[j] <= tar ){
				++i ; 
				if( i == x ) ++i ;  
				std::swap( s[j] , s[i] );
			}		
		}
	
		std::swap( s[i+1] , s[x] ) ; 
	
		sort( l , i ) ; 
		sort( i+2 , r ) ;
	}
}

int main(){
	srand( time( 0 ) ) ;

	scanf("%d",&n) ; 
	s = new int[n+10] ; 
	
	for(int i=0;i<n;++i) 
		scanf("%d",&s[i]); 
	
	sort( 0 , n-1 );  
	for(int i=0;i<n;++i)
		printf("%d\n",s[i]);
	delete [] s  ;
	
	return 0 ;
}
