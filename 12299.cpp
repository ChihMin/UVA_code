#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define N 300000
using namespace std;

struct ST{
	ST *R , *L ;
	int min ;
	
	ST(){
		R = L  = 0 ;
		min = 999999; 
	}
} *root = new ST();

int n ;
int s[N] ;


void build( int L , int R , ST *st ){
	if( L == R ){
		st->min = s[L] ; 
		return ;
	}
	if( !st->L ) st->L = new ST();
	if( !st->R ) st->R = new ST();
	 
	int mid = ( L + R ) >> 1 ; 
	build( L , mid , st->L );
	build( mid+1 , R , st->R );
	
	st->min = min( st->L->min , st->R->min ) ;
}

int query( int L , int R , int nL , int nR , ST *st ){
	if( L > nR || R < nL )	return 999999;
	if( nL <= L && R <= nR )	return st->min; 
	
	int mid = ( L + R ) >> 1 ;
	int Left = query( L , mid , nL , nR , st->L ) ;
	int Right = query( mid+1 , R , nL , nR , st->R );
	return min( Left , Right );  
}

void change( int L , int R , int Pos , int tar , ST *st ){
	if( L > Pos || R < Pos  )	return ; 
	if( Pos <= L && R <= Pos ){	
		st->min = tar ;	
		return ;
	}
	int mid = ( L + R ) >> 1 ;	
	change( L , mid , Pos , tar , st->L ) ;
	change( mid+1 , R , Pos , tar , st->R );
	
	st->min = min( st->L->min , st->R->min ); 
}
int main(){
	int T;
	scanf("%d %d",&n,&T);
	for(int i=0;i<n;++i)	scanf("%d",&s[i]);
	build( 0 , n-1 , root ) ;	
	
	char input[40] ;
	while( T-- ){
		scanf("%s",input);
	
		int flag = 0 , cnt = 0;
		int buffer[100] ;
		char Type[10] ;
		char *ptr = strtok( input , ",()");
		do{
			if( !flag ){
				sscanf( ptr ,"%s", Type) ; 
				flag = 1 ;
			}
			else sscanf( ptr ,"%d" ,&buffer[cnt++] );	
		} while( ( ptr = strtok( NULL, ",()") ) ); 
	
		if( !strcmp( Type , "query" ) ){
			
			int a = buffer[0] , b = buffer[1] ;
			if( a > b )	swap( a , b ) ;
			printf("%d\n",query( 0 , n-1 , a-1 , b-1 , root )) ;
		}
		else{
			if( cnt ){
				int value[100] , tmp ;
				for(int i=0;i<cnt;++i)	
					value[i] = query( 0 , n-1, buffer[i]-1 , buffer[i]-1 , root ) ;
				
				tmp = value[0] ;
				for(int i=0;i<cnt-1;++i){
					value[i] = value[i+1] ;
				} value[cnt-1] = tmp ;
				
				for(int i=0;i<cnt;++i)	
					change( 0 , n-1 , buffer[i]-1 , value[i] , root );
			
			}
		}	
	}

	return 0 ;
}
