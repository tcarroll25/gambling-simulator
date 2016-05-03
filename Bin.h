#ifndef BIN_H
#define BIN_H

#include <iostream>
#include <list>
#include "Outcome.h"


class Bin
{
public:
    Bin() = default;

    void addOutcome(outcome_ptr _outcome)
    {
        outcomes.push_back(_outcome);
    }

    unsigned int size() const
    {
        return outcomes.size();
    }

    void printOutcomes() const
    {
        std::cout << "Bin outcomes..." << std::endl;
        for (auto &o : outcomes) {
            std::cout << *o << std::endl;
        }
    }
    
    friend std::ostream &operator<<(std::ostream &output, const Bin &_bin)
    {
        for (auto &out : _bin.outcomes ) {
            if (out)
                output << *out << std::endl;
        }
        return output;
    }

private:
    std::list<outcome_ptr> outcomes;
};

#endif