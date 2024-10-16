/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:11:41 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:56:45 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
No contexto do exercício "Sed is for losers", sed refere-se a um utilitário de linha de 
comando muito utilizado em sistemas Unix e Linux para realizar operações de substituição 
de texto em arquivos. O nome "sed" é uma abreviação de "stream editor".
O que o sed faz:
Substituição de texto: O comando sed é frequentemente usado para substituir ocorrências 
de uma string por outra em um arquivo de texto. Por exemplo, você pode usar sed para substituir
todas as ocorrências de "s1" por "s2" em um arquivo.
Edição em fluxo: Ele processa o texto em fluxo, o que significa que pode ler, modificar 
e escrever texto diretamente, sem precisar abrir um editor de texto.
Uso em scripts: O sed é frequentemente usado em scripts de shell para automatizar 
tarefas de edição de texto.

No exercício:
O título sugere que você deve criar um programa em C++ que imita a funcionalidade do comando sed, 
mas sem usar as funções de manipulação de arquivos de C, além de proibir o uso de std::string::replace. 
O objetivo é fazer substituições de texto em um arquivo e criar um novo arquivo com as modificações, assim como o sed faria.
A ênfase no uso de C++ e nas funções de string permite explorar a manipulação de 
strings sem recorrer a operações de arquivos de nível inferior, promovendo o uso de 
abstrações mais avançadas disponíveis na linguagem.
*/

/*
As funções e métodos abaixo não fazem parte das funções de manipulação de arquivos 
da linguagem C, mas sim de C++. Vamos detalhar cada uma delas:
1 - file.is_open(): Esta é uma função da classe ifstream ou ofstream em C++. 
Ela verifica se um arquivo foi aberto com sucesso. É uma maneira de garantir que a 
operação de abertura do arquivo foi bem-sucedida.
2 - file.close(): Esta é outra função da classe ifstream ou ofstream em C++. 
Ela fecha um arquivo que foi aberto, liberando qualquer recurso associado a ele.
3 - line.find(s1, pos): Esta função é um método da classe std::string em C++. 
Ele busca a substring s1 a partir da posição pos em uma string chamada line. 
Se a substring for encontrada, ele retorna a posição da primeira ocorrência; 
caso contrário, retorna std::string::npos.

Essas funções e métodos fazem parte da biblioteca padrão de C++ e estão relacionadas 
à manipulação de arquivos e strings em um contexto orientado a objetos, enquanto as 
funções de manipulação de arquivos em C (como fopen, fclose, fread, etc.) são 
mais simples e baseadas em funções.
*/

/*
Funções que fazem parte das funções de manipulação são:
As C file manipulation functions são um conjunto de funções da linguagem de 
programação C que permitem ler, escrever e manipular arquivos em disco. Elas 
são parte da biblioteca padrão de entrada e saída (stdio.h). Essas funções 
permitem que os programadores realizem operações como abrir, fechar, ler, 
escrever e manipular arquivos.
Aqui estão algumas das funções mais comuns usadas para manipulação de arquivos em C:
1. fopen(): Abre um arquivo e retorna um ponteiro para ele.
FILE *fopen(const char *filename, const char *mode);
2. fclose(): Fecha um arquivo aberto.
int fclose(FILE *stream);
3. fread(): Lê dados de um arquivo para um buffer.
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
4. fwrite(): Escreve dados de um buffer para um arquivo.
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
5. fseek(): Move o ponteiro de leitura/escrita para uma posição específica em um arquivo.
int fseek(FILE *stream, long offset, int whence);
6. ftell(): Retorna a posição atual do ponteiro de leitura/escrita em um arquivo.
long ftell(FILE *stream);
7. rewind(): Move o ponteiro de leitura/escrita para o início de um arquivo.
void rewind(FILE *stream);
8. fprintf(): Escreve uma string formatada em um arquivo.
int fprintf(FILE *stream, const char *format, ...);
9. fscanf(): Lê dados formatados de um arquivo.
int fscanf(FILE *stream, const char *format, ...);
Essas funções permitem que você trabalhe com arquivos de texto e binários, 
possibilitando diversas operações, desde a simples gravação de dados 
até a manipulação mais complexa de arquivos.
*/

