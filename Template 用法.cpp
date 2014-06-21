#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
 
using namespace std;

template <class T> 
class stack{
	public:
		stack();
		T &top() const;
		void push( const T &x  );
		void pop();
		bool empty();
		int &size() ; 
	private:
		int capacity ; 
		T *array ; 
};

template <class T>
int& stack<T>::size(){
	return capacity ; 
}

template <class T> 
stack<T>::stack(){
	array = new T[100] ; 			
	capacity = 0 ; 
}

template <class T>
T& stack<T>::top() const{
	return array[capacity] ;  
}

template <class T>
void stack<T>::push( const T &x  ){
	array[++capacity] = x ;  
}

template <class T>	
void stack<T>::pop(){
	--capacity; 	
}

template <class C>
bool stack<C>::empty(){
	return capacity == 0 ; 	
}

struct Node{
	int x , y;  
};
int main(){
	stack < Node > A ; 
	int n ;
	scanf("%d",&n) ; 
	
	for(int i=0;i<n;++i){
		Node in;
		scanf("%d %d",&in.x, &in.y) ;
		A.push( in ) ; 	
		//printf("%d\n",A.top());
	}
	
	while( !A.empty() ) {
		Node pii = A.top () ; A.pop();
		printf("%d %d\n",pii.x,pii.y);
	}
		
	return 0 ;
} 
