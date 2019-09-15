#include<iostream>
#include<queue>
#define N 1000
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

typedef struct TNode2{
	int weight;
	struct TNode2 *lchild,*rchild;
}*Tree2;

//�����������д��������� 
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
//�����������д��������� 
void CreateTree2(Tree2 &T){
	int ch;
	cin>>ch;
	if(ch==0)
		T=NULL;
	else{
		T=new TNode2;
		T->weight=ch;
		CreateTree2(T->lchild);
		CreateTree2(T->rchild);
	}
}

void PreOrder(Tree T){
	if(T){
		cout<<T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(Tree T){
	if(T){
		InOrder(T->lchild);
		cout<<T->data;
		InOrder(T->rchild);
	}
}

void AfterOrder(Tree T){
	if(T){
		AfterOrder(T->lchild);		
		AfterOrder(T->rchild);
		cout<<T->data;
	}
}

//�������Һ���
void ExchangeLF(Tree &T){
	if(T==NULL)
		return ;
	else if(T->lchild==NULL && T->rchild==NULL)
		return ;
	else{
		Tree temp=T->lchild;
		T->lchild=T->rchild;
		T->rchild=temp;
		ExchangeLF(T->lchild);
		ExchangeLF(T->rchild);
	}
} 

//����ȼ���---��α��� 
int MaxWidth(Tree T){
	queue<Tree> Q;
	if(T==NULL)
		return 0;
	else{
		int max=0;
		Q.push(T);
		while(!Q.empty()){
			//cout<<Q.size()<<endl;
			int size=Q.size();
			if(size>max)
				max=size;
			while(size--){
				Tree temp=Q.front();
				Q.pop();
				if(temp->lchild)
					Q.push(temp->lchild);
				if(temp->rchild)
					Q.push(temp->rchild);
			}	
		}
		return max;
	}	
} 

//�����һ���·����������Ⱥ�·��
char path[N];//��ǰ������·�� 
int len1;
char pathLong[N];//�·�� 
int len2;
void MaxPath(Tree T){
	if(T==NULL)
		return ;
	else{
		if(T->lchild==NULL && T->rchild==NULL){//������Ҷ�ӽڵ� 
			path[len1]=T->data;
			if(len1>len2){
				for(int i=0;i<=len1;i++)
					pathLong[i]=path[i];
				len2=len1;
			}	
		}	
		else{
			path[len1++]=T->data;
			MaxPath(T->lchild);
			MaxPath(T->rchild);
			len1--; 
		}
	}
} 

//�������Ҷ�ӽڵ㵽���ڵ��·��
void AllPaths(Tree T){
	if(T==NULL)
		return ;
	else{
		if(T->lchild==NULL && T->rchild==NULL){
			path[len1]=T->data;
			for(int i=len1;i>=0;i--)
				cout<<path[i];
			cout<<endl;
		}
		else{
			path[len1++]=T->data;
			AllPaths(T->lchild);
			AllPaths(T->rchild);
			len1--;
		}
		
	}
} 
//������ 
void NodeCount(Tree T,int &a,int &b,int &c){
	if(T==NULL)
		return ;
	else {
		if(T->lchild==NULL && T->rchild==NULL)
			a++;
		else if(T->lchild && T->rchild)
			c++;
		else
			b++;
		NodeCount(T->lchild,a,b,c);
		NodeCount(T->rchild,a,b,c);
	}
}

//����߶�
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

//��ǳ�߶�
int MinDepth(Tree T){
	if(T==NULL)
		return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return 1;
		else{
			int m=MinDepth(T->lchild)+1;
			if(m==1)
				m=N;
			int n=MinDepth(T->rchild)+1;
			if(n==1)
				n=N;
			return m<n?m:n;
		}
	}
} 

//�ж����ṹ�Ƿ����
bool isSame(Tree T1,Tree T2){
	if(T1==NULL && T2==NULL)
		return true;
	else{
		if(T1->data!=T2->data)
			return false;
		else{
			return (isSame(T1->lchild,T2->lchild) && isSame(T1->rchild,T2->rchild));	
		}
	}
} 

//����WPL
void WPL(Tree2 T,int &wpl){
	if(T==NULL)
		wpl+=0;
	else{
		if(T->lchild==NULL&&T->rchild==NULL){
			wpl+=T->weight*len1;
		}
		else{
			len1++;
			WPL(T->lchild,wpl);			
			WPL(T->rchild,wpl);			
			len1--;
		}
	}
} 

//�ж��Ƿ�����ȫ������
bool isComplete(Tree T){
	if(T==NULL){
		return false;
	}
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return true;
		else{
			queue<Tree> Q;
			Q.push(T);
			while(!Q.empty()){
				Tree temp=Q.front();
				Q.pop();
				if(temp->lchild==NULL && temp->rchild)
					return false;
				else if((temp->lchild && temp->rchild==NULL)||(temp->lchild==NULL && temp->rchild==NULL)){
					if(Q.empty())
						return false;
					while(!Q.empty()){
						Tree temp1=Q.front();
						Q.pop();
						if(temp1->lchild || temp1->rchild)
							return false;
					}
				}
				else if(temp->lchild && temp->rchild){
					Q.push(temp->lchild);
					Q.push(temp->rchild);
				}		
			}
			return true;
		}
	}
} 

