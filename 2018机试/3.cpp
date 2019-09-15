//输入一个字符串，如DBACE，构造二叉排序树
//输出中序遍历，输出树的最深层次和最浅层次数，判断是否为完全二叉树 

#include<iostream>
#include<queue>
#define Max 1000

using namespace std;

typedef struct BSTNode{
	char data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//插入节点 
void InsertBST(BSTree &T,char data){
	if(T==NULL){
		BSTNode *S;
		S=new BSTNode;
		S->data=data;
		S->lchild=S->rchild=NULL;
		T=S;
	}	
	else if(data<T->data)
		InsertBST(T->lchild,data);
	else if(data>T->data)
		InsertBST(T->rchild,data);
}

//创建排序树 
void CreatBST(BSTree &T){
	T=NULL;
	char c;
	cin>>c;
	//0作为输入结束标志 
	while(c!='0'){
		InsertBST(T,c);
		cin>>c;
	}
}

//中序遍历
void InorderTraverse(BSTree &T){
	if(T){
		InorderTraverse(T->lchild);
		cout<<T->data<<" ";
		InorderTraverse(T->rchild);
	}
} 

//计算二叉树的深度 
int Depth(BSTree T){
	if(T==NULL)
		return 0;
	else{
		int m=Depth(T->lchild);
		int n=Depth(T->rchild);
		if(m>n)
			return m+1;
		else
			return n+1;
	}
}

//计算二叉树的最浅深度 
int lowDepth(BSTree T){
	if(T==NULL)
		return 0;
	if(T->lchild==NULL && T->rchild==NULL)
		return 1;
	
	int m=lowDepth(T->lchild)+1;
	int n=lowDepth(T->rchild)+1;
		
	if(m==1)
		m=Max;
	if(n==1)
		n=Max;
	
	return m < n ? m : n;
}


//判断是否是完全二叉树
bool isCompleteTree(BSTree T){

	queue<BSTree> Q;
	
	Q.push(T);
	while(!Q.empty()){
		BSTree p=Q.front();
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
					BSTree q=Q.front();
					Q.pop();
					if(q->lchild || q->rchild)
						return false;
				}
			}
			
		}
	}
	return true;
	
}

 
int main() {
	BSTree T;
	CreatBST(T);	
	cout<<"中序遍历："; 
	InorderTraverse(T);
	cout<<endl;
	cout<<"最深层次："<<Depth(T)<<endl;
	
	cout<<"最浅层次："<<lowDepth(T)<<endl;
	
	
	if(isCompleteTree(T))
		cout<<"是完全二叉树"; 
	else
		cout<<"不是完全二叉树"; 
	
	
}

