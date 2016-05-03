#ifndef WHEEL_H
#define WHEEL_H

#include <vector>
#include <random>
#include "Bin.h"

#define ROULETTE_WHEEL_SIZE 38

class Wheel;
using wheel_ptr = std::shared_ptr<Wheel>;

class Wheel
{
public:

    Wheel()
        : binVector(ROULETTE_WHEEL_SIZE)
        { }

    const unsigned int size() const { return binVector.size(); }

    void addOutcomeByBinIndex(const unsigned int binIndex, outcome_ptr outcome)
    {
        binVector[binIndex].addOutcome(outcome);
    }

    const unsigned int sizeOfBinByIndex(unsigned int binIndex) const
    {
        return binVector[binIndex].size();
    }

    const Bin& spin() const
    {
        return binVector[rng()];
    }

    const Bin& getBinByIndex(unsigned int binIndex) const
    {
        assert(binIndex < ROULETTE_WHEEL_SIZE - 1);
        return binVector[binIndex];
    }
    
    friend std::ostream &operator<<(std::ostream &output, const Wheel &_wheel)
    {
        for (int i = 0; i < ROULETTE_WHEEL_SIZE; ++i) {
            output << "BIN " << i << std::endl;
            if (_wheel.binVector[i].size() > 0)
                output << _wheel.binVector[i];
        }
        return output;
    }

private:

    const unsigned int rng() const
    {
        static std::default_random_engine generator;
        static std::uniform_int_distribution<unsigned int> distribution(0, ROULETTE_WHEEL_SIZE - 1);
        return distribution(generator);
    }

private:
    std::vector<Bin> binVector;
};

#endif