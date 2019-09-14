#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//ºó²å·¨ 
void CreateList(LinkList &L,int n){
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

void Sort(LinkList &L){
	
	LNode *p=L->next;
	LNode *q;
	while(p->next){
		LNode *k=p;
		q=p->next;
		while(q){
			if(q->data<k->data)
				k=q;
			q=q->next;
		}
		if(k!=p){
			int data=p->data;
			p->data=k->data;
			k->data=data;
		}	
		p=p->next;
	}
	
}

void Print(LinkList L){
	LNode *p=L->next;
	cout<<p->data;
	p=p->next;
	while(p){
		cout<<" "<<p->data;
		p=p->next;
	}
	cout<<endl;
}

int main(){

	int n;
	while(cin>>n){
		if(n==0)
			break;
		LinkList L;
		CreateList(L,n);
		Sort(L);
		Print(L);
	}
		
	return 0;
} 
