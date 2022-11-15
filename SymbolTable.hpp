#pragma once 
#include <string>
#include <iostream>
#include "List.hpp"

namespace Compiler {

    using namespace std;

    struct VarVal {
        int LineNumber;
        string Value;

        VarVal(int ln, string value) {LineNumber = ln; Value = value;}
    };
    
    struct VarNode {
        string Name, Scope, Type, Value;
        DLL<VarVal> LineVal;
        VarVal *Next, *Prev;

        VarNode(string name,string type, string value, DLL<VarVal> lineVal, string scope) {
            Name = name;
            Type = type;
            Value = value;
            LineVal = lineVal;
            Scope = scope;
        }
    };

    // struct FuncVal {
    //   int LineNumber;
    //   DLL<string> Value;

    //   FuncVal(int ln, DLL<string> returnVal) {
    //     LineNumber = ln;
    //     for(int i = 0; i < returnVal.size(); i++) {
    //         Value.push_back(returnVal.at(i).NodeValue);
    //     }
    //   }

    // };

    // struct FuncNode {
    //   string Name, Scope;
    //   DLL<string> Args, Return;
    //   DLL<FuncVal> LineNumber;
    //   FuncNode *Next, *Prev;

    //    FuncNode(string name,string scope, DLL<string> args, DLL<string> returns, DLL<FuncVal> ln) {
    //         Name = name;
    //         Scope = scope;
    //         //Args.push_back();
    //     }
    // };

    struct StructNode {
      string Name, Scope;
      DLL<string> Elements;
      DLL<int> LineNumber;
      StructNode *Next, *Prev;
    };

    template<typename t>
    class SymbolTable : public DLL<t> {
        private:
            VarNode *Head, *Tail;
        public:
            //SymbolTable() {Head =  new VarNode("Starting_Node","void","NULL",0,"global","static"); Tail = Head;}
            bool hasVal(string name);
            VarNode *GetHead() {return Head;}
            VarNode *GetTail() {return Tail;}  

            //void Print();
            
    };

}