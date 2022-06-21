project(shogi)
CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

add_compile_options(-Wall -Wextra -pedantic -Werror)
ADD_EXECUTABLE(shogi gra.cpp bledy.cpp gracz.cpp legenda.cpp pionek.cpp plansza.cpp pozycja.cpp rozgrywka.cpp)