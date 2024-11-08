#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h> // Para usar strcspn

#define MAX_PESSOAS 100
#define TAM_NOME 50

void ordenarTempos(char nomes[MAX_PESSOAS][TAM_NOME], int tempos[MAX_PESSOAS], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempos[j] > tempos[j + 1]) {
                // Troca os tempos
                int tempTempo = tempos[j];
                tempos[j] = tempos[j + 1];
                tempos[j + 1] = tempTempo;

                // Troca os nomes correspondentes
                char tempNome[TAM_NOME];
                strcpy(tempNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], tempNome);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "");

    char nomes[MAX_PESSOAS][TAM_NOME]; // Matriz para armazenar os nomes
    int tempos[MAX_PESSOAS] = {0}; // Matriz para armazenar os tempos, inicializada a zero
    int minutos = 1; // Começa em 1 minuto
    int segundos;
    int controle = 0;
    int escolha;
    char tecla;
    int numPessoas = 0; // Contador de pessoas registradas
    char fantasma;
    
    while (controle != 50) {
        system("cls");
        printf("[1] Iniciar temporizador\n[2] Apuração\n[3] Finalizar Programa\n");
        scanf("%d", &escolha);
        system("cls");

        if (escolha <= 0 || escolha > 3) {
            system("cls");
            printf("Digite um dos números abaixo\n[1] Iniciar temporizador\n[2] Apuração\n[3] Finalizar Programa\n");
            scanf("%d", &escolha);
        }

        switch (escolha) {
            case 1:
                if (numPessoas < MAX_PESSOAS) {
                    printf("Digite seu nome: ");
                    getchar(); // Limpa o buffer
                    fgets(nomes[numPessoas], TAM_NOME, stdin);
                    nomes[numPessoas][strcspn(nomes[numPessoas], "\n")] = '\0'; // Remove a nova linha

                    segundos = minutos * 60; // Converte minutos em segundos
                    printf("Iniciando o timer para %s...\n", nomes[numPessoas]);

                    // Timer regressivo
                    while (segundos > 0) {
                        int min = segundos / 60; // Calcula os minutos restantes
                        int seg = segundos % 60;  // Calcula os segundos restantes
                        
                        // Exibe o tempo restante
                        printf("%s: %02d:%02d ",nomes[numPessoas], min, seg);
                        fflush(stdout); // Atualiza a saída

                        Sleep(1000); // Pausa por 1 segundo
                        segundos--; // Decrementa o tempo
                        
                        // Verifica se uma tecla foi pressionada
                        if (_kbhit()) {
                            tecla = _getch();
                            if (tecla == '1') {
                                printf("\nTemporizador encerrado pelo usuário.\n");
                                break;
                            } else if (tecla == '2') {
                                system("cls");
                                printf("Tempo pausado. Digite:\n[0] para retomar o tempo\n[1] para encerrar o temporizador\n");
                                printf("\n\n%02d:%02d", min, seg);
                                tecla = _getch();

                                if (tecla == '1') {
                                    printf("\nTemporizador encerrado pelo usuário.\n\n");
                                    
                                    break;
                                } else if (tecla == '0') {
                                    // Retorna ao loop de contagem
                                }
                            }
                        }

                        system("cls"); // Limpa a tela
                        printf("Aperte: \n[1] Encerrar\n[2] Pausar\n\n\n  ");
                    }
					  if(segundos != 0){
					printf("Aperte [1] para voltar\n");  
					scanf("%s",&fantasma);
					}
                    if (segundos == 0) {
                        printf("\nTempo esgotado para %s!\n\n", nomes[numPessoas]);
                        tempos[numPessoas] = minutos * 60; // Armazena o tempo total se não foi finalizado
                        // Alerta sonoro
                        for (int j = 0; j < 5; j++) {
                            Beep(880, 500); // Beep de 880 Hz por 500 ms
                            Sleep(500); // Pausa de 500 ms entre os beeps
                        }
                    } else if (segundos < minutos * 60) {
                        tempos[numPessoas] = (minutos * 60) - segundos; // Armazena o tempo até o momento
                    }

                    numPessoas++; // Incrementa o contador de pessoas registradas
                } else {
                    printf("Número máximo de pessoas atingido!\n");
                    Sleep(2000); // Espera um pouco antes de continuar
                }
                
                break;

            case 2:
                // Ordena os tempos e nomes
                ordenarTempos(nomes, tempos, numPessoas);
                
                printf("Tempos armazenados:\n\n");
                for (int i = 0; i < numPessoas; i++) {
                    if (tempos[i] > 0) { // Apenas exibe nomes com tempo válido
                        printf("%dº %s: %d segundos\n\n", i + 1, nomes[i], tempos[i]);
                    }
                }
                printf("Deseja voltar ?\nAperte [1]\n");
                scanf("%d", &controle);
                break;

            case 3:
                controle = 50;
                break;
        }
    }

    return 0;
}
