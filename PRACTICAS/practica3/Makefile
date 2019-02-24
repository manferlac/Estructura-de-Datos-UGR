SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/test_ciudades $(BIN)/test_rutas $(BIN)/descifra_ruta

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/test_ciudades: $(OBJ)/test_ciudades.o $(OBJ)/posicion.o $(OBJ)/ciudad.o $(OBJ)/ciudades.o 
	$(CXX) -o $(BIN)/test_ciudades $(OBJ)/test_ciudades.o $(OBJ)/posicion.o $(OBJ)/ciudad.o $(OBJ)/ciudades.o -Iinclude

$(BIN)/test_rutas: $(OBJ)/test_rutas.o $(OBJ)/posicion.o $(OBJ)/ruta.o $(OBJ)/rutas.o
	$(CXX) -o $(BIN)/test_rutas $(OBJ)/test_rutas.o $(OBJ)/posicion.o $(OBJ)/ruta.o $(OBJ)/rutas.o -Iinclude

$(BIN)/descifra_ruta: $(OBJ)/descifra_ruta.o $(OBJ)/posicion.o  $(OBJ)/ciudad.o $(OBJ)/ciudades.o $(OBJ)/ruta.o $(OBJ)/rutas.o
	$(CXX) -o $(BIN)/descifra_ruta $(OBJ)/descifra_ruta.o $(OBJ)/posicion.o  $(OBJ)/ciudad.o $(OBJ)/ciudades.o $(OBJ)/ruta.o $(OBJ)/rutas.o -Iinclude

$(OBJ)/test_ciudades.o: $(SRC)/test_ciudades.cpp 
	$(CXX) -c -o $(OBJ)/test_ciudades.o $(SRC)/test_ciudades.cpp -Iinclude 

$(OBJ)/posicion.o: $(SRC)/posicion.cpp $(INC)/posicion.h
	$(CXX) -c -o $(OBJ)/posicion.o $(SRC)/posicion.cpp -Iinclude

$(OBJ)/ciudad.o: $(SRC)/ciudad.cpp $(INC)/ciudad.h
	$(CXX) -c -o $(OBJ)/ciudad.o $(SRC)/ciudad.cpp -Iinclude

$(OBJ)/ciudades.o: $(SRC)/ciudades.cpp $(INC)/ciudades.h
	$(CXX) -c -o $(OBJ)/ciudades.o $(SRC)/ciudades.cpp -Iinclude

$(OBJ)/test_rutas.o: $(SRC)/test_rutas.cpp 
	$(CXX) -c -o $(OBJ)/test_rutas.o $(SRC)/test_rutas.cpp -Iinclude 

$(OBJ)/ruta.o: $(SRC)/ruta.cpp $(INC)/ruta.h
	$(CXX) -c -o $(OBJ)/ruta.o $(SRC)/ruta.cpp -Iinclude

$(OBJ)/rutas.o: $(SRC)/rutas.cpp $(INC)/rutas.h
	$(CXX) -c -o $(OBJ)/rutas.o $(SRC)/rutas.cpp -Iinclude

$(OBJ)/descifra_ruta.o: $(SRC)/descifra_ruta.cpp 
	$(CXX) -c -o $(OBJ)/descifra_ruta.o $(SRC)/descifra_ruta.cpp -Iinclude 

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
