#ifndef NEURONIO_RE_LU
#define NEURONIO_RE_LU
#include <iostream>
#include "neuronio.hpp"

class NeuronioReLu : public Neuronio{
    public:
        NeuronioReLu(const vector<double>& pesos, double bias) 
        : Neuronio(pesos, bias) {}


       double predict(const vector<double>& entradas) const override {
            double soma = 0.0;
            
            for(int i = 0; i < entradas.size(); i++){
                soma = soma + entradas[i] * pesos[i];
            }

            soma = soma + bias;

            return max(0.0, soma);
        };
}; 
#endif