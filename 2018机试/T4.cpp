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

//ͳ�Ƶ��ʴ�Ƶ 
void Count(string str){
	int flag=0;//�Ƿ��ҵ� 
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

//��������
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

 

//����ĳ���ʵĴ�Ƶ
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

//���ǰk������,��д���ļ��� 
void Print(LinkList L,int k){
	fstream fout;
	fout.open("words2.txt",ios::out);
	if(!fout){
		cout<<"cannot open this file\n";
		exit(0);
	}
	fout<<"ǰ"<<k<<"�����ʣ�\n";
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
	cout<<n<<"������\n";
	while(!fin.eof()){
		fin>>str;
		Count(str);	
	}
	fin.close();
	Sort();
	
	LinkList L;
	CreateList(L);
	LNode *p=L->next;
	cout<<"���������\n";
	cout<<"����\t��Ƶ"<<endl;
	while(p){
		cout<<p->data.word<<"\t"<<p->data.num<<endl;
		p=p->next;
	}
	
	cout<<"\n������һ����: ";
	string key;
	cin>>key;
	cout<<"��ƵΪ��"<<CountKey(L,key)<<endl;
	
	cout<<"\n������һ��������";
	int k;
	cin>>k;
	cout<<"ǰ"<<k<<"������Ϊ��\n";
	Print(L,k);
	 
	
	return 0;
}
