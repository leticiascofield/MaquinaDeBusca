#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main() {

    std::vector<std::string> files; //Insere todos os arquivos de d1.txt até d30.txt
    for (int i = 1; i <= 30; ++i) {
        files.push_back("d" + std::to_string(i) + ".txt");
    }

    // Faz o índice invertido
    std::map<std::string, std::map<std::string, int>> inverseIndex = buildInverseIndex(files);

    // Abre o arquivo que contém todas as palavras de todos os arquivos
    std::ofstream outputFile("output.txt");

    // Escreve o índice invertido no arquivo output.txt
    for (const auto& termEntry : inverseIndex) {
        outputFile << termEntry.first << ":\n";
        const std::map<std::string, int>& docMap = termEntry.second;

        for (const auto& docEntry : docMap) {
            outputFile << "   " << docEntry.first << ": " << docEntry.second << "\n";
        }
    }

    // Fecha o arquivo output.txt
    outputFile.close();

    return 0;
}