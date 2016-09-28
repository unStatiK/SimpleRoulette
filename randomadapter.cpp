#include "randomadapter.h"
#include <QtGlobal>

RandomAdapter::RandomAdapter()
{

}

int RandomAdapter::getRandomPosition(const int count)
{    
    return qrand() % count;
}
