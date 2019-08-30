#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	string no;
	string name;
	char gender;
	int age;
	
	bool operator < (const Student &s){
		return no<s.no;
	}
}stu[1000];

int main(){
	int N,M;
	
	while(cin>>N){
		for(int i=0;i<N;i++){
			cin>>stu[i].no>>stu[i].name>>stu[i].gender>>stu[i].age;
		}
		sort(stu,stu+N);
		
		cin>>M;
		string target;
		for(int i=0;i<M;i++){
			cin>>target;
			int low=0;
			int high=N-1;
			int mid;
			while(low<=high){
				mid=(low+high)/2;
				if(stu[mid].no==target){
					cout<<stu[mid].no<<" "<<stu[mid].name<<" "<<stu[mid].gender<<" "<<stu[mid].age<<endl;
					break;
				}
				if(stu[mid].no<target)
					low=low+1;
				else
					high=high-1;				
			}	
			if(low>high){
				cout<<"No Answer!"<<endl;
			}	
		}
	}
	
	return 0;
}
