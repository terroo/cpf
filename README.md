# Gere e valide CPF com C++
> Código criado no vídeo: <https://youtu.be/_WTWl66TrlY>

---

# Compile
```bash
git clone https://github.com/terroo/cpf
cd cpf
g++ main.cpp cpf.cpp -o cpf
```

> Se tiver [Lua](https://terminalroot.com.br/tags#lua) instalado, basta compilar:
```bash
lua build.lua
```

---

# Use
> Se quiser instalar: `sudo cp cpf /usr/local/bin/`

Gerar CPF sem formatação
```bash
cpf 
# Exemplo de saída: 46318374892
```

Gerar CPF com formatação
```bash
cpf --format
# Exemplo de saída: 382.216.528-06
```

Validar CPF:
```bash
# Com formatação
cpf 382.216.528-06

# Ou sem formatação
cpf 46318374892
```

---

# Versão Web
### Feita com [Vue.js](https://github.com/vuejs) e [TailwindCSS](https://github.com/tailwindlabs/tailwindcss) rodando no [Apache](https://github.com/apache) com [C++](https://terminalroot.com.br/tags#cpp)
Disponível no diretório [api/](./api)
> Assista ao vídeo: <https://youtu.be/kTySQQT7_Sg>

---

# Assista ao vídeo do Modo CLI
## <https://youtu.be/_WTWl66TrlY>
