/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <string.h>

/*Contagem da quantidade de caracteres da frase*/
int counting(char v[]){ 
    int n=0, i;

    for(i=0; i<1000; i++){
        if(v[i]!='\0')
          n++;
        else
            break;
    }

return n;
}

/*Remoçao de toda pontuaçao existente na frase*/
void removepontuation(char v[]){
    int i;

    for(i=0; i<99; i++){
        if(v[i]== 46  || v[i]== 44 || v[i]== 58 || v[i]== 59 || v[i]== 63 || v[i]== 39 || v[i]== 34 || v[i]== 33 || v[i]== 40 || v[i]== 41 || v[i]== 45)
            v[i]=32;
    }
}

int main(){

    char text[100];
    int i=0, n_caracteres=0, n_palavras=0;
    char c_atual=1, c_anterior=1, c_anterior2=1;

    /*Leitura da frase e armazenamento em um vetor char*/
    scanf("%[^\n]", text);
    
    /*Contagem e remoçao de pontuaçao*/
    n_caracteres=counting(text);
    removepontuation(text);

    /*Cálculo do número de palavras da frase alterada*/
    for(i=0; i<n_caracteres; i++){
        c_atual = text[i];

        /*Confere se o numero consiste em um algarismo com casas decimais*/
        if(c_anterior2 == 48 || c_anterior2 == 49 || c_anterior2 == 50 || c_anterior2 == 51 || c_anterior2 == 52 || c_anterior2 == 53 || c_anterior2 == 54 || c_anterior2 == 55 || c_anterior2 == 56 || c_anterior2 == 57){
            if(c_anterior == ' '){
                if(c_atual == 48 || c_atual == 49 || c_atual == 50 || c_atual == 51 || c_atual == 52 || c_atual == 53 || c_atual == 54 || c_atual == 55 || c_atual == 56 || c_atual == 57){
                    n_palavras--;
                }
            }
        }
        
        /*Contagem das palavras por meio dos espaços*/
        if(c_atual != '\n'){
            /*Confere se nao há mais de um espaço separando as palavras*/
            if(c_atual == ' '){
                if(c_anterior == ' '){
                    n_palavras--;
                }
                n_palavras++;
            }
        }
        else{
            break;
        }
        
        /*Redefiniçao dos parametros necessarios para a comparaçao dos caracteres*/
        c_anterior2 = c_anterior;
        c_anterior = c_atual;
    }
    
    /*Confere se a frase nao termina com espaço*/
    if(c_anterior == ' '){
        n_palavras--;
    }
    
    /*Printa a quantidade de palavras existentes na frase*/
    printf("%d\n", n_palavras+1);
    
    return 0;
}