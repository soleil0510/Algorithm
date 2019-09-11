#include<iostream>
#include<cstring>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}TNode,*Tree;

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

void PreOrder(Tree T){
	if(T){
		cout<<T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 

//T1 T2树结构是否相同 ----分治法
//先判断当前节点是否相同，再递归判断左子树右子树是否相同 
bool cmpTree(Tree T1,Tree T2){
	if(T1==NULL && T2==NULL)
		return true;
	if(T1->data != T2->data)
		return false;
	else{
		return (cmpTree(T1->lchild,T2->lchild) && cmpTree(T1->rchild,T2->rchild));
	}
}

int main(){
	Tree T1;
	Tree T2;	
	CreatTree(T1);
	while(T1!=NULL){
		CreatTree(T2);
		if(cmpTree(T1,T2)==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		//PreOrder(T1);
		
		CreatTree(T1);
	}
	return 0;
} 
