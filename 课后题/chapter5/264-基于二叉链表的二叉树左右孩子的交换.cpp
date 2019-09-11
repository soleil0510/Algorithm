#include<iostream>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

void CreatTree(Tree &T){
	char ch;
	cin>>ch;
	if(ch=='0')
		T=NULL;
	else{
		T=new TNode;
		T->data=ch;
		CreatTree(T->lchild);
		CreatTree(T->rchild);
	}
}

void exchangeLR(Tree &T){
	Tree temp;
	if(T==NULL)
		return;
	if(T->lchild==NULL && T->rchild==NULL)
		return;
	else{
		temp=T->lchild;
		T->lchild=T->rchild;
		T->rchild=temp;
	}
	exchangeLR(T->lchild);
	exchangeLR(T->rchild);
}

void PreOrder(Tree T){
	if(T){
		cout<<T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

int main(){
	
	while(1){
		Tree T;
		T=NULL;
		CreatTree(T);
		if(T==NULL)
			break;
		exchangeLR(T);
		PreOrder(T);
		cout<<endl;

	}	
	
	return 0;
}
