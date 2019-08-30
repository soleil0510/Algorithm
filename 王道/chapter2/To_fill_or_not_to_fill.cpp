#include<iostream>
#include<algorithm>
using namespace std;

struct station{
	double price;
	double dis;
	bool operator < (const station &s) const{
		return dis<s.dis;
	}
}sta[500];

int main(){
	double Cmax,D,Davg;
	int N;
	double maxdis,minprice;
	while(cin>>Cmax>>D>>Davg>>N){
		for(int i=0;i<N;i++){
			cin>>sta[i].price>>sta[i].dis;
		}
		maxdis=Cmax*Davg;
		
		sort(sta,sta+N);
		if(sta[0].dis!=0){
			cout<<"The maximum travel distance = 0.00"<<endl;
			continue;
		}
		
		double curpos=0.0;
		double curoil=0.0;
		
		for(int i=0;i<N;i++){
			curpos=sta[i].dis;
			if(curpos+maxdis<sta[i+1].dis){
				printf("The maximum travel distance = %.2f\n",curpos+maxdis);
				break;
			}
			if(i>0)
				curoil-=(sta[i].dis-sta[i-1].dis)/Davg;
				
			double curdis=0.0;
			bool ischeap=false;
			for(int j=i+1;j<N;j++){
				curdis=sta[j].dis-sta[i].dis;
				if(curdis>maxdis)
					break;
				if(sta[j].price<sta[i].price){
					double  temp=(sta[j].dis-sta[i].dis)/Davg;
					if(temp>curoil){
						minprice+=(temp-curoil)*sta[i].price;
						curoil=temp;
					}
					ischeap=true;
					break;
				}
			}
			if(!ischeap){
				if(curpos+maxdis>=D){
					minprice+=((D-curpos)/Davg-curoil)*sta[i].price;
					printf("%.2f\n",minprice);
					break;
				}
				else{
					minprice+=(Cmax-curoil)*sta[i].price;
					curoil=Cmax;
				}
			}
		}	
	}
	
	
	return 0;
}
