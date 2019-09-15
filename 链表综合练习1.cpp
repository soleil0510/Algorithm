#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//后插创建链表 
void CreateList_1(LinkList &L,int n){
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
//前插创建链表 
void CreateList_2(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	for(int i=0;i<n;i++){
		LNode *p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}

//遍历并输出链表 
void Print(LinkList L){
	cout<<"\n结果：";
	LNode *p=L->next;
	if(p==NULL)
		cout<<"空";
	else{
		cout<<p->data;
		p=p->next;
		while(p){
			cout<<" "<<p->data;
			p=p->next;
		}	
	}

	cout<<endl;
	cout<<endl;
}
//合并为递增序列 （不能重复） 
void Merge_1(LinkList &A,LinkList &B,LinkList &C){
	C=A;
	LNode *a=A->next;
	LNode *b=B->next;
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
}
//合并为非递增序列 (允许重复)
void Merge_2(LinkList &A,LinkList &B,LinkList &C){
	C=A;
	LNode *a=A->next;
	LNode *b=B->next;
	LNode *c=C;
	while(a && b){
		if(a->data>b->data){
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
	
}
//求交集 --存放在A中 
void Intersection(LinkList &A,LinkList &B){
	LNode *c=A;
	LNode *a=A->next;
	LNode *b=B->next;
	while(a && b){
		if(a->data==b->data){
			c->next=a;
			c=a;
			a=a->next;
		}
		else if(a->data>b->data){
			b=b->next;
		}
		else{
			a=a->next;
		}
	}
	c->next=NULL;
	delete B;
}
//求差集 (仅出现在A中不出现在B中)
void Difference(LinkList &A,LinkList &B){
	LNode *c=A;
	LNode *a=A->next;
	LNode *b=B->next;
	while(a && b){
		if(a->data==b->data){
			a=a->next;
			b=b->next;
		}
		else if(a->data>b->data){
			b=b->next;
		}
		else{
			c->next=a;
			c=a;
			a=a->next;
		}
	}
	c->next=a;
	delete B; 
}

int main(){
	cout<<"1、合并为递增序列\n";
	cout<<"2、合并为非递增序列\n";
	cout<<"3、求交集\n";
	cout<<"4、求差集\n";
	
	while(1){
		cout<<"请选择：";
		int k;
		cin>>k;
		if(k==0)
			break;
		
		cout<<"\n输入两个整数：";
		int n,m;
		cin>>n>>m;
		
		cout<<"\n输入两个递增序列："<<endl;
		LinkList A,B,C;
		switch(k){
			case 1: 
				CreateList_1(A,n);
				CreateList_1(B,m);
				Merge_1(A,B,C);
				Print(C);break;
			case 2:
				CreateList_2(A,n);
				CreateList_2(B,m);
				Merge_2(A,B,C);
				Print(C);break;
			case 3:
				CreateList_1(A,n);
				CreateList_1(B,m);
				Intersection(A,B);
				Print(A);break;
			case 4:
				CreateList_1(A,n);
				CreateList_1(B,m);
				Difference(A,B);
				Print(A);break;
		} 	
	}
	
	
	return 0;
} 
