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

void DoubleOrder(Tree T){
	if(T){
		cout<<T->data;
		DoubleOrder(T->lchild);
		cout<<T->data;
		DoubleOrder(T->rchild);
	}
}

int main(){
	
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		DoubleOrder(T);
		cout<<endl;
	}	
	
	
	return 0;
}
