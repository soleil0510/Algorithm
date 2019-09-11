#include<iostream>
#define N 1000 
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

char path[N];
int idx;

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

void PrintPaths(Tree T){
	if(T){
		if(T->lchild==NULL && T->rchild==NULL){
			path[idx]=T->data;
			for(int i=idx;i>=0;i--)
				cout<<path[i];
			cout<<endl;
		}
		else{
			path[idx++]=T->data;
			PrintPaths(T->lchild);
			PrintPaths(T->rchild);
			idx--;
		}
		
		
	}
	
}

int main(){

	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		idx=0;
		PrintPaths(T);
	}
	
	return 0;
} 
