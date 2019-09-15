#include<iostream>
#include<cstring>
#include<cmath>
#define N 1000
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//�������� 
void CreateList(LinkList &L,int n){
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
//�������� 
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
//�������������� 
int Count(LinkList L){
	int num=0;
	LNode *p=L->next;
	while(p){
		if(p->data>0)
			num++;
		p=p->next;
	} 
	return num;
}
//ɾ������ֵ�ظ���Ԫ�� 
void DeleteAbs(LinkList &L){
	int temp[N];//�Խ�����ֵ��Ϊ�����±꣬�����ֵ����þ���ֵ�Ƿ���ֹ�
	memset(temp,0,sizeof(int)*N);
	LNode *p=L;
	while(p->next){
		LNode *q=p->next;
		if(temp[abs(q->data)]==0){
			temp[abs(q->data)]++;
			p=q;
		}
		else{
			p->next=q->next;
			delete 	q;
		}
	}
	
}

int main(){
	int n;
	cin>>n;
	LinkList L;
	CreateList(L,n);
	cout<<"��������"<<endl;
	Display(L);
	cout<<"�������ĸ�����"<<endl;
	cout<<Count(L)<<endl;
	cout<<"ɾ������ֵ֮�������"<<endl;
	DeleteAbs(L);
	Display(L);

	return 0;
}
