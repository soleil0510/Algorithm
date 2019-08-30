#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	int n;
	int a[1001];
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>a[i];
		int sum=0;
		while(n>1){
			int temp=0;
			sort(a,a+n);
			temp=a[0]+a[1];
			sum+=temp;
			if(n==2)
				break;
			for(int j=0;j<n-2;j++){
				a[j]=a[j+2];
			}
			a[n-2]=temp;
			n=n-1;
		}
		cout<<sum<<endl;
	} 
	return 0;
}
