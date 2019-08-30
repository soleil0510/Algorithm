#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	string name;
	int age;
	int score;
	bool operator < (const Student &s) const{
		if(score!=s.score)
			return score<s.score;
		else{
			if(name<s.name)
				return name<s.name;
			else
				return age<s.age;
		}
	}
	
}stu[1001]; 

bool cmp(Student s1,Student s2){
	if(s1.score!=s2.score){
		return s1.score<s2.score;
	}
	else{
		if(s1.name!=s2.name){
			return s1.name<s2.name;
		}
		else{
			return s1.age<s2.age;
		}
	}
	
}

int main(){
	int N;
	while(cin>>N){
		for(int i=0;i<N;i++){
			cin>>stu[i].name>>stu[i].age>>stu[i].score;
		}
		sort(stu,stu+N);
		for(int i=0;i<N;i++){
			cout<<stu[i].name<<" "<<stu[i].age<<" "<<stu[i].score<<endl;
		}
	}
	
	return 0;
}
