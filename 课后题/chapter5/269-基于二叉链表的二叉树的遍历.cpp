#include<iostream>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

void CreateTree(Tree &T){
	char ch;
	cin>>ch;
	if(ch=='0')
		T=NULL;
	else{
		T=new TNode;
		T->data=ch;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
	
}

void PreOrder(Tree T){
	if(T){
		cout<<T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}


void InOrder(Tree T){
	if(T){
		InOrder(T->lchild);
		cout<<T->data;
		InOrder(T->rchild);
	}
}


void AfterOrder(Tree T){
	if(T){
		AfterOrder(T->lchild);
		AfterOrder(T->rchild);
		cout<<T->data;
	}
}

int main(){
	
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		PreOrder(T);
		cout<<endl;
		
		InOrder(T);
		cout<<endl;
		
		AfterOrder(T);
		cout<<endl;
	}
	return 0;
}
