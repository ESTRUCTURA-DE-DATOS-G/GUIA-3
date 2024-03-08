#include <iostream>
#include <vector>
#include <cstdlib> // Funcion rand (Random)
#include <ctime> // Inicializa numeros aleatorios
#include <chrono> //Captura el tiempo

void llenarVector(std::vector<int> &numeros){
    for (int i = 0; i < 1000; i++) {
        numeros[i] = rand() % 6901 + 100; //Numeros aleatorios entre 100 y 7000
    }
}

void mostrarVector(const std::vector<int> &numeros){
    std::cout << "Contenido del vector: " << std::endl;
    for (int i = 0; i < 1000; i++) {
        std::cout << numeros[i] << " ";
        if ((i + 1) % 20 == 0) //Imiprimir de a 20 numeros
        {
            std::cout << std::endl;
        }    
    }
}

void burbujaVector(std::vector<int> &numeros, double &burbujaTiempo){
    
    //Inicializa la medicion de tiempo
    auto start = std::chrono::high_resolution_clock::now();
    
    int n = numeros.size();

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(numeros[j] > numeros[j + 1]){
                //Intercambia elementos
                int temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;
            }
        }
    }
    
    //finaliza la medicion de tiempo
    auto end = std::chrono::high_resolution_clock::now();

    //Calcula en milisegundos
    std::chrono::duration<double, std::milli> duration_ms = end - start;
    burbujaTiempo = duration_ms.count();
}

