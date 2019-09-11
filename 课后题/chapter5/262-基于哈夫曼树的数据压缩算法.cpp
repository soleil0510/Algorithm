#include<iostream>
#include<cstring>
#include<algorithm>
#define N 1000
using namespace std;

struct Word{
	char ch;
	int num;
}word[26];
int idx;

bool cmp(Word a,Word b){
	return a.ch<b.ch;
}

//统计字频 
void findword(char ch){
	//cout<<ch<<endl;
	int flag=0;
	for(int i=0;i<idx;i++){
		if(word[i].ch==ch){
			word[i].num++;
			flag=1;
			break;
		}
	}
	if(flag==0){
		word[idx].ch=ch;
		word[idx].num=1;
		idx++;
	}
}


typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

//从前n个节点中选出双亲为0且权值最小的两个下标 
void Select(HuffmanTree HT,int n,int &s1,int &s2){
	//cout<<"n:"<<n<<endl;
	int min=N;
	for(int i=1;i<=n;i++){
		if(HT[i].parent==0 && HT[i].weight<min){
			s1=i;
			min=HT[i].weight;
		}
	}
	min=N;
	for(int i=1;i<=n;i++){
		if(HT[i].parent==0 && HT[i].weight<min && i!=s1){
			s2=i;
			min=HT[i].weight;
		}
	}
}

//构造哈夫曼树 
void CreateHMTree(HuffmanTree &HT,int n){
	if(n<=1)
		return;
	int m=2*n-1;
	HT=new HTNode[m+1];
	for(int i=1;i<=m;i++){
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(int i=1;i<=n;i++)
		HT[i].weight=word[i-1].num;
	
	for(int i=n+1;i<=m;i++){
		int s1,s2;
		Select(HT,i-1,s1,s2);
		//cout<<s1<<"-"<<s2<<endl;
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
} 

typedef char **HuffmanCode;

//根据哈夫曼树构造哈夫曼编码
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n){
	HC=new char*[n+1];//1---n存放每个字符的编码
	char *cd=new char[n];//临时存放字符的编码，字符的编码长度不会超过n
	cd[n-1]='\0';//结束符，字符编码从n-2开始倒着往前存
	int c;//存放当前遍历到的结点下标 
	int f;//存放c的双亲
	int start;//编码的下标 
	for(int i=1;i<=n;i++){
		start=n-1;
		c=i;
		f=HT[c].parent;
		while(f!=0){
			start--;
			if(HT[f].lchild==c)
				cd[start]='0';
			else
				cd[start]='1';
			c=f;
			f=HT[c].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);
	} 
	delete cd;
} 


int main(){
	char str[1000];
	while(cin>>str){
		idx=0;
		if(strcmp(str,"0")==0)
			break;
		for(int i=0;i<strlen(str);i++)
			findword(str[i]);
		sort(word,word+idx,cmp);
		cout<<word[0].ch<<":"<<word[0].num;
		for(int i=1;i<idx;i++){
			cout<<" "<<word[i].ch<<":"<<word[i].num;
		}
		cout<<endl;
		
		HuffmanTree HT;
		CreateHMTree(HT,idx);
		
		for(int i=1;i<=2*idx-1;i++){
			cout<<i<<" "<<HT[i].weight<<" "<<HT[i].parent<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
		}
		
		HuffmanCode HC;
		CreatHuffmanCode(HT,HC,idx);
		cout<<word[0].ch<<":"<<HC[1];
		for(int i=2;i<=idx;i++)
			cout<<" "<<word[i-1].ch<<":"<<HC[i];
		cout<<endl;
		
		//编码
		string code="";
		for(int i=0;i<strlen(str);i++){
			for(int j=0;j<idx;j++){
				if(str[i]==word[j].ch){
					code+=HC[j+1];
					break;
				}
			}
		}
		cout<<code<<endl;
		
		//解码
		int c=2*idx-1;
		for(int i=0;i<code.length();i++){
		
			if(code[i]=='0')
				c=HT[c].lchild;
			else
				c=HT[c].rchild;
			if(HT[c].lchild==0 && HT[c].rchild==0){//查找到叶子节点 
				cout<<word[c-1].ch;	
				c=2*idx-1;//回到根节点 
			}
				
		} 
		cout<<endl;
			
		
	}		
	
	return 0;
}
