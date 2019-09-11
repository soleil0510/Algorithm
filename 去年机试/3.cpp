//����һ���ַ�������DBACE���������������
//������������������������κ���ǳ��������ж��Ƿ�Ϊ��ȫ������ 

#include<iostream>
#include<queue>
#define Max 1000

using namespace std;

typedef struct BSTNode{
	char data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//����ڵ� 
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

//���������� 
void CreatBST(BSTree &T){
	T=NULL;
	char c;
	cin>>c;
	//0��Ϊ���������־ 
	while(c!='0'){
		InsertBST(T,c);
		cin>>c;
	}
}

//�������
void InorderTraverse(BSTree &T){
	if(T){
		InorderTraverse(T->lchild);
		cout<<T->data<<" ";
		InorderTraverse(T->rchild);
	}
} 

//�������������� 
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

//�������������ǳ��� 
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


//�ж��Ƿ�����ȫ������
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
	cout<<"���������"; 
	InorderTraverse(T);
	cout<<endl;
	cout<<"�����Σ�"<<Depth(T)<<endl;
	
	cout<<"��ǳ��Σ�"<<lowDepth(T)<<endl;
	
	
	if(isCompleteTree(T))
		cout<<"����ȫ������"; 
	else
		cout<<"������ȫ������"; 
	
	
}

