#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#define N 1000
using namespace std;

struct Word{
	string word;
	int num;
}Words[N];
int idx=0;

//统计单词词频 
void Count(string str){
	int flag=0;//是否找到 
	for(int i=0;i<idx;i++){
		if(Words[i].word==str){
			flag=1;
			Words[i].num++;
		}
	}
	if(flag==0){
		Words[idx].word=str;
		Words[idx].num=1;
		idx++;
	}
}

//降序排序
void Sort(){
	for(int i=0;i<idx-1;i++){
		for(int j=i+1;j<idx;j++){
			if(Words[j].num>Words[i].num){
				Word temp=Words[i];
				Words[i]=Words[j];
				Words[j]=temp;
			}
		}
	}	
} 

typedef struct LNode{
	Word data;
	struct LNode *next;
}LNode,*LinkList;

 
void CreateList(LinkList &L){
	L=new LNode;
	L->next=NULL;
	LNode *r=L;
	for(int i=0;i<idx;i++){
		LNode *p=new LNode;
		p->data=Words[i];
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

 

//输入某个词的词频
int CountKey(LinkList L, string key){
	LNode *p=L->next;
	while(p){
		if(p->data.word==key){
			return p->data.num;
		}
		p=p->next;
	}
	return 0;
}

//输出前k个单词,并写入文件中 
void Print(LinkList L,int k){
	fstream fout;
	fout.open("words2.txt",ios::out);
	if(!fout){
		cout<<"cannot open this file\n";
		exit(0);
	}
	fout<<"前"<<k<<"个单词：\n";
	LNode *p=L->next;
	while(p && k--){
		fout<<p->data.word<<"\t"<<p->data.num<<"\n";
		cout<<p->data.word<<"\t"<<p->data.num<<endl;
		p=p->next;
	}
} 

int main(){
	fstream fin;
	fin.open("words.txt",ios::in);
	if(!fin){
		cout<<"cannot open this file!";
		exit(0);
	}
	idx=0;
	string str;
	int n;
	fin>>n;
	cout<<n<<"个单词\n";
	while(!fin.eof()){
		fin>>str;
		Count(str);	
	}
	fin.close();
	Sort();
	
	LinkList L;
	CreateList(L);
	LNode *p=L->next;
	cout<<"降序排序后：\n";
	cout<<"单词\t词频"<<endl;
	while(p){
		cout<<p->data.word<<"\t"<<p->data.num<<endl;
		p=p->next;
	}
	
	cout<<"\n请输入一个词: ";
	string key;
	cin>>key;
	cout<<"词频为："<<CountKey(L,key)<<endl;
	
	cout<<"\n请输入一个整数：";
	int k;
	cin>>k;
	cout<<"前"<<k<<"个单词为：\n";
	Print(L,k);
	 
	
	return 0;
}
