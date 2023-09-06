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

# Assista ao vídeo
## <https://youtu.be/_WTWl66TrlY>
