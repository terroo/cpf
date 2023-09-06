if(#arg > 0 and arg[1] == ("--check" or "-c")) then
  os.execute("cppcheck --suppress=missingIncludeSystem *.cpp")
end

os.execute("/usr/bin/g++ -Wall -Werror -Wextra -pedantic -g -fsanitize=address -O2 -o cpf *.cpp")
