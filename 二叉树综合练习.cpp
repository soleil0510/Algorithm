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

//根据先序序列创建二叉树 
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
//根据先序序列创建二叉树 
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

//交换左右孩子
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

//最大宽度计算---层次遍历 
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

//求出第一条最长路径并输出长度和路径
char path[N];//当前遍历的路径 
int len1;
char pathLong[N];//最长路径 
int len2;
void MaxPath(Tree T){
	if(T==NULL)
		return ;
	else{
		if(T->lchild==NULL && T->rchild==NULL){//遍历到叶子节点 
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

//输出所有叶子节点到根节点的路径
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
//结点个数 
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

//最深高度
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

//最浅高度
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

//判断树结构是否相等
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

//计算WPL
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

//判断是否是完全二叉树
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

//判断二叉排序树
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
	cout<<"1、左右孩子交换\n";
	cout<<"2、最大宽度的计算\n";
	cout<<"3、最长路径的求解\n";
	cout<<"4、所有叶子结点到根节点路径\n";
	cout<<"5、结点个数统计(0,1,2度)\n";
	cout<<"6、树高度计算--最深和最浅\n";
	cout<<"7、判断两个二叉树结构是否相等\n";
	cout<<"8、WPL计算\n";
	cout<<"9、判断是否为完全二叉树\n";
	cout<<"10、判断是否是二叉排序树\n";
	
	while(1){
		cout<<"\n请选择：";
		int k;
		cin>>k;
		if(k==0)
			break;
		Tree T;
		switch(k){
			case 10:
				cout<<"输入二叉树的先序序列：";		
				CreateTree(T);
				if(isSorted(T))
					cout<<"Yes\n";
				else
					cout<<"No\n";
				break;
			case 9:
				cout<<"输入二叉树的先序序列：";		
				CreateTree(T);
				if(isComplete(T))
					cout<<"Yes\n";
				else
					cout<<"No\n";
				break;
			case 1:
				cout<<"输入二叉树的先序序列：";	
				CreateTree(T);
				ExchangeLF(T);
				cout<<"交换后：";
				PreOrder(T);
				cout<<endl;
				break;
			case 2:
				cout<<"输入二叉树的先序序列：";			
				CreateTree(T);
				cout<<"最大宽度："<<MaxWidth(T)<<endl; 
				break;
			case 3:
				cout<<"输入二叉树的先序序列：";			
				CreateTree(T);
				len1=len2=0;
				cout<<"最长路径：\n";				
				MaxPath(T);
				cout<<len2+1<<"\t";
				for(int i=0;i<=len2;i++)
					cout<<pathLong[i];
				cout<<endl;
				break;
			case 4:
				cout<<"输入二叉树的先序序列：";			
				CreateTree(T);
				len1=0;
				AllPaths(T);
				break;
			case 5:
				cout<<"输入二叉树的先序序列：";			
				CreateTree(T);
				cout<<"结点个数：";
				int a,b,c;
				a=b=c=0;
				NodeCount(T,a,b,c);
				cout<<a<<" "<<b<<" "<<c<<endl;
				break;
			case 6:
				cout<<"输入二叉树的先序序列：";			
				CreateTree(T);
				cout<<"最深高度："<<MaxDepth(T)<<endl;
				cout<<"最浅高度："<<MinDepth(T)<<endl;
				break;
			case 7:
				Tree T1;
				cout<<"输入两个二叉树的先序序列：";			
				CreateTree(T);
				CreateTree(T1);
				if(isSame(T,T1))
					cout<<"Yes"<<endl;
				else
					cout<<"No\n";
				break;
			case 8:
				cout<<"输入二叉树的先序序列：";		
				Tree2 T2;	
				CreateTree2(T2);
				len1=0;
				int wpl=0;
				WPL(T2,wpl);
				cout<<"WPL："<<wpl<<endl;
				break;
			
		
		}
	}
	
	return 0;
}
