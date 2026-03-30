#pragma once
#include <concepts>
#include <iostream>

//definisco la classe rational
template<typename I>  requires std::integral<I>
class rational{
    I num_;
    I den_;

public:
    //Costruttore di default
    rational(){
        num_ = 0;
        den_ = 1;
    }

    //Costruttore user-defined
    rational(const I& num, const I& den){
        num_ = num;
        den_ = den;
    }

    //Metodo num()
    I num() const {
        return num_;
    }

    //Metodo den()
    I den() const {
        return den_;
    }
    
    //Operatore +=
    rational operator+=(const rational& other){
        num_ += other.num_;
        den_ += other.den_;
        return *this;
    }

    //Operatore +
    rational operator+(const rational& other) const{
        rational ret = *this;
        ret += other;
        return ret;
    }

    //Operatore -=
    rational operator-=(const rational& other){
        num_ -= other.num_;
        den_ -= other.den_;
        return *this;
    }

    //Operatore -
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    //Operatore *=
    rational operator*=(const rational& other){
        num_ *= other.num_;
        den_ *= other.den_;
        return *this;
    }

    //Operatore *
    rational operator*(const rational& other) const{
        rational ret = *this;
        ret *= other;
        return ret;
    }

    //In queste ultime due operazioni bisogna porre attenzione che non stiamo dividendo per 0
    //Operatore /=
    rational operator/=(const rational& other){
        if(den_ == 0 || other.num_ == 0){
            num_ = 1;
            den_ = 0;
            return *this;
        }
        num_ *= other.den_;
        den_ *= other.num_;
        return *this;
    }

    //Operatore /
    rational operator/(const rational& other) const{
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

//Operatore <<
template<typename T>
std::ostream&operator<<(std::ostream& os, const rational<T>& v){
    T n = v.num();
    T d = v.den();

    //Intanto controlliamo subito se siamo in un caso particolrare
    if(n == 0 && d == 0){
        os << "NaN" << "\n";
        return os;
    }
    //Il seondo controllo è il primo passo dell'alg di Euclide
    //Implementiamo l'algoritmo di Euclide, quindi come prima cosa controlliamo che il den != 0
    if(d == 0){
        os << "Inf" << "\n";
        return os;
    }
    //Visto che il den != 0 possiamo adesso procedere
    //Creo due nuove variabili su cui posso lavorare
    T a = n;
    T b = d;

    //Se a o b sono negativi, cambio il segno
    if(a < 0){
        a = -a;
    }
    
    if(b < 0){
        b = -b;
    }

    while(b != 0){
        T r = a % b;
        a = b;
        b = r;
    }

    //Abbiamo trovato il MCD
    T g = a;

    //Si può ora semplificare il num e il den
    n /= g;
    d /= g;

    //Se dovessimo avere un - al denominatore, portiamolo al numeratore
    if(d < 0){
        n = -n;
        d = -d;
    }

    /*Ho scelto di fare l'operazione di semplificazione una sola volta,
        prima di stampare il numero.
        In questo modo, non appesantisco il programma, e la semplificazione
        viene fatta una sola volta. 
        Se essa venisse invee fatta dopo ogni operazione, tutte le 
        operazioni avrebbero peso doppio.
        In caso di poche operazioni, la differenza non sarebbe enorme, ma 
        ho preferito comunque alleggerire il peso computazionale.
    */

    //Una volta accertata che il numero è semplificato, posso stampare
    os << n << "/" << d;
    return os;
}