#include<iostream>
#include<algorithm>
using namespace std;

struct program{
	int start;
	int end;
	
	bool operator < (const program &p){
		return end<p.end;
	}
}p[100];

int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			cin>>p[i].start>>p[i].end;
		}
		sort(p,p+n);
		int sum=1;
		int end=p[0].end;
		for(int i=1;i<n;i++){
			if(p[i].start>=end){
				sum+=1;
				end=p[i].end;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
