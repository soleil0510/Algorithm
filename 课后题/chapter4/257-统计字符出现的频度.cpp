#include<iostream>
#include<cstring>
#include<algorithm>
#define Maxsize 100
using namespace std;

struct word{
	char ch;
	int freq;
};

word Word[Maxsize];
int idx;

bool cmp(word a,word b){
	return a.ch<b.ch;
}

void findChar(char c){
	int i;
	for(i=0;i<idx;i++){
		if(Word[i].ch==c){
			Word[i].freq+=1;
			break;
		}
	}
	if(i==idx){
		Word[idx].ch=c;
		Word[idx].freq=1;
		idx++;
	}
}

int main(){
	string str;
	while(cin>>str){
		idx=0;
		if(str=="0")
			break;	
		int len=str.length();
		
		for(int i=0;i<len;i++){
			findChar(str[i]);
		}
		sort(Word,Word+idx,cmp);
		for(int i=0;i<idx;i++){
			cout<<Word[i].ch<<":"<<Word[i].freq<<endl;
		}
	}
	
	return 0;
}
