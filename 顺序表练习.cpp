#include<iostream>
#define N 1000
using namespace std;

typedef struct{
	int data[N];
	int length;
}SqList;

void Delete(SqList &L,int i){
	for(int j=i;j<L.length-1;j++)
		L.data[j]=L.data[j+1];
	L.length--;
}

void Delete_Items(SqList &L,int item){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==item){
			Delete(L,i);
			i--;
		}
	}
}

void Print(SqList L){
	for(int i=0;i<L.length;i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
}

int main(){
	cout<<"输入一个正整数：";
	int n;
	cin>>n;
	cout<<"输入一个整数序列：";
	SqList L;
	L.length=n;
	for(int i=0;i<n;i++){
		cin>>L.data[i];
	}
	cout<<"输入待删除的元素值：";
	int item;
	cin>>item;
	
	Delete_Items(L,item);
	Print(L);
	
	return 0;
} 
