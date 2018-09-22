#include <string>
#include <iostream>
//#include <stringstream>

void test(){
  string s="text to be parsed";
  size_t pos=0;
  std::string token;
  while( (pos = s.find(" ")) != std::string::npos)
  {
     token=s.substr(0,pos);
     std::cout<<token<<std::endl;
     s.erase(0,pos+1);
  }
  std::cout<<s<<std::endl;
}
