#include<iostream>
#define N 1000
using namespace std;

typedef struct SNode{
	int data;
	struct SNode *next;
}SNode,*LinkStack;

void Push(LinkStack &S,int e){
	SNode *p=new SNode;
	p->data=e;
	p->next=S;
	S=p;	
}

void Pop(LinkStack &S){
	if(S==NULL)
		return ;
	SNode *p=S;
	S=S->next;
	delete p;
}

int Top(LinkStack S){
	if(S!=NULL)
		return S->data;	
}

int main(){
	int n;
	int x;	
	int a[N];
	while(cin>>n){
		LinkStack S=NULL;
		if(n==0)
			break;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}	
			for(int i=0;i<n;i++){
				if(a[i]==-1){
					if(S==NULL){
						cout<<"POP ERROR"<<endl;
						break;
					}
					else{
						cout<<Top(S)<<endl;
						Pop(S);
					}
				}
				else{
					Push(S,a[i]);
				}
			}
	}
	
	
	return 0;
} 
