#include<bits/stdc++.h>
using namespace std;

int priority(char oparator){
    if(oparator =='^')
        return 100;
    
    else if(oparator =='*' || oparator =='/')
        return 50;
    
    else if(oparator =='+' || oparator =='-')
        return 25;
    
    else
        return -1;  

}

string infix_to_postfix(string infix){

    stack <char> oparators;

    string postfix="";

    for(int i=0;i<infix.length();i++){

        if(infix[i]>='0' && infix[i]<='9' ){

            postfix+=infix[i];
            if(infix[i+1]<='0' || infix[i+1]>='9'){

                postfix+=" ";
            }
        }

        else if(infix[i]=='('){

            oparators.push(infix[i]);

        }else if(infix[i]==')'){

            while(!oparators.empty() && oparators.top() != '('){

                postfix+=oparators.top();
                postfix+=" ";
                oparators.pop();

            }
            oparators.pop();
        }else{

            while(!oparators.empty() && priority(oparators.top()) >= priority(infix[i])){

                postfix+=oparators.top();
                postfix+=" ";
                oparators.pop();
            }
            oparators.push(infix[i]);
        }
    }

    while(!oparators.empty()){

        postfix+=oparators.top();
        postfix+=" ";
        oparators.pop();
    }

    return postfix;
}

double postfix_evaluation(string postfix){

    stack <double> operands;
    string temp="";

    for(int i=0;i<postfix.length();i++){

        if(postfix[i]>='0' && postfix[i]<='9'){

            while(postfix[i]!=' '){

                temp+=postfix[i];
                i++;
            }
            
            operands.push(stod(temp));

            temp="";

        }else if(postfix[i]!=' '){
            if(postfix[i]=='+'){

                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b+a);
                temp="";
                
            }else if(postfix[i]=='-'){

                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b-a);
                temp="";
            }else if(postfix[i]=='*'){

                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b*a);
                temp="";

            }else {
                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b/a);
                temp="";
            }
        }
    }

    return operands.top();
}
int main(){

    string infix="(12+34)*56-78/9";
    cout<<"Enter infix expression: "<<infix<<endl;

    string postfix = infix_to_postfix(infix);
    cout<<"Postfix expression: "<<postfix<<endl;

    double result = postfix_evaluation(postfix);
    cout<<"Postfix evaluation: "<<result<<endl;
}