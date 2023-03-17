#include <iostream>
#include <storage/postgres/postgres.hpp>

int main () {

    Postgres postgres("host=localhost port=5434 dbname=postgres user=main password=1001");

    std:: cout << "Hello, World" << std::endl;

    return 0;
}