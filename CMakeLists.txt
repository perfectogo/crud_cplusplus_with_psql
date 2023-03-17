include(FetchContent)

cmake_minimum_required(VERSION 3.16)

set(project_name CRUD_CPP_PSQL)

project(${project_name})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${project_name}-lib
        src/cmd/main.cpp
        # src/cmd/main.hpp
        src/storage/postgres/postgres.cpp
        src/storage/postgres/postgres.hpp
        src/storage/postgres/crud/crud.cpp
        src/storage/postgres/crud/crud.hpp
)

FetchContent_Declare(
        libpqxx
        GIT_REPOSITORY https://github.com/jtv/libpqxx.git
        GIT_TAG a6b1d60e74c1427c8ac2324b85cd4a0dc2068332
)

set(PQXX_LIBRARIES pqxx_static)
FetchContent_MakeAvailable(libpqxx)

target_link_libraries(${project_name}-lib
        PUBLIC ${PQXX_LIBRARIES}
        # PUBLIC Boost::thread
        # PUBLIC Crow::Crow
        # PUBLIC ${CDS_LIBRARIES}
        # PUBLIC dmitigr_pgfe
)

#target_include_directories(${project_name}-lib PUBLIC src)

## add executables
add_executable(${project_name}-exe
        src/cmd/main.cpp
)

target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)