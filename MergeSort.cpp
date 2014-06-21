#include <cstdio>
#include <cstdlib>

class Node{
	public :
		Node *l , *r  ; 
		int n , cnt ;
		int *s ; 
		
		Node( int _n ){
			n = _n ; 
			s = new int[n] ; 
			cnt = 0;
			l = r = NULL ;
		}
		
		~Node(){
			delete [] s ; 
			delete l ;
			delete r ; 
		//	printf("destroy XDD\n"); 
		}
		
		void push( int x ){
			s[cnt++] = x ; 
		}

} *root ;   

int *s; 

void sort( int l , int r , Node *t ){
	
	if( l == r ){	
		t->push( s[l] ) ; 
		return ; 
	}
	
	int mid = ( l + r ) >> 1 ; 
	
	t->l = new Node( mid - l + 1 ) ;
	t->r = new Node( r - mid ) ;
	
	sort( l , mid , t->l ) ;
	sort( mid+1 , r , t->r ) ; 
	
	int back1 = t->l->cnt , back2 = t->r->cnt ; 
	int head1 = 0 , head2 = 0; 
	
	while( head1 < back1 && head2 < back2 ){
		if( t->l->s[head1] < t->r->s[head2] )
			t->push( t->l->s[head1++] ) ;
		else	t->push( t->r->s[head2++] ) ;
	}
	
	while( head1 < back1 )	t->push( t->l->s[head1++] ) ;
	while( head2 < back2 )	t->push( t->r->s[head2++] ) ;
}

int main(){
	int n ; 
	scanf("%d",&n) ; 
	s = new int[n+10] ;
	root = new Node( n ) ; 
	
	for(int i=0;i<n;++i) 
		scanf("%d",&s[i]); 
	
	sort( 0 , n - 1 , root );
	
	for(int i=0;i<n;++i) 
		printf("%d\n",root->s[i] );
	
	delete root ; 
	
	return 0; 
}
