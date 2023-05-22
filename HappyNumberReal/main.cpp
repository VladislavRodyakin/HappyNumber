#include <iostream>
#include <fstream>
#include "Checker.hpp"
#include "Parser.hpp"

int main(int argc, char* argv[]){
    std::string file_path;
    if (argc == 1)
        file_path = "input.txt";
    else
        file_path = argv[2];

    std::ifstream inp(file_path);
    if (!inp.is_open()) {
        std::cout << "Failed to open file.";
        return 0;
    }

    try {
        Parser par(inp);
        int checking_num = par.getNext();
        while (checking_num != -1) {
            std::cout << checking_num << " - " << Checker::check_happines(checking_num) << std::endl;
        }// посмотреть iomnip для вывода t/f (уже)
    }
    catch (const std::exception& e) {
        std::cout << e.what();
    }

    return 0;
}
