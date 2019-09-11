#include<iostream>
#define MAXSIZE 100
using namespace std;

typedef struct{
	int *data;
	int length;
}SQList;

void CreatList(SQList &L,int n){
	L.data=new int[MAXSIZE];
	L.length=0;
	for(int i=0;i<n;i++){
		cin>>L.data[i];
		L.length++;
	}
}

void Display(SQList L){
	cout<<L.data[0]; 
	for(int i=1;i<L.length;i++){
		cout<<" "<<L.data[i];
	}
	cout<<endl;
}

void Delete(SQList &L,int i){
	for(int j=i;j<=L.length-1;j++)
		L.data[j-1]=L.data[j];
	L.length--;
}

//É¾³ýËùÓÐitem 
void DeleteItem(SQList &L,int item){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==item){
			Delete(L,i+1);
			i--;
		}
	} 
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		SQList L;
		CreatList(L,n);
		int item;
		cin>>item;
		DeleteItem(L,item);
		Display(L);
	}
} 
