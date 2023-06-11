#include "MaquinadeBusca.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::string;  
using std::vector;
using std::map;
using std::stringstream;

MaquinaDeBusca::MaquinaDeBusca(vector <string> documentos){
    this->documentos = documentos;
}

string MaquinaDeBusca::normalizarTexto(string texto){
    string textoNormalizado;
    static const string caractereMaiusculo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const string caractereBasico = "abcdefghijklmnopqrstuvwxyz";
    static const string alfabetoOuEspaco = " abcdefghijklmnopqrstuvwxyz";
    string aux;
    aux.reserve(texto.length());

    for (char c : texto) { //troca caracteres maiusculos para o caractere basico
        size_t found = caractereMaiusculo.find(c);
        if (found != string::npos) {
                aux += caractereBasico[found];
        } else {
                aux += c;
        }
    }

    int count = 0;
    for(int i = 0; i < aux.size(); i++){ //exclui caracteres que não são letras ou espaço
        for(int j = 0; j < alfabetoOuEspaco.size(); j++){
            if(aux[i] == alfabetoOuEspaco[j]){
                count++;
            }
        }
        if(count == 0){
            aux.erase(aux.begin() + i);
            i--;
        }
        count = 0;
    }

    for(int i = 0; i < aux.size(); i++){ //coloca a auxiliar no textoNormalizado
        textoNormalizado.push_back(aux[i]);
    }

    return textoNormalizado;
}
       
vector<string> MaquinaDeBusca::separarPalavras(string textoNormalizado){
    vector <string> palavrasPesquisadas; //vetor onde ficarão as palavras já separadas

    for (int i = 0; i < textoNormalizado.size(); i++) {
    string palavraAtual;
        if (textoNormalizado[i] != ' '){
            while (i < textoNormalizado.size() && textoNormalizado[i] != ' '){
            palavraAtual.push_back(textoNormalizado[i]);
            i++;
            }
        palavrasPesquisadas.push_back(palavraAtual);
        }
    }

    return palavrasPesquisadas;
}

map<string, map<string, int>> MaquinaDeBusca::criarIndiceInvertido(const vector<string>& documentos) {
    map<string, map<string, int>> indiceInvertido;

    for (const string& documento : documentos) {
        std::ifstream input(documento);
        string linha;

        while (std::getline(input, linha)) {
            stringstream ss(linha);
            string palavra;

            while (ss >> palavra) {
                palavra = normalizarTexto(palavra);
                indiceInvertido[palavra][documento]++;
            }
        }
        input.close();
    }

    return indiceInvertido;
}


vector<string> MaquinaDeBusca::ordenarDocumentos(const vector<string>& palavrasPesquisadas, const map<string, map<string, int>>& indiceInvertido) {
    map<string, int> prioridadeDocumentos;

    for (const auto& palavra : palavrasPesquisadas) {
    const auto& documentos = indiceInvertido.find(palavra);
        if (documentos != indiceInvertido.end()) {
            for (const auto& documento : documentos->second) {
                if (documento.second > 0) {
                    prioridadeDocumentos[documento.first] += documento.second;
                }
            }
        }
    }
    // Filtra os documentos que possuem todas as palavras pesquisadas
    vector<string> documentosComTodasPalavras;
    vector<string> documentosOrdenados;

    for (const auto& documento : prioridadeDocumentos) {
        if (documento.second > 0) {
            documentosComTodasPalavras.push_back(documento.first);
        }
    }

    // Ordena os documentos com base na prioridade (soma das ocorrências de todas as palavras pesquisadas)
    std::sort(
        documentosComTodasPalavras.begin(),
        documentosComTodasPalavras.end(),
        [&prioridadeDocumentos](const string& a, const string& b) {
            if (prioridadeDocumentos[a] == prioridadeDocumentos[b]) {
                return a < b;
            }
            return prioridadeDocumentos[a] > prioridadeDocumentos[b];
        }
    );

    for(int i = 0; i < documentosComTodasPalavras.size(); i++){ //coloca o documentosComTodasPalavras no documentosOrdenados
        documentosOrdenados.push_back(documentosComTodasPalavras[i]);
    }

    return documentosOrdenados;
}

vector<string> MaquinaDeBusca::pesquisar(string textoPesquisado){
    map<string, map<string, int>> indiceInvertido = criarIndiceInvertido(documentos);
    string pesquisaNormalizada = normalizarTexto(textoPesquisado);
    vector <string> palavrasPesquisadas = separarPalavras(pesquisaNormalizada);
    vector<string> documentosOrdenados = ordenarDocumentos(palavrasPesquisadas, indiceInvertido);
    return documentosOrdenados;
}
