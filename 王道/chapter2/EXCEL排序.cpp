#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;

struct Student{
	char num[7];
	char name[9];
	int score;
}stu[100001];

bool cmp1(Student s1,Student s2){
	return strcmp(s1.num,s2.num)<0;
}

bool cmp2(Student s1,Student s2){
	return strcmp(s1.name,s2.name)<=0;
}

bool cmp3(Student s1,Student s2){
	if(s1.score==s2.score || strcmp(s1.name,s2.name)==0){
		return strcmp(s1.num,s2.num)<0;
	}
	else{
		return s1.score<=s2.score;
	}
}

int main(){
	int N,C;
	while(cin>>N){		
		if(N==0)
			break;
		
		cin>>C;
		for(int i=0;i<N;i++){
			cin>>stu[i].num>>stu[i].name>>stu[i].score;
		}
		if(C==1)
			sort(stu,stu+N,cmp1);
		if(C==2)
			sort(stu,stu+N,cmp2);
		if(C==3)
			sort(stu,stu+N,cmp3);
			
		cout<<"Case:"<<endl;
		for(int i=0;i<N;i++){
			cout<<stu[i].num<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
		}
	}

	return 0;
	
} 
