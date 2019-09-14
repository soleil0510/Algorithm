#include<iostream>
#define N 1000
using namespace std;

typedef struct{
	int x;
	int count;
}Data;

typedef struct TNode{
  	Data data;
	struct TNode *lchild,*rchild;
}*Tree;


void InorderData(Tree T,int *a,int *b,int &i){
	if(T){
		InorderData(T->lchild,a,b,i);
		a[i]=T->data.x;
		b[i]=T->data.count;
		i++;
		//cout<<T->data.x<<" ";
		InorderData(T->rchild,a,b,i);
	}
}

void InsertTree(Tree &T,int a){
	if(T==NULL){
		T=new TNode;
		T->data.x=a;
		T->data.count=0;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else{
		if(T->data.x>a)
			InsertTree(T->lchild,a);
		else if(T->data.x<a)
			InsertTree(T->rchild,a);
	}
}

void Search(Tree &T,int x){
	Tree s=new TNode;
	s->data.x=x;
	s->data.count=0;
	s->lchild=NULL;
	s->rchild=NULL;
	
	if(T==NULL){
		T=s;
		return ;
	}
	else{
		Tree f=NULL;//记录当前遍历结点的双亲结点 
		Tree p=T;//记录当前遍历到的结点 
		while(p){
			if(p->data.x==x){
				p->data.count++;
				return ;
			}
			f=p;
			if(p->data.x>x)
				p=p->lchild;
			else
				p=p->rchild;
		}
		if(f->data.x>x)
			f->lchild=s;
		else
			f->rchild=s;
	}	
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		Tree T=NULL;
		while(n--){
			int a;
			cin>>a;
			InsertTree(T,a);
		}
		
		int x;
		cin>>x;

		Search(T,x);	
		
		int a[N];
		int b[N];
		int n=0;
		InorderData(T,a,b,n);
		
		cout<<a[0];
		for(int i=1;i<n;i++)
			cout<<" "<<a[i];
		cout<<endl;
		
		cout<<b[0];
		for(int i=1;i<n;i++)
			cout<<" "<<b[i];
		cout<<endl;
	}
	
	
	return 0;
}
