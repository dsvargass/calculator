#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * O código abaixo executa operações simples de matemática como: Soma, Subtração, Divisão, Multiplicação, Raiz Quadrada e Potência.
 * Autor: Diego Vargas.
 * Github: dsvargass
 */
int main(int argc, char *argv[]) {
    int option; //Utilizado para identificar se é raiz quadrada ou não.
    char operator;
    double value1, value2;
    bool abortApplication = false;
    printf("Seja bem vindo(a) ao sistema de calculadora. \n Me chamo Diego Vargas e estudo Ciências de Dados pela Universidade UniLasalle, Matrícula: 202222025\n");
    
    //Esse while é necessário para permitir que o usuário faça várias operações sem precisar fechar o sistema e abrir novamente.
    while(!abortApplication) {
        printf("Digite 1 para Raiz Quadrada ou Digite 2 para (soma, multiplicação, divisão e potenciação): ");
        scanf("%d", &option);

        /*
         * 1 = RAIZ QUADRADA
         * 2 = SOMA, SUBTRAÇÃO, DIVISÃO, MULTIPLICAÇÃO E POTÊNCIA
         */
        if (option == 1) {
            printf("Informe a raiz quadrada de: ");
            scanf("%lf", &value1);

            double raizQuadrada = sqrt(value1);
            printf("Valor da raiz quadrada %.1lf: \n", raizQuadrada);
        } else if (option == 2) {
            /*
             * Em quanto o usuário não selecionar um operador válido, o sistema não vai permitir que ele avance para a próxima etapa.
             */
            bool nextStep = false;
            while(nextStep == false) {
                printf("Informe qual operação deseja realizar (+, -, *, / ou p para potência): ");
                scanf(" %c", &operator);
               
                if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != 'p') {
                    printf("Operação inválida, tente novamente. \n");
                } else {
                    nextStep = true;
                }
            }
            
            if (operator != 'p') {
                printf("Informe o primeiro valor: ");
                scanf("%lf", &value1);
                
                printf("Informe o segundo valor: ");
                scanf("%lf", &value2);
            }

            switch(operator) {
                case '+':
                    printf("%.1lf + %.1lf = %.1lf\n", value1, value2, value1 + value2);
                    break;
                case '-':
                    printf("%.1lf - %.1lf = %.1lf\n", value1, value2, value1 - value2);
                    break;
                case '*':
                    printf("%.1lf * %.1lf = %.1lf\n", value1, value2, value1 * value2);
                    break;
                case '/':
                    printf("%.1lf / %.1lf = %.1lf\n", value1, value2, value1 / value2);
                    break;
                case 'p':
                    printf("Informe o valor: ");
                    scanf("%lf", &value1);
                    
                    printf("Informe a potência: ");
                    scanf("%lf", &value2);
                    double potencia = pow(value1, value2);
                    printf("Valor da potência %.1lf: \n", potencia);
                    break;
                default:
                    printf("");
            }
        } else {
            printf("Por favor informe os valores de acordo com as opções solicitadas.");
            abortApplication = true;
        } 

        printf("\n");
    }

    return 0;
}
