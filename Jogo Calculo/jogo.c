#include <stdio.h> // padrão para entreda e saida
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

typedef struct {
    int dificuldade[10];
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

typedef struct {
    char nome[50];
    int pontuacao[10];
    int quantidade;
} Jogador;

void menu (Jogador *jogador, Calcular *calc);
void desempenhoJogador (Jogador *jogador, Calcular *calc);
void instrucoesJogo (Jogador *jogador);
void jogar (Jogador *jogador, Calcular *calc, int *opc);
void reinciarJogo (Jogador *jogador, Calcular *calc);
void somarOperacao (Jogador *jogador, Calcular *calc, int *opc);
void subtracaoOperacao (Jogador *jogador, Calcular *calc, int *opc);
void multiplicarOperacao (Jogador *jogador, Calcular *calc, int *opc);

bool validarNome(char validar[]);
bool validarOpcao(char opcao[]);
bool validarInt(char resposta[]);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Jogador jogador;
    Calcular calc;

    memset(jogador.nome, 0, sizeof(jogador.nome));
    menu(&jogador, &calc);

    printf("Saindo do programa...");

    return 0;
}

void menu(Jogador *jogador, Calcular *calc) {
    int opc = 0;
    bool sair = false;

    do {
        if (strlen(jogador->nome) == 0) {
            jogador->quantidade = 0;
            for (int i = 0; i < 10; i++) {
                calc->dificuldade[i] = 0;
                jogador->pontuacao[i] = 0; 
            }

            calc->valor1 = 0;
            calc->valor2 = 0;
            calc->operacao = 0;
            calc->resultado = 0;

            bool sair = false;
            do {
                char validar[50];
                printf("\nDigite o nome do jogador: ");
                scanf("%49s", validar);

                if (validarNome(validar)) {
                    printf("O nome do Jogador precisa ter mais de 2 caracteres!!\n");
                    continue;
                }

                strcpy(jogador->nome, validar);  

                sair = true;

            } while (!sair);
        }

        char opcao[3];

        printf("\n\nOlá %s escolha uma opção: \n", jogador->nome);
        printf("\n1 - Instruções do jogo\n");
        printf("--------------------------------------\n");
        printf("Dificuldade do Jogo:\n");
        printf("2 - Nível Fácil\n");
        printf("3 - Nível Médio\n");
        printf("4 - Nível Difícil\n");
        printf("5 - Nível Insano\n");
        printf("--------------------------------------\n");
        printf("6 - Ver meu desempenho\n");
        printf("7 - Reiniciar o jogo\n");
        printf("8 - Sair do Jogo\n");

        printf("\nDigite uma opção: ");
        scanf("%2s", opcao);

        if (validarOpcao(opcao)) {
            fflush(stdin);
            continue;
        }

        opc = atoi(opcao);
        switch (opc) {
        case 1:
            instrucoesJogo(jogador);
            break;
        case 2:
            jogar(jogador, calc, &opc);
            break;

        case 3:
            jogar(jogador, calc, &opc);
            break;

        case 4:
            jogar(jogador, calc, &opc);
            break;

        case 5:
            jogar(jogador, calc, &opc);
            break;

        case 6:
            desempenhoJogador(jogador, calc);
            break;
        
        case 7:
            reinciarJogo(jogador, calc);
            break;

        case 8:
            sair = true;
            break;

        default:
            printf("Algo deu errado :'(");
            break;
        }
    } while (!sair);
}

void desempenhoJogador (Jogador *jogador, Calcular *calc) {
    int pontuacaototal = 0;

    system("cls");
    if (jogador->quantidade == 0) {
        printf("\n\nO jogador não jogou nenhuma fase!!!");
    } else {
        pontuacaototal = jogador->pontuacao[2] + jogador->pontuacao[3] + jogador->pontuacao[4] + jogador->pontuacao[5];

        printf("\n\nDesempenho do jogador:");
        printf("\nNome do jogador: %s",  jogador->nome);
        printf("\n----------------------------------------------");
        printf("\nPontuação:");
        printf("\nFácil: %d", jogador->pontuacao[2]);
        printf("\nMédio: %d", jogador->pontuacao[3]);
        printf("\nDifícil: %d", jogador->pontuacao[4]);
        printf("\nInsano: %d", jogador->pontuacao[5]);
        printf("\nTotal: %d", pontuacaototal);
        printf("\n----------------------------------------------");
        printf("\nQuantidade de Fases:");
        printf("\nFácil: %d", calc->dificuldade[2]);
        printf("\nMédio: %d", calc->dificuldade[3]);
        printf("\nDifícil: %d", calc->dificuldade[4]);
        printf("\nInsano: %d", calc->dificuldade[5]);
        printf("\nTotal: %d", jogador->quantidade);
        printf("\nErros: %d", jogador->quantidade-pontuacaototal);  
        printf("\n----------------------------------------------");

        float stats = (float)pontuacaototal / jogador->quantidade;

        if (stats >= 0.9) {
            printf("\nStatus: Gênio!!!\n\n");
        } else if (stats >= 0.7) {
            printf("\nStatus: Muito bom!\n\n");
        } else if (stats >= 0.5) {
            printf("\nStatus: Bom.\n\n");
        } else if (stats >= 0.3) {
            printf("\nStatus: Regular.\n\n");
        } else {
            printf("\nStatus: Precisa melhorar.\n\n");
        }
    }
}

