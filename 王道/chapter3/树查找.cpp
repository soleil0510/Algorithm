//树查找：输出完全二叉树第k层的所有结点

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
	int tree[1001];
	int n,m;
	while(cin>>n){
		for(int i=0;i<1001;i++)
			tree[i]=0;
		for(int i=0;i<n;i++)
			cin>>tree[i];
		cin>>m;
		if(m>int(log(n)/log(2))+1)
			cout<<"EMPTY";
		else{
			cout<<tree[int(pow(2.0,m-1)-1)];
			int j;
			for(j=pow(2.0,m-1);j<pow(2.0,m)-1;j++){
				if(tree[j]!=0)
					cout<<" "<<tree[j];
				else
					break;
			}	
		}
		

		cout<<endl;
	}	
	return 0;
} 
