#include<iostream>
#include<algorithm>
using namespace std;

struct goods{
	double j;//÷ÿ¡ø 
	double f;//º€«Æ 
	double ratio;
	bool operator < (const goods &g){
		return ratio>g.ratio;
	} 
	
}buf[1000];

int main(){
	double m;
	int n;
	while(cin>>m>>n){
		if(m==-1&&n==-1)
			break;
		for(int i=0;i<n;i++){
			cin>>buf[i].j>>buf[i].f;
			buf[i].ratio=buf[i].j/buf[i].f;
		}
		sort(buf,buf+n);
		
		double sum=0;
		int index=0;
		while(m>0&&index<n){
			if(m>=buf[index].f){
				sum+=buf[index].j;
				m-=buf[index].f;
			}	
			else{
				sum+=buf[index].j*m/buf[index].f;
				m=0;
			}
			index++;
		}
		
		printf("%.3f\n",sum);
	}
	
	
	return 0;
}
