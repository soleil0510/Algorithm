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

//找到倒数第k个节点 
void FindNode(LinkList L,int k,int n){
	LNode *p=L->next;
	int j=1;
	while(j<(n-k+1)){
		p=p->next;
		j++;
	}	
	cout<<p->data<<endl;
	
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		LinkList L;
		CreatList(L,n);
		int k;
		cin>>k;
		FindNode(L,k,n);
	}
	return 0;
}
