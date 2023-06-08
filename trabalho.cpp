#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

class MaquinaDeBusca{
    public:

    //Criar uma maquina de busca com documentos
    MaquinaDeBusca(std::vector <std::string> documentos){
        this->documentos = documentos;
    }

    //Para normalizar um texto (textoPesquisado e documentos)
    std::string normalizarTexto(std::string texto){

        std::string textoNormalizado;
        static const std::string caractereMaiusculo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        static const std::string caractereMinusculo = "abcdefghijklmnopqrstuvwxyz";
        static const std::string alfabeto = " abcdefghijklmnopqrstuvwxyz";
        std::string aux;
        aux.reserve(texto.length());

        for (char c : texto) { //troca caracteres maiusculos para o caractere basico
            size_t found = caractereMaiusculo.find(c);
            if (found != std::string::npos) {
                aux += caractereMinusculo[found];
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

        for(int i = 0; i < aux.size(); i++){ //coloca a auxiliar no textoNormalizado
            textoNormalizado.push_back(aux[i]);
        }
        return textoNormalizado;
    }

       std::vector <std::string> pesquisar(std::string textoPesquisado){
        std::string pesquisaNormalizada = normalizarTexto(textoPesquisado);
        std::vector <std::string> palavrasPesquisadas = separarPalavras(pesquisaNormalizada);
        std::vector<std::map <std::string, int>> documentosComPalavra = procurarPalavra(palavrasPesquisadas, documentos);
        //Ainda falta resolver prioridade de documentos e retornar
        return 0;
    }

    //Para separar o texto pesquisado
    std::vector <std::string> separarPalavras(std::string textoNormalizado){

        std::vector <std::string> palavrasPesquisadas; //onde ficarão as palavras já separadas no vetor

        for(int i=0; i<textoNormalizado.size(); i++){ //itera pelo texto
            std::string palavraAtual;
            if(textoNormalizado[i+1] == ' ' || i+1 == textoNormalizado.size()){ //se a próxima posição for ' ' ou fim do texto, fazer:
                palavraAtual.clear();
                for(int j = i; textoNormalizado[j] != ' ' && j >= 0; j--){ //coloca palavra em palavraAtual (invertida)           
                    palavraAtual.push_back(textoNormalizado[j]);  
                }
                std::reverse(palavraAtual.begin(), palavraAtual.end()); //volta palavra para ordem normal
                palavrasPesquisadas.push_back(palavraAtual); //coloca palavra em palavrasPesquisadas
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


    //Para procurar as palavras pesquisadas nos documentos
    // Vector - palavra[i] que aparece nos documentos
    // Map - documento[j] e quantidade de vezes que tem palavra[i] (quantidade>0)
    //usar find()
    /*std::vector<std::map <std::string, int>> procurarPalavra(std::vector<std::string> palavrasPesquisadas, std::vector <std::string> documentos){
        std::vector<std::map <std::string, int>> documentosComPalavra; 
        //código
        for (int i = 0; i < palavrasPesquisadas.size(); i++){
            for (int j = 0; j < documentos.size(); j++)
                if (documentos.find(palavrasPesquisadas)){

                }
        }

        return documentosComPalavra;
    }*/

    //ver se tem todas as palavras em um docs -> fazer uma função (de map) para contar quantas vezes um string 
    //(ex: d1.txt) aparece no vetor, se a quantidade for igual o tamanho do vetor, esse docs tem todas as palavras

    //somar os ints desse docs (que é um map), o que for maior aparece primeiro
    //if dois sejam iguais, aparecer o com nome menor


    //Ainda tem que fazer funções do subsistema de recuperação e no main colocar os arquivos dos documentos no vector<string>
    private:

    std::vector <std::string> documentos;

    
};