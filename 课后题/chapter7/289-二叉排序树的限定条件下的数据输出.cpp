#include<iostream>
#define N 1000
using namespace std;

typedef struct TNode{
	int data;
	struct TNode *lchild,*rchild;
}*Tree;

void InsertTree(Tree &T,int data){
	if(T==NULL){
		T=new TNode;
		T->data=data;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else{
		if(T->data>data)
			InsertTree(T->lchild,data);
		else if(T->data<data)
			InsertTree(T->rchild,data);
	}
}

//void CreateTree(Tree &T){
//	T=NULL;
//	int data;
//	cin>>data;
//	while(data!=-1){
//		InsertTree(T,data);
//		cin>>data;
//	}
//}

void Inorder(Tree T){	
	if(T){
		Inorder(T->lchild);
		cout<<T->data<<" ";
		Inorder(T->rchild);
	}
}

//输出所有比x大的数，从小到大输出 
void printOverX(Tree T,int x){
	Tree p;
	Tree f;
	p=T;
	if(p){
		//找到第一个大于等于x的结点p 
    	while(p && p->data<x){
    		p=p->rchild;
		}
		T=p;
		if(p){
			f=p;
			p=p->lchild;
			while(p && p->data>=x){
				f=p;
				p=p->lchild;
			}
			if(p){
				f->lchild=NULL;
			}
			Inorder(T);
		} 
		
	}
	
}

int main(){
	
	int n;
	while(cin>>n){
		if(n==0)
			break;
		Tree T=NULL;
		int a;
		for(int i=0;i<n;i++){
			cin>>a;
			InsertTree(T,a);
		}
//		Inorder(T);
//		cout<<endl;
		int x;
		cin>>x;
		printOverX(T,x);
		cout<<endl;
		
	}
	return 0;
}
