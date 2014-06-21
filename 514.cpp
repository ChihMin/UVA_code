#include <cstdio>
#include <stack>

using namespace std;

stack < int > s ; 
int tar[3000] ; 
int n ; 
int main(){
	
	while( ~scanf("%d",&n) ){
		if( !n )	break;  
		
		while( ~scanf("%d",&tar[1]) ){
			if( tar[1] == 0 )	break;
			
			while( !s.empty() )	s.pop(); 
			  
			for(int i=2;i<=n;++i)
				scanf("%d",&tar[i]); 
		
			int now = 1 ; 
			for(int i=1;i<=n;++i){
				s.push( i ) ; 
				while( !s.empty() && s.top() == tar[now] ){
					now++ ; 
					s.pop() ; 
				}
			}
			if( !s.empty() )	printf("No\n");
			else printf("Yes\n");
		}
		printf("\n");
	}

	
	return 0; 
}
