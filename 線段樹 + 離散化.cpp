#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 600000;

struct ST{
	ST *R , *L ;
	int sum ;
	int mask;
	int nL , nR ;
	
	ST(){
		R = L = 0 ;
		mask = nL = nR = sum = 0; 
	}	
} *root = new ST(); 

struct NODE{
	int x , y , query ; 	
}Node[INF] ; 

struct MAP{
	int val; 
	int id ;  
	bool left ;	
} map[INF] ;

bool cmp( MAP A , MAP B ){
	return A.val < B.val ;	
}

void build( ST *st , int nL , int nR ){
	//printf("%d %d\n",nL,nR);
	
	if( !nL | !nR )	return ;
	if( nL > nR )	return ;
	
	st->nR = nR ;
	st->nL = nL ;
	st->sum = st->mask = 0;
	if( nL == nR ){
		return ;
	}
	
	int mid = (nL+nR)/2 ;
	if( !st->R ) st->R = new ST();
	if( !st->L ) st->L = new ST();
	
	build( st->L , nL , mid );
	build( st->R , mid+1 , nR );
}

void update( ST *st ){
	if( st->mask == 0 )	
		return ;
	
	st->L->sum += st->mask ; 
	st->L->mask += st->mask ;
	
	st->R->sum += st->mask;
	st->R->mask += st->mask ;
	
	st->mask = 0 ; 
}

void change( ST *st , int nL , int nR , int L , int R ){
	if( !L | !R )	return ;
	if( R < L )	return ;
	if( L > nR || R < nL )
		return ;
	
	if( nL <= L && nR >= R ){
		st->sum += 1;
		//printf("(%d,%d)  st->sum = %d memory = %d\n",L,R,st->sum,st);
		st->mask += 1 ;
		return ;
	}
	update( st );
	
	int mid = (L+R)/2 ;
	change( st->L , nL , nR , L , mid );
	change( st->R , nL , nR , mid+1 , R );
	
	st->sum = min( st->L->sum , st->R->sum ); 
}

void query( ST *st , int nL , int nR , int L , int R , int *ptr ){
	//printf("%d %d ----> %d memory = %d\n",L,R,st->sum,st); 
	
	if( !L | !R )	return ;
	if( L > R )	return ;
	if( L > nR || R < nL )
		return ;
		
	if( nL <= L && R <= nR ){
		*ptr = min( *ptr , st->sum );
		return ;
	}
	
	update( st );
	
	int mid = (L+R)/2 ;
	query(st->L,nL,nR,L,mid,ptr);
	query(st->R,nL,nR,mid+1,R,ptr);
	
	st->sum = min( st->L->sum , st->R->sum ); 
}

void print( ST *st , int L , int R ){
	if( !L | !R )	return ;
	if( L > R )	return ;
	if( L == R )	return ; 
	
	update( st );
	//printf("print %d <-> %d = %d memory = %d\n",L,R,st->sum,st );
	
	
	int mid = (L+R)/2 ; 
	print( st->L , L , mid );	
	print( st->R , mid+1 , R ); 
}

int main(){
	
	int T;
	scanf("%d",&T);
	for(int n=1;n<=T;++n){
		char type ;
		cin >> type >> Node[n].x >> Node[n].y ;
		Node[n].query = 0;
		
		map[n*2-1].val = Node[n].x ;
		map[n*2-1].id = n ;
		map[n*2-1].left = 1;
		
		map[n*2].id = n ;
		map[n*2].val = Node[n].y ;
		map[n*2].left = 0;
		
		if( type == '?' ){
			Node[n].query = 1;
			
			sort( map+1 , map+1+2*n , cmp ); 
			
			int tmp = map[1].val , t = 1;
			for(int i=1;i<=2*n;++i){
				if( tmp != map[i].val ){
					++t , tmp = map[i].val ;
				}
				
				if( map[i].left )
					Node[map[i].id].x = t;
				else
					Node[map[i].id].y = t; 
			}
			
			build( root , 1 , t );
			for(int i=1;i<=n;++i){
				//printf("%d,%d\n",Node[i].x,Node[i].y);
				if( Node[i].query && i != n ){
					//printf("YA\n");
					continue ;
				}
				if( i != n )
					change( root , Node[i].x , Node[i].y , 1 , t  );
				if( i == n ){
					int x = Node[i].x ;
					int y = Node[i].y ;
					 
					int min_num = INF*100;
					print( root , 1 , t );
					query( root , x , y , 1 , t , &min_num );
					printf("%d\n",min_num);	
				}
					
			}
			
			delete( root );
			root = new ST();
		}
	}
	
	
	return 0;
}
