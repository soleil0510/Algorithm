#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;  //½¨Á¢Ð¡¶¥¶Ñ 

int main(){
	int n;
	int a[1001];
	while(cin>>n){
		int sum=0;
		while(!Q.empty()){
			Q.pop();
		}
		for(int i=0;i<n;i++){
			cin>>a[i];
			Q.push(a[i]);
		}
		while(Q.size()>1){
			int b=Q.top();
			Q.pop();
			int c=Q.top();
			Q.pop();
			sum+=b+c;
			Q.push(b+c);
		}
		cout<<sum<<endl;
	}
	
	
	return 0;
} 
