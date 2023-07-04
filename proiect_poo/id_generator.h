#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

#include <iostream>
#include <vector>
#include <random>
#include <QVector>

class Id_Generator
{
    static QVector<int> ids;

    public:
    static int getId();
};

#endif // ID_GENERATOR_H
