#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4
#define M 5

void ordena(char nome[N][50], int n, float media[N]) {
    char temp[50]; // Variável temporária para troca de strings
    float constante;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Compara as strings usando strcmp
            if (media[i] < media[j]) {
                // Troca as strings
                strcpy(temp, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], temp);
                //troca vetor nota junto com a string do nome
                constante = media[i];
                media [i] = media [j];
                media [j] = constante;
            }
        }
    }
}

float media_Geral(float nota[M], int pesos[M]){
    float soma = 0, peso = 0, media;
    for(int i = 0; i < M; i++){
        soma += nota[i] * pesos[i];
        peso += pesos[i];
    }
    media = soma/peso;
    return media;
}

int main(void){
    char nome[N][50] = {"Ciclano sem Sal", "Fulano de Tal", "Deltrano Default", "Beltrana Radical"};
    int pesos[M] = {2, 3, 3, 4, 2}, calssificacao [N];
    float media1, media2, media3, media4, media[M];
    //vamos dividir a questao em 4 casos, um para cada aluno
    //primeiro caso aluno ciclano sem sal
    float nota1[M] = {9.5 , 8.2, 5.4, 2.3, 7.8};
    media[0] = media_Geral(nota1, pesos);
    float nota2[M] = {7.2, 7.1, 6.8, 4.8, 5.7};
    media[1] = media_Geral(nota2, pesos);
    float nota3[M] = {5.6, 8, 9.5, 10, 7.4};
    media[2] = media_Geral(nota3, pesos);
    float nota4[M] = {4.5, 7.9, 5.2, 4.1, 9};
    media[3] = media_Geral(nota4, pesos);
    //imprime fora de ordem
    for(int i = 0; i < N; i++){
    printf("%d - %s - %.2f\n", i+1, nome[i], media[i]);
    }
    printf("\n\n");
    //ordena
    ordena(nome, N, media);
    //imprime na ordem
    printf("A classificacao final eh:\n");
    for(int i = 0; i < N; i++){
    printf("%d - %16s - %.2f\n", i+1, nome[i], media[i]);
    }
}