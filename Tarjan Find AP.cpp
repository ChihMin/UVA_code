#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#define N 200 
using namespace std;

bool linked[N][N] ;
bool AP[N] ; // record point i is whether AP or not
int clk[N] , low[N] ;	
int n , clock , ans ;	// n number of Node in this graph 
char input[100000] ;	//input string 

int dfs( int x , int last ){	// last is used to record x's parent
	int child = 0 ;
	int lowx = 0;
	lowx = clk[x] = ++clock ; 
	
	for(int y=1;y<=n;++y){
		if( linked[x][y] ){	// if there's an edge between x , y 
			if( !clk[y] ){	// if point y isn't visited 
				child++;
				
				int lowy = dfs( y , x );	// let y be x , and y's par is x  
				lowy = low[y] ;
				lowx = min( lowx , lowy ) ;
				
				if( low[y] >= clk[x] )	AP[x] = 1;	// if low[y] >= clk[x] , point X is AP
			}
			else if( clk[y] && y != last ){	// if there's a backedge between x ,y 							// and y is not x's parent 
				lowx = min( lowx , clk[y] );   //low[x] record the ealier visiting time
			}
		}
	}
	
	if( child == 1 && !last )	AP[x] = 0 ;
	return low[x] = lowx ;
}
int main(){
		
	while( ~scanf("%d",&n) ){	// input the number of Node in one graph  
		if( !n )	break; 
		
		memset( linked , 0 , sizeof( linked ) );
		memset( low , 0 , sizeof( low ) );
		memset( clk , 0 , sizeof( clk ) );	
		memset( AP , 0 , sizeof( AP ) );
			
		
		scanf(" ");	
		while( gets( input ) ){	// get the whole input line
			if( !input[0] )	continue;	// if there's a case that onlt input enter
			
			char *ptr = strtok( input , " " ) ;	// slice the string 
			int a;
			sscanf( ptr , "%d", &a );	// input the a point
			
			if( a == 0 )	break; 
			
			while( ( ptr = strtok( NULL , " " ) ) ){	//input another point b 
				int b ; 	
				sscanf( ptr , "%d" , &b ) ;
				linked[a][b] = linked[b][a] = 1 ;	//construct the link with bidirectional edge
			}
		}
	
		ans = clock = 0;	// ans is the total of AP 
		for(int i=1;i<=n;++i)
			if( !clk[i] ){		//if point i wasn't visited 
				dfs( i , 0 ) ;		// let i be root and do dfs 
			}
		for(int i=1;i<=n;++i){	
			ans += AP[i] ;	// if point i is AP , ans += 1 ;
		}
		printf("%d\n",ans);	//	print the answer
	}

	return 0 ;
}

