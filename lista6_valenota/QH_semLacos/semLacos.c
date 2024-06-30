void ordena(int *v, int n) {
    if (n <= 1) return;  // Caso base: um vetor de 1 ou 0 elementos já está ordenado

    // Ordena recursivamente os primeiros n-1 elementos
    ordena(v, n-1);

    // Insere o último elemento na posição correta no vetor
    int ultimo = v[n-1];
    int i = n-2;

    // Encontra a posição correta do elemento `ultimo` no vetor já ordenado v[0...n-2]
    while (i >= 0 && v[i] > ultimo) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = ultimo;
}