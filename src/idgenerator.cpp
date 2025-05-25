#include "../include/idgenerator.h"

IDGenerator::IDGenerator() : currentId(0) {}

IDGenerator& IDGenerator::getInstance() {
    static IDGenerator instance;
    return instance;
}

unsigned int IDGenerator::getNextId() {
    return ++currentId;
}
