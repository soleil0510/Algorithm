#include<iostream>
#include<cstring>
#include<cmath>
#define N 1000
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//创建链表 
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
//遍历链表 
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
//计算正整数个数 
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
//删除绝对值重复的元素 
void DeleteAbs(LinkList &L){
	int temp[N];//以结点绝对值作为数组下标，数组的值代表该绝对值是否出现过
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
	cout<<"遍历链表："<<endl;
	Display(L);
	cout<<"正整数的个数："<<endl;
	cout<<Count(L)<<endl;
	cout<<"删除绝对值之后的链表："<<endl;
	DeleteAbs(L);
	Display(L);

	return 0;
}
