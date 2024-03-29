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

//�ϲ�����
LinkList MergeList(LinkList &A,LinkList &B){
	
	LNode *a=A->next;
	LNode *b=B->next;
	LinkList C=A;
	LNode *c=C;
	while(a && b){
		if(a->data<b->data){
			c->next=a;
			c=a;
			a=a->next;
		}
		else if(a->data>b->data){
			c->next=b;
			c=b;
			b=b->next;
		}
		else{
			c->next=a;
			c=a;
			a=a->next;	
			b=b->next;
		}
	}
	c->next=a?a:b;
	delete B;
	return C;
	
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

int main(){
	
	int m,n;
	while(cin>>m>>n){
		if(m==0&&n==0)
			break;
		LinkList A,B;
		CreatList(A,m);
		CreatList(B,n);
		
		LinkList C=MergeList(A,B);
		
		Display(C);
		
	}
		
	return 0;
}
