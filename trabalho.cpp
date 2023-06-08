#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include<algorithm>


class MaquinaDeBusca{
    public:

    //Criar uma maquina de busca com documentos
    MaquinaDeBusca(std::vector <std::string> documentos){
        this->documentos = documentos;
    }

    //Para normalizar um texto (textoPesquisado e documentos)
    std::string normalizarTexto(std::string texto){

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
       std::vector <std::string> pesquisar(std::string textoPesquisado){
        std::string pesquisaNormalizada = normalizarTexto(textoPesquisado);
        std::vector <std::string> palavrasPesquisadas = separarPalavras(pesquisaNormalizada);
        std::vector<std::map <std::string, int>> documentosComPalavra = procurarPalavra(palavrasPesquisadas, documentos);
        //Ainda falta resolver prioridade de documentos e retornar
        return {};
    }

    //Para separar o texto pesquisado
    std::vector <std::string> separarPalavras(std::string textoNormalizado){
        
    std::vector <std::string> palavrasPesquisadas; //onde ficarão as palavras já separadas no vetor

       for (int i = 0; i < textoNormalizado.size(); i++) {
        std::string palavraAtual;
    if (textoNormalizado[i] != ' ') {
        while (i < textoNormalizado.size() && textoNormalizado[i] != ' ') {
            palavraAtual.push_back(textoNormalizado[i]);
            i++;
        }
        palavrasPesquisadas.push_back(palavraAtual);
    }
  }
   return palavrasPesquisadas;
    }

    //Função que faz o índice invertido
    std::map<std::string, std::map<std::string, int>> buildInverseIndex(const std::vector<std::string>& files) {
        
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

    std::vector<std::map <std::string, int>> procurarPalavra(std::vector<std::string> palavrasPesquisadas, std::vector <std::string> documentos){
        std::vector<std::map <std::string, int>> documentosComPalavra; 
        //código
        for (int i = 0; i < palavrasPesquisadas.size(); i++){
            for (int j = 0; j < documentos.size(); j++)
                if (documentos.find(palavrasPesquisadas)){

                }
        }

        return documentosComPalavra;
    }


    //somar os ints desse docs (que é um map), o que for maior aparece primeiro
    //if dois sejam iguais, aparecer o com nome menor

    private:

    std::vector <std::string> documentos;

    
};