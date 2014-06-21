#include <cstdio>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#define N 200 
using namespace std;

struct NODE{
	double x , y ,z , r ;
	bool hole ;
} Node[N] ;

const int INF = 99999999;
int n , s , t , CASE ;
double dp[N][N] ;

void ini(){
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			dp[i][j] = INF; 	
}

void ConsMap(){
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			double xx = Node[i].x - Node[j].x ;
			double yy = Node[i].y - Node[j].y ;
			double zz = Node[i].z - Node[j].z ;
			
			double dis = sqrt( xx*xx + yy*yy + zz*zz );
			
			if( Node[i].hole ) dis -= Node[i].r ;
			if( Node[j].hole ) dis -= Node[j].r ;
			
			if( dis <= 0 ) dp[i][j] = 0;
			else dp[i][j] = dis ; 
		}
}

void floyd( ){
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k][j] );	
	printf("Cheese %d: Travel time = %.lf sec\n",++CASE,dp[s][t]*10);
}
int main(){
	CASE = 0;
	while( cin >> n ){
		if( n == -1 ) break; 
		
		for(int i=0;i<n;++i){
			cin >> Node[i].x >> Node[i].y >> Node[i].z >> Node[i].r  ;
			Node[i].hole = 1 ;
		}
		double x ,y, z ;
		cin >> x >> y >>z ;
		Node[n].x = x , Node[n].y = y , Node[n].z = z ;
		Node[n].hole = 0 ;
		n++ ;
		
		cin >> x >> y >>z ;
		Node[n].x = x , Node[n].y = y , Node[n].z = z ;
		Node[n].hole = 0 ;
		n++ ;
		
		s = n-2 , t = n-1 ;
		
		ini();
		
		ConsMap();
		floyd();
	}
	
		
	return 0 ;
}
