#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string> 
#include <iostream>
#include <map>

using namespace std;

struct Node{
	int k ; 
	string name , type ; 
	
	Node( int _k , const string &_type , const string &_name ){
		name = _name  , type = _type ;
		k = _k  ;
	}
} ; 

vector < Node > v ; 
map < string , bool > hash  ;

int main(){
	
	int T ; 
	scanf("%d",&T ) ; 
	
	while( T-- ){
		v.clear() ; hash.clear(); 
	
		int n ; 
		scanf("%d",&n ) ;
		for(int i=0;i<n;++i){
			string type , name ; 
			int k ; 
			
			cin >> k >> type >> name ; 
			if( type == "A" )	v.insert( v.begin() , Node( k , type , name ) ) ;
			else if( type == "B" )	v.insert( v.begin() + v.size()/2 , Node( k , type , name ) ) ;
			else	v.push_back( Node( k , type , name ) ) ;
		}
		
		printf("Before:\n");
		int cnt = v.size() ; 
		for(int i=0;i<cnt;++i)
			cout << v[i].k << ' ' << v[i].type << ' ' << v[i].name << endl ; 
		
		printf("After:\n");
		int m ; 
		scanf("%d",&m );
		for(int i=0;i<m;++i){
			string name ; 
			cin >> name  ; 
			hash[name] = true;  
		}
		
		int ans = 0 ;
		for(int i=0;i<n;++i){
			string &name = v[i].name ; 
			if( hash.find( name ) == hash.end() ){
				ans++ ; 
				cout << v[i].k << ' ' << v[i].type << ' ' << v[i].name << endl ;
			}
		}	
		if( !ans ) printf("null\n");
	}

	return 0; 
}
