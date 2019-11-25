#include "Trie.hpp"

int main(){
    Trie a;
    Trie b; //ejercicio de matrices
    Trie c; //ejercicio storewords
    int rows = 3;
    int cols = 3;
    int** matriz = new int*[rows];
    for (int i = 0; i < rows; ++i)
        matriz[i] = new int[cols];
    
    int valor = 1;

    for (size_t f(0); f < rows; ++f) {
        for (size_t c(0); c < cols; ++c) {
            matriz[f][c] = valor++;
        }
    }
   c.storewords("la prima de anita lava con su tia anita la ropa de anita") ;

   b.vectores(rows,cols,matriz);
   b.print();
  //  a.desde_ar_n("o.txt");
   
//    a.print();
     

    return 0;
}