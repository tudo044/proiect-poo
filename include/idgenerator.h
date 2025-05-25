#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IDGenerator {
private:
    unsigned int currentId;
    IDGenerator();

public:
    static IDGenerator& getInstance();
    unsigned int getNextId();

    IDGenerator(const IDGenerator&) = delete;
    IDGenerator& operator=(const IDGenerator&) = delete;
};

#endif // IDGENERATOR_H
