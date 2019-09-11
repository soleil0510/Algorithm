#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void CreatList(LinkList &L,int n){
	L = new LNode;
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


void Display(LinkList L){
	LNode *p=L->next;
	cout<<p->data;
	p=p->next;
	while(p){
		cout<<" "<<p->data;
		p=p->next;
	}
	cout<<endl;
}

void splitList(LinkList A){

	LinkList B=A;
	LinkList C=new LNode;
	LNode *a=A->next;
	LNode *b=B;
	LNode *c=C;
	while(a){
		if(a->data<0){
			b->next=a;
			b=a;
			a=a->next;
		}
		else if(a->data>0){
			c->next=a;
			c=a;
			a=a->next;
		}
	}
	if(a==NULL){
		b->next=NULL;
		c->next=NULL;
	}
	Display(B);
	Display(C);
	
}



int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		LinkList A;
		CreatList(A,n);
		splitList(A);
	
	}
	
	return 0;
} 
