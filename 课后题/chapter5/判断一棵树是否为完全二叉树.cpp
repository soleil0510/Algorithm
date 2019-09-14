#include<iostream>
#include<queue>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}TNode,*Tree;

void CreateTree(Tree &T){
	char data;
	cin>>data;
	if(data=='0')
		T=NULL;
	else{
		T=new TNode;
		T->data=data;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
}

void InOrder(Tree T){
	if(T){
		cout<<T->data;
		InOrder(T->lchild);
		InOrder(T->rchild);
	}
}

//判断是否是完全二叉树 
bool isCompleteTree(Tree T){
	if(T==NULL)
		return false;
	else if(T->lchild==NULL && T->rchild==NULL)
		return true;
	else{
		queue<Tree> Q;
		Q.push(T);
		while(!Q.empty()){
			Tree p=Q.front();
			Q.pop();
			if(p->lchild && p->rchild){
				Q.push(p->lchild);
				Q.push(p->rchild);
			}
			else if(p->lchild==NULL && p->rchild)
				return false;
			else if(p->lchild && p->rchild==NULL){
				if(Q.empty())
					return false;
				else{
					while(!Q.empty()){
						Tree q=Q.front();
						Q.pop();
						if(q->lchild || q->rchild)
							return false;
					}	
				} 
				
			}
		} 
		return true;
	}
	
}

int main(){
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		InOrder(T);
		cout<<endl;
		if(isCompleteTree(T))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}	
	
	return 0;
}

