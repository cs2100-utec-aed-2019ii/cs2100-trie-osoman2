#include "Trie.hpp"

int main(){
    Trie a;
    a.insert("hola");
    a.insert("holaa");
    a.insert("holaaa");

    cout <<a.search_by_complete_word("hola")<<endl;
    a.delete_("hola");
    cout <<a.search_by_complete_word("hola")<<endl;
    cout <<a.search_by_complete_word("holaaa")<<endl;

    return 0;
}