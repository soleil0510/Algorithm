#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void CreatList(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	LNode *r=L;
	for(int i=0;i<n;i++){
		LNode *p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	} 
}

void FindMax(LinkList L){
	LNode *p=L->next;
	int max=p->data;
	p=p->next;
	while(p){
		if(p->data>max)
			max=p->data;
		p=p->next;
	}
	cout<<max<<endl;
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		LinkList L;
		CreatList(L,n);
		FindMax(L);	
	}
	return 0;	
}
