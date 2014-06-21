#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

map < int , int > Map ; 
struct Node{
	map < int , int > ans ; 
	long long int bit ; 
	int num ; 
	
	Node(){
		ans.clear() ;
		bit = 0 ;
		num = 0 ; 
	}
	
	Node( const Node &in ,  int x );
	
	bool appear( int x ){
		return ans.find( x ) != ans.end() ; 
	}
} ; 

Node::Node( const Node &in , int x ){
	*this = in ; 
	
	map < int , int > :: iterator it ;
	ans[x] = 1; 
	
	map < int , int > :: iterator st ; 
	for(it=ans.begin();it!=ans.end();++it){
		//printf("HERHE~~~\n");
	
		int tmp =  x - it->first ; 
		if( tmp < 0 )	tmp = -tmp ; 
	
		st = Map.find( tmp ) ; 
		if( st != Map.end() ){
			if( !( bit & ( (long long int )1 <<  st->second ) ) ){
				bit |= ((long long int )1 << st->second ) ;  
				num++ ; 
			}
		}
	}
}

queue < Node > Q ; 
Node ans ; 
long long int one = 1 ; 
long long int tar ; 
int s[60] ;  
int n ; 
int ansCnt  ; 

void bfs(){
	while( !Q.empty() )	Q.pop() ; 
	
	ansCnt = 1000 ; 
	Node tmp = Node() ;
	tmp.ans[0] = 1; 
	Q.push( tmp ) ; 
	
	map < int , int > :: iterator it ; 
	while( !Q.empty() ){
		//printf("OH NO\n");
		Node u = Q.front() ; Q.pop() ; 
		
		
		if( u.bit == tar  ){
			if( ansCnt > u.ans.size() ){
				ans = u ; 
				ansCnt = ans.ans.size() ; 
			}
			else if( ansCnt == u.ans.size() ){
				map < int , int > :: iterator it = u.ans.end() ;
				map < int , int > :: iterator st = ans.ans.end() ;
				it-- , st-- ; 
				if( it->first < st->first )	ans = u ; 
			}
		}
		
		
		if( u.ans.size() >= ansCnt )	continue; 
		if( u.ans.size() == 7 )	continue ; 
		/*
		for(it=u.ans.begin();it!=u.ans.end();++it)	cout << it->first << ' '; 
		cout << "bit is " << u.bit  << endl ; 
		printf("size = %d , bit = %lld\n",ansCnt ,ans.bit );
		*/
		
		for(int i=0;i<n;++i){
			if( !( u.bit & ( one<<i )  ) ){	
				for(it=u.ans.begin();it!=u.ans.end();++it){			
					
					int x = it->first ; 
					//printf("x = %d\n",x);
					Node A , B ; 
					if( x + s[i] <= s[n-1] && !u.appear( x + s[i] )){	
						A = Node( u , x + s[i] ) ; 
						//printf("AA is okay\n");
						if( A.bit != u.bit && A.ans.size() <= ansCnt )	Q.push( A ) ; 
					}
					if( x - s[i] <= s[n-1] && x - s[i] >= 0 && !u.appear( x - s[i]) ) {
						B = Node( u , x - s[i] ) ;
						//printf("BB is okay\n");  
						if( B.bit != u.bit && B.ans.size() <= ansCnt ) 	Q.push( B ) ; 
					}
					
				}
			} 
		} 
	}
}

int main(){
	
	int Case = 0 ; 
	while( ~scanf("%d",&n) ){
		if( !n ) 	break ;
		Map.clear() ; 
		
		
		for(int i=0;i<n;++i){
			int x ; 
			scanf("%d",&x ) ;
			Map[x] = 1; 
		}
		
		n = 0 ;
		map < int , int >::iterator it ; 
		for(it=Map.begin();it!= Map.end();++it){
			it->second = n ; 
			s[n++] = it->first ; 
		}
		//for(int i=0;i<n;++i)	printf("%d ",s[i]);
		
		tar = ((long long int)1<<n ) - 1 ;
		bfs() ; 
		
		//printf("size = %d , bit = %d\n",ans.ans.size() , ans.bit ) ; 
		printf("Case %d:\n",++Case);
		printf("%d\n",ans.ans.size()) ; 
		for(it=ans.ans.begin() ;it!=ans.ans.end();++it)	
			printf("%d ",it->first) ; 
		printf("\n");
	}

	return 0; 
}
