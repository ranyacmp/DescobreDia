#include<stdio.h>

int lerDia();
int lerMes(); 
int lerAno(); 
int testarBissexto(int ano);
int validarData(int dia, int mes, int ano, int bissexto);
int mensagem(int valor);
int semana(int dia, int mes, int bissexto);
int diasCorridos(int dia, int mes, int bissx);
void mensagemFinal(int dia1, int mes1, int ano1, int diaSemana);

main(){

    int dia1=0, mes1=0, ano1= 0, bissexto1=0,condicao= 0;

        while(condicao == 0){

            int dia= lerDia();
            int mes= lerMes(); 
            int ano= lerAno(); 
            int bissexto= testarBissexto(ano);

            printf("================ VALIDANDO DATA ================ \n");

            int validar = validarData(dia, mes, ano, bissexto);
            int validacao= mensagem(validar);

            dia1= dia; 
            mes1= mes; 
            ano1= ano; 
            bissexto1= bissexto;
            
            condicao = validacao; 

        }

    printf("================ DATA VALIDA ================ \n");

    int diaSemana= semana(dia1, mes1, bissexto1);

    mensagemFinal(dia1, mes1, ano1, diaSemana);

    return 0;

}

/* Função 'lerDia' recebe o dia digitado pelo ususário, verifica se atende a condição e retorna o dia para 
a função principal, se não atender pede para o usuário digitar novamente.*/
int lerDia(){
    
    int condicao=1;
        while(condicao){

            int dia;
            printf("\n Digite o dia: \n"); 
            scanf("%d", &dia);

            if(dia >= 1 && dia <= 31){
                return dia;
            }else{
                printf("Dia invalido, tente novamente. \n");
                continue;
            }

        }

}

/* Função 'lerMes' recebe o mes digitado pelo ususário, verifica se atende a condição e retorna o mes para 
a função principal, se não atender pede para o usuário digitar novamente.*/
int lerMes(){

    int condicao=1; 
        while(condicao){

            int mes;
            printf("Digite o mes: \n");
            scanf("%d", &mes);

            if(mes >= 1 && mes <= 12){
                return mes;
            }else{
                printf("Mes invalido, tente novamente. \n"); 
                continue;
            }
        }

}

/* Função 'lerAno' recebe o ano digitado pelo ususário, verifica se atende a condição e retorna o ano para 
a função principal, se não atender pede para o usuário digitar novamente.*/
int lerAno(){

    int condicao=1; 
        while(condicao){
            
            int ano; 
            printf("Digite o ano: \n");
            scanf("%d", &ano);

            if(ano >= 1900 && ano <= 2100){
                return ano;
            }else{
                printf("Ano invalido, tente novamente \n");
                continue;
            }

        }
}

/* A função 'testarBissexto' recebe o ano digitado pelo usuário como parâmetro e verifica se ele é bissexto 
ou nao. Se o ano for bissexto retorna 1, se não 0. */
int testarBissexto(int ano){

        if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
            return 1;
        }else{
            return 0;
        }

}

/* A função 'validarData' recebe o dia, mes, ano e se o ano é bissexto ou não como parâmetro e verifica se atende
as condições. Se houver erro retorna algum numero de 1 a 3 que na função 'mensagem' possuem mensagens específicas
de erro para o usuário, se não retorna 0 e continua o fluxo.*/
int validarData( int dia, int mes, int ano, int bissexto){

        if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30){
            return 1;
        }

        if( bissexto == 0 ){
            if( mes == 2 && dia > 28){
                return 2;
            }
        }

        if(bissexto == 1){
            if(mes == 2 && dia > 29){
                return 3;
            }
        }

    return 0;
}

/* A funçao 'mensagem' recebe um numero como parêmetro da função 'validarData' e verifica se existe algum erro, se
sim lança o erro na tela e inicia novamente o programa pedindo a data para o usuário, se nao ela retorna o 1 que 
interrompe o fluxo e valida a data.*/
int mensagem(int valor){
    if(valor == 1){
        printf("Data invalida, os meses 04 06 09 e 11 nao possuem mais que 30 dias. \n");
        return 0;
    }else if(valor == 2){
        printf("Data invalida, o mes de fevereiro (02) nao possui mais que 28 dias. \n");
        return 0;
    }else if(valor == 3){
        printf("Data invalida, em anos bissextos o mes de fevereiro (02) nao possuem mais que 29 dias. \n ");
        return 0;
    }else{
        return 1;
    }
}

/* A função 'semana' recebe o dia, mes e se o ano é bissexto como parâmetro e calcula qual o dia da 
semana corresponde à aquela data.
O calculo pode ser encontrado em: http://jornalheiros.blogspot.com/2018/03/metodo-para-calcular-o-dia-da-semana-de-uma-data-qualquer.html
*/
int semana(int dia, int mes, int bissexto){

    int ultimos;
    printf("Digite os dois ultimos digitos do ano: \n");
    scanf("%d", &ultimos);

    int calc1= ultimos - 1, calc2= ultimos / 4, calc3= 5; 
    int calc4= diasCorridos(dia,mes, bissexto);
    int total= calc1 + calc2 + calc3 + calc4; 
    int num= total % 7; 

    return num;
}

/* A função 'diasCorridos' calcula os dias corridos de 01/01 até o dia digitado, do mesmo ano. Função
auxiliar da função 'semana'. */
int diasCorridos(int dia, int mes, int bissx){

    int dias=0;
    if(bissx == 1){

        for(int i=1; i < 13; i++){

                if((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12 ) && i != mes){
                    dias = dias + 31;
                }else if( (i == 4 || i == 6 || i == 9 || i == 11 ) && i != mes){
                    dias= dias + 30;
                }else if( i == 2 && i != mes){
                    dias= dias + 29;
                }else if( i == mes){
                    dias = dias + dia;
                    return dias;
                }

        }

    }else if(bissx == 0){

        for(int i=1; i < 13; i++){

                if((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12 ) && i != mes){
                    dias = dias + 31;
                }else if( (i == 4 || i == 6 || i == 9 || i == 11 ) && i != mes){
                    dias= dias + 30;
                }else if( i == 2 && i != mes){
                    dias= dias + 28;
                }else if( i == mes){
                    dias = dias + dia;
                    return dias;
                }
        }

    }
}

/* A função 'mensagemFinal' recebe o resultado da função 'semana' e mostra qual foi o dia da semana. 
A tabela de dias e seus respectivos numeros pode ser encotrada em: 
http://jornalheiros.blogspot.com/2018/03/metodo-para-calcular-o-dia-da-semana-de-uma-data-qualquer.html
*/
void mensagemFinal(int dia1, int mes1, int ano1, int diaSemana){

    char vetor1[7][30]= {"Quarta-Feira","Quinta-Feira", "Sexta-Feira","Sabado", "Domigo","Segunda-Feira","Terca-Feira"};
    char vetor2[7][30]= {"Terca-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sabado", "Domingo","Segunda-Feira"};

    if(ano1 >= 1900 && ano1 < 2000){
        
        printf("Sua data foi %d/%d/%d %s. \n",dia1, mes1, ano1, vetor1[diaSemana]);
    
    }else if (ano1>= 200 && ano1 <= 2100){

        printf("Sua data foi %d/%d/%d %s. \n",dia1, mes1, ano1, vetor2[diaSemana]);

    } 
}


