void instrucoesJogo(Jogador *jogador) {
    system("cls");
    printf("\nOlá %s espero que esteja bem! \n", jogador->nome);
    printf("\n Instruções do Jogo de Cálculo:");
    printf("\n O sistema irá gerar aleatoriamente uma operação de soma, subtração ou multiplicação para ser resolvida pelo jogador.");
    printf("\n A cada operação acertada o jogador irá receber uma pontuação");
    printf("\n O jogo é dividido em níveis:");
    printf("\n Nível 1 (Fácil): Operações entre 0 e 10.");
    printf("\n Nível 2 (Médio): Operações entre 0 e 100.");
    printf("\n Nível 3 (Difícil): Operações entre 0 e 1000.");
    printf("\n Nível 4 (Insano): Operações entre 0 e 10000."); 
    printf("\n AVISO: Não coloque '.' ou ',' na resposta!");
}

void jogar(Jogador *jogador, Calcular *calc, int *opc) {
    int fase = 0;
    int sair = 0;

    system("cls");
    printf("\nOlá %s!", jogador->nome);

    do {
        srand(time(0));
        char opcao[3];

        do {
            printf("\nDigite quantas fases deseja fazer: ");
            scanf("%s", opcao);
            fflush(stdin);
            
            if (validarInt(opcao)) {
                fflush(stdin);
                continue;
            }

            fase = atoi(opcao);
            if (fase <= 0) {
                system("cls");
                printf("\n\tO número de fases tem que ser maior que zero!\n");
                continue;
            }
            
        } while (!fase);
        
        fflush(stdin);

        printf("\nVamos começar em");
        for (int i = 3; i > 0; i--) {
            printf("\n%d..", i);
            Sleep(1000);
        }

        for (int i = 1; i <= fase; i++) {
            srand(time(0));
            printf("\n\nFase %d", i);

            calc->operacao = rand() % 3;

            if (calc->operacao == 0) {
                somarOperacao(jogador, calc, opc);
            } else if (calc->operacao == 1 ) {
                subtracaoOperacao(jogador, calc, opc);
            } else {
                multiplicarOperacao(jogador, calc, opc);
            }
    
            jogador->quantidade++;
            if (calc->resultado) {
                jogador->pontuacao[*opc]++;
            } 

        }

        do {
            printf("\n\nDeseja fazer mais fases?\n1 - Sim\n2 - Não");
            printf("\nDigite sua opção: ");
            scanf("%2s", opcao);
            fflush(stdin);

            if (validarInt(opcao)) {
                fflush(stdin);
                continue;
            }

            sair = atoi(opcao);
            if (sair != 1 && sair != 2) {
                printf("\n\tOpcão invalida!");
                continue;
            }

        } while (sair != 1 && sair != 2);

     } while (sair != 2);

}

void reinciarJogo (Jogador *jogador, Calcular *calc) {
    system("cls");

    memset(jogador->nome, 0, sizeof(jogador->nome));
    for (int i = 0; i > 10; i++) {
        calc->dificuldade[i] = 0;
        jogador->pontuacao[i] = 0; 
    }
    jogador->quantidade = 0; 

    printf("\n\nPronto jogo reiniciado! \nO nome, pontuação e fases feitas foram resetadas.\n");
}

