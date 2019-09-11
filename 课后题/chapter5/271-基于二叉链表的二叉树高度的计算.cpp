//二叉树的最深高度和最浅高度 
#include<iostream>
#define max 1000
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


//最深 
int MaxDepth(Tree T){
	if(T==NULL)
		return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return 1;
		int l=MaxDepth(T->lchild);
		int r=MaxDepth(T->rchild);
		return l>r?l+1:r+1;
	}
}

//最浅 
int MinDepth(Tree T){
	if(T==NULL)
		return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return 1;
		int l=MinDepth(T->lchild);
		if(l==0)
			l=max;
		int r=MinDepth(T->rchild);
		if(r==0)
			r=max;
		return l<r?l+1:r+1;
	}
}

int main(){
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		cout<<MaxDepth(T)<<endl;
		//cout<<MinDepth(T)<<endl;
	}
	
	return 0;
}
