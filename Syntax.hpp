#pragma once
#include "Token.hpp"

namespace Compiler {

    class Syntax {
        public:
            int CreateTree(vector<Token>& Tokens);
    };
}