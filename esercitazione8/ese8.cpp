#include <iostream>

#include "ese8.h"

template<typename T>
void print_set(const std::set<T>& set){
    for(T el : set){
        std::cout << el << " ";
    }
    std::cout << "\n";
}

int main(){
    unidirected_edge<int> arco(2,3);

    //controllo di from
    std::cout << "arco.from: " << arco.from() <<  "\n";
    //contorllo di to
    std::cout << "arco.to: " << arco.to() << "\n";

    unidirected_edge<int> arco2(2,6);
    //controllo di operator<
    std::cout << "arco < arco2 ?: " << (arco < arco2) << "\n";
    //controllo di operator==
    std::cout << "arco = arco2 ?: " << (arco == arco2) << "\n";
    //controllo di operator<<
    std::cout << "arco " << arco << "\n";




    unidirected_graph<int> g;

    //aggiungo qui anche gli archi nel senso opposto per controllare che add_edge aggiunga solo archi non gia presenti
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,1);
    g.add_edge(2,3);
    g.add_edge(3,1);
    g.add_edge(3,2);
    g.add_edge(3,4);
    g.add_edge(3,5);
    g.add_edge(4,3);
    g.add_edge(4,5);
    g.add_edge(5,3);
    g.add_edge(5,4);
    g.add_edge(5,6);

    //controllo il metodo neighbours
    std::cout << "Vicini del nodo 3: ";
    print_set(g.neighbours(3));

    //controllo il metodo all_edges
    std::cout << "Lista di tutti gli archi: ";
    //nel ciclo for: const serve perche non voglio modificare gli archi
    //std::... potrebe essere acccorciato con auto (ma io per ora voglio scrivere cosi)
    //l'& serve per non dovere ogni volta fare copie degli el.
    for(const unidirected_edge<int>& el : g.all_edges()){
        std::cout << el << ", ";
    };

    std::cout << "\n";

    //controllo metodo all_nodes
    std::cout << "Lista di tutti i nodi: ";
    print_set(g.all_nodes());

    //controllo edge_number
    std::cout << "edge_number per arco (2, 1): " << g.edge_number(unidirected_edge(2,1)) << "\n";

    //controllo edge_at
    if(auto e = g.edge_at(1)){
        std::cout << "edge_at per arco numero 1: " << *e << "\n";
    }
   
    if(auto e = g.edge_at(0)){
        std::cout << "edge_at per arco numero 0: " << *e << "\n";
    }

    if(auto e = g.edge_at(5)){
        std::cout << "edge_at per arco numero 5: " << *e << "\n";
    }
   
   
    //controllo operator-
    unidirected_graph<int> g2;

    g2.add_edge(1,2);
    g2.add_edge(1,3);
    g2.add_edge(3,5);
    g2.add_edge(5,6);

    unidirected_graph<int> G = g - g2;

    std::cout << "Differenza tra g e g2: \n";
    for(const unidirected_edge<int>& el : G.all_edges()){
        std::cout << el << ", ";
    };

    std::cout << " \n";

    return 0;
}