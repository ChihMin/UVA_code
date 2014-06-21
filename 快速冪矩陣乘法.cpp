#include <cstdio>
#include <cstring> 
#include <iostream>
using namespace std;

struct Node{
	long long int mat[2][2];  
	long long int mod ; 
	
	Node(){
		memset( mat , 0 , sizeof( mat ) ) ; 
		mod = 1000000007; 
	}
	
	Node operator*( const Node &A ) const;
};

Node Node::operator*(const Node &A) const{
	Node tmp = Node();
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				tmp.mat[i][j] = (( tmp.mat[i][j] + ( mat[i][k] * A.mat[k][j] ) % mod ) % mod ) % mod ; ; 
	return tmp ; 
}

long long int a ,b , t ; 
long long int mod = 1000000007 ; 
Node one , square , triple ; 

Node power( long long int n ){
	
	if( n == 2 )	return square ; 
	if( n == 1 )	return one ;
	
	Node now = power( n / 2 ) ;
	if( n % 2 )	return (now * now) * one ;
	return now * now ;  
}

int main(){
	
	one.mat[0][0] = 2 , one.mat[0][1] = 1 ;
	one.mat[1][0] = 1 , one.mat[1][1] = 3 ; 
	
	square = one * one ;
	triple = square * one ; 
	
	while( cin >> a >> b >> t ){
		a %= mod , b %= mod ; 
		Node result ; 
		if( t ){	 
			result = power( t ); 
			long long int tmpa = a , tmpb = b ;	
			a = (tmpa * result.mat[0][0])%mod + (tmpb * result.mat[0][1])%mod ;
			b = (tmpa * result.mat[1][0])%mod + (tmpb * result.mat[1][1])%mod ;
			a %= mod , b %= mod ; 
		}
		
		cout << a << ' ' << b << endl ;
	}
	 
	return 0; 
}
