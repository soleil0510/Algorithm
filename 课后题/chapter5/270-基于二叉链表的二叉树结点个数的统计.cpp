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

void Count(Tree T,int &a,int &b,int &c){
	if(T==NULL)
		return ;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			a++;
		else{
			if((T->lchild==NULL &&T->rchild ) || (T->lchild && T->rchild==NULL))
				b++;
			else if(T->lchild && T->rchild)
				c++;

		}	
		Count(T->lchild,a,b,c);
		Count(T->rchild,a,b,c);
	} 	
}

//0¶È½áµã
void ZeroNode(Tree T,int &num){
	if(T==NULL)
		return ;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			num++;
		
		ZeroNode(T->lchild,num);
		ZeroNode(T->rchild,num);	
			
	}
	
} 

void OneNode(Tree T,int &num){
	if(T==NULL)
		return ;
	else{
		if((T->lchild==NULL &&T->rchild ) || (T->lchild && T->rchild==NULL))
			num++;	
		OneNode(T->lchild,num);
		OneNode(T->rchild,num);		
	}
	
	
}

void TwoNode(Tree T,int &num){
	if(T==NULL)
		return ;
	else{
		if(T->lchild && T->rchild )
			num++;
		TwoNode(T->lchild,num);
		TwoNode(T->rchild,num);
	}
}

int main(){
	
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		int num1=0;
		ZeroNode(T,num1);
		int num2=0;
		OneNode(T,num2);
		int num3=0;
		TwoNode(T,num3);

		cout<<num1<<" "<<num2<<" "<<num3<<endl;
//		int a=0;
//		int b=0;
//		int c=0;
//		Count(T,a,b,c);
//		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
