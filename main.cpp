#include <iostream>
#include <stdio.h>
#include "Token.hpp"
#include "Syntax.hpp"
// #include "Token.cpp"
// #include "Syntax.cpp"
#include "Global.hpp"
#include "List.hpp"
// #include "SymbolTable.hpp"
using namespace std;
using namespace Compiler;

// struct Me
// {
// 	string value;
// };

// struct LineVar {
//     int ln;
//     string value;
// };

// struct LineList {
//     DLL<LineVar> Node;
// };

int main () {
   
    // LineList a;
    // LineVar b;
    // b.ln = 1;
    // b.value = "string";
    // a.Node.push_back(b);

    // cout << a.Node.at(0)->NodeValue.ln << " " << a.Node.at(0)->NodeValue.value << endl;

    // Open the file.
    // Tokenie the text.
    // parse the text.
    // create an executable.

    FILE *fd = fopen("Simple.bp", "r");
    if (!fd) {
        cout << "Cant find file." << endl;
    } else {
        cout << "File found." << endl;
    }

    fseek(fd, 0, SEEK_END);
    size_t fileSize = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    std::string fileContents(fileSize, ' ');
    fread((void *)fileContents.data(), 1, fileSize, fd);
    //cout << fileContents << endl;

    Tokenizer To;
    Global Go;

    cout << "=================================" << endl;
    cout << "               Type              " << endl;
    cout << "=================================" << endl;

    vector<string> List = Go.CreateTypeList();
    
    for(string type : List) {
        cout << type << endl;
    }

    cout << "=================================" << endl;
    cout << "             Tokens              " << endl;
    cout << "=================================" << endl;

    vector<Token> Tokens = To.CreateToken(fileContents);

    for (Token it : Tokens) {
        it.DebugPrint();
    }


    cout << "=================================" << endl;
    cout << "               List              " << endl;
    cout << "=================================" << endl;

    // Me a, b, c, d, e, f;

	// a.value = "11";
	// b.value = "12";
	// c.value = "13";
	// d.value = "14";
	// e.value = "15";
	// f.value = "16";

	// DLL<Me> TestList;

	// TestList.push_front(a);
	// TestList.push_front(b);
	// TestList.push_front(c);
	// TestList.push_front(d);
	// TestList.push_front(e);
	// TestList.push_front(f);

	// for (Me it : TestList) {
	// 	cout << it.value << " ";
	// }
    // cout << endl;

	// for(DLL<Me>::iterator it = TestList.begin(); it != TestList.end(); it++) {
	// 	cout << (*it).value << endl;
	// }

    cout << "=================================" << endl;
    cout << "          Symbol Table           " << endl;
    cout << "=================================" << endl;

    // SymbolTable global;
	// global.Print();

    cout << "=================================" << endl;
    cout << "             Syntax              " << endl;
    cout << "=================================" << endl;

    Syntax Check;
    int result = Check.CreateTree(Tokens);
    cout << result << endl;


    return 0;
}