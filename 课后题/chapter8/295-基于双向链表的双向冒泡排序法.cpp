#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *prior;
	struct LNode *next;
}LNode,*LinkList;

void CreateList(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	L->prior=NULL;
	LNode *r=L;
	
	for(int i=0;i<n;i++){
		LNode *p=new LNode;
		cin>>p->data;
		p->next=NULL;
		p->prior=r;
		r->next=p;
		r=p;
	}
	
}

void Print(LinkList L){
//	LNode *p=L->next;
//	while(p->next){
//		p=p->next;
//	}
//	while(p->prior){
//		cout<<p->data;
//		p=p->prior;
//	}
//	cout<<endl;
	LNode *p=L->next;
	cout<<p->data;
	p=p->next;
	while(p){
		cout<<" "<<p->data;
		p=p->next;
	}
	cout<<endl;
}

//Ë«ÏòÃ°ÅÝÅÅÐò 
void Sort(LinkList &L){
	int flag=1;
	LNode *head=L;
	LNode *tail=NULL;
	while(flag){
		flag=0;//Î´·¢Éú½»»» 
		LNode *p=head->next;
		while(p->next!=tail){
			LNode *q=p->next;
			if(q->data<p->data){
				flag=1;
				int t=q->data;
				q->data=p->data;
				p->data=t;
			}
			else
				p=p->next;
		}
		tail=p;
		p=tail->prior;
		while(flag && p->prior!=head){
			if(p->data<p->prior->data){
				int t=p->data;
				p->data=p->prior->data;
				p->prior->data=t;
			}
			else
				p=p->prior;
		}
		head=p;
	}
		
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
