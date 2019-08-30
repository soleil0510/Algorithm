#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	int n,V;
	double W;
	double p[100];
	int C;
	cin>>C;
	while(C--){
		cin>>n>>V>>W;
		W=W*0.01;
		int current_V=0;
		double current_W=0.00;
		for(int i=0;i<n;i++){
			cin>>p[i];
			p[i]=p[i]*0.01;
		} 
		for(int i=0;i<n;i++){
			double temp=(current_W*current_V+p[i]*V)/(current_V+V);
			if(temp-0.000001<=W){
				current_V+=V;
				current_W=temp;
			}
			else
				break;
			
		}
		printf("%d %.2f\n",current_V,current_W);
	}
	
	return 0;
}
