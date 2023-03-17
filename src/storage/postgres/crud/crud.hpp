#ifndef Crud_hpp
#define Crud_hpp

#include "pqxx/pqxx"
#include <iostream>

class Crud {
    private:
        pqxx::connection* mDb;

    public:
        Crud(pqxx::connection* conn);
        ~Crud();

        bool Create(std::string name);
};

#endif