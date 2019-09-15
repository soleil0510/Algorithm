#include<iostream>
using namespace std;

typedef struct TNode{
	int data;
	struct TNode *lchild,*rchild;
}*Tree;

void Insert(Tree &T,int data){
	if(T==NULL){
		T=new TNode;
		T->data=data;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else{
		if(T->data>data)
			Insert(T->lchild,data);
		else
			Insert(T->rchild,data);
	}
	
}

void CreateTree(Tree &T,int n){
	T=NULL;
	int data;
	for(int i=0;i<n;i++){
		cin>>data;
		Insert(T,data);
	}
}

void Inorder(Tree T){
	if(T){
		Inorder(T->lchild);
		cout<<T->data<<" ";
		Inorder(T->rchild); 
	}
}
int main(){
	int n;
	cin>>n;
	Tree T;
	CreateTree(T,n);
	int data;
	cin>>data;
	Inorder(T);
	cout<<endl;
	
	Tree p=T;
	while(p && p->data<data){
		p=p->rchild;
	}
	T=p;
	
	Tree f=p;
	Tree q=p->lchild;
	while(q && q->data>=data){
		f=q;
		q=q->lchild;
	}
	f->lchild=NULL;
	Inorder(T);
	cout<<endl;
	
		
	return 0;
} 
