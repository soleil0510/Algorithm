#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//前插法 
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

//求差集 
LinkList DifferentSet(LinkList &A,LinkList &B){
	LinkList C=A;
	LNode *a=A->next;
	LNode *b=B->next;
	LNode *c=C; 
	while(a && b){
		if(a->data==b->data){
			a=a->next;
			b=b->next;
		} 
		else{
			if(a->data>b->data){
				b=b->next;
			} 
			else{
				c->next=a;
				c=a;
				a=a->next;
			}
		}
	}
	c->next=a?a:NULL;
	delete B;
	return C;
	
} 

void Display(LinkList L){
	LNode *p=L->next;
	cout<<p->data;
	p=p->next;
	int sum=1;
	while(p){
		cout<<" "<<p->data;
		p=p->next;
		sum++;
	}
	cout<<endl;
	cout<<sum<<endl;
}

int main(){
	
	int m,n;
	while(cin>>m>>n){
		if(m==0&&n==0)
			break;
		LinkList A,B;
		CreatList(A,m);
		CreatList(B,n);
		
		LinkList C=DifferentSet(A,B);
		
		Display(C);
		
	}
		
	return 0;
}
