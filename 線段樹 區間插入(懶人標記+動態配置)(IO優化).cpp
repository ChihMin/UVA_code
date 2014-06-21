#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct SegmentTree{
	SegmentTree *nR , * nL;

	int L , R ;
	int mask ;
	long long int sum ;

	SegmentTree(){
		nR = nL = 0;
		L = R = -1 ;
		mask = sum =  0;
	}

} *root = new SegmentTree();

int n =0 , q=0;
int s[100001];

void build( int L , int R , SegmentTree *st ){

	st->L = L ;
	st->R = R ;

	if( L == R ){
		st->sum = s[L];
		return ;
	}

	int mid = ( L + R ) / 2 ;

	if( !st->nR ) st->nR = new SegmentTree();
	if( !st->nL ) st->nL = new SegmentTree();

	build( L , mid , st->nL );
	build( mid+1 , R , st->nR );
	st->sum = st->nL->sum + st->nR->sum ;
}

void update( int L , int R , SegmentTree *st ){

	if( !st->mask )	return ;
	int mid = ( L + R )/2 ;

	int mask = st->mask ;
	if( st->nL ){
		st->nL->mask += mask;
		st->nL->sum += ((long long int )mask*(long long int )( mid - L + 1 ) );
	}

	if( st->nR ){
		st->nR->mask += mask;
		st->nR->sum += ((long long int )mask*(long long int )( R - mid ));
	}
	st->mask = 0;
	return;
}

long long int query( int L , int R , int nL , int nR , SegmentTree *st ){
	if( L > nR || R < nL )
		return 0;

	if( nL <= L && R <= nR ){
		return st->sum ;
	}

	update( L , R , st );

	int mid = ( L + R ) /2 ;
	SegmentTree *lt = st->nL , *rt = st->nR ;
	return query( L , mid , nL , nR , lt ) +   query( mid+1 , R , nL , nR , rt );
}

void change( int L , int R , int nL, int nR , int mask , SegmentTree *st ){
	if( R < nL || L > nR )
		return ;

	if( nL <= L && R <= nR ){
		st->mask += mask ;
		st->sum += ((long long int)mask*(long long int)(R-L+1));
		return ;
	}

	update( L,R,st );

	int mid = ( L + R ) /2 ;
	change( L , mid , nL , nR , mask , st->nL );
	change( mid+1 , R, nL , nR , mask , st->nR );

	st->sum = st->nL->sum + st->nR->sum ;
}

int main(){

	scanf("%d %d",&n,&q);

	for(int i=0;i<n;++i){
		cin >> s[i] ;
	}

	build( 0 , n-1 , root );

	for(int i=0;i<q;++i){
		char c ;
		scanf(" %c ",&c);
		//cout << "ewrwerwer====" << c << '\n';
		//system("pause");

		if( c == 'Q' ){
			int x , y ;

			scanf("%d %d",&x,&y);
			//system("pause");
			long long int sum = query( 0 , n-1 , x-1 , y-1 , root );
			//system("pause");
			printf("%I64d\n",sum);
			//printf("%c %d %d = %I64d\n",c,x,y,sum);
		}
		else{
			int mask , x , y;
			scanf("%d %d %d ",&x,&y,&mask);
			change( 0 , n-1 , x-1 , y-1 , mask , root );
			/*
			for(int j=0;j<n;++j){
				cout << query(0,n-1,j,j,root) << ' ';
			}
			cout << '\n' ;
			*/
		}
	}

	return 0;
}
