#include "Global.hpp"

namespace Compiler {

	using namespace std;

	vector<string> Global::CreateTypeList() {

		vector<string> List;
		List.push_back("string");
		List.push_back("number");
		List.push_back("bool");
		List.push_back("void");
		List.push_back("char");
		List.push_back("auto");

		return List;
	}

	DLL<Errorous> Global::CreateErrorList() {
		DLL<Errorous> ErrorList;
		return ErrorList;
	}

	DLL<string> Global::CreatePrintList() {
		DLL<string> PrintList;
		return PrintList;
	}
}

