#ifndef postgres_hpp
#define postgres_hpp

#include <pqxx/pqxx>

class Postgres {
    private:
        pqxx::connection mDb;

    public:
        Postgres(std::string connString);
        ~Postgres();
};

#endif