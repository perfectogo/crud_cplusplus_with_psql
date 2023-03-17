#include "postgres.hpp"

Postgres::Postgres(std::string connString) : mDb(connString) {}

Postgres::~Postgres() { /*mDb.close();*/ }