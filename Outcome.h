#ifndef OUTCOME_H
#define OUTCOME_H

#include <string>
#include <iostream>
#include <memory>

class Outcome;
using outcome_ptr = std::shared_ptr<Outcome>;

class Outcome
{
public:
    
    Outcome(std::string _name, unsigned int _odds)
        : name(_name), odds(_odds)
        { }

    const std::string getName() { return name; }
    const unsigned int getOdds() { return odds; }


    bool operator==(const Outcome& _outcome) const
    {
        return (_outcome.name == name &&
                _outcome.odds == odds);
    }

    bool operator!=(const Outcome& _outcome) const
    {
        return (_outcome.name != name ||
                _outcome.odds != odds);
    }

    int winAmount(const int amount) const
    {
        return amount * odds;
    }

    friend std::ostream &operator<<(std::ostream &output, const Outcome &_outcome)
    {
        output << "NAME: " << _outcome.name << " "
               << "ODDS: " << _outcome.odds;
        return output;
    }


private:
    const std::string name;
    const unsigned int odds;
};

#endif