void somarOperacao(Jogador *jogador, Calcular *calc, int *opc) {
    bool sair = false;
    char validar[20];
    int resposta = 0; 

    int dividir = (*opc == 2) ? 11 :         // 0 a 10
                    (*opc == 3) ? 101 :      // 0 a 100
                    (*opc == 4) ? 1001 :     // 0 a 1000
                     10001 ;                 // 0 a 10000
    
    calc->valor1 = rand() % dividir;
    calc->valor2 = rand() % dividir;
    calc->operacao = calc->valor1 + calc->valor2;

    do {
        printf("\nQuanto é %d + %d : ", calc->valor1, calc->valor2);
        scanf("%19s", validar);
        fflush(stdin);

        if (validarInt(validar)) {
            fflush(stdin);
            continue;
        }

        sair = true;
        resposta = atoi(validar);

    } while (!sair);


    if (resposta == calc->operacao) {
        printf("\nParabens %s você acertou!!", jogador->nome);
        calc->resultado = 1;
    } else {
        printf("\nInfelizmente %s você errou!!", jogador->nome);
        printf("\nA resposta era: %d ", calc->operacao);
        calc->resultado = 0;
    }

    calc->dificuldade[*opc]++;
}

void subtracaoOperacao (Jogador *jogador, Calcular *calc, int *opc) {
    bool sair = false;
    char validar[20];
    int aux;
    int resposta = 0; 

    int dividir = (*opc == 2) ? 11 :         // 0 a 10
                    (*opc == 3) ? 101 :      // 0 a 100
                    (*opc == 4) ? 1001 :     // 0 a 1000
                     10001 ;                 // 0 a 10000
    
    calc->valor1 = rand() % dividir;
    calc->valor2 = rand() % dividir;

    if (calc->valor2 > calc->valor1) {
        aux = calc->valor1;
        calc->valor1 = calc->valor2;
        calc->valor2 = aux;
    }

    calc->operacao = calc->valor1 - calc->valor2;

    do {
        printf("\nQuanto é %d - %d : ", calc->valor1, calc->valor2);
        scanf("%19s", validar);
        fflush(stdin);

        if (validarInt(validar)) {
            fflush(stdin);
            continue;
        }

        sair = true;
        resposta = atoi(validar);

    } while (!sair);


    if (resposta == calc->operacao) {
        printf("\nParabens %s você acertou!!", jogador->nome);
        calc->resultado = 1;
    } else {
        printf("\nInfelizmente %s você errou!!", jogador->nome);
        printf("\nA resposta era: %d ", calc->operacao);
        calc->resultado = 0;
    }

    calc->dificuldade[*opc]++;
}

void multiplicarOperacao (Jogador *jogador, Calcular *calc, int *opc) {
    bool sair = false;
    char validar[20];
    int resposta = 0; 

    int dividir = (*opc == 2) ? 11 :         // 0 a 10
                    (*opc == 3) ? 101 :      // 0 a 100
                    (*opc == 4) ? 1001 :     // 0 a 1000
                     10001 ;                 // 0 a 10000
    
    calc->valor1 = rand() % dividir;
    calc->valor2 = rand() % dividir;
    calc->operacao = calc->valor1 * calc->valor2;

    do {
        printf("\nQuanto é %d * %d : ", calc->valor1, calc->valor2);
        scanf("%19s", validar);
        fflush(stdin);

        if (validarInt(validar)) {
            fflush(stdin);
            continue;
        }

        sair = true;
        resposta = atoi(validar);

    } while (!sair);


    if (resposta == calc->operacao) {
        printf("\nParabens %s você acertou!!", jogador->nome);
        calc->resultado = 1;
    } else {
        printf("\nInfelizmente %s você errou!!", jogador->nome);
        printf("\nA resposta era: %d ", calc->operacao);
        calc->resultado = 0;
    }

    calc->dificuldade[*opc]++;
}

bool validarNome(char validar[]) {
    return strlen(validar) <= 2;
}

bool validarOpcao(char opcao[]) {
    int letra = 0;
    int numero = 0;

    for (int i = 0; i < strlen(opcao); i++) {
        if (!isdigit(opcao[i])) {
            letra++;
            system("cls");
            printf("\n\tDigite apenas números");
            return true;
        }
    }

    numero = atoi(opcao);
    if (numero > 9) {
        system("cls");
        printf("\n\Opcão invalida!");
        return true;
    }
    
    return false;

}

bool validarInt(char resposta[]) {
    int letra = 0;

    for (int i = 0; i < strlen(resposta); i++) {
        if (!isdigit(resposta[i])) {
            letra++;
            system("cls");
            printf("\n\tDigite apenas números\n");
            return true;
        }
    }

    return false;

}

