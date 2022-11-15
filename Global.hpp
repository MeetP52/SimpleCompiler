#pragma once
#include <vector>
#include <string>
#include "List.hpp"


namespace Compiler {

	using namespace std;

	enum ErrorLevels {
		Error,
		Warning,
		Note
	};

	struct Errorous {
		ErrorLevels ErrorLevel;
		string msg;
		size_t ln;
	};

	class Global {
		public:
			vector<string> CreateTypeList();		
			DLL<Errorous> CreateErrorList();
			DLL<string> CreatePrintList();

	};
}

