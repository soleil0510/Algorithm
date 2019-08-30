//Ãÿ ‚≥À∑®£∫123*45=1*4+1*5+2*4+2*5+3*4+3*5

//#include<iostream>
//#include<cstring>
//#define N 20
//using namespace std;
//
//int a[N],b[N];
//
//int main(){
//	int A,B;
//	
//	while(cin>>A>>B){
//		int i=0,j=0;
//		while(A/10!=0){
//			a[i]=A%10;
//			A=A/10;
//			i++;
//		}
//		a[i]=A;
//		while(B/10!=0){
//			b[j]=B%10;
//			B=B/10;
//			j++;
//		}
//		b[j]=B;
//		
//		int sum=0;
//		for(int m=0;m<=i;m++){
//			for(int n=0;n<=j;n++){
//				sum+=a[m]*b[n];
//			}
//			
//		}
//		cout<<sum<<endl;
//		
//	} 
//	
//	
//	return 0;
//} 


#include<iostream>
#include<cstring>
using namespace std;

int main(){
	
	char s1[20],s2[20];
	while(scanf("%s%s",s1,s2)!=EOF){
		int ans=0;
		for(int i=0;i<strlen(s1);i++){
			for(int j=0;j<strlen(s2);j++){
				ans+=(s1[i]-'0')*(s2[j]-'0');
			}
		}
		cout<<ans<<endl;
	}
}
