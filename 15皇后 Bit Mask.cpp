#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char map[20][20] ;
int block[20] ;  
int n , sum ;   

void dfs( int L , int R , int V , int step ){
	if( step == n ){	
		sum++;  
		return ; 
	}
	else{
		int state = ( L | R | block[step] | V ) ;
		
		int tmp = ~state ;
		tmp = ( tmp & (-tmp) ) ;
		
		while( tmp < (1<<n) ){
		
			dfs( ( L|tmp)<<1 , (R|tmp)>>1 , V|tmp , step + 1 ) ;
		 
			state = state | tmp  ;
			tmp = ~state ;
			tmp = ( tmp & (-tmp) ) ;
		}
	}
}

int main(){
	
	int Case = 0 ;
	while( ~scanf("%d",&n ) ){
		if( !n )	break;  
		
		memset( block , 0 , sizeof( block ) ) ; 
		
		for(int i=0;i<n;++i){
			scanf("%s",map[i]);
			for(int j=0;j<n;++j)
				if( map[i][j] == '*' )
					block[i] |= ( 1 << j ) ; 
		}
		/*
		for(int i=0;i<n;++i)
			printf("%s\n",map[i]);
		*/
		sum = 0 ;
		dfs( 0 , 0 , 0 , 0 ) ; 
		printf("Case %d: %d\n",++Case,sum);
	}

	return 0; 
}
