#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 10001

using namespace std;

int n ;
int B[10001];
int s[N] ;
int lis[N] , lds[N];

int binary( int l , int r , int x ){

	while( l < r ){
		int mid = (l+r) >> 1 ;
		if( B[mid+1] >= x )
			r = mid ;
		else
			l = mid+1;
	}
	return l;


}
void ini(){
	for(int i=1;i<=n;++i)
		B[i] = 99999999;
	B[0] = -99999999;
}

int main(){

	while( cin >> n ){
		for(int i=1;i<=n;++i){
			cin >> s[i] ;
		}

		ini();

		for(int i=1;i<=n;++i){
			lis[i] = binary( 1 , n , s[i] ) +1 ;
			if( s[i] < B[lis[i]] )
				B[lis[i]] = s[i] ;
		}
		ini();
		for(int i=n;i>=1;--i){
			lds[i] = binary(1,n,s[i]) +1 ;
			if( s[i] < B[lds[i]] )
				B[lds[i]] = s[i] ;
		}

		int ans = 0;
		for(int i=1;i<=n;++i){
			int k = min( lis[i] , lds[i] ) ;
			if( k > ans )
				ans = k;
		}
		printf("%d\n",(ans-1)*2-1);
	}
    return 0;
}
