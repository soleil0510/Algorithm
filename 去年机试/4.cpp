//给一个txt文本，读文件，计算每个词的词频，降序排序，构造单链表
//输入一个词，输出该词的词频
//输入一个数k，输出前k个单词
#include<cstdio>
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;


int index=0;//单词数组的个数 
struct Word{
	string word;
	int num;
}Words[100];

bool cmp(struct Word w1,struct Word w2){
	return w1.num>w2.num?true:false;	
} 

//查找有没有这个单词，若有，频度加一，没有，存入数组，频度设为1
void checkWord(string word){
	int flag=0;//未找到 
	for(int i=0;i<index;i++){
		if(Words[i].word==word){
			flag=1;
			Words[i].num++;
			break;
		}
	}
	if(flag==0){
		Words[index].word=word;
		Words[index].num=1;
		index++;
	}
}


typedef struct LNode{
	Word word;
	struct LNode *next;	
}LNode,*LinkList;

//后插法构造单链表 
void CreatList(LinkList &L){
	L=new LNode;
	L->next=NULL;
	LNode *r=L;
	for(int i=0;i<index;i++){
		LNode *p=new LNode;
		p->word=Words[i];
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

//查找某个词的词频
int findWord(string word){
	//从数组中查找 
	for(int i=0;i<index;i++){
		if(Words[i].word==word)
			return Words[i].num;
	}
	return 0;
	//从链表中查找
	 
} 

//输出链表中的前k个单词
void printWord(LinkList L,int k){
	
	LNode *p;
	p=L->next;
	while(k--){
		cout<<p->word.word<<endl;
		p=p->next;
	}
	
} 

int main(){
	fstream fin;
	fin.open("words.txt",ios::in|ios::out);
	if(!fin)
	{
		cout<<"cannot open txt\n";
		exit(0);
	}
	string w;
	if(fin.is_open()){
		while(!fin.eof()){
			getline(fin,w,' ');
			checkWord(w);
		}
	}
	fin.close();
	cout<<"排序前："<<endl;
	for(int i=0;i<index;i++){
		cout<<Words[i].word<<"-"<<Words[i].num<<endl;
	}
	cout<<"排序后："<<endl;
	//降序排序 
	sort(Words,Words+index,cmp);

	//构造单链表 
	LinkList L=NULL;
	CreatList(L);
	LNode *p=L->next;
	while(p){
		cout<<p->word.word<<"--"<<p->word.num<<endl;
		p=p->next;
	}
	
	string w1;
	cout<<"\n输入一个词：";
	cin>>w1;
	cout<<"词频是："<<findWord(w1)<<endl;
	
	int k;
	cout<<"\n输入一个数k：";
	cin>>k;
	cout<<"前"<<k<<"个单词："<<endl;
	printWord(L,k);
	
	
	return 0;
}
