#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath> 

using namespace std;

vector < int > v[1000] ; 
int n  , m  , u ;
int s[1000010] ;

 	
int main(){
	
	int T ; 
	while( ~scanf("%d %d %d",&n,&T,&u) ){
		
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
		}	
	
		m = sqrt( n ) ; 	// 分sqrt(n) 等分 每個sqrt(n) 個
		for(int i=0;i<=m+10;++i)	v[i].clear() ; 
		
		int cnt = -1; 
		for(int i=0;i<n;++i){	//開始塞
			if( !( i % m ) )	cnt++ ; 
			v[cnt].push_back( s[i] ) ;
		}
		cnt++ ; 
		for(int i=0;i<cnt;++i)	
			sort( v[i].begin() , v[i].end() ) ;	//幫塊狀排序好 
	 	
		while( T-- ){
			int L , R , x , p ; 
			scanf("%d %d %d %d",&L,&R,&x,&p ) ; 
			L -=1 , R -= 1 , p -= 1 ; 
			
			int start = L / m ; 	// 找到塊狀的位置
			int end = R / m ;
			int sum = 0 ;		//記錄<x的總和
			
			for(int i=start+1 ; i < end ; ++i ){	//中間區段的個數加起來
				vector < int >::iterator p = lower_bound( v[i].begin() , v[i].end() , x ) ;
				//二分搜去找那區塊x值的位置
				vector < int >::iterator q = v[i].begin()  ; // 那個區塊的頭 
				sum += ( p - q ) ;  	// 算小於x 的個數
			}
			 
			int disL = v[start].size() - (L % m) ; 
			int disR = (R % m) + 1 ; 
			
			for(int i=0,j=L;i<disL;++i,++j)
				if( s[j] < x )	sum++  ;
			
		 	for(int i=0,j=R;i<disR;++i,--j)
		 		if( s[j] < x )	sum++  ;
		 //	printf("disL = %d , disR = %d , sum = %d\n",disL , disR ,sum);
		 	
		 	int value = (int)((long long)u*(long long)sum/(long long)( R - L + 1 )) ; 
		 	int tarSit = p / m ; 
		 	int	tar = p % m  ;
		 	v[tarSit][tar] = value ; 
		 	s[p] = value ; //更新value 
		 	
		 	for(int i = (p/m)*m,j=0;j<v[tarSit].size();++j,i++) //把那整塊複製到塊狀中
		 		v[tarSit][j] = s[i] ; 
		 	
		 	sort( v[tarSit].begin() , v[tarSit].end() ) ; //sort那個區塊
			
		}
		
		for(int i=0;i<n;++i)
			printf("%d\n",s[i]);
	}
	return 0 ;
}
