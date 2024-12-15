#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>
#include <fstream>

class IFightObserver{
public:
    virtual void HandleEvent(const std::string&) const = 0;
};

class FileFightObserver: public IFightObserver{
public:
    void HandleEvent(const std::string&) const override;
};

class ConsoleFightObserver: public IFightObserver{
public:
    void HandleEvent(const std::string&) const override;
};

#endif //OBSERVER_H
