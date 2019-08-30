//¶þ²æÅÅÐòÊ÷

#include<iostream>
using namespace std;

struct Node{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[101];
int loc;

void preorder(Node *T){
	cout<<T->c<<" ";
	if(T->lchild!=NULL)
		preorder(T->lchild);
	if(T->rchild!=NULL)
		preorder(T->rchild);	
}


void middleorder(Node *T){
	if(T->lchild!=NULL)
		middleorder(T->lchild);
	cout<<T->c<<" ";
	if(T->rchild!=NULL)
		middleorder(T->rchild);	
}


void postorder(Node *T){
	if(T->lchild!=NULL)
		postorder(T->lchild);
	if(T->rchild!=NULL)
		postorder(T->rchild);
	cout<<T->c<<" ";
}

Node *create(){
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

Node *insert(Node *T,int x){
	if(T==NULL){
		T=create();
		T->c=x;
		return T;
	}
	else{
		if(x<T->c)
			T->lchild=insert(T->lchild,x);
		else
			T->rchild=insert(T->rchild,x);
		return T;
	}
	
}

int main(){
	int n;
	while(cin>>n){
		loc=0;
		int x;
		Node *T=NULL;
		for(int i=0;i<n;i++){
			cin>>x;
			T=insert(T,x);
		}
		preorder(T);
			cout<<endl;
			middleorder(T);
			cout<<endl;
			
			postorder(T);
			cout<<endl;
	}
	
	return 0;
} 
