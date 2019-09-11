//��һ��txt�ı������ļ�������ÿ���ʵĴ�Ƶ���������򣬹��쵥����
//����һ���ʣ�����ôʵĴ�Ƶ
//����һ����k�����ǰk������
#include<cstdio>
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;


int index=0;//��������ĸ��� 
struct Word{
	string word;
	int num;
}Words[100];

bool cmp(struct Word w1,struct Word w2){
	return w1.num>w2.num?true:false;	
} 

//������û��������ʣ����У�Ƶ�ȼ�һ��û�У��������飬Ƶ����Ϊ1
void checkWord(string word){
	int flag=0;//δ�ҵ� 
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

//��巨���쵥���� 
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

//����ĳ���ʵĴ�Ƶ
int findWord(string word){
	//�������в��� 
	for(int i=0;i<index;i++){
		if(Words[i].word==word)
			return Words[i].num;
	}
	return 0;
	//�������в���
	 
} 

//��������е�ǰk������
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
	cout<<"����ǰ��"<<endl;
	for(int i=0;i<index;i++){
		cout<<Words[i].word<<"-"<<Words[i].num<<endl;
	}
	cout<<"�����"<<endl;
	//�������� 
	sort(Words,Words+index,cmp);

	//���쵥���� 
	LinkList L=NULL;
	CreatList(L);
	LNode *p=L->next;
	while(p){
		cout<<p->word.word<<"--"<<p->word.num<<endl;
		p=p->next;
	}
	
	string w1;
	cout<<"\n����һ���ʣ�";
	cin>>w1;
	cout<<"��Ƶ�ǣ�"<<findWord(w1)<<endl;
	
	int k;
	cout<<"\n����һ����k��";
	cin>>k;
	cout<<"ǰ"<<k<<"�����ʣ�"<<endl;
	printWord(L,k);
	
	
	return 0;
}
