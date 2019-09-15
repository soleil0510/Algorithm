//判断一中缀表达式中（）是否合法，并计算结果 

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

stack<double> number;
stack<char> sign;

bool isLegal(string exp){
	stack<char> S;
	for(int i=0;i<exp.length();i++){
		if(exp[i]=='('){
			S.push(exp[i]);
		}
		else if(exp[i]==')'){
			if(S.empty())
				return false;
			else{
				S.pop();
			}
		}
	}
 	if(!S.empty())
 		return false;
 	else
 		return true;
}

//是否是字符 
bool isChar(char c){
	if((c>='0' && c<='9') || c=='.')
		return false;
	else	
		return true;
}

//计算优先级
char ops[7]={'+','-','*','/','(',')','#'};
int cmp[7][7]={
{1,1,0,0,0,1,1},
{1,1,0,0,0,1,1},
{1,1,1,1,0,1,1},
{1,1,1,1,0,1,1},
{0,0,0,0,0,3,-1},
{1,1,1,1,-1,1,1},
{0,0,0,0,0,-1,3},
};

char Precede(char top,char ch){
	int m,n;
	for(int i=0;i<7;i++){
		if(ops[i]==top)
			m=i;
		if(ops[i]==ch)
			n=i;
	}
	int prio=cmp[m][n];
	//cout<<"prio="<<prio<<endl;
	switch(prio){
		case 1:return '>';
		case 0:return '<';
		case 3:return '=';
	}
} 

//计算二元运算结果 
double Operate(double a,double b,char c){
	//cout<<a<<c<<b<<"=";
	switch(c){
		case '+':
			return (a+b);
		case '-':
			return (a-b);
		case '*':
			return (a*b);
		case '/':
			return (a/b);
	}
} 

int main(){
	string exp;
	while(cin>>exp){
		if(!isLegal(exp))
			cout<<"不合法\n";			
		else{
			cout<<"合法\n";
			while(!number.empty()){
				number.pop();
			}
			while(!sign.empty()){
				sign.pop();
			}
			sign.push('#');
			int i=0;
			while(i<exp.length()){
				//cout<<exp[i];
				if(isChar(exp[i])){//运算符 
					char c=Precede(sign.top(),exp[i]);
					switch(c){
						case '<':
							sign.push(exp[i]);
							i++;
							break;
						case '=':   //(  =  )
							sign.pop();
							i++;
							break;
						case '>':
							char s=sign.top();
							sign.pop();
							double a=number.top();
							number.pop();
							double b=number.top();
							number.pop();
							double result=Operate(b,a,s);
							//cout<<result<<endl;
							number.push(result);
							break;
					}
				}
				else{  //操作数，包括小数 
					double num=(double)(exp[i]-'0');
					number.push(num);
					i++;
				}
			}
			
		}
		if(!number.empty())
			cout<<"="<<number.top()<<endl;
	}
	
	return 0;
} 
