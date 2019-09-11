#include<iostream>
#include<cstring>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}*Tree;

Tree CreateTree(char *s,int i,int j){
	
	Tree T;
	int k;
	int pos;
	int flag=0;//代表是否找到运算符 
	//处理括号
	if(s[i]=='(' && s[j]==')'){
		int flag2=0;//判断是否是成对的括号 
		for(int n=i+1;n<=j-1;n++){
			if(s[n]=='(')//中间包含括号
			{
				flag2=1;
				break; 
			}
		}
		if(flag2==0){
			i=i+1;
			j=j-1;
		}
	} 
	
	if(i==j){ //说明子串只有一个字符，叶子节点 
		T=new TNode;
		T->data=s[i];
		T->lchild=NULL;
		T->rchild=NULL;
		return T;
	}
 
	for(k=i;k<=j;k++){ //先找加号 
		if(s[k]=='+' || s[k]=='-'){
			int flag1=0;//判断是否是括号里的加号 
			for(int z=k-1;z>=i;z--){
				if(s[z]==')')
					break;
				if(s[z]=='('){
					flag1=1;
					break;
				}
			} 
			if(flag1==0){
				pos=k;
				flag=1;
				break;
			}
			else
				continue;
		}
	}
	
	
	if(flag==0){ //找乘除 
		for(k=i;k<=j;k++){
			if(s[k]=='*' || s[k]=='/'){
				pos=k;
				flag=1;
			}	
		}
	}
	
	if(flag==0){ //找括号 
		for(k=i;k<=j;k++){
			if(s[k]=='('){
				flag=1;
				pos=k-1;
				break;	
			}
			if(s[k]==')'){
				flag=1;
				pos=k+1;
				break;
			}
			
		}	
	}
	
	if(flag!=0){
		T=new TNode;
		T->data=s[pos];
		T->lchild=CreateTree(s,i,pos-1);
		T->rchild=CreateTree(s,pos+1,j);
		return T;
	}
	else
		return NULL;
}

void InOrder(Tree T){
	if(T){
		InOrder(T->lchild);
		cout<<T->data;
		InOrder(T->rchild);
	}
}

double Calculate(Tree T){
	if(T==NULL)
		return 0;
	else{
		if(T->lchild==NULL && T->rchild==NULL)
			return int(T->data-'0');
		else{
			double a=Calculate(T->lchild);
			double b=Calculate(T->rchild);
			char opr=T->data;
			double res;
			switch(opr){
				case '+':
					res=a+b;break;
				case '-':
					res=a-b;break;
				case '*':
					res=a*b;break;
				case '/':
					res=a/b;break;
			}
			return res;
		}
	}
}

int main(){
	
	char s[1000];
	while(cin>>s){
		if(strcmp(s,"=")==0)
			break;
		s[strlen(s)-1]='\0';//去掉等号 
		Tree T=CreateTree(s,0,strlen(s)-1);
		//InOrder(T);
		//cout<<endl;
		cout<<Calculate(T)<<endl;
	}
	
	return 0;
} 
