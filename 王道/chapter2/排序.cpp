//#include<iostream>
//using namespace std;
//
//int main(){
//	int n;
//	int a[101];
//	while(cin>>n){
//		for(int i=0;i<n;i++){
//			cin>>a[i];
//		}
//		int temp;
//		for(int i=0;i<n-1;i++){
//			for(int j=i+1;j<n;j++){
//				if(a[i]>a[j]){
//					temp=a[i];
//					a[i]=a[j];
//					a[j]=temp;					
//				}				
//			}
//		}
//		for(int i=0;i<n;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
//} 




#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int a[101];
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
