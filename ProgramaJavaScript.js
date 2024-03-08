function generarNumerosAleatorios(cantidad) {
  const numeros = [];
  for (let i = 0; i < cantidad; i++) {
    numeros.push(Math.floor(Math.random() * 10000));
  }
  return numeros;
}

//Burbuja
function burbuja(arr) {
  const n = arr.length;
  let tiempoInicio = Date.now();

  for (let i = 0; i < n - 1; i++) {
    for (let j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Intercambiar elementos si están en el orden incorrecto
        const temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  let tiempoFin = Date.now();
  let tiempoTotal = tiempoFin - tiempoInicio;
  return { tiempo: tiempoTotal, arrayOrdenado: arr.slice() };
}

//Inserción
function insercion(arr) {
  const n = arr.length;
  let tiempoInicio = Date.now();

  for (let i = 1; i < n; i++) {
    const key = arr[i];
    let j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }

  let tiempoFin = Date.now();
  let tiempoTotal = tiempoFin - tiempoInicio;
  return { tiempo: tiempoTotal, arrayOrdenado: arr.slice() };
}

//Selección
function seleccion(arr) {
  const n = arr.length;
  let tiempoInicio = Date.now();

  for (let i = 0; i < n - 1; i++) {
    let minIndex = i;
    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    const temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }

  let tiempoFin = Date.now();
  let tiempoTotal = tiempoFin - tiempoInicio;
  return { tiempo: tiempoTotal, arrayOrdenado: arr.slice() };
}

//Shell
function shell(arr) {
  const n = arr.length;
  let tiempoInicio = Date.now();

  for (let gap = Math.floor(n / 2); gap > 0; gap = Math.floor(gap / 2)) {
    for (let i = gap; i < n; i++) {
      const temp = arr[i];
      let j = i;

      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
      }

      arr[j] = temp;
    }
  }

  let tiempoFin = Date.now();
  let tiempoTotal = tiempoFin - tiempoInicio;
  return { tiempo: tiempoTotal, arrayOrdenado: arr.slice() };
}

//HeapSort
function heapSort(arr) {
  const n = arr.length;
  let tiempoInicio = Date.now();

  function heapify(arr, n, i) {
    let largest = i;
    const left = 2 * i + 1;
    const right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
      largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
      largest = right;
    }

    if (largest !== i) {
      const temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;

      heapify(arr, n, largest);
    }
  }

  for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (let i = n - 1; i > 0; i--) {
    const temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);
  }

  let tiempoFin = Date.now();
  let tiempoTotal = tiempoFin - tiempoInicio;
  return { tiempo: tiempoTotal, arrayOrdenado: arr.slice() };
}

//QuickSort
function quickSort(arr) {
  let tiempoInicio = Date.now();

  function partition(arr, low, high) {
    const pivot = arr[high];
    let i = low - 1;

    for (let j = low; j < high; j++) {
      if (arr[j] < pivot) {
        i++;
        const temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    const temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
  }

  function quickSortUtil(arr, low, high) {
    if (low < high) {
      const pi = partition(arr, low, high);

      quickSortUtil(arr, low, pi - 1);
      quickSortUtil(arr, pi + 1, high);
    }
  }

  quickSortUtil(arr, 0, arr.length - 1);

  let tiempoFin = Date.now();
  let tiempoTotal = tiempoFin - tiempoInicio;
  return { tiempo: tiempoTotal, arrayOrdenado: arr.slice() };
}


const numerosAleatorios = generarNumerosAleatorios(5000);


const resultadoBurbuja = burbuja([...numerosAleatorios]);
const resultadoInsercion = insercion([...numerosAleatorios]);
const resultadoSeleccion = seleccion([...numerosAleatorios]);
const resultadoShell = shell([...numerosAleatorios]);
const resultadoHeapSort = heapSort([...numerosAleatorios]);
const resultadoQuickSort = quickSort([...numerosAleatorios]);

// Mostrar resultados
console.log('Burbuja:', resultadoBurbuja.tiempo, 'ms');
console.log('Inserción:', resultadoInsercion.tiempo, 'ms');
console.log('Selección:', resultadoSeleccion.tiempo, 'ms');
console.log('Shell:', resultadoShell.tiempo, 'ms');
console.log('HeapSort:', resultadoHeapSort.tiempo, 'ms');
console.log('QuickSort:', resultadoQuickSort.tiempo, 'ms');
