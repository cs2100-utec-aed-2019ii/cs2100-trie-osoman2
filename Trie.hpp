#ifndef TRIE_H
#define TRIE_H
#include "TrieNode.hpp"
#include <string>
class Trie
{
private:
 
    TrieNode* root;
public:
    Trie():root(nullptr){};
    
    ~Trie(){}


    void insert(string cad){
        insert(0,root,cad);
    }
    void insert(int indice,TrieNode* &nodo,string cad){
        if(cad.length()==indice){
            if(nodo) {nodo->is_node = true; return;}
        }
        if(nodo){
                auto aux = cad[indice];
                TrieNode* hijo = nodo->get(aux);
                if(hijo==nullptr){
                    hijo = new TrieNode();
                    nodo->children.insert({aux,hijo});
                    insert(indice+1,hijo,cad);
                }
                else{
                    insert(indice+1,hijo,cad);
                }
        }
        else{
            nodo = new TrieNode();
            TrieNode* hijo = new TrieNode();
            nodo->children.insert({cad[indice],hijo});
            insert(indice+1,hijo,cad);
        }
    }


    bool search_by_prefix(string cad){
        return search_by_prefix(0,cad,root); 
    }
    bool search_by_prefix(int indice,string cad,TrieNode* &nodo){
        if(nodo){
            auto aux = cad[indice];
            TrieNode *hijo = nodo->get(aux);
            if(hijo){
                if(cad.length()==indice+1) return true;
                else return search_by_prefix(indice+1,cad,hijo);
            }
            else return false;
        }
        else return false;
    }

    bool search_by_complete_word(string cad){
        return search_by_complete_word(0,cad,root); 
    }
    bool search_by_complete_word(int indice,string cad,TrieNode* &nodo){
        if(nodo){
            auto aux = cad[indice];
            TrieNode *hijo = nodo->get(aux);
            if(hijo){
                if(cad.length()==indice+1){
                    if(hijo->is_node) return true;
                    else return false;
                } 
                else return search_by_complete_word(indice+1,cad,hijo);
            }
            else return false;
        }
        else return false;
    }

    void delete_(string cad){

    }

    void print(){

    }
};


#endif