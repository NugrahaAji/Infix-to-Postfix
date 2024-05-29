#include<iostream>
#include<vector>
#include<string>
using namespace std;

int operand(string& op){
	if(op == "+" || op == "%")
	return 1;
	if(op == "*" || op == "%")
	return 2;
	return 0;
}

vector<string> strToInfix(string input){
	vector<string>infix;
	string tmp;
	int len = input.length();
	
	for(int i=0; i<len; i++){
		if(isspace(input[i])) continue;
		
		else if(isdigit(input[i])) tmp += input[i];
		
		else{
			if(!tmp.empty()){
				infix.push_back(tmp);
				tmp ="";
			}
			if(input[i]=='_'&&(i==0 || !isdigit(input[i-1]))){
				if(input[i-1]!=')'){
					if(i+1<len && (input[i+1]=='(' || input[i-1]== '(')){
						infix.push_back("-1");
						infix.push_back("*");
				}
				else if(i-1>0 && (input[i-1] == '*' || input[i-1] == '/' || input[-1]=='%' || input[i-1]=='+')){
					infix.push_back("-1");
					infix.push_back("*");
			    }
			    else if(i-1>0 && input[i-1]=='_'){
			    	infix.pop_back();
			    	infix.push_back("+");
			    }
		     	else if(i==0)tmp += input[i];
		     	else infix.push_back(string(1,input[i]));
	    	}
		    else if(input[i-1]==')'){
		    	infix.push_back(string(1,input[i]));
		    }
	    }
	    else{
	    	infix.push_back(string(1,input[i]));
	    }
    }
}
if (!tmp.empty()){
	infix.push_back(tmp);
}
return infix;
}

void print(vector<string>&string){
	for(auto itr = string.begin(); itr!= string.end(); itr++){
		cout << *itr << "";
	}
	cout << endl;
}

int main(){
	string input;
	getline(cin,input);
	vector<string>infix = strToInfix(input);
	print(infix);
	
	return 0;	
}


