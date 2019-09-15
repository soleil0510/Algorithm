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

//ǰ�崴������ 
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

//������������� 
void Print(LinkList L){
	LNode *p=L->next;
	if(p==NULL)
		cout<<"��";
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

//�������ֵ 
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

//�ֽ�����,ʹ��A�Ľ��ռ� 
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
//ɾ��>=a <=b�Ľ�� 
void DeleteNodes(LinkList &L,int a,int b){
	//�ҵ���һ�����ڵ���a�Ľ���ǰһ�����,��pָ���� 
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
//���ҵ�����k�����---�ռ临�Ӷ�O��1�� 
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
//ɾ������ֵ��Ƚ�㣬ʱ�临�Ӷ�O��n�� 
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
	cout<<"1�������������ֵ\n";
	cout<<"2��ԭ����ת����\n";
	cout<<"3���ֽ�����\n";
	cout<<"4��ɾ������������ָ�������ڵĽ��\n";
	cout<<"5�����ҵ�����k�����\n";
	cout<<"6��ɾ������ֵ��ȵĽ��\n";
	
	while(1){
		cout<<"��ѡ��";
		int k;
		cin>>k;
		if(k==0)
			break;
		
		cout<<"\n����һ����������";
		int n;
		cin>>n;
		
		LinkList A;
		
		switch(k){
			case 1: 
				cout<<"\n����һ���������У�"<<endl;
				CreateList_1(A,n);
				cout<<"���ֵ��"<<FindMax(A)<<endl;
				break;
			case 2:
				cout<<"\n����һ���������У�"<<endl;
				CreateList_2(A,n);
				Print(A);
				break;
			case 3:
				cout<<"\n����һ����0�������У�"<<endl;
				CreateList_1(A,n);
				LinkList B,C;
				Split(A,B,C);
				Print(B);
				Print(C);
				break;
			case 4:
				cout<<"\n����һ���������У�"<<endl;
				CreateList_1(A,n);
				cout<<"����������������";
				int a,b;
				cin>>a>>b;
				DeleteNodes(A,a,b);
				Print(A);
				break;
			case 5:
				cout<<"\n����һ���������У�"<<endl;
				CreateList_1(A,n);
				cout<<"����һ������k��";
				int k;
				cin>>k;
				Find_K(A,k); 
			case 6:
				cout<<"\n����һ���������У�"<<endl;
				CreateList_1(A,n);
				Delete_Abs(A);
				cout<<"ɾ������ֵ��Ƚ�㣺";
				Print(A);
		}
		
		
	}
	
	return 0;
}
