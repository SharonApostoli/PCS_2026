#pragma once

#include <iostream>
#include <set> 
#include <map>
#include <iterator>
#include <optional>

//fai classe unidirected_edge (rappresenta un arco di un grafo)
//in questo caso, grafo non diretto:
//la classe deve avere:
template<typename T>
class unidirected_edge{
    T node_f;
    T node_t;

public:
    //costruttore che permette di specificare i due nodi connessi all'arco
    //garantendo che from < to
    unidirected_edge(const T& partenza, const T& arrivo){
        if(partenza < arrivo){
            node_f = partenza;
            node_t = arrivo;
        }else{
            node_f = arrivo;
            node_t = partenza;
        }
    }

    //due metodi: from() e to() che restituiscono i due nodi
    T from() const {
        return node_f;
    }

    T to() const {
        return node_t;
    }

    //operator< per ordinare gli archi
    bool operator< (const unidirected_edge& other) const {
        unidirected_edge ret = *this;
        if(ret.node_f != other.node_f){
            return ret.node_f < other.node_f;
        }
        return ret.node_t < other.node_t;
    }

    //operator==
    bool operator== (const unidirected_edge& other) const{
        unidirected_edge ret = *this;
        return (ret.node_f == other.node_f && ret.node_t == other.node_t);
    }

};

//operator<<
template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& edge){
    os << "(" << edge.from() << ", " << edge.to() << ")";
    return os;
}





//fai classe unidirected_graph
//la classe deve avere:
template<typename T>
class unidirected_graph{
    /*per rappresentare il grafo, utilizzo la lista di adiacenza in quanto essa ha un costo
    computazionale per la ricerca dei vicini O(1)*/
    /*tra: list, set, map e unordered_map, la struttura piu adatta secondo me è una map in quanto
    mantiene il concetto di array + lista vista a lezione dove da una parte abbiamo i nodi e poi
    ci sono i suoi vicini.
    Inoltre le keys sono ordinate e la struttura sfrutta l'albero red-black, sfruttato anche da set.*/

    //lista di adiacenza (nodo, vicini)
    std::map<T, std::vector<std::pair<T, int>>> adiacenza;

    /*per la rappresentazione degli archi, invece, scegliamo un set, che evita duplicati, mantiene gli archi
    ordinati e ha un costo di ricerca più basso O(logm)*/
    //archi
    std::set<unidirected_edge<T>> edge;

public:
    //costruttore di default
    unidirected_graph(){
    };

    //costruttore di copia
    unidirected_graph(const unidirected_graph& other){
        adiacenza = other.adiacenza;
        edge = other.edge;
    }


    //metodi: neighbours() che, dato un nodo, restituisce i vicini
    std::vector<std::pair<T,int>> neighbours(const T& nodo) const{
        auto key = adiacenza.find(nodo);
        if(key == adiacenza.end()){
            return {};
        }
        return key -> second;
    }

    //add_edge() aggiungere un arco
    void add_edge(T a, T b, int w = 1){
        //creo l'oggetto arco
        unidirected_edge<T> arco(a, b);
        //controllo se l'arco è gia presente tra gli archi che ho
        if(edge.find(arco) != edge.end()){
            //Se c'è non aggiungo, e esco
            return;
        }
        //se non è presente lo aggiungo agli archi che ho
        edge.insert(arco);

        //ma poi devo anche aggiornare la lista di adiacenza:
        adiacenza[a].push_back({b, w});
        adiacenza[b].push_back({a, w});
    }


    //all_edges() restituisce tutti gli archi
    std::set<unidirected_edge<T>> all_edges() const{
        return edge;
    }


    //all_nodes() restituisce tutti i nodi
    std::set<T> all_nodes() const{
        //creo un set vuoto dove andro poi a mettere tutti i nodi
        std::set<T> nodi;
        //nel ciclo for per un set, non posso usare int i = 0;....
        //ma devo usare questa forma che scandice ogni elemento (chiamato pair)
        //infatti la mappa ha struttura a "coppie" (const T, set), 
        for(const auto& pair : adiacenza){
            //aggiungiamo al set nodi il "primo" elemento della mappa di adiacenza, ovvero i nodi
            //(i "secondi" elementi sarebbero il set degli archi)
            nodi.insert(pair.first);
        }
        return nodi;
    }


    //edge_number() dato un arco, restituisce la sua numerazione all'interno del grafo
    int edge_number(const unidirected_edge<T> & arco) const{
        int pos = 0;
        for(const unidirected_edge<T>& i : edge){
            if(i == arco){
                return pos;
            }
            pos++;
        }
        return -1;
    }


    //edge_at() dato un numero d'arco, restituisce l'oggetto arco all'interno del grafo
    std::optional<unidirected_edge<T>> edge_at(int num) const{
        //prima controllo se il num è valido, ovvero se e neg o troppo grande
        if(num < 0 || num >= edge.size()){
            return std::nullopt;
        }

        //in set non posso andare avanti come in un vettore o array, quindi devo usare un iteratore
        //scrivo auto per non stare a scrivere ogni volta tutto il codice
        auto it = edge.begin();

        //usando advance faccio andare avanti l'iteratore di num
        std::advance(it, num);

        //ritorno ciò a qui punta a questo punto l'iteratore "derefrenceandolo"
        return *it;
    }

    //operator-() che calcola la differenza tra due grafi: G - G' = archi presenti in G ma non G'
    unidirected_graph operator-(const unidirected_graph& other) const{
        //qui andrò a mettere tutti gli archi presenti in G ma non in G'
        unidirected_graph archi;

        //per ogni arco presente nella struttura edge del grafo G
        for(const unidirected_edge<T>& el : edge){
            //controllo se l'arco è presente nella struttura edge del secondo grafo G'
            if(other.edge.find(el) == other.edge.end()){
                //se non è presente in G' lo aggiungo alla nuova struttura dati archi.
                archi.add_edge(el.from(), el.to(), 1);
            }
        }
        return archi;  
    }

    /*Non è stato implementato un metodochiamato add_node() in quanto ogni votla che aggiungiamo un arco, vengono 
    automaticamente messi nella struttura unidirected_graph i due nodi all'estremo dell'arco. Inoltre, cosi facendo,
    non succederà di avere un nodo non connesso tramite arco a nessun altro nodo. Esistera sempre infatti un arco
    per ogni nodo.*/
};