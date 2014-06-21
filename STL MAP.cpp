#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

struct Node{
	int l , t ;
};

struct cmp{
	bool operator()( Node A , Node B ){
		if( A.l == B.l )
			return A.t < B.t ;
		return A.l > B.l ;
	}
};

int n , m ;
map < Node , int , cmp > PQ; 
map < int , Node > exist ; 

int main(){
	
	int now = 0;
	while( cin >> m >> n ){
		if( !m & !n ) break;
		
		int ans = 0;
		PQ.clear() ;
		exist.clear(); 
		
		for(int i=0;i<n;++i){
			int x ; 
			cin >> x ;
			
			if( exist.find( x ) == exist.end() ){
				if( exist.size() < m ){
					
				
					Node input ;
					input.l = 1 ;
					input.t = i;
				
					exist[x] = input;
					PQ.insert( map< Node , int > :: value_type( input , x ) ) ;
				}
				else{
					map < Node , int , cmp >::iterator it = PQ.begin(); 
					
					Node top = it->first ; 
					int num = it->second ; 
						
					PQ.erase( it ) ;
					exist.erase( exist.find( num ) );
					
					Node input ;
					input.l = 1 ;
					input.t = i;
					
					exist[x] = input;
					PQ.insert( map< Node , int >::value_type( input , x ) ) ;
					
					ans++;
				}
			}
			
			else{
				Node tmp = exist[x] ;
				map < Node , int , cmp >::iterator it = PQ.find( tmp ) ;
				
				tmp.l++ ;
				exist[x] = tmp ;
				PQ.erase( it )  ;
				PQ.insert( map< Node , int >::value_type( tmp , x ) );
			}
		}
		printf("Case %d: %d\n",++now,ans);
	}
	return 0;
}
