#include<iostream>
#include<cstring>
#include<cmath>
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

void Display(LinkList &L){
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
		LNode *pre=L;
		int temp[1000];
		memset(temp,0,sizeof(int)*1000);
		while(pre->next){
			LNode *p=pre->next;
			if(temp[abs(p->data)]==0){
				temp[abs(p->data)]=1;
				pre=p;
			}
			else{
				pre->next=p->next;
				delete p;
			}
			
		}
		
//		LNode *p=L->next;
//		
//		while(p){
//			LNode *q=p;
//			
//			while(q->next){
//				if(abs(q->next->data)==abs(p->data)){
//					LNode *k=q->next;
//					q->next=k->next;
//					delete k;
//				}
//				else
//					q=q->next;
//			}
//			p=p->next;
//		} 
		
		Display(L);
	}
	
	return 0;
}
