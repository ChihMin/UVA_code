#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node{
	double x , y ;
	int num ;	
} p[2000] , start , b[2000] ;

int n , l;
int newn ;

void ini(){
	start.x = 9999999;
	start.y = 9999999;
	start.num = -1; 	
}

bool judge( Node A , Node B ){
	if( A.y == B.y )
		return A.x < B.x ;
	return 	A.y < B.y ;
}

bool dis( Node A , Node B , Node C ){
	double x1 = A.x - C.x ;
	double y1 = A.y - C.y ;
	
	double x2 = B.x - C.x ;
	double y2 = B.y - C.y ;
	
	double M = x1 * x1 + y1 * y1 ;
	double N = x2 * x2 + y2 * y2 ;
	
	return 	M > N ;
}

double mul( Node A , Node B , Node C ){
	double x1 = A.x - C.x ;
	double y1 = A.y - C.y ;
	
	double x2 = B.x - C.x ;
	double y2 = B.y - C.y ;
		
	return x1*y2 - y1*x2 ;	
}

double edge( Node A , Node B ){
	double xx = A.x - B.x ;
	double yy = A.y - B.y ;
	
	return sqrt( xx*xx + yy*yy )  ; 	
}

bool cmp( Node A , Node B ){
	return mul( A , B , start ) > 0 ||
	 ( mul( A , B , start ) == 0 && 
	 dis( A , B , start ) ) ;
}

int main(){	
	ini();
	
	cin >> n >> l ;
	for(int i=0;i<n;++i){
		cin >> p[i].x >> p[i].y;	
		if( judge( p[i], start ) )
			start = p[i] ;
		p[i].num = i+1;
	} 

	sort(  p , p + n , cmp );

	newn = 2 ;
	b[0] = p[0] , b[1] = p[1] ;
	
	for(int i=2;i<n;++i){
		while( newn > 1 && mul( b[newn-1] , b[newn-2] , p[i] ) >= 0 )
			newn-- ;
		b[newn++] = p[i] ;	
	}
	b[newn] = b[0] ;
	double ans = 0; 
	for(int i=1;i<=newn;++i)
		ans += edge( b[i] , b[i-1] );
	
	ans += 2 * l * 3.14 ;
	printf("%.0lf\n",ans);
	
	return 0;
} 
