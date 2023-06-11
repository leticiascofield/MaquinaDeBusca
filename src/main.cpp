#include "MaquinadeBusca.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using std::string;  
using std::vector;
using std::to_string;
using std::cin;
using std::cout;
using std::getline;
using std::endl;

int main() {
vector<string> documentos; // Insira todos os arquivos de d1.txt até d30.txt
    for (int i = 1; i <= 30; ++i) {
        documentos.push_back("d" + to_string(i) + ".txt");
    }

    MaquinaDeBusca Maquina(documentos);

    string textoPesquisado;
    cout << "Digite o texto a ser pesquisado: ";
    getline(cin, textoPesquisado);

    vector<string> documentosOrdenados = Maquina.pesquisar(textoPesquisado);

    if (documentosOrdenados.empty()) {
        cout << "Nenhum documento encontrado com as palavras pesquisadas." << endl;
    } else {
        cout << "Documentos encontrados (em ordem de prioridade):" << endl;
        for (const auto& documento : documentosOrdenados) {
            cout << documento << endl;
        }
    }

    return 0;
}

