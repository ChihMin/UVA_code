#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
                                                                                
using namespace std;

int s[100000]={0},list[100000]={0},p[100000]={0},p2[100000]={0};

int main(){
	int l,r,last=0,h,n=0,b=1000;
	
	while(scanf("%d%d%d",&l,&h,&r)!=EOF)
		for(int i=l;i<r;i++){
			if(h>s[i])	s[i]=h;
			if(r>last)	last=r;
			if(b>l)	b=l;
		}
	
	n=1;
	
	for(int i=0;i<=last;i++){
		if(list[n-1]!=s[i]){
			list[n]=s[i];
			p2[n]=i;
			n++;
		}	
	}
	
	for(int i=1;i<n-1;i++)		
		printf("%d %d ",p2[i],list[i]);
	
	
	printf("%d %d\n",p2[n-1],list[n-1]);
	
	//system("pause");
	return 0;	
}
