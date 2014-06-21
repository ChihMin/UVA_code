#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#define N 300  

using namespace std;

const int INF = -1;

map < string , int > name ; 
int n , r ;
int num = 0 ;  
int linked[N+10][N+10]; 
int d[N+10][N+10] ;

void ini(){
	num = 0;
	name.clear() ;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			linked[i][j] = INF  , d[i][j] = INF;
	
	for(int i=0;i<=n;++i)	d[i][i] = 0 ;
}

void floyd( ){
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j) 
				d[i][j] = max( d[i][j] , min( d[i][k] , d[k][j]  ) ) ;
}	

int main(){
	
	int Case = 0 ;
	while( cin >> n >> r ){
		if( !n & !r ) 	break; 
		
		
		ini(); 
		while( r-- ){
			string A , B; 
			int v ; 
			
			cin >> A >> B >> v ;
			 
			if( name.find( A ) == name.end() )
				name[A] = num ++ ;
			
			if( name.find( B ) == name.end() )
				name[B] = num++ ; 
				
			int a = name[A] ; 
			int b = name[B] ;  
			
			d[a][b] = max( d[a][b] , v ) ;
			d[b][a] = max( d[b][a] , v ) ;  
		}
		

		floyd(); 
		
		string A , B ;
		cin >> A >> B ;
		
		int a = name[A] ; 
		int b = name[B] ;
		
		printf("Scenario #%d\n",++Case); 
		cout << d[a][b]  << " tons" << endl << endl ;
	} 	

	return 0;
}
