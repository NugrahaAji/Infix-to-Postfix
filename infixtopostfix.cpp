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
			if(input[i]=='-'&&(i==0 || !isdigit(input[i-1]))){
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
		     	else if(i==0) tmp += input[i];
				
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

	if 	(!tmp.empty()){
		infix.push_back(tmp);
	}
	return infix;
}

vector<string> infixToPostfix(vector<string> infix){
	vector<string> postfix;
	vector<string> oprnd;
	string tmp;

	for(auto itr = infix.begin(); itr != infix.end(); itr++){
		tmp = *itr;
		if(isdigit(tmp[0]) || (tmp[0] == '-' && isdigit(tmp[1]) && tmp.size() > 1)){
			postfix.push_back(tmp);
		}
		else if(tmp == "("){
			oprnd.push_back(tmp);
		}
		else if(tmp == ")"){
			while(!oprnd.empty() && oprnd.back() != "("){
				postfix.push_back(oprnd.back());
				oprnd.pop_back();
			}
			oprnd.pop_back();
		}
		else{
			while(!oprnd.empty() && operand(oprnd.back()) >= operand(tmp)){
				postfix.push_back(oprnd.back());
				oprnd.pop_back();
			}
			oprnd.push_back(tmp);
		}
	}
	while(!oprnd.empty()){
		postfix.push_back(oprnd.back());
		oprnd.pop_back();
	}
	return postfix;
}

void print(vector<string>&string){
	for(auto itr = string.begin(); itr!= string.end(); itr++){
		cout << *itr << " ";
	}
	cout << endl;
}

int main(){
	string input;
	getline(cin,input);
	vector<string> infix = strToInfix(input);
	vector<string> postfix = infixToPostfix(infix);
	print(postfix);
	
	return 0;	
}


