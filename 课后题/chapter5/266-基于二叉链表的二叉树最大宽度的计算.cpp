#include<iostream>
#include<queue>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

//typedef struct QNode{
//	Tree data;
//	struct QNode *next;
//}QNode,*Queue;
//
//typedef struct{
//	Queue front;
//	Queue rear;
//}LinkQueue;
//
//void InitQueue(LinkQueue &Q){
//	Q.front=Q.rear=new QNode;
//	Q.front->next=NULL; 
//}
//
//void PushQueue(LinkQueue &Q,Tree t){
//	Queue q=new QNode;
//	q->data=t;
//	q->next=NULL;
//	Q.front->next=q;
//	Q.rear=q;
//}
//
//Tree PopQueue(LinkQueue &Q){
//	Tree t;
//	if(Q.front==Q.rear){
//		t->data=NULL;
//	}
//		
//	Queue p=Q.front->next;
//	t=p->data;
//	Q.front->next=p->next;
//	if(Q.rear==p)
//		Q.rear=Q.front;
//	delete p;
//	
//	return t;
//}
//
//Tree FrontQueue(LinkQueue Q){
//	if(Q.front!=Q.rear)
//		return Q.front->next->data;
//}
//
//bool isEmpty(LinkQueue Q){
//	return Q.front==Q.rear;
//}
//
//int Size(LinkQueue Q){
//	int sum=0;
//	QNode q=Q.front->next;
//	while(q){
//		sum++;
//		q=q->next;
//	}
//	return sum;
//	
//}
//
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

int Count(Tree T){
	if(T==NULL)
		return 1;
	queue<Tree> Q;
	Q.push(T);
//	LinkQueue Q;
//	InitQueue(Q);
//	PushQueue(Q,T);
	int max=0;
	while(!Q.empty()){
		int size=Q.size();
		if(size>max)
			max=size;
		while(size--){
			Tree temp=Q.front();
			Q.pop();
			if(temp->lchild!=NULL)
				Q.push(temp->lchild);
			if(temp->rchild!=NULL)
				Q.push(temp->rchild);
		}
	}
	return max;
}

int main(){
	while(1){
		Tree T;
		CreateTree(T);
		if(T==NULL)
			break;
		
		cout<<Count(T)<<endl;
	}	
	
	
	return 0;
}
