INC = include
LIB = lib
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c
AR = 

# ************ Compilación de módulos ************

$(BIN)/test_ciudades: $(OBJ)/test_ciudades.o $(OBJ)/posicion.o $(OBJ)/ciudad.o $(OBJ)/ciudades.o 
	$(CXX) -o $(BIN)/test_ciudades $(OBJ)/test_ciudades.o $(OBJ)/posicion.o $(OBJ)/ciudad.o $(OBJ)/ciudades.o -Iinclude




$(OBJ)/test_ciudades.o: $(SRC)/test_ciudades.cpp 
	$(CXX) -c -o $(OBJ)/test_ciudades.o $(SRC)/test_ciudades.cpp -Iinclude 

$(OBJ)/posicion.o: $(SRC)/posicion.cpp $(INC)/posicion.h
	$(CXX) -c -o $(OBJ)/posicion.o $(SRC)/posicion.cpp -Iinclude

$(OBJ)/ciudad.o: $(SRC)/ciudad.cpp $(INC)/ciudad.h
	$(CXX) -c -o $(OBJ)/ciudad.o $(SRC)/ciudad.cpp -Iinclude

$(OBJ)/ciudades.o: $(SRC)/ciudades.cpp $(INC)/ciudades.h
	$(CXX) -c -o $(OBJ)/ciudades.o $(SRC)/ciudades.cpp -Iinclude

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
