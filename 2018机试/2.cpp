//����n������������һ��������
//������������������ĸ���
//��ĳ�����ľ���ֵ���ֶ�Σ�ֻ����һ����ɾ��ʣ����� 

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
	
	cout<<"ȥ�غ������";
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
	cout<<"����������";
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
