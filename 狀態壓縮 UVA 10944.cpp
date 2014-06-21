#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{
	int x ,y ;
} nut[100] , start;


int n;
int x , y;
int linked[30][30];
char Map[30][30];
int dp[30][(1<<18)];

int cal( int T ){
	if( T < 0 )
		return T*-1;
	return T;
}

bool judge( int a , int b ){
	if( a > x || a < 0 )
		return false;
	if( b > y || b < 0 )
		return false;
	return true ;
}

void proc( ){
	for(int i=1;i<=n;++i){
		int a = nut[i].x , b = nut[i].y ;
		int aa = start.x , bb = start.y ;

		int xx = cal(aa - a) ;
		int yy = cal(bb - b) ;

		linked[0][i] = linked[i][0] = max( xx , yy );
	}

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			int xx = cal( nut[i].x - nut[j].x);
			int yy = cal( nut[i].y - nut[j].y );
			linked[i][j] = max( xx , yy);
		}

	for(int i=0;i<=(1<<n);++i)
		for(int j=0;j<=n;++j)
			dp[j][i] = 99999999;
	for(int i=1;i<=n;++i)
		dp[i][1<<(i-1)] = linked[0][i];
}

int main(){

	while( cin >> x >>y ){

		n =0 ;
		memset( linked , 0 , sizeof( linked ) );

		for(int i=0;i<x;++i){
			cin >> Map[i];
			for(int j=0;j<y;++j){
				if( Map[i][j] == '#' ){
					n++;
					nut[n].x = i , nut[n].y = j ;
				}
				else if( Map[i][j] == 'L' )
					start.x = i , start.y = j ;
			}
		}

		if( !n ){
			cout << 0 << '\n' ;
			continue;
		}

		proc();

		for(int i=0;i<(1<<n);++i){
			for(int j=1;j<=n;++j)
				if( i & (1<<(j-1) )){
					for(int k=1;k<=n;++k)
						if( !(i & 1<<(k-1))){
							dp[k][i+(1<<(k-1))] =
							 min( dp[k][i+(1<<(k-1))] , dp[j][i]+linked[j][k] );
						}
				}
		}

		int ans = (1<<29);
		for(int i=1;i<=n;++i)
			ans = min( ans , dp[i][(1<<n)-1] + linked[0][i] ) ;
		cout << ans  << '\n';
	}

	return 0;
}
