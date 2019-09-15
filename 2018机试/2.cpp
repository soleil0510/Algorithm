//输入n个整数，构造一个单链表
//遍历链表，输出正整数的个数
//若某个数的绝对值出现多次，只保留一个，删除剩余的数 

#include<iostream>
#include<cmath>
using namespace std;

typedef struct LNode{
	int elem;
	struct LNode *next;
}LNode,*LinkList;

void CreatList(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	LNode *r=L;
	for(int i=0;i<n;i++){
		LNode *p=new LNode;
		cin>>p->elem;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

void Display(LinkList &L){

	LinkList p;
	p=L->next;	
	while(p){
		cout<<p->elem<<" ";
		p=p->next;
	}
	cout<<endl;
}


int main(){
	LinkList L;
	int n;
	cin>>n;
	CreatList(L,n);
	
	cout<<"去重后的链表：";
	LNode *p=L->next;
	while(p){
		LNode *q=p;
		while(q->next){
			if(abs(q->next->elem)==abs(p->elem)){
				LNode *k=q->next;
				q->next=k->next;
				delete k;
			}
			else
				q=q->next;
		}
		p=p->next;
	}
	Display(L);
	cout<<"正数个数：";
	int ans=0;
	LNode *s;
	s=L->next;
	while(s){
		if(s->elem>0)
			ans++;
		s=s->next;	
	}
	cout<<ans<<endl;
	
	return 0;
}
