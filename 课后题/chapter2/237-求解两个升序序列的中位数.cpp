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

LinkList MergeList(LinkList &A,LinkList &B){
	LinkList C=A;
	LNode *a=A->next;
	LNode *b=B->next;
	LNode *c=C;
	while(a && b){
		if(a->data<b->data){
			c->next=a;
			c=a;
			a=a->next;
		}
		else{
			c->next=b;
			c=b;
			b=b->next;
		}
	} 
	c->next=a?a:b;
	delete B;
	return C;
}



int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		LinkList A;
		LinkList B;
		CreatList(A,n);
		CreatList(B,n);
		LinkList C=	MergeList(A,B);
		LNode *q=C;
		while(n--){
			q=q->next;
		}
		cout<<q->data<<endl;
	}	
	
	
	return 0;
}
