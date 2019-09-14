#include<iostream>
using namespace std;

typedef struct TNode{
	char bf;
	struct TNode *lchild,*rchild;
}*Tree;

void CreateTree(Tree &T){
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else{
		T=new TNode;
		T->bf=ch;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
}

void Inorder(Tree T){
	if(T){
		cout<<T->bf;
		Inorder(T->lchild);
		Inorder(T->rchild);
	}
}

int Count(Tree T){
	if(T==NULL)
		return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return 1;
		if(T->bf=='1')
			return Count(T->lchild)+1;
		else
			return Count(T->rchild)+1;
	}
}
int main(){
	
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
//		Inorder(T);
//		cout<<endl;
		cout<<Count(T)<<endl;
	}	
	return 0;
} 
