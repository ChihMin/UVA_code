#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int s[] = { 1 , 2 ,2 , 3 ,3 , 3,39 ,39 ,40 ,46 ,47 ,48 };
int n = 12 ; 
void BS_Lower( int l , int r , int tar ){
	while( l < r ) {
		int mid = ( l + r ) >> 1 ; 
		if( tar <= s[mid] )	r = mid  ;
		else	l = mid+1 ; 
	}
	
	printf("%d -> %d\n",l,s[l]);
}

void BS_Upper( int l , int r , int tar ){
	while( l < r ) {
		int mid = ( l + r ) >> 1 ; 
		if( tar < s[mid] )	r = mid  ;
		else	l = mid+1 ; 
	}
	
	printf("%d -> %d\n",l,s[l]);
}

int main(){
		
	int x ;
	while( ~scanf("%d",&x) ) {
		BS_Lower( 0 , n - 1 , x ); 
		BS_Upper( 0 , n - 1 , x ) ;
	}
	
	return 0; 	
}
