#include <cstdio>
#include <algorithm>
#define N 600
using namespace std;

const int INF = 2147483647 ;
const int _INF = -2147483647;
struct Packet{
	int max , min  ;
};

struct ST{
	ST *L , *R ;
	int min , max;
	
	ST(){
		min = INF , max = _INF ;
		L = R = 0;
	}
} *root[N];

int n , m ;
int MAP[N][N] ;

void build( int L , int R , int i , ST *st ){
	if( L == R ){	
		st->min = st->max = MAP[i][L];
		return ;
	} 
	int mid = ( L + R ) >> 1 ;
	if( !st->L ) st->L = new ST();
	if( !st->R ) st->R = new ST(); 
	
	build( L , mid , i , st->L );
	build( mid+1 , R , i , st->R );
	
	st->min = min( st->L->min , st->R->min );
	st->max = max( st->L->max , st->R->max );
}


Packet query( int L , int R , int nL, int nR , ST *st ){
	Packet tmp ;
	if( L > nR || R < nL ){
		tmp.max = _INF , tmp.min = INF ;
		return tmp ;
	}
	if( nL <= L && R <= nR ){
		tmp.max = st->max , tmp.min = st->min ;
		return tmp ;
	}
	
	int mid = ( L + R ) >> 1 ;
	Packet A = query( L , mid , nL , nR , st->L );
	Packet B = query( mid+1 , R , nL , nR , st->R );
	
	tmp.max = max( A.max , B.max ) ;
	tmp.min = min( A.min , B.min ) ;
	return tmp ;
}

void change( int L , int R , int Pos , int value , ST *st ){
	if( L > Pos || R < Pos )	return ;
	if( Pos <= L  && R <= Pos ){
		st->min = st->max = value ;
		return ;
	}
	
	int mid = (L+R) >> 1 ;
	change( L , mid , Pos , value , st->L );
	change( mid+1 , R , Pos , value , st->R );
	
	st->min = min( st->L->min , st->R->min ) ;
	st->max = max( st->L->max , st->R->max ) ;
}

int main(){
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		root[i] = new ST();
		
		for(int j=0;j<m;++j)
			scanf("%d",&MAP[i][j] );
		build( 0 , m-1 , i, root[i] );
	}
	
	int T;
	scanf("%d",&T);
	while( T-- ){
		char c[10] ;
		scanf("%s",c);
		
		if( c[0] == 'q' ){			
			int x1 ,y1 ,x2 ,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			
			Packet ans;
			ans.min = INF , ans.max = _INF ;
			for(int i=x1;i<=x2;++i){
				Packet tmp_ans = query( 0 , m-1 , y1-1 , y2-1 , root[i-1] );
				if( tmp_ans.max > ans.max )	ans.max = tmp_ans.max;
				if( tmp_ans.min < ans.min ) ans.min = tmp_ans.min;
			}
			printf("%d %d\n",ans.max,ans.min);
		}
		else{
			int x , y , v;
			scanf("%d %d %d",&x,&y,&v);
			x -= 1 , y-= 1 ;
			change( 0 , m-1 , y ,  v , root[x] );
		}
		
	}
	
	return 0 ;
}
