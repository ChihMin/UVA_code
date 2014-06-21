#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string A , B ;
int s1[10000] , s2[10000] , sum[10000];
int n,  m; 

bool judge( ){
	if( n != m ) return n < m ;
	for(int i=0;i<n;++i){
		if( s1[i] == s2[i] )	continue;
		return s1[i] < s2[i] ;
	}
	return 0;
}

void add(){
	memset( sum , 0 , sizeof( sum ) );
	
	int len = max( n , m );
	for(int i=0;i<len;++i){
		sum[i] += ( s1[i] + s2[i] ) ;
		if( sum[i] > 9 ){
			int tmp = sum[i] / 10 ;
			sum[i] %= 10 ;
			sum[i+1] += tmp ;
		}
	}
		
	for(int i=len;i>=0;i--){
		if( i == len && sum[len] == 0 )
			continue;
		cout << sum[i]  ;
	}
	cout << endl ;
}

void cut( ){
	memset( sum , 0 , sizeof( sum ) );

	int *p1 = s1 , *p2 = s2 ;
	
	bool big = judge();
	if( big ) // if s1 < s2 change 
		p1 = s2 ,  p2 = s1;
		
	int MIN = min( n , m ); // min len
	int len = max( n , m );// max len
	for(int i=0;i<len;++i){
		sum[i] = p1[i] - p2[i] ;
		if( sum[i] < 0 )
			sum[i] += 10 , p1[i+1] -= 1 ;
			//borrow the value
	}
	
	bool flag = 0;
	if( big ) cout << '-';
	for(int i=len-1;i>=0;i--){
		// first digit not zero
		if( !flag && sum[i] )	flag = 1 ;
		if( flag ) printf("%d",sum[i]);
	}
	if( !flag ) printf("0"); //if a-b == 0
	cout << endl;
}

void multiple(){
	memset( sum , 0 , sizeof( sum ));

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			sum[i+j] += (s1[i] * s2[j]) ;
	int len = n + m;
	for(int i=0;i<=len;++i){
		if( i == len && sum[i] >= 10 )len++ ;
		int tmp = sum[i] / 10;
		sum[i] %= 10;
		sum[i+1] += tmp ;
	}
	bool flag = 0;
	for(int i=len-1;i>=0;i--){
		if( !flag && sum[i] != 0 ) flag = 1 ;
		if( flag ) printf("%d",sum[i]);
	}if( !flag ) printf("0"); // if a * b == 0
	cout << endl;
}

int main(){
	
	while( cin >> A >> B ){
		
		n = A.length();
		m = B.length() ;
		
		memset( s1 , 0 , sizeof( s1 ) );
		memset( s2 , 0 , sizeof( s2 ) );
		
		for(int i=0;i<n;++i)	s1[i] = A[n-i-1] - '0' ;
		for(int i=0;i<m;++i)	s2[i] = B[m-i-1] - '0' ;
		
		add( );
		cut( );
		multiple( );
	}

	return 0 ;
}
