//求二叉树子树结点个数
#include<iostream>
using namespace std;
int sum;

void count(int m,int n){
	if(m*2<=n)
		sum++;	
	else
		return;
	if(m*2+1<=n)
		sum++;
	else 
		return;
	count(2*m,n);
	count(2*m+1,n);
}

int main(){
	int n,m;
	while(cin>>m>>n){
		sum=1;
		count(m,n);
		cout<<sum<<endl;
	}
	
	return 0;
}
