// ERRADO

#include <stdio.h>

typedef struct {
    int numParticipantes;
    int comandoChefe;
    int acoes[100]; // Assume-se que não haverá mais de 100 participantes
} Rodada;

typedef struct {
    int id;
    int vivo; // 1 para vivo, 0 para eliminado
} Participante;

int main() {
    int P, R, teste = 0;
    while (1) {
        scanf("%d %d", &P, &R);
        if (P == 0 && R == 0) break; // Condição de término

        Participante participantes[100];
        int ordem[100];

        // Lê a ordem inicial dos participantes
        for (int i = 0; i < P; i++) {
            scanf("%d", &ordem[i]);
            participantes[i].id = ordem[i];
            participantes[i].vivo = 1;
        }

        Rodada rodadas[100];
        for (int i = 0; i < R; i++) {
            scanf("%d %d", &rodadas[i].numParticipantes, &rodadas[i].comandoChefe);
            for (int j = 0; j < rodadas[i].numParticipantes; j++) {
                scanf("%d", &rodadas[i].acoes[j]);
            }
        }

        // Processa cada rodada
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < rodadas[i].numParticipantes; j++) {
                if (participantes[j].vivo && rodadas[i].acoes[j] != rodadas[i].comandoChefe) {
                    participantes[j].vivo = 0; // Participante eliminado
                }
            }
        }

        // Determina o vencedor
        int vencedor;
        for (int i = 0; i < P; i++) {
            if (participantes[i].vivo) {
                vencedor = participantes[i].id;
                break;
            }
        }

        printf("Teste %d\n%d\n\n", ++teste, vencedor);
    }

    return 0;
}