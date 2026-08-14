# Get Next Line - Projeto 42

<p align="center">
  <img src="https://img.shields.io/badge/42-%23000000.svg?style=for-the-badge&logo=42&logoColor=white" alt="42 Badge" />
  <img src="https://img.shields.io/badge/C-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white" alt="C Badge" />
  <img src="https://img.shields.io/github/license/NdondaDaniel2020/get_next_line?style=for-the-badge" alt="License Badge" />
</p>

## 📝 Sobre o Projeto

O **Get Next Line** (GNL) é um projeto clássico da grade curricular da 42. O objetivo é programar uma função em C que lê uma linha de cada vez a partir de um File Descriptor (descritor de arquivo), retornando a linha lida. 

Este projeto introduz conceitos fundamentais em C, tais como:
- **Variáveis estáticas**: Para reter dados lidos em chamadas anteriores.
- **Gerenciamento de buffer**: Otimização de leitura usando um tamanho de buffer dinâmico definido na compilação.
- **Alocação dinâmica de memória**: Manipulação cuidadosa de strings na heap (`malloc`, `free`) para evitar memory leaks.

---

## 🛠️ Protótipo da Função

```c
char *get_next_line(int fd);
```

### Parâmetros e Retorno
- **`fd`**: O descritor de arquivo (File Descriptor) de onde a leitura será realizada (ex: arquivo aberto com `open()`, entrada padrão `0`, etc.).
- **Retorno**: 
  - A linha lida (incluindo o caractere de nova linha `\n`, se estiver presente no arquivo).
  - `NULL` se o arquivo chegou ao fim (EOF) ou se ocorreu algum erro de leitura/alocação.

---

## 📂 Estrutura dos Arquivos

O repositório está organizado da seguinte forma:

| Arquivo | Descrição |
| :--- | :--- |
| [get_next_line.h](file:///spot/NdDaniel/Code/42/get_next_line/get_next_line.h) | Cabeçalho com definições e protótipos da parte obrigatória. |
| [get_next_line.c](file:///spot/NdDaniel/Code/42/get_next_line/get_next_line.c) | Função principal `get_next_line` e lógica de leitura de arquivos. |
| [get_next_line_utils.c](file:///spot/NdDaniel/Code/42/get_next_line/get_next_line_utils.c) | Funções auxiliares de manipulação de strings (`ft_strlen`, `ft_strjoin`, etc.). |
| [get_next_line_bonus.h](file:///spot/NdDaniel/Code/42/get_next_line/get_next_line_bonus.h) | Cabeçalho com suporte para a parte bônus. |
| [get_next_line_bonus.c](file:///spot/NdDaniel/Code/42/get_next_line/get_next_line_bonus.c) | Implementação bônus que suporta múltiplos File Descriptors simultaneamente. |
| [get_next_line_utils_bonus.c](file:///spot/NdDaniel/Code/42/get_next_line/get_next_line_utils_bonus.c) | Funções auxiliares para a versão bônus. |

---

## 💡 Como Funciona?

A função funciona lendo o arquivo em blocos de tamanho `BUFFER_SIZE` e armazenando as leituras em uma **variável estática**.

1. **Leitura**: Um loop lê do arquivo em pedaços definidos por `BUFFER_SIZE` até encontrar um caractere `\n` ou alcançar o fim do arquivo.
2. **Armazenamento**: O conteúdo lido é anexado à variável estática.
3. **Extração**: A função extrai a linha completa até o primeiro `\n` (inclusive) para retornar ao usuário.
4. **Atualização**: A variável estática é atualizada para conter apenas a sobra após o `\n`, aguardando a próxima chamada da função.

### 🌟 Parte Bônus
Na parte bônus, o `get_next_line` consegue gerenciar múltiplos descritores de arquivos simultaneamente. Por exemplo, se você ler do `fd 3`, depois do `fd 4`, e voltar a ler do `fd 3`, a função se lembrará de onde parou no `fd 3` sem perder nenhuma linha. Isso é implementado usando um array estático de ponteiros (`static char *str[4069]`).

---

## 🚀 Como Compilar e Usar

### 1. Compilação
Ao compilar seu programa junto com o `get_next_line`, você deve definir o tamanho do buffer desejado adicionando a flag `-D BUFFER_SIZE=N` no compilador (substitua `N` por um número inteiro maior que zero).

Exemplo de compilação (Parte Obrigatória):
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

Exemplo de compilação (Parte Bônus):
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

### 2. Exemplo de Código (`main.c`)

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("exemplo.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Lembre-se de liberar a memória alocada!
    }
    close(fd);
    return (0);
}
```

---

## 📄 Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo [LICENSE](file:///spot/NdDaniel/Code/42/get_next_line/LICENSE) para mais informações.
