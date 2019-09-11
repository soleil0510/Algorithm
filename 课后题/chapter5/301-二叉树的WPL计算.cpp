#include<iostream>
using namespace std;

typedef struct TNode{
	int data;
	struct TNode *lchild,*rchild;
}*Tree;

void CreateTree(Tree &T){
	int data;
	cin>>data;
	if(data==0)
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

int len;
int wpl;
void WPL(Tree T){
	if(T==NULL)
		return ;
	if(T->lchild==NULL && T->rchild==NULL){ //р╤вс╫з╣Ц 
		wpl+=T->data*len;
	}
	else{
		len++;
		WPL(T->lchild);
		WPL(T->rchild);
		len--;
	}
}

int main(){
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
//		InOrder(T);
//		cout<<endl;
		len=0;
		wpl=0;
		WPL(T);
		cout<<wpl<<endl;

	}	
	
	return 0;
}

