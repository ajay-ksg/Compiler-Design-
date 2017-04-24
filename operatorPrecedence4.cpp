#include <iostream>
#include<algorithm>
#include <string>
#include <stack>
#include <vector>
#include <map>
using namespace std;

struct Grammar{
    char LHS;
    vector<string> rhs;
}prdcn;

vector<struct Grammar> G;
vector<char> stack1;
stack<char> stck;

char input_s;
string input;
int i = 0;
map<char, map<char,char> >preTable;
map<char, char>row;

void precedence(){
row['+'] = '>';
row['-'] = '>';
row['*'] = '<';
row['/'] = '<';
row['i'] = '<';
row['('] = '<';
row[')'] = '>';
row['$'] = '>';

preTable['+'] = row;

cout<<preTable['+']['+'];
cout<<"\t";
cout<<preTable['+']['-'];
cout<<"\t"<<preTable['+']['*'];
cout<<"\t"<<preTable['+']['/'];
cout<<"\t"<<preTable['+']['i'];
cout<<"\t"<<preTable['+']['('];
cout<<"\t"<<preTable['+'][')'];
cout<<"\t"<<preTable['+']['$'];
cout<<"\n";

row['+'] = '>';
row['-'] = '>';
row['*'] = '<';
row['/'] = '<';
row['i'] = '<';
row['('] = '<';
row[')'] = '>';
row['$'] = '>';
preTable['-'] = row;

cout<<preTable['-']['+'];
cout<<"\t";
cout<<preTable['-']['-'];
cout<<"\t"<<preTable['-']['*'];
cout<<"\t"<<preTable['-']['/'];
cout<<"\t"<<preTable['-']['i'];
cout<<"\t"<<preTable['-']['('];
cout<<"\t"<<preTable['-'][')'];
cout<<"\t"<<preTable['-']['$'];
cout<<"\n";

row['+'] = '>';
row['-'] = '>';
row['*'] = '>';
row['/'] = '>';
row['i'] = '<';
row['('] = '<';
row[')'] = '>';
row['$'] = '>';
preTable['*'] = row;

cout<<preTable['*']['+'];
cout<<"\t";
cout<<preTable['*']['-'];
cout<<"\t"<<preTable['*']['*'];
cout<<"\t"<<preTable['*']['/'];
cout<<"\t"<<preTable['*']['i'];
cout<<"\t"<<preTable['*']['('];
cout<<"\t"<<preTable['*'][')'];
cout<<"\t"<<preTable['*']['$'];
cout<<"\n";


row['+'] = '>';
row['-'] = '>';
row['*'] = '>';
row['/'] = '>';
row['i'] = '<';
row['('] = '<';
row[')'] = '>';
row['$'] = '>';
preTable['/'] = row;

cout<<preTable['/']['+'];
cout<<"\t";
cout<<preTable['/']['-'];
cout<<"\t"<<preTable['/']['*'];
cout<<"\t"<<preTable['/']['/'];
cout<<"\t"<<preTable['/']['i'];
cout<<"\t"<<preTable['/']['('];
cout<<"\t"<<preTable['/'][')'];
cout<<"\t"<<preTable['/']['$'];
cout<<"\n";

row['+'] = '>';
row['-'] = '>';
row['*'] = '>';
row['/'] = '>';
row['i'] = '>';
row['('] = '>';
row[')'] = '>';
row['$'] = '>';
preTable['i'] = row;

cout<<preTable['i']['+'];
cout<<"\t";
cout<<preTable['i']['-'];
cout<<"\t"<<preTable['i']['*'];
cout<<"\t"<<preTable['i']['/'];
cout<<"\t"<<preTable['i']['i'];
cout<<"\t"<<preTable['i']['('];
cout<<"\t"<<preTable['i'][')'];
cout<<"\t"<<preTable['i']['$'];
cout<<"\n";

row['+'] = '<';
row['-'] = '<';
row['*'] = '<';
row['/'] = '<';
row['i'] = '<';
row['('] = '=';
row[')'] = '<';
row['$'] = ' ';
preTable['('] = row;

cout<<preTable['(']['+'];
cout<<"\t";
cout<<preTable['(']['-'];
cout<<"\t"<<preTable['(']['*'];
cout<<"\t"<<preTable['(']['/'];
cout<<"\t"<<preTable['(']['i'];
cout<<"\t"<<preTable['(']['('];
cout<<"\t"<<preTable['('][')'];
cout<<"\t"<<preTable['(']['$'];
cout<<"\n";

row['+'] = '>';
row['-'] = '>';
row['*'] = '>';
row['/'] = '>';
row['i'] = ' ';
row['('] = ' ';
row[')'] = '>';
row['$'] = '>';
preTable[')'] = row;

cout<<preTable[')']['+'];
cout<<"\t";
cout<<preTable[')']['-'];
cout<<"\t"<<preTable[')']['*'];
cout<<"\t"<<preTable[')']['/'];
cout<<"\t"<<preTable[')']['i'];
cout<<"\t"<<preTable[')']['('];
cout<<"\t"<<preTable[')'][')'];
cout<<"\t"<<preTable[')']['$'];
cout<<"\n";

row['+'] = '<';
row['-'] = '<';
row['*'] = '<';
row['/'] = '<';
row['i'] = '<';
row['('] = '<';
row[')'] = ' ';
row['$'] = ' ';
preTable['$'] = row;

cout<<preTable['$']['+'];
cout<<"\t";
cout<<preTable['$']['-'];
cout<<"\t"<<preTable['$']['*'];
cout<<"\t"<<preTable['$']['/'];
cout<<"\t"<<preTable['$']['i'];
cout<<"\t"<<preTable['$']['('];
cout<<"\t"<<preTable['$'][')'];
cout<<"\t"<<preTable['$']['$'];
cout<<"\n";

}

