#include "crud.hpp"

Crud::Crud(pqxx::connection* conn) : mDb(conn) {}
Crud::~Crud() {}

bool Crud::Create(std::string name) {

    auto worker = pqxx::work();

}