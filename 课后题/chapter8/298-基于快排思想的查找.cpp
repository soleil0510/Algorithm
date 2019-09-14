#include<iostream>
#define N 1000
using namespace std;

int Partition(int a[],int low,int high){
	a[0]=a[low];
	while(low<high){
		while(low<high && a[high]>=a[0]){
			high--;
		}
		a[low]=a[high];
		while(low<high && a[low]<=a[0]){
			low++;
		}
		a[high]=a[low];
	}
	a[low]=a[0];
	return low;
}


void Sort(int a[],int low,int high){
	if(low<high){
		int idx=Partition(a,low,high);
		Sort(a,low,idx-1);
		Sort(a,idx+1,high);	
	}
}

int Find(int a[],int low,int high,int key){
	
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		int a[N];
		for(int i=1;i<=n;i++)
			cin>>a[i];
	//	Sort(a,1,n);

		int key;
		cin>>key;
		int idx=Find(a,1,n,key);
		if(idx==-1)
			cout<<"not find"<<endl;
		else
			cout<<idx<<" "<<key<<endl; 
	}		
		
	
	return 0;
} 
