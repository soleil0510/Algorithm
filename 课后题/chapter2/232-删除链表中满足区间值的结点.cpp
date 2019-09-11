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

void Delete(LinkList &L,int n1,int n2){
	LNode *p=L;
	LNode *q=L;
	int j=0;
	while(p->next && (j<n1-1)){
		p=p->next;
		j++;
	}
	int k=0;
	while(q->next && (k<n2)){
		q=q->next;
		k++;
	}
	p->next=q->next;
}

void DeleteNodes(LinkList &L,int mink,int maxk){
	LNode *p=L->next;
	int n1=1;//开始结点的位置 
	while(p){
		if(p->data>=mink){
			break;
		}
		else{
			n1++;
			p=p->next;
		}
	}
	
	p=L->next;
	int n2=1;
	while(p){
		if(p->data==maxk){
			break;
		}
		else if(p->data>maxk){
			n2=n2-1;
			break;
		}
		else{
			n2++;
			p=p->next;
		}
	}
	Delete(L,n1,n2);
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
	int n;
	while(cin>>n){
		if(n==0)
			break;
		LinkList L;
		CreatList(L,n);
		
		int mink,maxk;
		cin>>mink>>maxk;
		DeleteNodes(L,mink,maxk);
		Display(L);
	}
	
	return 0;
}
