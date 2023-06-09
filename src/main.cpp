#include "MaquinadeBusca.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
std::vector<std::string> files; // Insira todos os arquivos de d1.txt até d30.txt
    for (int i = 1; i <= 30; ++i) {
        files.push_back("d" + std::to_string(i) + ".txt");
    }

    MaquinaDeBusca Maquina(files);

    // Constrói o índice invertido
    std::map<std::string, std::map<std::string, int>> inverseIndex;
    inverseIndex = Maquina.buildInverseIndex(files);

    std::string textoPesquisado;
    std::cout << "Digite o texto a ser pesquisado: ";
    std::getline(std::cin, textoPesquisado);

    // Normaliza o texto pesquisado
    std::string pesquisaNormalizada;
    pesquisaNormalizada = Maquina.normalizarTexto(textoPesquisado);

    // Separa as palavras pesquisadas
    std::vector<std::string> palavrasPesquisadas;
    palavrasPesquisadas = Maquina.separarPalavras(pesquisaNormalizada);

    // Procura as palavras nos documentos e obtém os documentos ordenados por prioridade
    std::vector<std::string> documentosOrdenados;
    documentosOrdenados = Maquina.procurarPalavras(palavrasPesquisadas, inverseIndex);

    std::cout << "Palavras pesquisadas:" << std::endl;
    for (const auto& palavra : palavrasPesquisadas) {
        std::cout << palavra << std::endl;
    }

    if (documentosOrdenados.empty()) {
        std::cout << "Nenhum documento encontrado com as palavras pesquisadas." << std::endl;
    } else {
        std::cout << "Documentos encontrados (em ordem de prioridade):" << std::endl;
        for (const auto& documento : documentosOrdenados) {
            std::cout << documento << std::endl;
        }
    }

    return 0;
}

