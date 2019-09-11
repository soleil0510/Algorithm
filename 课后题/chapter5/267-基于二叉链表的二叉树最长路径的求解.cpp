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
		 //������Ҷ�ӽڵ㣬path���γ�һ����·����
		 //��longpath�бȽϣ������������滻 
		if(T->lchild==NULL && T->rchild==NULL){
			path[len]=T->data;
			if(len>longlen){
				for(int i=0;i<len+1;i++)
					longpath[i]=path[i];
				longlen=len;
			}
		}
		//�ݹ��������������������ÿһ��·�� 
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
