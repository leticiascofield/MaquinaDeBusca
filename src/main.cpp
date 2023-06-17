#include "MaquinadeBusca.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string caminhoDocumentos = "./documentos";

    // Cria uma instância de MaquinaDeBusca
    MaquinaDeBusca maquina;

    // Obtém os caminhos dos arquivos no diretório
    std::vector<std::string> caminhoArquivos = maquina.obterCaminhoArquivos(caminhoDocumentos);

    // Passa o vetor caminhoArquivos para o construtor de MaquinaDeBusca
    MaquinaDeBusca maquinaDeBusca(caminhoArquivos);

    std::string textoPesquisado;
    std::cout << "Digite o texto a ser pesquisado: ";
    std::getline(std::cin, textoPesquisado);

    std::vector<std::string> documentosOrdenados = maquinaDeBusca.pesquisar(textoPesquisado);

    return 0;
}
