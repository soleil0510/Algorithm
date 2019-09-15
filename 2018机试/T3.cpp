#include<iostream>
#define Max 1000
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

//插入结点到二叉排序树 
void Insert(Tree &T,char ch){
	if(T==NULL){
		T=new TNode;
		T->data=ch;
		T->lchild=NULL;
		T->rchild=NULL;
	} 
	else{
		if(T->data>ch)
			Insert(T->lchild,ch);
		else
			Insert(T->rchild,ch);
	}
}

//创建二叉排序树 
void CreateTree(Tree &T){
	char ch;
	cin>>ch;
	while(ch!='#'){
		Insert(T,ch);
		cin>>ch;
	}
}
//中序遍历 
void InOrder(Tree T){
	if(T){
		InOrder(T->lchild);
		cout<<T->data;
		InOrder(T->rchild);
	}
}
//最深层次 
int MaxDepth(Tree T){
	if(T==NULL)
		return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return 1;
		else{
			int m=MaxDepth(T->lchild)+1;
			int n=MaxDepth(T->rchild)+1;
			return m>n?m:n;
		}
	}
} 
//最浅层次 
int MinDepth(Tree T){
	if(T==NULL)
		return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return 1;
		else{
			int m=MinDepth(T->lchild)+1;
			if(m==1)
				m=Max;
			int n=MinDepth(T->rchild)+1;
			if(n==1)
				n=Max;
			return m<n?m:n;
		}
	}
}

typedef struct{
	Tree *base;
	int front;
	int rear; 
}Queue; 

//初始化
void InitQueue(Queue &Q){
	Q.base=new Tree[Max];
	if(!Q.base)
		return;
	Q.front=Q.rear=0;
} 


//判断队列是否为空
bool isEmpty(Queue Q){
	return Q.front==Q.rear;
} 

//判断队列是否为满 
bool isFull(Queue Q){
	return (Q.rear+1)%Max==Q.rear;
} 

//入队
void Push(Queue &Q,Tree T){
	if(isFull(Q))
		return ;
	Q.base[Q.rear]=T;
	Q.rear=(Q.rear+1)%Max;
} 

//出队
void Pop(Queue &Q){
	if(isEmpty(Q))
		return ;
	Q.front=(Q.front+1)%Max;
} 

//取队头
Tree Front(Queue Q){
	if(isEmpty(Q))
		return NULL;
	return Q.base[Q.front];
} 

//求队列长度
int Size(Queue Q){
	return (Q.rear-Q.front+Max)%Max;
} 


//判断是否为完全二叉树 --借助队列进行层次遍历
 
bool isCompleteTree(Tree T){
	if(T==NULL)
		return false;
	else{
		
			Queue Q;
			InitQueue(Q);
			Push(Q,T);
			while(!isEmpty(Q)){
				Tree temp=Front(Q);
				Pop(Q);
				if(T->lchild==NULL && T->rchild==NULL)
					return true;
				else if(temp->lchild==NULL && temp->rchild)
					return false;
				else if((temp->lchild && temp->rchild==NULL)||(temp->lchild==NULL && temp->rchild==NULL)){
					while(!isEmpty(Q)){
						Tree p=Front(Q);
						Pop(Q);
						if(p->lchild || p->rchild)
							return false;
					}
				}
				else{
					Push(Q,T->lchild);
					Push(Q,T->rchild);
				}
			}
			return true;
	}
}
 
int main(){
	Tree T=NULL;
	cout<<"输入一个字符串，以“#”结尾：";
	CreateTree(T);
	cout<<"中序遍历结果：";
	InOrder(T);
	cout<<endl;
	cout<<"最深层次："<<MaxDepth(T)<<endl;
	cout<<"最浅层次："<<MinDepth(T)<<endl;
	if(isCompleteTree(T))
		cout<<"是完全二叉树"<<endl;
	else
		cout<<"不是完全二叉树"<<endl;
		
	
	return 0;
}
