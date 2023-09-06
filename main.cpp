#include "cpf.hpp"

int main(int argc, char** argv){
  std::srand(std::time(0));
  auto c = std::make_unique<Cpf>();
  if(argc > 1){
    std::string args = argv[1];
    if(args == "--format"){
      c->format_cpf();
      std::cout << c->m_numbs << '\n';
    }else if(c->check_cpf(&args)){
      std::cout << "\033[32;1m\u2714 CPF válido!\033[m\n";
    }else{
      std::cerr << "\033[31;1m\u2716 CPF ou Parâmetro inválido.\033[m\n";
      return EXIT_FAILURE;
    }
  }else{
    std::cout << c->m_numbs << '\n';
  }

  return 0;
}

