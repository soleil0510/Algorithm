#include<iostream>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;


//void InsertTree(Tree &T,char data){
//		
//}

void CreateTree(Tree &T){
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else{
		T=new TNode;
		T->data=ch;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
}

//ÅÐ¶ÏÊÇ·ñÊÇ¶þ²æÅÅÐòÊ÷ 
bool isBSTree(Tree T){
	if(T==NULL )
		return true;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return true;
		else if((T->lchild->data < T->data) && (T->rchild->data>T->data))
			return isBSTree(T->lchild) && isBSTree(T->rchild);
		else
			return false;
	}
	
}

void Inorder(Tree T){
	if(T){
		Inorder(T->lchild);
		cout<<T->data;
		Inorder(T->rchild);
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
		if(isBSTree(T))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
} 
