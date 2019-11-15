#include "Trie.hpp"

int main(){
    Trie a;
    a.insert("hola");
  
    cout <<a.search_by_prefix("ao")<<endl;
    cout <<a.search_by_complete_word("hol")<<endl;

    return 0;
}