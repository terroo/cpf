#include "cpf.hpp"
#include <nlohmann/json.hpp>

int main(){

  auto split = [](const std::string& str){
    std::vector<std::string> vec;
    bool change {false};
    std::string key {}, value {};

    for (size_t i {}; i < str.size(); ++i){
      if(str.substr(i, 1) == "="){
        change = true;
      }

      if(!change){
        key += str.substr(i, 1);
      }else{
        value += str.substr(i + 1, 1);
      }
    }
    vec.push_back(key);
    vec.emplace_back(value);

    return vec;
  };

  std::srand(std::time(0));
  auto c = std::make_unique<Cpf>();

  std::string get {};

  if(std::getenv("QUERY_STRING")){
    get = std::getenv("QUERY_STRING");
  }

  nlohmann::json json, check;
  json["cpf"] = c->m_numbs;

  c->format_cpf();
  json["format"] = c->m_numbs;

  std::cout << "Content-type: application/json\n" << '\n';

  if(get.empty()){
    std::cout << json << '\n';
  }else{
    if(split(get)[0] == "cpf"){
      if(c->check_cpf(&split(get)[1])){
        check["check"] = "true";
      }else{
        check["check"] = "false";
      }
    }
    std::cout << check << '\n';
  }

  return 0;
}

