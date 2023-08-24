#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PERGUNTAS 10
#define NUM_OPCOES 4

char perguntas[NUM_PERGUNTAS][100] = {
    "Qual filme ganhou o Oscar de Melhor Filme em 2020?",
    "Qual filme é famoso pela frase 'A vida é como uma caixa de chocolates'?",
    "Em qual filme Leonardo DiCaprio interpreta um papel de naufrágio?",
    "Qual é o filme de maior bilheteria de todos os tempos?",
    "Qual filme apresenta um personagem chamado Darth Vader?",
    "Qual é o filme dirigido por Quentin Tarantino que apresenta um baile icônico?",
    "Qual é o nome do robô amigável em Wall-E?",
    "Qual é o filme de animação da Pixar sobre um rato que quer ser um chef?",
    "Qual é o filme baseado em um naufrágio real estrelado por Tom Hanks?",
    "Qual é o filme de ficção científica de 1982 que se passa em um futuro distópico em que humanos caçam androides?"
};

char opcoes[NUM_PERGUNTAS][NUM_OPCOES][70] = {
    {"a) 1917\nb) Parasita\nc) Coringa\nd) O Irlandês"},
    {"a) O Poderoso Chefão\nb) Forrest Gump\nc) Titanic\nd) Clube da Luta"},
    {"a) Titanic\nb) A Origem\nc) O Regresso\nd) Ilha do Medo"},
    {"a) Vingadores: Ultimato\nb) Avatar\nc) Titanic\nd) O Rei Leão"},
    {"a) Star Wars\nb) O Senhor dos Anéis\nc) Harry Potter\nd) Jurassic Park"},
    {"a) Pulp Fiction\nb) Bastardos Inglórios\nc) Kill Bill\nd) Era Uma Vez em Hollywood"},
    {"a) Wally\nb) Johnny\nc) Eve\nd) Buddy"},
    {"a) Up: Altas Aventuras\nb) Ratatouille\nc) Divertida Mente\nd) Procurando Nemo"},
    {"a) O Regresso\nb) Capitão Phillips\nc) Náufrago\nd) O Lobo de Wall Street"},
    {"a) Blade Runner\nb) Matrix\nc) O Exterminador do Futuro\nd) Mad Max"}
};

char respostas_corretas[NUM_PERGUNTAS] = {'b', 'b', 'c', 'b', 'a', 'd', 'a', 'b', 'c', 'a'};

void mostrarMenu() {
    printf("\n====================================\n");
    printf(" Bem-vindo ao Quiz de Filmes!\n");
    printf("====================================\n");
    printf(" 1. Iniciar o Jogo\n");
    printf(" 2. Sair\n");
    printf("====================================\n");
    printf("Escolha uma opção: ");
}

void jogarQuiz() {
    int pontos = 0;
    int vidas = 3;
    int perguntas_usadas[NUM_PERGUNTAS] = {0};

    srand(time(NULL));

    for (int i = 0; i < NUM_PERGUNTAS; i++) {
        int indice_pergunta;

        do {
            indice_pergunta = rand() % NUM_PERGUNTAS;
        } while (perguntas_usadas[indice_pergunta] == 1);

        perguntas_usadas[indice_pergunta] = 1;

        printf("\nP%d: %s\n", i + 1, perguntas[indice_pergunta]);
        printf("%s\n", opcoes[indice_pergunta]);

        char resposta_usuario;

        printf("Escolha a opção correta (a/b/c/d): ");
        scanf(" %c", &resposta_usuario);

        if (resposta_usuario == respostas_corretas[indice_pergunta]) {
            printf("Resposta correta!\n");
            pontos++;
        } else {
            vidas--;
            printf("Resposta incorreta! Vidas restantes: %d\n", vidas);

            if (vidas == 0) {
                printf("Fim de jogo! Você obteve %d pontos.\n", pontos);
                return;
            }
        }
    }

    printf("Parabéns, você concluiu o quiz com %d pontos!\n", pontos);
}

int main() {
    int escolha;

    do {
        mostrarMenu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                jogarQuiz();
                break;
            case 2:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (1);

    return 0;
}
