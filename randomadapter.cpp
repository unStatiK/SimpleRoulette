#include "randomadapter.h"
#include <ctime>
#include <cstdlib>

RandomAdapter::RandomAdapter()
{

}

int RandomAdapter::getRandomPosition(const int count)
{
    std::srand(std::time(0));
    return std::rand() % count;
}
