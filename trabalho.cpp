#include <iostream>
#include <string>
#include <map>
#include <vector>

class MaquinaDeBusca{
    public:

    //Criar uma maquina de busca com documentos
    MaquinaDeBusca(std::vector <std::wstring> documentos){
        this->documentos = documentos;
    }

    std::vector <std::wstring> pesquisar(std::wstring textoPesquisado){
        std::wstring pesquisaNormalizada = normalizarTexto(textoPesquisado);
        std::vector <std::wstring> palavrasPesquisadas = separarPalavras(pesquisaNormalizada);
        std::vector<std::map <std::wstring, int>> documentosComPalavra = procurarPalavra(palavrasPesquisadas, documentos);
        //Ainda falta resolver prioridade de documentos e retornar
        return 0;
    }

    //Para normalizar um texto (textoPesquisado e documentos)
    std::wstring normalizarTexto(std::wstring texto){

        std::wstring textoNormalizado;
        static const std::wstring maiusculaOuAcento = L"ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅàáâãäåÇçÈÉÊËèéêëÌÍÎÏìíîïÒÓÔÕÖØòóôõöøÙÚÛÜùúûüÝý";
        static const std::wstring caractereBasico = L"abcdefghijklmnopqrstuvwxyzaaaaaaaaaaaacceeeeeeeeiiiiiiiioooooooooooouuuuuuuuyy";
        static const std::wstring alfabeto = L" abcdefghijklmnopqrstuvwxyz";
        std::wstring aux;
        aux.reserve(texto.length());

        for (wchar_t c : texto) { //troca caracteres maiusculos ou com acento para o caractere basico
            size_t found = maiusculaOuAcento.find(c);
            if (found != std::wstring::npos) {
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
    std::vector <std::wstring> separarPalavras(std::wstring textoNormalizado){

        std::vector <std::wstring> palavrasPesquisadas; //onde ficarão as palavras já separadas no vetor

        for(int i=0; i<textoNormalizado.size(); i++){ //itera pelo texto
            std::wstring palavraAtual;
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


    //Para procurar as palavras pesquisadas nos documentos
    // Vector - palavra[i] que aparece nos documentos
    // Map - documento[j] e quantidade de vezes que tem palavra[i] (quantidade>0)
    //usar find()
    std::vector<std::map <std::wstring, int>> procurarPalavra(std::vector<std::wstring> palavrasPesquisadas, std::vector <std::wstring> documentos){
        std::vector<std::map <std::wstring, int>> documentosComPalavra; 
        //código
        for (int i = 0; i < palavrasPesquisadas.size(); i++){
            for (int j = 0; j < documentos.size(); j++)
                if (documentos.find(palavrasPesquisadas)){

                }
        }

        return documentosComPalavra;
    }

    //ver se tem todas as palavras em um docs -> fazer uma função (de map) para contar quantas vezes um wstring 
    //(ex: d1.txt) aparece no vetor, se a quantidade for igual o tamanho do vetor, esse docs tem todas as palavras

    //somar os ints desse docs (que é um map), o que for maior aparece primeiro
    //if dois sejam iguais, aparecer o com nome menor


    //Ainda tem que fazer funções do subsistema de recuperação e no main colocar os arquivos dos documentos no vector<wstring>
    private:

    std::vector <std::wstring> documentos;

};