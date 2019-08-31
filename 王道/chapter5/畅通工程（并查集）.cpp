//ÿ��������֮�䶼��ͨ·������һ����ֱ��������
//ÿ�ν����ཻ���������Ϻϲ������������ٸ���ͨ��ͼ��-1 

#include<iostream>
using namespace std;

int Tree[1000];
int findRoot(int x){
	if(Tree[x]==-1)
		return x;
	else{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
		 
}

int main(){ 
	
	int N,M;
	while(cin>>N){
		if(N==0)
			break;
		cin>>M;
		int a,b;
		//���
		int i; 
		for(i=1;i<=N;i++)
			Tree[i]=-1; 
		
		for(i=0;i<M;i++){
			cin>>a>>b;
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
				Tree[a]=b;
		} 
		
		int ans=0;
		for(i=1;i<=N;i++){
			if(Tree[i]==-1)
				ans++;
		}
		
		cout<<ans-1<<endl;
	}
	
	
	return 0;
}