void Display(){
cout<<"+\t-\t*\t/\ti\t(\t)\t$\n";



}

void shift( char ch ){
    stack1.push_back(ch);

}

void print_stack1(){

    for(int i = 0; i < stack1.size(); i++){
        cout<<stack1[i];
    }
    cout<<endl;
}

bool findp(string s , char & lhs){
    for(int j = 0; j < G.size(); j++){
        for(int k = 0; k < G[j].rhs.size(); k++){
            if(G[j].rhs[k] == s){
                lhs = G[j].LHS;
                return true;
             }
         }
    }
return false;
}

void reduce(string x){
    int n = x.length();
    string s;
    char lhs;

    //reduce ids to non-terminals
    bool reduced = false;

    if(x.length() == 1){

        if(findp(x,lhs)){
            stck.push(lhs);

            if(input_s == '$' && stck.top() != G[0].LHS &&stck.size() ==2){
                cout <<"i'm in if "<<endl;
                string st;
                st+= stck.top();
                while(findp(st,lhs)){
                    stck.pop();
                    stck.push(lhs);
                    st[0] = lhs;
                }
            }

            return ;
        }
    }
    else{

        if(x.size() > 2){
            s = x;

            //reverse(s.begin(),s.end());
            string leftArg ,rightArg,temp;
            leftArg += s[0];
            rightArg += s[2];

            bool found1 = true, found2 = true;
            while(found1){

                if(findp(s,lhs)){
                    stck.push(lhs);

                    if(input_s == '$' && stck.top() != G[0].LHS &&stck.size() ==2){
                        string st;
                        st+= stck.top();
                        while(findp(st,lhs)){
                            stck.pop();
                            stck.push(lhs);
                            st[0] = lhs;
                        }
                    }
                    return ;
                }

                if(findp(leftArg , lhs)){
                   s[0] = lhs;

                   leftArg[0] = lhs;

                   found1 = true;
                }
                else
                    found1 = false;



                // update second argument
                s[2] = rightArg[0];
                found2 = true;
                temp = rightArg;
                while(found2){

                    if(findp(s,lhs)){
                        stck.push(lhs);

                        if(input_s == '$' && stck.top() != G[0].LHS &&stck.size() ==2){
                            string st;
                            st+= stck.top();
                            while(findp(st,lhs)){
                                stck.pop();
                                stck.push(lhs);
                                st[0] = lhs;
                            }
                        }
                        return ;
                    }
                   if(findp(temp , lhs)){
                        s[2] = lhs;

                        temp[0] = lhs;
                        found2 = true;
                    }
                    else
                        found2 = false;


                }
            }
        }
    }


}



void parse(string input){

    string s;
    char prevOp = '$';
    char currOp = '$';
    stack1.push_back('$');

    input+='$';

    char stack1_top ;
    while(1){

        stack1_top = stack1.back();
        if(stack1_top == '('){
            stack1.pop_back();
            stack1_top = stack1.back();
        }
        input_s = input[i];
        if(input[i] ==')'&&input[i+1]=='$')
            input_s = input[++i];



        if(stck.top() == G[0].LHS && input_s == '$' && stck.size() == 2){
             cout<<"String accepted succesfuly\n";
             return ;
        }


        if((preTable[stack1_top][input_s] == '<')||(preTable[stack1_top][input_s] == '=')) {
                shift(input_s);

                i++;

        }
        else{
            if((preTable[stack1_top][input_s] == '>')){
                while(preTable[stack1_top][input_s] == '>'){


                      if(stack1_top == '+'||stack1_top =='-'||stack1_top =='*'||stack1_top =='/'){

                        s += stck.top();
                        stck.pop();
                        s += stack1_top;
                        stack1.pop_back();
                        stack1_top = stack1.back();
                        s += stck.top();
                        stck.pop();
                      }
                      else{



                            s += stack1_top;
                            stack1.pop_back();
                            //update top of stack1
                            stack1_top = stack1.back();

                      }

                      reverse(s.begin(),s.end());
                      reduce(s);

                      s.erase();
                }


                if(input_s !=')')
                    shift(input_s);
                if(input[i]!='$')
                    i++;

            }
            else{
                cout<<"ERROR: cannot parse the string \n";
                break;
            }

        }


    }
}

int main(){

    string end,prod;
    struct Grammar p;
    end+='#';
    stck.push('$');
    /*do{
        cin >> prod;
        if(prod == end)
            break;
        else{
            p.LHS = prod[0];
            p.rhs = prod.substr(3);
            G.push_back(p);
        }

    }while(prod != end);
*/
p.LHS = 'E';
p.rhs.push_back("E+T");
p.rhs.push_back("T");
G.push_back(p);
p.rhs.erase(p.rhs.begin(),p.rhs.end());
p.LHS = 'T';
p.rhs.push_back("T*F");
p.rhs.push_back("F");
G.push_back(p);
p.rhs.erase(p.rhs.begin(),p.rhs.end());

p.LHS = 'F';
p.rhs.push_back("(E)");
p.rhs.push_back("i");
G.push_back(p);
p.rhs.erase(p.rhs.begin(),p.rhs.end());


    cout<<"Note : The following Program will work for the Grammer Bellow :\n";
    cout<<"E-> E+T | T\nT-> T*F | F\nF-> (E) | i\n";
    cout<<"Precedence Table for above Grammar :-\n";
    Display();
    precedence();
    cout<<"\n\nEnter input string\n";
    cin>>input;

    parse(input);

}
