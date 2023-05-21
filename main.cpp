#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main() {

    //colocar os arquivos dos documentos no vector<wstring> documentos
    std::wstring textoPesquisado = "Eu estou pesquisando isso";
    std::vector <std::wstring> documentos; //colocar os arquivos dos documentos
    MaquinaDeBusca(documentos) buscaTeste; //quais documentos tem minha maquina de busca (no caso, todos)
    buscaTeste.pesquisar(textoPesquisado);

    return 0;
}