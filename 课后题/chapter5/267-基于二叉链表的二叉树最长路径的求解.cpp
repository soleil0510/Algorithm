#include<iostream>
#define N 1000
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

char path[N];
int len;
char longpath[N];
int longlen;

void LongPath(Tree T){
	if(T){
		 //遍历到叶子节点，path中形成一条新路径，
		 //与longpath中比较，若更长，则替换 
		if(T->lchild==NULL && T->rchild==NULL){
			path[len]=T->data;
			if(len>longlen){
				for(int i=0;i<len+1;i++)
					longpath[i]=path[i];
				longlen=len;
			}
		}
		//递归遍历左子树和右子树的每一条路径 
		else {
			path[len++]=T->data;
			LongPath(T->lchild);
			LongPath(T->rchild);
			len--;
		}
		
	}
	
}

int main(){
	
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		len=0;
		longlen=0;
		LongPath(T);
		cout<<longlen+1<<endl;
		for(int i=0;i<longlen+1;i++)
			cout<<longpath[i];
		cout<<endl;	
	}	
	return 0;
}
