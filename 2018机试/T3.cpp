#include<iostream>
#define Max 1000
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

//�����㵽���������� 
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

//�������������� 
void CreateTree(Tree &T){
	char ch;
	cin>>ch;
	while(ch!='#'){
		Insert(T,ch);
		cin>>ch;
	}
}
//������� 
void InOrder(Tree T){
	if(T){
		InOrder(T->lchild);
		cout<<T->data;
		InOrder(T->rchild);
	}
}
//������ 
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
//��ǳ��� 
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

//��ʼ��
void InitQueue(Queue &Q){
	Q.base=new Tree[Max];
	if(!Q.base)
		return;
	Q.front=Q.rear=0;
} 


//�ж϶����Ƿ�Ϊ��
bool isEmpty(Queue Q){
	return Q.front==Q.rear;
} 

//�ж϶����Ƿ�Ϊ�� 
bool isFull(Queue Q){
	return (Q.rear+1)%Max==Q.rear;
} 

//���
void Push(Queue &Q,Tree T){
	if(isFull(Q))
		return ;
	Q.base[Q.rear]=T;
	Q.rear=(Q.rear+1)%Max;
} 

//����
void Pop(Queue &Q){
	if(isEmpty(Q))
		return ;
	Q.front=(Q.front+1)%Max;
} 

//ȡ��ͷ
Tree Front(Queue Q){
	if(isEmpty(Q))
		return NULL;
	return Q.base[Q.front];
} 

//����г���
int Size(Queue Q){
	return (Q.rear-Q.front+Max)%Max;
} 


//�ж��Ƿ�Ϊ��ȫ������ --�������н��в�α���
 
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
	cout<<"����һ���ַ������ԡ�#����β��";
	CreateTree(T);
	cout<<"������������";
	InOrder(T);
	cout<<endl;
	cout<<"�����Σ�"<<MaxDepth(T)<<endl;
	cout<<"��ǳ��Σ�"<<MinDepth(T)<<endl;
	if(isCompleteTree(T))
		cout<<"����ȫ������"<<endl;
	else
		cout<<"������ȫ������"<<endl;
		
	
	return 0;
}
