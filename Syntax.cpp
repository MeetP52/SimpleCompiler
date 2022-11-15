#include "Token.hpp"
#include "Syntax.hpp"
#include <iostream>

namespace Compiler {

    using namespace std;

    int Syntax::CreateTree(vector<Token>& Tokens) {

        /*
            So at each level we want to look for 3 things:
                * Functions <- Mostly these
                * Objects   <- Then these
                * Variables <- Hopefully not these
            
            For the simple test we only have variables so we must look for them.
        */  
       int z = 0;

        for(int i = 0; i < Tokens.size(); i++) {
            /* 
                At each stage we want to look for :
                    * Function, Obj, or Varaible decleration
                    * KeyWords: such as -> [if, while, for, ...]
                    * Operations: such as -> [+,-,/,*]
                    * Function Calls: add(numb 1, numb 2);
                    
                For the simple test we only care to check for operations
            */
            if(Tokens[i].type == OPERATOR) {
                if((i-1) < 0) {
                    cout << "Cant start like this -> " << Tokens[i].text << " at line " << Tokens[i].ln << endl;
                    break;
                } else {
                    if((i+1) > Tokens.size()) {
                        cout << "Cant end with " << Tokens[i].type << " at line " << Tokens[i].ln << endl;
                        break;
                    } else {
                        char op = Tokens[i].text[0];
                        if(Tokens[i-1].type == NUMBER && Tokens[i+1].type == NUMBER) {
                            int x = stoi(Tokens[i-1].text);
                            int y = stoi(Tokens[i+1].text);
                            switch(op) {
                                case '+':
                                    z = x + y;
                                    break;
                                case '-':
                                    z = x - y;
                                    break;
                                case '*':
                                    z = x * y;
                                    break;
                                case '/':
                                    if(y = 0) {
                                        cout << "You cannot divide by 0: " << Tokens[i+1].ln << endl; 
                                        break;
                                    } else {
                                        z = x / y;
                                    } break;
                            }
                        } else {
                            cout << "You can't add a number with a non number" << endl;
                            break;
                        }
                    }
                }
            }
        }
        return z;
    }


    // int Syntax::CreateTree(vector<Token>& Tokens) {
        
    // }
}