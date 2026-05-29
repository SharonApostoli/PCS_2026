#include <iostream>
#include <fstream> //file I/O
#include <string>

#include "progetto.h"


void read_file(std::string filename){
    std::ifstream ifs(filename);

    //Controllo se il file è stato aperto correttamente
    if(!ifs.is_open()){
        std::cerr << "Il file dei dati non è stato aperto correttamente! \n";
        return -1;
    }

    //Se siamo qui, il file è stato aperto correttamente
    //La prima variabile che troviamo sarà il tipo (R oppure V) seguita dal numero 
    //Devo ancora creare gli oggetti da inserire qui
    //Subito dopo avremo il valore della componente (resistenza o tensione) 
    
    //Infine avremo gli estremi dell'arco 

    
    //Estraiamo ora i dati dal file, andando avanti fino a che riesco a leggere il risultato
    while(ifs >> tipo >> valore >> edge1 >> edge2)

    file.close();
}