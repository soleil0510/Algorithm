#include<iostream>
#include<cstring>

#define N 1000
using namespace std;

//��s1���ճ���n��ʽ��Ϊs2,s2�������ո�ʣ���ַ����Ƶ�s3 
void format(char *s1,char *s2, char *s3, int n){
	int j=0;
	int k=0;
	
	for(int i=0;i<strlen(s1);i++){
		if(s1[i]==' '){
			s3[k++]=s1[i];
		}
		else{
			if(j>=n)
				s3[k++]=s1[i];
			else
				s2[j++]=s1[i];
		}
	}
	s2[j]='\0';
	s3[k]='\0';
		
		cout<<s2<<endl;
		cout<<s3<<endl;
}

int main(){
	
	int n;
	while(scanf("%d",&n)){
		char s1[N];
		char s2[N];
		char s3[N];
		if(n==0)
			break;
		getchar();//��ȡ���з� 
		gets(s1);
		format(s1,s2,s3,n);
	} 
	
	return 0;
} 
