#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <unordered_set>
#include <unordered_map>

std::unordered_map<std::string, std::string> tokenMapping{
  {"(", "lparen"},
  {")", "rparen"},
  {"{", "lbrace"},
  {"}", "rbrace"},
  {"int", "type"},
  {";", "semicolon"},
  {"=", "op"},
  {"+", "op"},
  {"-", "op"},
  {"/", "op"},
  {"*", "op"},
  {"|", "op"},
  {"&", "op"},
  {"<", "op"},
  {">", "op"},
};

struct TokenType{

  std::string s;
  std::string type;

};

bool isReserved(char c)
{

  return !isalnum(c) && c != '_';

}

bool isWhiteSpace(char c)
{

  return c == ' ' || c == '\t' || c == '\n';

}

bool isConstant(std::string &s)
{

  return isdigit(s[0]);

}

std::vector<TokenType> splitRaw(std::ifstream &file)
{

  std::vector<TokenType> tokens;
  
  std::string tmp = "";
  std::streambuf *pbuf = file.rdbuf();

  while(pbuf->sgetc() != EOF){
    // remove consecutive whitespace
    while(pbuf->sgetc() != EOF && isWhiteSpace(pbuf->sgetc())){
      pbuf->sbumpc();
    }
    if(pbuf->sgetc() == EOF){
      return tokens;
    }
    if(!isReserved(pbuf->sgetc())){
      // regular alphanumeric values
      while(pbuf->sgetc() != EOF && !isReserved(pbuf->sgetc())){
        tmp += pbuf->sbumpc();
      }
      if(!tokenMapping.contains(tmp)){
        isConstant(tmp) ? tokens.push_back({tmp, "constant"}) : tokens.push_back({tmp, "variable"});
      }
      else{
        tokens.push_back({tmp, tokenMapping[tmp]});
      }
      tmp = "";
    }
    else{
      // Reserved character
      tmp += pbuf->sbumpc();
      tokens.push_back({tmp, tokenMapping[tmp]});
      tmp = "";
    }
  }

  return tokens;
}

int main(void)
{

  const std::string fileName = "sample.c";
  std::ifstream file(fileName);

  std::vector<TokenType> tokens = splitRaw(file);

  for(auto tok : tokens){
    std::cout << tok.s << " " << tok.type << std::endl;
  }
  
}