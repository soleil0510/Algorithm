#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdio>
#include<cstring>
#define N 1000
using namespace std;

struct Student{
	string no;
	int s1;
	int s2;
	int s3;
	double sum;
}stu[N];
bool cmp(Student s1,Student s2){
	return s1.sum>s2.sum;
}

void Delete(Student *stu, int &n, int i){
	for(int j=i;j<n-1;j++){
		stu[j]=stu[j+1];
	}
	n--;
}

int main(){
	fstream fin;
	fin.open("t2.txt",ios::in|ios::out);
	if(!fin){
		cout<<"cannot open\n";
		exit(0);
	}
	char str[N];
	fin.getline(str,sizeof(Student));
	cout<<str<<endl;
	int i=0;
	while(!fin.eof()){
		fin>>stu[i].no;
		fin>>stu[i].s1;
		stu[i].s1=(double)stu[i].s1;
		fin>>stu[i].s2;
		stu[i].s2=(double)stu[i].s2;
		fin>>stu[i].s3;
		stu[i].s3=(double)stu[i].s3;
		stu[i].sum=stu[i].s1*0.85+stu[i].s2*0.15;
		i++;
	}
	sort(stu,stu+i,cmp);
	for(int j=0;j<i;j++)
		cout<<stu[j].no<<"\t"<<stu[j].s1<<"\t"<<stu[j].s2<<"\t"<<stu[j].s3<<"\t"<<stu[j].sum<<endl;
	
	cout<<"É¾³ýºó£º\n";
	for(int k=0;k<i;k++){
		if(stu[k].s3<425){
			Delete(stu,i,k);
			k--;
		}
	}
	
	fstream fout;
	fout.open("t2.txt",ios::in|ios::out);
	if(!fout){
		cout<<"cannot open\n";
		exit(0);
	}
	fout<<"no\ts1\ts2\ts3\tsum\n";
	for(int j=0;j<i;j++){
		cout<<stu[j].no<<"\t"<<stu[j].s1<<"\t"<<stu[j].s2<<"\t"<<stu[j].s3<<"\t"<<stu[j].sum<<endl;
		fout<<stu[j].no<<"\t"<<stu[j].s1<<"\t"<<stu[j].s2<<"\t"<<stu[j].s3<<"\t"<<stu[j].sum<<endl;
	}
		
	fin.close();
	
	return 0;
}
