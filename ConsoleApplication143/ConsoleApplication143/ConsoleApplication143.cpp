#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>

using namespace std;

vector<vector<bool>> generarMatrizRandom(int n) {
	srand(static_cast<unsigned>(time(0)));

	vector<vector<bool>> matriz(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matriz[i][j] = rand() % 2;
		}
	}

	return matriz;
}

void imprimirMatriz(const vector<vector<bool>>& matriz) {
	int n = matriz.size();
    cout << "  ";
    for (int i = 0; i < n; i++) {
        cout <<" " << char(65 + i) << "";
    }
    cout << endl;
	for (int i = 0; i < n; i++) {
        cout << " " << char(65 + i) << " ";
        for (int j = 0; j < n; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

void matrizDiagonal(vector<vector<bool>>& matriz) {
	int n = matriz.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matriz[j][j] = 1;
		}
	}
}

vector<vector<bool>> encontrarMatrizCaminos(const vector<vector<bool>>& matriz) {
    int n = matriz.size();
    vector<vector<bool>> matrizCaminos(matriz);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrizCaminos[i][j] = matrizCaminos[i][j] || (matrizCaminos[i][k] && matrizCaminos[k][j]);
            }
        }
    }

    return matrizCaminos;
}

int main() {
  
        int n;
        cout << "Ingrese el tamanio de la matriz (entre 5 y 15): ";
        cin >> n;

        if (n < 5 || n > 15) {
            cout << "El tamanio de la matriz debe estar entre 5 y 15." << endl;
            return 1;
        }

        vector<vector<bool>> matriz;
        char opcion;

        cout << "Desea generar una matriz aleatoria? (S/N): ";
        cin >> opcion;
        cout << endl;

        if (opcion == 'S' || opcion == 's') {
            matriz = generarMatrizRandom(n);
            cout << "Matriz generada aleatoriamente:" << endl;
            imprimirMatriz(matriz);
            cout << endl;
            cout << "Matriz con diagonal: " << endl;
            matrizDiagonal(matriz);
            imprimirMatriz(matriz);
            cout << endl;

            vector<vector<bool>> matrizCaminos = encontrarMatrizCaminos(matriz);
            cout << "Matriz de caminos: " << endl;
            encontrarMatrizCaminos(matriz);
            imprimirMatriz(matrizCaminos);

        }
        else {
            cout << "Ingrese los elementos de la matriz (0 o 1):" << endl;
            matriz.resize(n, vector<bool>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int valor;
                    cin >> valor;
                    matriz[i][j] = (valor == 1); // Convierte el valor a booleano
                }
            }
            system("cls");
            cout << "Matriz generada:" << endl;
            imprimirMatriz(matriz);
            cout << endl;
            cout << "Matriz con diagonal: " << endl;
            matrizDiagonal(matriz);
            imprimirMatriz(matriz);
            cout << endl;

            vector<vector<bool>> matrizCaminos = encontrarMatrizCaminos(matriz);
            cout << "Matriz de caminos: " << endl;
            encontrarMatrizCaminos(matriz);
            imprimirMatriz(matrizCaminos);
        }

        

}