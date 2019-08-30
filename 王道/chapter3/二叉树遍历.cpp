//根据前序和中序序列，写出后序序列
#include<iostream>
#include<cstring>
using namespace std;

struct Node{
	Node *lchild;
	Node *rchild;
	char c;	
}Tree[50];

char str1[30],str2[30];
int loc;

Node *create(){
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++]; 
} 

Node *restore(int s1,int e1,int s2,int e2){
	Node *ret=create();
	ret->c=str1[s1];
	int rootindex;
	for(int i=s2;i<=e2;i++){
		if(str2[i]==ret->c){
			rootindex=i;
			break;
		}
	}
	if(rootindex!=s2)
		ret->lchild=restore(s1+1,s1+rootindex-s2,s2,rootindex-1);
	if(rootindex!=e2)
		ret->rchild=restore(s1+rootindex-s2+1,e1,rootindex+1,e2);
	return ret;		
}

void postorder(Node *T){
	if(T->lchild!=NULL)
		postorder(T->lchild);
	if(T->rchild!=NULL)
		postorder(T->rchild);
	cout<<T->c;
}

int main(){
	while(1){
		loc=0;
		cin>>str1;
		cin>>str2;
		int e1=strlen(str1)-1;
		int e2=strlen(str2)-1;
		Node *tree = restore(0,e1,0,e2);
		postorder(tree);
		cout<<endl;
	}	
	return 0;
} 
