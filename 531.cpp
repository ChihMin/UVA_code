#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define N 200 

using namespace std;

string s1[N] , s2[N];
string list[N] ;
int cnt = 0;
int len1 = 0 , len2 = 0;
int dp[N][N] , prev[N][N] ;

void find_LCS( int i , int j ){
	if( !i | !j )	return ;
	if( prev[i][j] == 1 ){	
		list[cnt++] = s1[i-1] ;
		find_LCS( i-1 , j-1 );
	}
	else if( prev[i][j] == 2 )	
		find_LCS( i-1 , j );
	
	else find_LCS( i , j-1 );
}

void LCS(){
	memset( dp , 0 , sizeof( dp ) );
	
	for(int i=1;i<=len1;++i)
		for(int j=1;j<=len2;++j){
			if( s1[i-1] == s2[j-1] ){ 
				dp[i][j] = dp[i-1][j-1] + 1 ;  
				prev[i][j] = 1 ; // turn left and up 
			}
			else{
				dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
				if( dp[i-1][j] > dp[i][j-1] )	prev[i][j] = 2 ; // turn up
				else	prev[i][j] = 3 ;		// turn left 
			}	
		}
	find_LCS(  len1 , len2 ); 
}

int main(){

	string input ;
	while( cin >> input ){
		char c = input[0] ;
		
		if( input.length() != 1 || c != '#' ){
			s1[len1++] = input ;
			while( cin >> input ){
				c = input[0];
				if( c == '#' && input.length() == 1 ) break;
				
				s1[len1++] = input ;
			}
		}
		while( cin >> input ){
			c = input[0];
			if( c == '#' && input.length() == 1 ) break;
			
			s2[len2++] = input ;
		}
		
		
		LCS();
		for(int i=cnt-1;i>0;i--){
			cout << list[i] << ' '; 
		}cout << list[0] << endl ;
		
		len1 = len2 = cnt = 0;
	}
	
	return 0;
}
