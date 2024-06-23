#include <stdio.h>

double fogo(int nivel){
    if (nivel == 1) return 2.0;
    if (nivel == 2) return 3.0;
    if (nivel == 3) return 5.0;
    return 0;
}
double agua(int nivel){
    if (nivel == 1) return 1.0;
    if (nivel == 2) return 2.5;
    if (nivel == 3) return 4.0;
    return 0;
}
double terra(int nivel){
    if (nivel == 1) return 2.5;
    if (nivel == 2) return 5.5;
    if (nivel == 3) return 7.0;
    return 0;
}

double calculaVantagem ( int tipoPlayer, int tipoCPU ){
    if (tipoPlayer == tipoCPU) return 1.0; //Jogador = Civilização

    if (tipoPlayer == 2 && tipoCPU == 1) return 2.0; //Fogo X Terra
    if (tipoPlayer == 2 && tipoCPU == 3) return 0.5; //Fogo X Agua

    if (tipoPlayer == 3 && tipoCPU == 2) return 2.0; //Água X Fogo 
    if (tipoPlayer == 3 && tipoCPU == 1) return 0.5; //Água X Terra 

    if (tipoPlayer == 1 && tipoCPU == 2) return 0.5; //Terra X Fogo
    if (tipoPlayer == 1 && tipoCPU == 3) return 2.0; //Terra X Água

    return 1;
}

double calculaDano(int tipoPlayer, int nivelPlayer, int tipoCPU, double defesaCPU){
    double multNivel;
    if (tipoPlayer == 1){
        multNivel = terra(nivelPlayer);
    } else if (tipoPlayer == 2){
        multNivel = fogo(nivelPlayer);
    } else if (tipoPlayer == 3){
        multNivel = agua(nivelPlayer);
    } else {
        return 0;
    }

    double multTipo = calculaVantagem(tipoPlayer, tipoCPU);
    double dano = 100 * multNivel * multTipo - defesaCPU;
    return (dano > 0) ? dano:0;
}

int main() {
    // Exemplo 1: Terra (tipo 1) nível 1 contra Fogo (tipo 2) com defesa 73.4
    double dano1 = calculaDano(1, 1, 2, 73.4);
    printf("%f\n", dano1); // Deve imprimir 51.600000

    // Exemplo 2: Terra (tipo 1) nível 3 contra Água (tipo 3) com defesa 1475.892
    double dano2 = calculaDano(1, 3, 3, 1475.892);
    printf("%f\n", dano2); // Deve imprimir 0.000000

    return 0;
}
