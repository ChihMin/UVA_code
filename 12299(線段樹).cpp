#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct SegmentTree{
	SegmentTree *nR , *nL ;
	int sum	;
	
	SegmentTree(){
		nR = nL = 0;
		sum = 99999999;
	}
} *root = new SegmentTree();

struct Change{
	int sit , v ;		
} edit[1000000];

int sum ;
int n , q;
int A[200000];

void build( int L , int R , SegmentTree *st ){
	if( L == R ){
		st->sum = A[L] ;
		return ;
	}
	
	int mid = ( L + R ) / 2 ;
	
	if( !st->nL )	st->nL = new SegmentTree();
	if( !st->nR )	st->nR = new SegmentTree();  
	
	build( L , mid , st->nL );
	build( mid+1 , R , st->nR );
	
	st->sum = min ( (st->nL)->sum , (st->nR)->sum ); 
	
}


void query( int L , int R , int x , int y , SegmentTree *st ){
	if( x <= L && R <= y ){
		sum = min(sum , st->sum);
		return ;
	}
	
	int mid = (L + R)/2;	
	if( x <= mid && st->nL )	query( L , mid , x , y , st->nL );
	if( y > mid && st->nR)	query( mid+1 , R , x , y , st->nR );
} 

void updata( int L , int R , int x , int tar , SegmentTree *st ){
	if( L == R ){
		st->sum = tar;
		return ;
	}
	int mid = ( L+R )/2 ;
	
	if( x <= mid && st->nL ) 
		updata( L , mid , x , tar , st->nL );
	if( x > mid && st->nR )
		updata( mid+1 , R , x , tar , st->nR );
	
	st->sum = min ( (st->nL)->sum , (st->nR)->sum ); 
}

int list[2000000];
void str_input( char *s ){
	//system("pause");
	
	int cnt = 0;
	
	
	int total = 0;
	for( char *i = s+6  ; *i ; ++i ){
		if( *i >= '0' && *i <= '9' )
			total = total*10 + (int)(*i - '0');
		
		else{
			list[cnt++] = total ;	
			total = 0;
		}
	}
	/*
	for(int i=0;i<cnt;++i)
		cout << list[i] << '\n' ;
	*/
//	system("pause");

	if( s[0] == 's' ){
		for(int i=1;i<cnt;++i){
			edit[i].sit = list[i];
			
			sum = 99999999; 
			
			int sit = list[i] ;
			query( 0 , n-1 , sit-1 , sit-1 , root );
			edit[i-1].v = sum ; 
		}
		sum = 99999999;
		query( 0 , n-1 , list[0]-1 , list[0]-1 , root );			
		edit[0].sit = list[0] ;
		edit[cnt-1].v = sum ;
		/*
		for(int i=0;i<cnt;++i)
			printf("(%d--->%d)\n",edit[i].sit,edit[i].v);
		*/	
		
		for(int i=0;i<cnt;++i){
			int x = edit[i].sit;
			int tar = edit[i].v ;
			
			updata( 0 , n-1 , x-1 , tar , root  )	;
		}
		
	}
	
	if( s[0] == 'q' ){//cout <<"sdsdsdsds\n"; 
		int x = list[0] ;
		int y = list[1] ;
		
		sum = 99999999;
		query( 0 , n-1 , x-1 , y-1 , root );
		printf("%d\n",sum);
	}
	/*
	for(int i=0;i<n;++i){
			sum = 9999999;
			query( 0 , n-1 , i , i , root );
			cout << "YA:" << sum << '\n' ;	
		}
	*/
}

int main(){
	
	cin >> n >> q ;
	for(int i=0;i<n;++i){
		scanf("%d",&A[i]);	
	}
	
	build( 0 , n-1 , root );
	while( q-- ){
		
		char input[1000];
		scanf("%s",input);
		
		//system("pause");
		
		str_input( input ); 
		
		
		/*
		sum = 0;
		query( 0 , n-1 , x , y , root );
		cout << sum << '\n' ;
		*/
	}	
	return 0;
}
