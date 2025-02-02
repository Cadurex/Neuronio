#include "NeuronioReLu.hpp"

int main() {
    int numNeuronios, numPesos;

    cout << "Digite a quantidade de neurônios: ";
    cin >> numNeuronios;
    cout << "Digite a quantidade de pesos por neurônio: ";
    cin >> numPesos;

    vector<Neuronio*> neuronios;

    // Criando neurônios dinamicamente
    for (int i = 0; i < numNeuronios; i++) {
        vector<double> pesos(numPesos);
        double bias;

        cout << "Digite os " << numPesos << " pesos do neurônio " << i + 1 << ":\n";
        for (int j = 0; j < numPesos; j++) {
            cout << "Peso " << j + 1 << ": ";
            cin >> pesos[j];
        }
        cout << "Digite o bias do neurônio " << i + 1 << ": ";
        cin >> bias;

        // Criando o neurônio e armazenando no vetor
        neuronios.push_back(new NeuronioReLu(pesos, bias));
    }

    // Entrada dos valores de entrada para os neurônios
    vector<double> entradas(numPesos);
    cout << "Digite os valores de entrada:\n";
    for (int i = 0; i < numPesos; i++) {
        cout << "Entrada " << i + 1 << ": ";
        cin >> entradas[i];
    }

    // Calculando e exibindo a saída de cada neurônio
    cout << "\nResultados:\n";
    for (int i = 0; i < numNeuronios; i++) {
        cout << "Saída do neurônio " << i + 1 << ": " << neuronios[i]->predict(entradas) << endl;
    }

    for (int i = 0; i < numNeuronios; i++) {
        delete neuronios[i];
    }

    return 0;
}
