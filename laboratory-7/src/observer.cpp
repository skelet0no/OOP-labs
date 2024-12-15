#include "../include/observer.h"

void ConsoleFightObserver::HandleEvent(const std::string& str) const{
    std::cout << "LOGGER: " << str << std::endl;
}

void FileFightObserver::HandleEvent(const std::string& str) const{
    std::fstream file;
    file.open("log.txt", std::ios::app);

    file << str << std::endl;

}