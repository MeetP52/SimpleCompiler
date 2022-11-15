#pragma once
#include <vector>
#include <string>

namespace Compiler {

	using namespace std;

	enum TokenType {
		WHITESPACE,
		IDENTIFIER,
    	LSIGN,
    	RSIGN,
		LPARAN,
		RPARAN,
		LBRACE,
		RBRACE,
		LBRAC,
		RBRAC,
		OPERATOR,
		SPECIAL_SYMBOL,
		NUMBER,
		STRING,
		CHARACTER,
		VOID,
		BOOL,
		DECIMAL,
		DOT,
		COMMENT,
		POTENTIAL_COMMENT,
		SET_OPERATOR,
		END_STATEMENT,
		END_LINE,
		COLON,
		COMMA,
		UNKNOWN
	};

	static const char *StringWords[] = {
		"WHTIESPACE",
		"IDENTIFIER",
		"LSIGN",
		"RSIGN",
		"LPARAN",
		"RPARAN",
		"LBRACE",
		"RBRACE",
		"LBRAC",
		"RBRAC",
		"OPERATOR",
		"SPECIAL_SYMBOL",
		"NUMBER",
		"STRING",
		"CHARACTER",
		"VOID",
		"BOOL",
		"DECIMAL",
		"DOT",
		"COMMENT",
		"POTENTIAL_COMMENT",
		"SET_OPERATOR",
		"END_STATEMENT",
		"END_LINE",
		"COLON",
		"COMMA",
		"UNKNOWN"
	};

  static const char *KeyWords[] {
      "break",
      "case",
      "switch",
      "if",
      "else",
      "while",
      "do",
      "private",
      "public",
      "protected",
      "return",
      "output",
      "input"
  };

	struct Token {
		TokenType type = {WHITESPACE};
		string text = "";
		size_t ln = 0;
		void DebugPrint();
	};

	class Tokenizer {
		public:
			vector<Token> CreateToken(const string& inpuit);
      		vector<string> CreateTypeList();
		private:
			void EndToken(Token &token, vector<Token> &tokens);
	};

}
