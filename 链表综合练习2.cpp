#include<iostream>
#include<cstring>
#include<cmath>
#define N 1000
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

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

}

//查找最大值 
int FindMax(LinkList L){
	int max=0;
	LNode *p=L->next;
	max=p->data;
	p=p->next;
	while(p){
		if(p->data>max)
			max=p->data;
		p=p->next;
	}
	return max;
	
}

//分解链表,使用A的结点空间 
void Split(LinkList &A,LinkList &B,LinkList &C){
	C=new LNode;
	C->next=NULL;
	B=A;
	LNode *a=A->next;
	LNode *b=B;
	LNode *c=C;
	while(a){
		if(a->data>0){
			b->next=a;
			b=a;
			a=a->next;
		}
		else if(a->data<0){
			c->next=a;
			c=a;
			a=a->next;
		}
	}
	b->next=NULL;
	c->next=NULL;
} 
//删除>=a <=b的结点 
void DeleteNodes(LinkList &L,int a,int b){
	//找到第一个大于等于a的结点的前一个结点,用p指向它 
	LNode *p=L;
	LNode *q;
	while(p->next){
		q=p->next;
		if(q->data>=a){
			break;
		}
		p=q;
	} 
	
	LNode *m=L;
	LNode *n; 
	while(m->next){
		n=m->next;
		if(n->data==b){
			m=n;
			break;
		}
		if(n->data>b){
			break;
		}
		m=n;
	}
	LNode *k=p->next; 
	p->next=m->next;
	delete k;
	
}
//查找倒数第k个结点---空间复杂度O（1） 
void Find_K(LinkList L,int k){
	LNode *p=L->next;
	int n=0;
	while(p){
		n++;
		p=p->next;
	} 
	int j=n-k+1;
	LNode *q=L->next;
	while(q && j>1){
		q=q->next;
		j--;
	}
	cout<<q->data<<endl;
	
} 
//删除绝对值相等结点，时间复杂度O（n） 
void Delete_Abs(LinkList &L){
	int	a[N];
	memset(a,0,sizeof(int)*N);
	
	LNode *p=L;
	LNode *q;
	while(p->next){
		q=p->next;
		if(a[abs(q->data)]==0){
			a[abs(q->data)]++;
			p=q;
		}
		else{
			p->next=q->next;
			delete q;
		}	
	}
}

int main(){
	cout<<"1、查找链表最大值\n";
	cout<<"2、原地逆转链表\n";
	cout<<"3、分解链表\n";
	cout<<"4、删除有序链表中指定区间内的结点\n";
	cout<<"5、查找倒数第k个结点\n";
	cout<<"6、删除绝对值相等的结点\n";
	
	while(1){
		cout<<"请选择：";
		int k;
		cin>>k;
		if(k==0)
			break;
		
		cout<<"\n输入一个正整数：";
		int n;
		cin>>n;
		
		LinkList A;
		
		switch(k){
			case 1: 
				cout<<"\n输入一个整数序列："<<endl;
				CreateList_1(A,n);
				cout<<"最大值："<<FindMax(A)<<endl;
				break;
			case 2:
				cout<<"\n输入一个整数序列："<<endl;
				CreateList_2(A,n);
				Print(A);
				break;
			case 3:
				cout<<"\n输入一个非0整数序列："<<endl;
				CreateList_1(A,n);
				LinkList B,C;
				Split(A,B,C);
				Print(B);
				Print(C);
				break;
			case 4:
				cout<<"\n输入一个递增序列："<<endl;
				CreateList_1(A,n);
				cout<<"输入两个正整数：";
				int a,b;
				cin>>a>>b;
				DeleteNodes(A,a,b);
				Print(A);
				break;
			case 5:
				cout<<"\n输入一个整数序列："<<endl;
				CreateList_1(A,n);
				cout<<"输入一个整数k：";
				int k;
				cin>>k;
				Find_K(A,k); 
			case 6:
				cout<<"\n输入一个整数序列："<<endl;
				CreateList_1(A,n);
				Delete_Abs(A);
				cout<<"删除绝对值相等结点：";
				Print(A);
		}
		
		
	}
	
	return 0;
}