void seleccionVector(std::vector<int> &numeros, double &seleccionTiempo) {

    auto start = std::chrono::high_resolution_clock::now();

    int n = numeros.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (numeros[j] < numeros[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambiar elementos
        int temp = numeros[i];
        numeros[i] = numeros[min_idx];
        numeros[min_idx] = temp;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration_ms = end - start;
    seleccionTiempo = duration_ms.count();
}

void insercionVector(std::vector<int> &numeros, double &insercionTiempo){
    
    auto start = std::chrono::high_resolution_clock::now();

    int n = numeros.size();
    for (int i = 1; i < n; i++) {
        int key = numeros[i];
        int j = i-1;
        while(j >= 0 && numeros[j] > key){
            numeros[j+1] = numeros[j];
            j = j-1;
        }
        numeros[j+1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration_ms = end - start;
    insercionTiempo = duration_ms.count();
}

void shellSortVector(std::vector<int> &numeros, double &shellSortTiempo){
    
    auto start = std::chrono::high_resolution_clock::now();

    int n = numeros.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++){
            int temporal = numeros[i];
            int j;
            for(j = i; j >= gap && numeros[j - gap] > temporal; j -= gap){
                numeros[j] = numeros[j - gap];
            }
            numeros[j] = temporal;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> duration_ms = end - start;
    shellSortTiempo = duration_ms.count();
}

void heapify(std::vector<int> &arr, int n, int i){
    int largo = i;
    int x = 2*i+1;
    int m = 2*i+2;

    if(x < n && arr[x] > arr[largo]){
        largo = x;
    }
    if(m < n && arr[m] > arr[largo]){
        largo = m;
    }
    if(largo != i){
        
        int swap = arr[i];
        arr[i] = arr[largo];
        arr[largo] = swap;
        heapify(arr, n, largo);
    }   
}

void heapSortVector(std::vector<int> &arr, double &heapTiempo){
    auto start = std::chrono::high_resolution_clock::now();

    int n = arr.size();

    for(int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    for (int i = n-1; i > 0; i--){
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> duration_ms = end - start;
    heapTiempo = duration_ms.count();   
}

int particion (std::vector<int> & arr, int bajo, int alto){
    int pivote = arr[alto];
    int i = bajo-1;

    for (int j = bajo; j <= alto-1; j++){
        if(arr[j] < pivote){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[alto]);
    return i+1;
}

void quickSort(std::vector<int>& arr, int bajo, int alto){
    if(bajo < alto){
        int pi = particion(arr, bajo, alto);
        quickSort(arr, bajo, pi-1);
        quickSort(arr, pi+1, alto);
    }
}

void quickSortVector(std::vector<int> &arr, double &quickTiempo){
    auto start = std::chrono::high_resolution_clock::now();

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration_ms = end - start;
    quickTiempo = duration_ms.count();
}

int main()
{
    //Inicializar para los numeros aleatorios
    srand(time(0));

    //Declarar el vector
    std::vector<int> numeros(1000);
     double burbujaTiempo= 0;
     double seleccionTiempo = 0; 
     double insercionTiempo = 0, shellSortTiempo = 0, heapTiempo = 0, quickTiempo = 0;

    int opcion;

    do
    {
        //Menu
        std::cout << "Menu: " << std::endl;
        std::cout << "1. Llenar el vector con numeros aleatorios " << std::endl;
        std::cout << "2. Mostrar el vector " << std::endl;
        std::cout << "Metodos de Ordenamiento " << std::endl;
        std::cout << "3. Burbuja  " << std::endl;
        std::cout << "4. Seleccion " << std::endl;
        std::cout << "5. Insercion " << std::endl;
        std::cout << "6. Shell Sort " << std::endl;
        std::cout << "7. Heap Sort " << std::endl;
        std::cout << "8. Quick Sort " << std::endl;
        std::cout << "9. Comparativo tiempos " << std::endl;
        std::cout << "0. SALIR " << std::endl;
        std::cout << "Digite la opcion a realizar " << std::endl;
        std::cin >> opcion;

        switch(opcion){
            case 1:
                llenarVector(numeros);
                std::cout <<"Vector con numeros aleatorios " << std::endl;
                break;
    
            case 2:
                mostrarVector(numeros);
                break;
            
            case 3:
                burbujaVector(numeros, burbujaTiempo);
                std::cout << "TIEMPO TOMADO: " << burbujaTiempo << " milisegundos" << std::endl;
                std::cout << std::endl;
                mostrarVector(numeros);
                break; 

            case 4:
                seleccionVector(numeros, seleccionTiempo);
                std::cout << "TIEMPO TOMADO: " << seleccionTiempo << " milisegundos" << std::endl;
                std::cout << std::endl;
                mostrarVector(numeros);
                break;

            case 5:
                insercionVector(numeros, insercionTiempo);
                std::cout << "TIEMPO TOMADO: " << insercionTiempo << " milisegundos" << std::endl;
                std::cout << std::endl;
                mostrarVector(numeros);
                break;

            case 6:
                shellSortVector(numeros, shellSortTiempo);
                std::cout << "TIEMPO TOMADO: " << shellSortTiempo << " milisegundos" << std::endl;
                std::cout << std::endl;
                mostrarVector(numeros);
                break;

            case 7:
                heapSortVector(numeros, heapTiempo);
                std::cout << "TIEMPO TOMADO: " << heapTiempo << " milisegundos" << std::endl;
                std::cout << std::endl;
                mostrarVector(numeros);
                break;

            case 8:
                quickSortVector(numeros, quickTiempo);
                std::cout << "TIEMPO TOMADO: " << quickTiempo << " milisegundos" << std::endl;
                std::cout << std::endl;
                mostrarVector(numeros);
                break;
            
            case 9:
                std::cout << "Comparación de tiempos de ordenamiento:" << std::endl;
                std::cout << "Bubble: " << burbujaTiempo << " milisegundos" << std::endl;
                std::cout << "Seleccion: " << seleccionTiempo << " milisegundos" << std::endl;
                std::cout << "Insercion: " << insercionTiempo << " milisegundos" << std::endl;
                std::cout << "Shell: " << shellSortTiempo << " milisegundos" << std::endl;
                std::cout << "Heap: " << heapTiempo << " milisegundos" << std::endl;
                std::cout << "Quick: " << quickTiempo << " milisegundos" << std::endl;
                break;

            case 0:
                std::cout <<"Profe merecemos ese 5 :)" << std::endl;
                break;
            default:
                std::cout << "Opcion invalida, Digita una opcion valida" << std::endl;
        }
    } while (opcion != 0);
    
    return 0;
}
