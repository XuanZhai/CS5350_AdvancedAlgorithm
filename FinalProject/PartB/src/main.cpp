#include <iostream>
#include <chrono>
#include <filesystem>
#include <vector>
#include "SLVO.h"
#include "URO.h"
#include "BFSO.h"
#include "DFSO.h"
#include "SOLVO.h"
#include "LOLVO.h"
#include "AlgoInterface.h"

using namespace std::chrono;
namespace fs = std::filesystem;


std::vector<std::string> open_dir_using_filesystem(const char* folderpath){
    std::vector<std::string> result;
    for (const auto & entry : fs::directory_iterator(folderpath)){
        const char* filename = entry.path().c_str();
        std::string filenam1(filename);
        result.push_back(filenam1);
    }
    return result;
}


void RunTimeTest(const std::string& filename){
    AlgoInterface* Algos[6];
    Algos[0] = new SLVO;
    Algos[1] = new URO;
    Algos[2] = new SOLVO;
    Algos[3] = new LOLVO;
    Algos[4] = new BFSO;
    Algos[5] = new DFSO;

    long int times[6]{ 0 };

    for(int i = 0; i < 6; i++){
        long int time = 0;
        int Colorused = 0;
        for(int j = 0; j < 10; j++) {
            Algos[i]->ReadFile(filename);
            auto start = high_resolution_clock::now();
            Algos[i]->Coloring(false);
            auto end = high_resolution_clock::now();
            Colorused += Algos[i]->nColorUsed+1;
            time += duration_cast<microseconds>(end - start).count();
        }
        time /= 10;
        times[i] = time;
       // printf("%d uses %d colors\n", i,Colorused/10);
    }

    for(int i = 0; i < 6; i++){
        printf("%d is: %ldμs \n", i, times[i]);
    }

    for(auto & Algo : Algos){
        delete Algo;
    }
}


int main(int argc, char** argv) {
    std::vector<std::string> files = open_dir_using_filesystem(argv[1]);
    for(int i = 0; i < files.size(); i++){
        std::cout << files.at(i) << std::endl;
        RunTimeTest(files.at(i));
        std::cout << "\n" << std::endl;
    }
    return 0;
}
