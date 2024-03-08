import random
import time
class Vector:
    def __init__(self):
        self.tamaño = 0
        self.vector = []

    def obtenerTamaño(self):
        while True:
            print("*************************************************************************************")
            opcion_menu = input("De qué tamaño desea el vector:\n1. 100\n2. 500\n3. 1000\n4. 2000\n5. Siguiente\n6. Salir\n")
            opcion_menu = int(opcion_menu)
            if opcion_menu >= 1 and opcion_menu <= 5:
                if opcion_menu == 1:
                    self.tamaño = 100
                    self.vector = [None] * self.tamaño
                    self.llenarvector()
                elif opcion_menu == 2:
                    self.tamaño = 500
                    self.vector = [None] * self.tamaño
                    self.llenarvector()
                elif opcion_menu == 3:
                    self.tamaño = 1000
                    self.vector = [None] * self.tamaño
                    self.llenarvector()
                elif opcion_menu == 4:
                    self.tamaño = 2000
                    self.vector = [None] * self.tamaño
                    self.llenarvector()
                elif opcion_menu == 5:
                    self.run()
                    break
            elif opcion_menu == 6:
                print("profe nunca es tarde para ponernos ese 5")
                exit()
            else:
                print("Seleccione una opción válida...")
            
                


    def llenarvector(self):
        for i in range(len(self.vector)):
            self.vector[i] = random.randint(1, 7000)
        print("Vector lleno:", self.vector)
        print("VECTOR LLENO")


class MetodoOrdenamiento(Vector):
    def __init__(self):
        super().__init__()
        self.aux = 0
        self.i = 0

    def inicioTimepo(self):
        self.start_time = time.time()
    
    def finTiempo(self):
        self.end_time = time.time()
        print("Tiempo de ejecución: ", self.end_time - self.start_time, "segundos")
    
    def tipoBurbuja(self):
        self.inicioTimepo()
        for i in range(len(self.vector) - 1):
            for j in range(i + 1, len(self.vector)):
                if self.vector[i] > self.vector[j]:
                    self.aux = self.vector[i]
                    self.vector[i] = self.vector[j]
                    self.vector[j] = self.aux
        print("Vector ordenado con Burbuja:", self.vector)
        self.finTiempo()
        
    
    def tipoInsercion(self):
        self.inicioTimepo()
        for p in range(1, len(self.vector)):
            self.aux = self.vector[p]
            j = p - 1
            while j >= 0 and self.aux < self.vector[j]:
                self.vector[j + 1] = self.vector[j]
                j -= 1
            self.vector[j + 1] = self.aux
        print("Vector ordenado con Insercion:", self.vector)
        self.finTiempo()
    def tipoSeleccion(self):
        self.inicioTimepo()
        for i in range(len(self.vector)):
            menor = i
            for j in range(i + 1, len(self.vector)):
                if self.vector[j] < self.vector[menor]:
                    menor = j
            if menor != i:
                self.vector[i], self.vector[menor] = self.vector[menor], self.vector[i]
        print("Vector ordenado con Seleccion:", self.vector)
        self.finTiempo()
    
    def tipoShell(self):
        self.inicioTimepo()
        salto = len(self.vector) // 2
        while salto > 0:
            for i in range(salto, len(self.vector)):
                temp = self.vector[i]
                j = i
                while j >= salto and self.vector[j - salto] > temp:
                    self.vector[j] = self.vector[j - salto]
                    j -= salto
                self.vector[j] = temp
            salto //= 2
        print("Vector ordenado con Shell:", self.vector)
        self.finTiempo()
    
    def heapify(self, n, i):
        largest = i
        l = 2 * i + 1
        r = 2 * i + 2

        if l < n and self.vector[l] > self.vector[largest]:
            largest = l

        if r < n and self.vector[r] > self.vector[largest]:
            largest = r

        if largest != i:
            self.vector[i], self.vector[largest] = self.vector[largest], self.vector[i]
            self.heapify(n, largest)

    def tipoHeapsort(self):
        
        self.inicioTimepo()
        n = len(self.vector)
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(n, i)
        for i in range(n - 1, 0, -1):
            self.vector[i], self.vector[0] = self.vector[0], self.vector[i]
            self.heapify(i, 0)
        print("Vector ordenado con Heapsort:", self.vector)
        self.finTiempo()
    
    def tipoQuicksort(self, izq, der):
        self.inicioTimepo()
        if izq >= der:
            return
        pivote = self.vector[izq]
        i = izq
        j = der
        while i < j:
            while self.vector[i] <= pivote and i < j:
                i += 1
            while self.vector[j] > pivote:
                j -= 1
            if i < j:
                self.vector[i], self.vector[j] = self.vector[j], self.vector[i]
        self.vector[izq], self.vector[j] = self.vector[j], self.vector[izq]
        self.tipoQuicksort(izq, j - 1)
        self.tipoQuicksort(j + 1, der)
        
    def resultadoQuick(self):
        print("Vector ordenado con Quicksort:", self.vector)
        self.finTiempo()

    def run(self):
        while True:
            print("*************************************************************************************")
            opcion_menu = input("Qué tipo de ordenamiento desea hacer:\n1. Burbuja\n2. Inserción\n3. Selección\n4. Shell\n5. Heapsort\n6. Quicksort\n7. Volver\n8. Salir\n")
            opcion_menu = int(opcion_menu)
            if opcion_menu >= 1 and opcion_menu <= 6:
                if opcion_menu == 1:
                    self.tipoBurbuja()
                elif opcion_menu == 2:
                    self.tipoInsercion()
                elif opcion_menu == 3:
                    self.tipoSeleccion()
                elif opcion_menu == 4:
                    self.tipoShell()
                elif opcion_menu == 5:
                    self.tipoHeapsort()
                elif opcion_menu == 6:
                    self.tipoQuicksort(0, len(self.vector) - 1)
                    self.resultadoQuick()
            elif opcion_menu == 7:
                ejecutar.obtenerTamaño()
                break
            elif opcion_menu == 8:
                print("profe nunca es tarde para ponernos ese 5")
                exit()
            else:
                print("Seleccione una opción válida...")


ejecutar = MetodoOrdenamiento()
ejecutar.obtenerTamaño()  
ejecutar.run()  
