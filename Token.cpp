#include "Token.hpp"
#include <iostream>

namespace Compiler {

using namespace std;

vector<Token> Tokenizer::CreateToken(const string &input) {

  vector<Token> tokens;
  Token token;

  token.ln = 1;

  for (char ch : input) {
    if (token.type == POTENTIAL_COMMENT) {
      switch (ch) {
      case 't':
        token.text.append(1, '\t');
        break;
      case 'n':
        token.text.append(1, '\n');
        break;
      case 'r':
        token.text.append(1, '\r');
        break;
      case '\'':
        token.text.append(1, '\\');
        break;
      default:
        cout << "Unknown string '" << token.text << "'" << token.ln << endl;
      }
      continue;
    }
    switch (ch) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      if (token.type == WHITESPACE) {
        token.type = IDENTIFIER;
        token.text.append(1, ch);
      } else if (token.type == IDENTIFIER) {
        token.text.append(1, ch);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        token.type = UNKNOWN;
        token.text.append(1, ch);
      }
      break;

    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      if (token.type == WHITESPACE) {
        token.type = IDENTIFIER;
        token.text.append(1, ch);
      } else if (token.type == IDENTIFIER) {
        token.text.append(1, ch);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        token.type = UNKNOWN;
        token.text.append(1, ch);
      }
      break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      if (token.type == WHITESPACE) {
        token.type = NUMBER;
        token.text.append(1, ch);
      } else if (token.type == NUMBER || token.type == DECIMAL) {
        token.text.append(1, ch);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == IDENTIFIER ||
                 token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else if (token.type == OPERATOR && token.text == "-") {
        token.type = NUMBER;
        token.text.append(1,ch);
      } else { 
        token.text = UNKNOWN;
        token.text.append(1, ch);
      }
      break;
    case '=':
      if (token.type == WHITESPACE) {
        token.type = SET_OPERATOR;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = SET_OPERATOR;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;

    case '\\':
      if (token.type == WHITESPACE) {
        token.type = POTENTIAL_COMMENT;
        token.text.append(1, ch);
      } else if (token.type == POTENTIAL_COMMENT) {
        token.type = COMMENT;
        token.text.append(1, ch);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
      }
      break;

    case '+':
    case '*':
    case '/':
    case '%':
      if (token.type == WHITESPACE) {
        token.type = OPERATOR;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = OPERATOR;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;

    case '-':
    if (token.type == WHITESPACE) {
        token.type = OPERATOR;
        token.text.append(1, ch);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = OPERATOR;
        token.text.append(1, ch);
      }
      break;

    case '(':
      if (token.type == WHITESPACE) {
        token.type = LPARAN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = LPARAN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case ')':
      if (token.type == WHITESPACE) {
        token.type = RPARAN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = RPARAN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case '{':
      if (token.type == WHITESPACE) {
        token.type = LBRACE;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = LBRACE;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case '}':
      if (token.type == WHITESPACE) {
        token.type = RBRACE;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = RBRACE;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case '<':
      if (token.type == WHITESPACE) {
        token.type = LSIGN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = LSIGN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case '>':
      if (token.type == WHITESPACE) {
        token.type = RSIGN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = RSIGN;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case '[':
      if (token.type == WHITESPACE) {
        token.type = LBRAC;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = LBRACE;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case ']':
      if (token.type == WHITESPACE) {
        token.type = RBRAC;
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = RBRAC;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;

    case ' ':
    case '\t':
      if (token.type == STRING || token.type == CHARACTER ||
          token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
      }
      break;

    case '\n':
    case '\r':
      if (token.type == STRING || token.type == CHARACTER ||
          token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        token.type = END_LINE;
        EndToken(token, tokens);
      }
      break;

    case '"':
      if (token.type == WHITESPACE) {
        token.type = STRING;
      } else if (token.type == STRING) {
        EndToken(token, tokens);
      } else if (token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        token.type = UNKNOWN;
        token.text.append(1, ch);
      }
      break;

    case '\'':
      if (token.type == WHITESPACE) {
        token.type = CHARACTER;
        token.text.append(1, ch);
      } else if (token.type == CHARACTER) {
        token.text.append(1, ch);
        EndToken(token, tokens);
      } else if (token.type == STRING || token.type == COMMENT ||
                 token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        token.type = UNKNOWN;
        token.text.append(1, ch);
      }
      break;

    case '.':
      if (token.type == NUMBER) {
        token.type = DECIMAL;
        token.text.append(1, ch);
      } else if (token.type == STRING || token.type == CHARACTER ||
                 token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = DOT;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;

    case ',':
      if (token.type == STRING || token.type == CHARACTER ||
          token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = COMMA;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;

    case ';':
      if (token.type == STRING || token.type == CHARACTER ||
          token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = END_STATEMENT;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;

    case ':':
      if (token.type == STRING || token.type == CHARACTER ||
          token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = COLON;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    case '&':
    case '#':
    case '@':
    case '!':
    case '|':
    case '?':
    case '^':
    case '`':
      if (token.type == STRING || token.type == CHARACTER ||
          token.type == COMMENT || token.type == UNKNOWN) {
        token.text.append(1, ch);
      } else {
        EndToken(token, tokens);
        token.type = SPECIAL_SYMBOL;
        token.text.append(1, ch);
        EndToken(token, tokens);
      }
      break;
    default:
      token.type = UNKNOWN;
      token.text.append(1, ch);
      break;
    }
  }
  EndToken(token, tokens);
  return tokens;
}

void Token::DebugPrint() {
  cout << "Token(" << StringWords[type] << ",\"" << text << "\", " << ln << ")"
       << endl;
}

void isVarType(Token &token, vector<string> List) {
  for(string type : List) {
    
  }
}

void Tokenizer::EndToken(Token &token, vector<Token> &tokens) {
  if (token.type != WHITESPACE && token.type != UNKNOWN) {
    tokens.push_back(token);
  }
  token.type = WHITESPACE;
  token.text.erase();
}

vector<string> Tokenizer::CreateTypeList() {
  vector<string> List;
  List.push_back("string");
  List.push_back("number");
  List.push_back("char");
  List.push_back("bool");
  List.push_back("void");
  List.push_back("auto");

  return List;
}

} // namespace Compiler
