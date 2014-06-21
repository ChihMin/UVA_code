#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct SegmentTree{
	SegmentTree *nL , *nR ;
	int mask ;
	int color;
	int R , L;

	SegmentTree(){
		nL = nR = 0;
		mask = 0 ;
		R = L = - 1;
	}
} *root = new SegmentTree() ;

int n , t , q;
bool visit[31];

void build( int L , int R , SegmentTree *st ){
	st->L = L;
	st->R = R;
	st->color = 1;

	if( L == R ){
		st->mask = 1;
		return ;
	}

	int mid = ( L + R ) / 2 ;
	if( !st->nL ) st->nL = new SegmentTree();
	if( !st->nR ) st->nR = new SegmentTree();

	build( L , mid , st->nL );
	build( mid+1 , R , st->nR );
}

void update( int L , int R , SegmentTree *st ){
	if( !st->mask )
		return;

	int mask = st->mask;
	if( st->nL ){
		st->nL->mask = mask;
		st->nL->color = 1<<(mask-1);
	}

	if( st->nR ){
		st->nR->mask = mask;
		st->nR->color = 1<<(mask-1);
	}
	st->mask = 0;
}

void change( int L , int R , int nL , int nR , int mask , SegmentTree *st){
	if( L > nR || R < nL )
		return ;

	if( nL <= L && R <= nR ){
		//printf("Change ---> %d<->%d = %d\n",L+1,R+1,mask);
		st->mask = mask;
		st->color = 1<<(mask-1);
		return;
	}

	update( L , R , st );

	int mid = (L+R)/2;
	SegmentTree *M = st->nL, *N = st->nR ;

	if( M )	change(L,mid,nL,nR,mask,st->nL);
	if( N ) change(mid+1,R,nL,nR,mask,st->nR);

	st->color = st->nL->color | st->nR->color ;
}

int diff ;
void query( int L , int R , int nL , int nR , SegmentTree *st ){
	if( L > nR || R < nL )	return ;
	if( nL <= L && R <= nR ){
		//printf("%d <-> %d = ",L+1,R+1);
		/*
		for(int i=0;i<t;++i){
			if( st->color & (1<<i) )
				printf("%d,",i+1);
		}
		*/
		for(int i=0;i<t;++i)
			if( !visit[i] && (st->color & (1<<i)) ){
				diff++;
				visit[i] = 1;
				//printf("%d,",i+1);
			}
		//cout << '\n' ;
		return;
	}

	update( L,R,st );

	int mid = (L+R)/2 ;
	if( st->nL )
		query( L,mid,nL,nR,st->nL);

	if( st->nR )
		query( mid+1,R,nL,nR,st->nR);
}

int main(){

	cin >> n >> t >> q;
	build( 0 , n-1 , root );

	for(int i=0;i<q;++i){

		char c;
		scanf(" %c ",&c);


		if( c == 'C' ){
			int x , y , z ;

			scanf("%d %d %d",&x,&y,&z);
			if( x > y )	swap( x , y );
			//printf("%c %d %d %d \n",c,x,y,z);
			change( 0 , n-1 , x-1 , y-1 , z , root );


			/*
			for(int j=0;j<n;++j)
				query( 0 , n-1 , j , j , root );
			cout << '\n' ;
			*/
		}

		else{
			memset( visit , 0, sizeof( visit ));
			diff = 0;

			int x , y;
			scanf("%d %d",&x,&y);
			if( x > y )
				swap( x , y );
			//printf("%c %d %d \n",c,x,y);
			query( 0 , n-1 , x-1 , y-1 , root );
			printf("%d\n",diff);
		}
	}

	return 0;
}