//�ж϶���������
bool isSorted(Tree T){
	if(T==NULL)
		return true;
	else if(T->lchild==NULL && T->rchild==NULL)
		return true;
	else{
		if(T->lchild && T->lchild->data>T->data)
			return false;
		if(T->rchild && T->rchild->data<T->data)
			return false;
		return (isSorted(T->lchild) && isSorted(T->rchild));
	}
	
} 

int main(){
	cout<<"1�����Һ��ӽ���\n";
	cout<<"2������ȵļ���\n";
	cout<<"3���·�������\n";
	cout<<"4������Ҷ�ӽ�㵽���ڵ�·��\n";
	cout<<"5��������ͳ��(0,1,2��)\n";
	cout<<"6�����߶ȼ���--�������ǳ\n";
	cout<<"7���ж������������ṹ�Ƿ����\n";
	cout<<"8��WPL����\n";
	cout<<"9���ж��Ƿ�Ϊ��ȫ������\n";
	cout<<"10���ж��Ƿ��Ƕ���������\n";
	
	while(1){
		cout<<"\n��ѡ��";
		int k;
		cin>>k;
		if(k==0)
			break;
		Tree T;
		switch(k){
			case 10:
				cout<<"������������������У�";		
				CreateTree(T);
				if(isSorted(T))
					cout<<"Yes\n";
				else
					cout<<"No\n";
				break;
			case 9:
				cout<<"������������������У�";		
				CreateTree(T);
				if(isComplete(T))
					cout<<"Yes\n";
				else
					cout<<"No\n";
				break;
			case 1:
				cout<<"������������������У�";	
				CreateTree(T);
				ExchangeLF(T);
				cout<<"������";
				PreOrder(T);
				cout<<endl;
				break;
			case 2:
				cout<<"������������������У�";			
				CreateTree(T);
				cout<<"����ȣ�"<<MaxWidth(T)<<endl; 
				break;
			case 3:
				cout<<"������������������У�";			
				CreateTree(T);
				len1=len2=0;
				cout<<"�·����\n";				
				MaxPath(T);
				cout<<len2+1<<"\t";
				for(int i=0;i<=len2;i++)
					cout<<pathLong[i];
				cout<<endl;
				break;
			case 4:
				cout<<"������������������У�";			
				CreateTree(T);
				len1=0;
				AllPaths(T);
				break;
			case 5:
				cout<<"������������������У�";			
				CreateTree(T);
				cout<<"��������";
				int a,b,c;
				a=b=c=0;
				NodeCount(T,a,b,c);
				cout<<a<<" "<<b<<" "<<c<<endl;
				break;
			case 6:
				cout<<"������������������У�";			
				CreateTree(T);
				cout<<"����߶ȣ�"<<MaxDepth(T)<<endl;
				cout<<"��ǳ�߶ȣ�"<<MinDepth(T)<<endl;
				break;
			case 7:
				Tree T1;
				cout<<"�����������������������У�";			
				CreateTree(T);
				CreateTree(T1);
				if(isSame(T,T1))
					cout<<"Yes"<<endl;
				else
					cout<<"No\n";
				break;
			case 8:
				cout<<"������������������У�";		
				Tree2 T2;	
				CreateTree2(T2);
				len1=0;
				int wpl=0;
				WPL(T2,wpl);
				cout<<"WPL��"<<wpl<<endl;
				break;
			
		
		}
	}
	
	return 0;
}
