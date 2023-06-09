#include "MaquinadeBusca.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

MaquinaDeBusca::MaquinaDeBusca(std::vector <std::string> documentos){
    this->documentos = documentos;
}

string MaquinaDeBusca::normalizarTexto(std::string texto){
    std::string textoNormalizado;
    static const std::string maiusculaOuAcento = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅàáâãäåÇçÈÉÊËèéêëÌÍÎÏìíîïÒÓÔÕÖØòóôõöøÙÚÛÜùúûüÝý";
    static const std::string caractereBasico = "abcdefghijklmnopqrstuvwxyzaaaaaaaaaaaacceeeeeeeeiiiiiiiioooooooooooouuuuuuuuyy";
    static const std::string alfabeto = " abcdefghijklmnopqrstuvwxyz";
    std::string aux;
    aux.reserve(texto.length());

        for (char c : texto) { //troca caracteres maiusculos ou com acento para o caractere basico
            size_t found = maiusculaOuAcento.find(c);
            if (found != std::string::npos) {
                    aux += caractereBasico[found];
            } else {
                    aux += c;
            }
        }

        int count = 0;
        for(int i = 0; i < aux.size(); i++){ //exclui caracteres que não são letras ou espaço
            for(int j = 0; j < alfabeto.size(); j++){
                if(aux[i] == alfabeto[j]){
                    count++;
                }
            }
            if(count == 0){
                aux.erase(aux.begin() + i);
                i--;
            }
            count = 0;
        }

        for(int i = 0; i < aux.size(); i++){//coloca a auxiliar no textoNormalizado
            textoNormalizado.push_back(aux[i]);
        }
    return textoNormalizado;
}
       
//Para separar o texto pesquisado
vector<string> MaquinaDeBusca::separarPalavras(std::string textoNormalizado){
    std::vector <std::string> palavrasPesquisadas; //onde ficarão as palavras já separadas no vetor

    for (int i = 0; i < textoNormalizado.size(); i++) {
    std::string palavraAtual;
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

vector<string> MaquinaDeBusca::pesquisar(std::string textoPesquisado){
    std::string pesquisaNormalizada = normalizarTexto(textoPesquisado);
    std::vector <std::string> palavrasPesquisadas = separarPalavras(pesquisaNormalizada);
    return {};
}

map<string, map<string, int>> MaquinaDeBusca::buildInverseIndex(const std::vector<std::string>& files) {
    std::map<std::string, std::map<std::string, int>> inverseIndex;

    for (const std::string& file : files) {
    std::ifstream input(file);
    std::string line;

        while (std::getline(input, line)) {
            std::stringstream ss(line);
            std::string word;

            while (ss >> word) {
                word = normalizarTexto(word);
                inverseIndex[word][file]++;
            }
        }

    input.close();
}
return inverseIndex;
}


std::vector<std::string> procurarPalavras(const std::vector<std::string>& palavrasPesquisadas, const std::map<std::string, std::map<std::string, int>>& inverseIndex) {
    std::map<std::string, int> prioridadeDocumentos;

    for (const auto& palavra : palavrasPesquisadas) {
    const auto& documentos = inverseIndex.find(palavra);
        if (documentos != inverseIndex.end()) {
            for (const auto& documento : documentos->second) {
                if (documento.second > 0) {
                    prioridadeDocumentos[documento.first] += documento.second;
                }
            }
        }
    }
    // Filtra os documentos que possuem todas as palavras pesquisadas
    std::vector<std::string> documentosComTodasPalavras;

    for (const auto& documento : prioridadeDocumentos) {
        if (documento.second > 0) {
            documentosComTodasPalavras.push_back(documento.first);
        }
    }

    // Ordena os documentos com base na prioridade (soma das ocorrências de todas as palavras pesquisadas)
    std::sort(documentosComTodasPalavras.begin(), documentosComTodasPalavras.end(),
    [&prioridadeDocumentos](const std::string& a, const std::string& b) {
        if (prioridadeDocumentos[a] == prioridadeDocumentos[b]) {
            return a < b;
        }
        return prioridadeDocumentos[a] > prioridadeDocumentos[b];
    }
);
return documentosComTodasPalavras;
}


    //somar os ints desse docs (que é um map), o que for maior aparece primeiro
    //if dois sejam iguais, aparecer o com nome menor
