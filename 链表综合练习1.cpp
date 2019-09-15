#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//��崴������ 
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
	cout<<"\n�����";
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
	cout<<endl;
}
//�ϲ�Ϊ�������� �������ظ��� 
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
//�ϲ�Ϊ�ǵ������� (�����ظ�)
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
//�󽻼� --�����A�� 
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
//�� (��������A�в�������B��)
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
	cout<<"1���ϲ�Ϊ��������\n";
	cout<<"2���ϲ�Ϊ�ǵ�������\n";
	cout<<"3���󽻼�\n";
	cout<<"4����\n";
	
	while(1){
		cout<<"��ѡ��";
		int k;
		cin>>k;
		if(k==0)
			break;
		
		cout<<"\n��������������";
		int n,m;
		cin>>n>>m;
		
		cout<<"\n���������������У�"<<endl;
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
