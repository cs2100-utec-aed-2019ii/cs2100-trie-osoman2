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
        if(search_by_complete_word(cad)==false){cout<<"No existe esa palabra"<<endl;return;}
        else delete_(root,cad,0);
    }
    void delete_(TrieNode* nodo,string cad,int indice){
        if(nodo){
            auto aux = cad[indice];
            auto hijo = nodo->get(aux);

            if (nodo->children.size()==1){
                if(indice+1==cad.length()){
                    if (hijo->children.size()==0){
                        hijo = nullptr;
                        nodo->children.clear();
                        if(search_by_complete_word(redudele(cad)))return;
                        else delete_(root,redudele(cad),0);
                    }
                    else {hijo->is_node = false;return;}
                    
                }
                else delete_(hijo,cad,indice+1);
            }
            else{
                if(indice+1==cad.length()) hijo->is_node =false;
                else delete_(hijo,cad,indice+1);
            }
        }
    }
    string redudele(string cad){
        string a;
        for (int i = 0; i < cad.length()-1; i++)
        {
            a = a+cad[i];
        }
        return a;
    }
    
    void print(){
        print(root);    
    }
    void print(TrieNode* nodo){
        if(nodo){
            for (auto i = nodo->children.begin(); i != nodo->children.end(); i++)
            {
               cout<<i->first<<" ";
               print(i->second);
            }
            cout<<endl;
        }
        return;
    }
};


#endif