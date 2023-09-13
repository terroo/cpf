#include "cpf.hpp"

Cpf::Cpf(){
  for (size_t i {}; i < 9; ++i){
    this->m_numbs += std::to_string(std::rand() % 9);
  }
  generate_first_digit();
  generate_second_digit();
}

void Cpf::generate_first_digit(){
  int d1 {};
  for (size_t i {}, k {10}; i < m_numbs.size(); ++i, --k){
    d1 += std::stoi(m_numbs.substr(i, 1)) * k; 
  }

  (d1 % 11 < 2) ?
    this->m_numbs += "0" :
    this->m_numbs += std::to_string(11 - (d1 % 11));
}

void Cpf::generate_second_digit(){
  int d2 {};
  for (size_t i {}, k {10}; i < m_numbs.size() - 1; ++i, --k){
    d2 += std::stoi(m_numbs.substr(i + 1, 1)) * k; 
  }

  (d2 % 11 < 2) ?
    this->m_numbs += "0" :
    this->m_numbs += std::to_string(11 - (d2 % 11));
}

void Cpf::format_cpf(){
  m_numbs.insert(m_numbs.size() - 8, 1, '.');
  m_numbs.insert(m_numbs.size() - 5, 1, '.');
  m_numbs.insert(m_numbs.size() - 2, 1, '-');
}

bool Cpf::check_cpf(std::string * cpf){
  // Limpa o CPF
  (*cpf).erase(std::remove((*cpf).begin(), (*cpf).end(), '.'), (*cpf).end());
  (*cpf).erase(std::remove((*cpf).begin(), (*cpf).end(), '-'), (*cpf).end());

  // Verificar se o CPF é somente números
  if(!std::all_of(cpf->begin(), cpf->end(), ::isdigit) || 
      cpf->size() != 11){
    return false;
  }

  std::vector<std::string> v = {
    "00000000000", "11111111111", "22222222222", "33333333333", 
    "44444444444", "55555555555", "66666666666", "77777777777", 
    "88888888888", "99999999999"
  };

  if(std::find(v.begin(), v.end(), *cpf) != v.end()){
    return false;
  }


  this->m_numbs = cpf->substr(0, 9);
  generate_first_digit();
  generate_second_digit();
  return this->m_numbs == *cpf;
}
