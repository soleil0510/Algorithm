#include<iostream>
using namespace std;

typedef struct LNode{
	char data;
	struct LNode *next;
}LNode,*LinkList;

void CreatList(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	
	for(int i=0;i<n;i++){
		LNode *p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;		
	}
	
}

int main(){
	int m,n;
	while(cin>>m>>n){
		if(m==0 && n==0)
			break;
		LinkList str1;
		LinkList str2;
		CreatList(str1,m);
		CreatList(str2,n);
		LNode *p=str1;
		LNode *q=str2;
		while(p->next && q->next){
			if(p->next->data==q->next->data){
				p=p->next;
				q=q->next;
			}
			else{
				break;
			}
			
		}
		cout<<p->data<<endl;
		
	}
	
	return 0;
}