/*
Uso de exit vs return:
Embora exit(1) e return(1) terminem o programa com um código de erro, há diferenças subtis.
Ambos terminam o programa com um código de erro 1. No entanto, exit(1) é mais eficiente, 
pois termina o programa imediatamente, enquanto return(1) termina o programa após executar o main.
Contudo neste caso é melhor usarmos o return (1). E porquê? Porque exit(1) encerra imediatamente o programa, 
não chamando os destructors de objetos automáticos na pilha. 
Em contraste, return(1) finaliza a função main, permitindo que o programa realize a limpeza 
e os destructors sejam chamados. Para um programa pequeno e simples como este, 
return(1) é geralmente preferido.
*/

/*
Uso da Função replace:
A função line.replace(pos, s1.length(), s2); está em desacordo com as restrições do exercício que 
proíbe o uso de std::string::replace.
*/

/*
// Qual a diferença entre ifstream e ofstream? 
R: ifstream é usado para ler ficheiros, enquanto ofstream é usado para escrever ficheiros.
*/

/*
A função .is_open() é usada para verificar se o ficheiro foi aberto com sucesso. 
Recebe um valor booleano, retornando true se o ficheiro foi aberto com sucesso e false caso contrário.
*/

/*
Fechamento de Arquivos: Embora você esteja fechando os arquivos corretamente, isso não é estritamente necessário, 
pois os destructors de ifstream e ofstream fecharão os arquivos automaticamente ao sair do escopo. 
No entanto, fechá-los explicitamente é uma boa prática, especialmente em programas maiores.
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) 
{
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1; // Preferível para permitir a limpeza correta. 
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    if (s1.empty()) 
    {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    }
    
    std::string s2 = argv[3];
    std::string new_filename = filename + ".replace";
    std::ifstream file(filename); // Qual a diferença entre ifstream e ofstream? R: ifstream é usado para ler ficheiros, enquanto ofstream é usado para escrever ficheiros.
    if (!file.is_open()) // Se não conseguir abrir o ficheiro usando a função open, então dá erro imprimindo a respetiva msg.
    {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }

    std::ofstream new_file(new_filename); // Isto serve para criar um novo ficheiro com o nome filename.replace
    if (!new_file.is_open()) // Se não conseguir abrir o ficheiro usando a função open, então dá erro imprimindo a respetiva msg.
    
    {
        std::cerr << "Error: could not create new file" << std::endl;
        return 1;
    }

    std::string line; // Define uma string chamada line, que é usada para armazenar cada linha do ficheiro.
    while (std::getline(file, line)) 
    {
        size_t pos = 0; // Define a posição inicial da string s1 e guarda essa posição na variável pos.
        while ((pos = line.find(s1, pos)) != std::string::npos) // Enquanto encontrar a string s1 na linha do ficheiro, substitui pela string s2 e continua a procurar a string s1 na linha. Isto serve para substituir a string s1 pela string s2. Como? A função find procura a string s1 na string line. Se encontrar, substitui pela string s2.
        {
            line.erase(pos, s1.length()); // Remove a string s1. Não podendo usar a função replace, line.replace(pos, s1.length(), s2);, temos de usar a função erase para remover a string s1 e depois inserir a string s2 usando a função insert. 
            line.insert(pos, s2); // Insere a string s2 na posição correta
            pos += s2.length(); // Atualiza a posição para continuar a procura
        }
        new_file << line << std::endl;
    }
    
    // Fechamento dos arquivos (opcional, mas uma boa prática)
    file.close();
    new_file.close();
    return 0;
}
