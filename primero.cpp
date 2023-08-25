#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX = 1000;

int main() {
    double A[MAX][MAX], x[MAX], y[MAX];

    // Inicialización de A y x, asignación de y = 0
    for (int i = 0; i < MAX; ++i) {
        x[i] = i;
        y[i] = 0;
        for (int j = 0; j < MAX; ++j) {
            A[i][j] = i + j;
        }
    }

    // Medición de tiempo para el primer par de bucles
    auto start1 = high_resolution_clock::now();

    // Primer par de bucles
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    // Reseteamos y para la siguiente prueba
    fill(y, y + MAX, 0.0);

    // Medición de tiempo para el segundo par de bucles
    auto start2 = high_resolution_clock::now();

    // El segundo par de bucles
    for (int j = 0; j < MAX; ++j) {
        for (int i = 0; i < MAX; ++i) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    // Imprimimos los tiempos de ejecución
    cout << "Tiempo del primer par de bucles: " << duration1.count() << " microsegundos" << endl;
    cout << "Tiempo del segundo par de bucles: " << duration2.count() << " microsegundos" << endl;

    return 0;
}
