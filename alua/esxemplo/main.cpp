#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <cctype>
#include <locale.h>




struct endereco  //armazena os dados do endereço
{
    char rua[31];
    int numero;
    int cep;
};
struct notas  //armazena os dados das notas
{
    float nota1;
    float nota2;
    float medparc;
    float notafinal;
    float exame;
    char situacao[10];

};


struct cadastro  //armazena os dados do cadastro
{
    char nome[21];
    int matricula, dval;
    char cpf[15];
    char datanascimento[11];
    int dia,mes,ano;
    char datamatricula[11];
    int diamat,mesmat,anomat;
    int telefone;
    struct endereco local;
    struct notas desemp;
};

struct relatorio
{
    int tester;
    int r,s;
};


struct cadastro aluno[10];

char data (char data[11], int *dia, int *mes, int *ano)  //funcao mascara data
{
    char tecla;
    int i = 0;
    while(1)
    {
        if(i==10)
        {
            data = '\B';
            break;
        }
        else if(i==2 || i==5)
        {
            data = 'C';
            printf("%c",data);
            i++;
        }
        else
        {
            tecla = getch();
            if(tecla>='0' && tecla<='9')
            {

                if(i<10)
                {

                    data=tecla;
                    printf("%c",tecla);
                }
                i++;
            }
            else if( (tecla == '\b') )
            {
                if(i>0)
                {
                    printf("\b");
                    i--;
                    if(i == 2 || i == 5)
                    {
                        i--;
                        printf("\b");
                    }
                }
            }
            else if(tecla == ' ')
            {
                i++;
                printf("%c",data[i-1]);
            }
        }
    }
    *dia = (data[0]-48)*10 + (data[1]-48);
    *mes = (data[3]-48)*10 + (data[4]-48);
    *ano = (data[6]-48)*1000 + (data[7]-48)*100 + (data[8]-48)*10 + (data[9]-48);
    return(data[11]);
}
char cpf(char cpf[15])  //funcao mascara cpf
{
    char tecla;
    int i=0;
    while(1)
    {
        fflush(stdin);
        if(i==14)
        {
            cpf ='\0';
            break;
        }
        if((i==3)||(i==7))
        {
            cpf = '.';
            printf("%c", cpf);
            i++;
        }
        if((i==11))
        {
            cpf = '-';
            printf("%c", cpf);
            i++;
        }
        else
        {
            tecla=getch();
            if((tecla>='0')&&(tecla<='9'))
            {
                if(i<14)
                {
                    cpf=tecla;
                    printf("%c", tecla);
                }
                i++;
            }
            else if(tecla=='\b')
            {
                if(i>0)
                {
                    printf("\b");
                    i--;
                    if((i==3)||(i==7)||(i==11))
                    {
                        i--;
                        printf("\b");
                    }
                }
            }
            else if(tecla==' ')
            {
                i++;
                printf("%c", cpf[i-1]);

            }
        }
    }
    return(cpf[15]);
}
void buscpf(int d, int *cdt)  //funcao busca pelo cpf
{
    int cont,e=0;
    char cpfbusca[15];
    system("cls");
    printf("\n\n\t\t\tDIGITE O CPF: ");
    scanf("%s", cpfbusca);
    for(cont=0; cont<d; cont++)
    {
        if(cpfbusca==aluno[cont].cpf)
            printf("\n\n\t\t\tNOME: %s\n",aluno[cont].nome);
        printf("\t\t\tCPF: %s\n", aluno[cont].cpf);
        printf("\t\t\tMATRÍCULA: %d\n",aluno[cont].matricula);
        printf("\t\t\tTELEFONE: %d\n", aluno[cont].telefone);
        printf("\t\t\tENDEREÇO: %s, %d\n",aluno[cont].local.rua,aluno[cont].local.numero);
        printf("\t\t\tCEP: %d\n", aluno[cont].local.cep);
        printf("\t\t\tDATA DE NASCIMENTO: %s\n", aluno[cont].datanascimento);
        printf("\t\t\tNOTA FINAL: %.2f\n\t\t\tSITUAÇÃO: %s\n", aluno[cont].desemp.notafinal, aluno[cont].desemp.situacao);
        printf("\n\n");
        getch();
        e++;
        *cdt=cont;
    }
}
void busnome(int d, int *cdt)  //funcao busca pelo nome
{
    int cont,e=0;
    char nomebusca[21];
    system("cls");
    printf("\n\n\n\t\t\tDIGITE O NOME DO ALUNO: ");
    scanf("%20[^\n]", nomebusca);
    for(cont=0; cont<d; cont++)
    {
        if((stricmp (nomebusca, aluno[cont].nome))==0)
        {
            printf("\n\n\t\t\tNOME: %s\n",aluno[cont].nome);
            printf("\t\t\tCPF: %s\n", aluno[cont].cpf);
            printf("\t\t\tMATRÍCULA: %d\n",aluno[cont].matricula);
            printf("\t\t\tTELEFONE: %d\n", aluno[cont].telefone);
            printf("\t\t\tENDEREÇO: %s, %d\n",aluno[cont].local.rua,aluno[cont].local.numero);
            printf("\t\t\tCEP: %d\n", aluno[cont].local.cep);
            printf("\t\t\tDATA DE NASCIMENTO: %s\n", aluno[cont].datanascimento);
            printf("\t\t\tNOTA FINAL: %.2f SITUAÇÃO: %s\n", aluno[cont].desemp.notafinal,aluno[cont].desemp.situacao);
            printf("\n\n");
            getch();
            e++;
            *cdt=cont;
        }

    }
    if(e==0)
    {
        printf("\t\t\tNENHUM ALUNO ENCONTRADO!");
        getch();
    }
}

void busmatricula(int d, int *cdt)  //funcao busca pela matricula
{
    int e, cont, nm;
    e=0;
    system("cls");
    printf("\n\n\n\t\t\tDIGITE O NÚMERO DA MATRÍCULA: ");
    scanf("%d", &nm);
    for(cont=0; cont<d; cont++)
    {
        if(nm==aluno[cont].matricula)
        {
            printf("\n\n\t\t\tNOME: %s\n",aluno[cont].nome);
            printf("\t\t\tCPF: %s\n", aluno[cont].cpf);
            printf("\t\t\tMATRÍCULA: %d\n",aluno[cont].matricula);
            printf("\t\t\tTELEFONE: %d\n", aluno[cont].telefone);
            printf("\t\t\tENDEREÇO: %s, %d\n",aluno[cont].local.rua,aluno[cont].local.numero);
            printf("\t\t\tCEP: %d\n", aluno[cont].local.cep);
            printf("\t\t\tDATA DE NASCIMENTO: %s\n", aluno[cont].datanascimento);
            printf("\t\t\tNOTA FINAL: %.2f\n\t\t\tSITUAÇÃO: %s\n", aluno[cont].desemp.notafinal, aluno[cont].desemp.situacao);
            printf("\n\n");
            *cdt=cont;
            getch();
            e++;

        }

    }
    if(e==0)
    {
        printf("\t\t\tNENHUM ALUNO ENCONTRADO!");
        getch();
    }

}
void novocadastro(int k)  //funcao que cria um novo cadastro
{
    fflush(stdin);
    system("cls");
    int i,j;

    printf("\n\t\t");
    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }

        printf("_");
    }

inicio:
    printf("\n\n\t\t\t DIGITE OS DADOS SOLICITADOS \n\t\t");

    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }
        printf("_");
    }

    printf("\n\t\t\tNOME DO ALUNO: ");
    scanf("%20[^\n]",aluno[k].nome);
    printf("\n\t\t\tDATA DE NASCIMENTO: ");
    data(aluno[k].datanascimento,&aluno[k].dia,&aluno[k].mes,&aluno[k].ano);
    printf("\n\n\t\t\tCPF: ");
    cpf(aluno[k].cpf);
    printf("\n\n\t\t\tMATRÍCULA: ");
    scanf("%d", &aluno[k].matricula);
    printf("\n\t\t\tDATA DE MATRÍCULA: ");
    data(aluno[k].datamatricula,&aluno[k].diamat,&aluno[k].mesmat,&aluno[k].anomat);
    printf("\n\t\t\tNOME DA RUA: ");
    gets("%s",aluno[k].local.rua);
    printf("\n\t\t\tNÚMERO: ");
    scanf("%d", &aluno[k].local.numero);
    printf("\n\t\t\tCEP: ");
    scanf("%d", &aluno[k].local.cep);
    printf("\n\t\t\tTELEFONE: ");
    scanf("%d", &aluno[k].telefone);
    printf("\n\t\t\tPRIMEIRA NOTA: ");
    scanf("%f", &aluno[k].desemp.nota1);
    printf("\n\t\t\tSEGUNDA NOTA: ");
    scanf("%f", &aluno[k].desemp.nota2);
    aluno[k].desemp.medparc=((aluno[k].desemp.nota1)+(aluno[k].desemp.nota2))/2;
    if(aluno[k].desemp.medparc>=7)
    {
        aluno[k].desemp.notafinal = aluno[k].desemp.medparc;
        aluno[k].desemp.exame = 0,00;
        strcpy(aluno[k].desemp.situacao, "\t APROVADO \n");
    }
    else
    {
exame1:
        printf("\n\t\t\tNOTA EXAME: ");
        scanf("%f", &aluno[k].desemp.exame);
        aluno[k].desemp.notafinal = (aluno[k].desemp.medparc+aluno[k].desemp.exame)/2;
        if(aluno[k].desemp.notafinal>=5)
        {
            strcpy(aluno[k].desemp.situacao, "\t APROVADO \n");
        }
        else
        {
            strcpy(aluno[k].desemp.situacao, "\t REPROVADO \n");
        }
    }

    printf("\n\t\t\tMÉDIA FINAL %.2f %s\n", aluno[k].desemp.notafinal,aluno[k].desemp.situacao);
//
    system("pause");

}

int n,i,j;
int menu(void)
{

    int teste;
    printf("\n\t\t");
    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }

        printf("_");
    }

inicio:
    printf("\n\n\t\t\t CADASTRO DE ALUNOS \n \t\t\t MENU PRINCIPAL\n\t\t");

    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }
        printf("_");
    }

    printf("\n\n");
    printf("\t\t\t1 - NOVO CADASTRO\n");
    printf("\t\t\t2 - EDITAR CADASTRO\n");
    printf("\t\t\t3 - EXCLUÍR CADASTRO\n");
    printf("\t\t\t4 - BUSCAR CADASTRO\n");
    printf("\t\t\t5 - RELATÓRIO\n");
    printf("\t\t\t6 - SAÍR\n");
    printf("\n\n");
    printf("\t\t\tDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d",&teste);
    return(teste);
}
int menubusca(void)  //funcao que exibe o menu da busca
{
    int teste;
    int i,j;

    printf("\n\t\t");
    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }

        printf("_");
    }

inicio:
    printf("\n\n\t\t\t MENU DE BUSCA \n\t\t");

    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }
        printf("_");
    }
    printf("\n\t\t\t1 - BUSCAR POR NOME\n");
    printf("\t\t\t2 - BUSCAR POR MATRÍCULA\n");
    printf("\t\t\t3 - BUSCAR POR CPF\n");
    printf("\t\t\t6 - SAÍR\n");
    printf("\t\t\t OPÇÃO: ");
    scanf("%d",&teste);
    return(teste);

}
int menuedit()  //funcao que exibe o menu de editar cadastro
{
    int teste;

    printf("\n\t\t");
    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }

        printf("_");
    }

inicio:
    printf("\n\n\t\t\t MENU EDITAR \n\t\t");

    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }
        printf("_");
    }
    printf("\n\t\t\t1 - EDIÇÃO POR NOME\n");
    printf("\t\t\t2 - EDIÇÃO POR MATRÍCULA\n");
    printf("\t\t\t3 - EDIÇÃO POR CPF\n");
    printf("\t\t\t6 - SAÍR\n");
    printf("\t\t\t OPÇÃO: ");
    scanf("%d",&teste);
    return(teste);

}

int menudel(void)  //menu que exibe o menu de excluir um cadastro
{
    int teste;
    int i,j;

    printf("\n\t\t");
    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }

        printf("_");
    }

inicio:
    printf("\n\n\t\t\t MENU EXCLUSÃO \n\t\t");

    for(i = 0; i < 45; i++)
    {
        for(j = 0; j < 2000000; j++)
        {
        }
        printf("_");
    }
    printf("\n\t\t\t1 - EXCLUSÃO POR NOME\n");
    printf("\t\t\t2 - EXCLUSSÃO POR MATRÍCULA\n");
    printf("\t\t\t3 - EXCLUSÃO POR CPF\n");
    printf("\t\t\t6 - SAÍR\n");
    printf("\t\t\t OPÇÃO: ");
    scanf("%d",&teste);
    return(teste);

}





main()  //funcao principal
{
    setlocale(LC_ALL, "Portuguese");
    int j,opcao, busopcao, ediopcao, delopcao, relopcao, v, numerocdt,k, x;
    int i=0;
    int m=0;
    int teste=0,aux;


    int ordem[10]= {0,1,2,3,4,5,6,7,8,9};

    while(opcao!=6)
    {
        system("cls");
        opcao = menu(); //chama funcao menu
        switch(opcao)
        {
        case 1:
            novocadastro(i); //chama funcao novocadastro
            i++;
            break;

        case 4:
            while(busopcao!=6)
            {
                system("cls");
                busopcao = menubusca(); //chama funcao menu busca
                switch(busopcao)
                {
                case 1:
                    fflush(stdin);
                    busnome(i, &numerocdt); //chama funcao busca pelo nome
                    break;
                case 2:
                    fflush(stdin);
                    busmatricula(i, &numerocdt); //chama funcao busca pela matricula
                    break;
                case 3:
                    fflush(stdin);
                    buscpf(i, &numerocdt); //chama funcao busca pelo cpf
                    break;
                }
            }
            break;
        case 2:
            while(ediopcao!=6)
            {
                system("cls");
                ediopcao = menuedit(); //chama funcao menu editar
                switch(ediopcao)
                {
                case 1:
                    fflush(stdin);
                    busnome(i,&numerocdt); //chama funcao editar pelo nome
                    fflush(stdin);
                    novocadastro(numerocdt); //chama funcao para criar novo cadastro
                    break;
                case 2:
                    fflush(stdin);
                    busmatricula(i,&numerocdt); //chama funcao que edita pela matricula
                    fflush(stdin);
                    novocadastro(numerocdt); //chama funcao para criar novo cadastro
                    break;
                case 3:
                    fflush(stdin);
                    buscpf(i,&numerocdt); //chama funcao que edita pelo cpf
                    fflush(stdin);
                    novocadastro(numerocdt); //chama funcao para criar novo cadastro
                    break;
                }
            }
            break;
        case 3:
            while(delopcao!=6)
            {
                system("cls");
                delopcao = menudel(); //chama funcao menu excluir
                switch(delopcao)
                {
                case 1:
                    fflush(stdin);
                    busnome(i, &numerocdt); //chama funcao de busca pelo nome
                    for(x=numerocdt; x<i; x++)
                    {
                        aluno[x]=aluno[x+1];
                    }
                    i--;
                    break;
                case 2:
                    fflush(stdin);
                    busmatricula(i, &numerocdt); //chama funcao de busca pela matricula
                    for(x=numerocdt; x<i; x++)
                    {
                        aluno[x]=aluno[x+1];
                    }
                    i--;
                    break;
                case 3:
                    fflush(stdin);
                    buscpf(i, &numerocdt); //chama funcao de busca pelo cpf
                    for(x=numerocdt; x<i; x++)
                    {
                        aluno[x]=aluno[x+1];
                    }
                    i--;
                    break;
                }
            }
            break;
        case 5:
            system("cls");
            while(delopcao!=6)
            {
                system("cls");
                int ordem[10]= {0,1,2,3,4,5,6,7,8,9};
                int teste;
                int r,s,m,aux;

                printf("\n\t\t");
                for(r = 0; r < 45; r++)
                {
                    for(s = 0; s < 2000000; s++)
                    {
                    }

                    printf("_");
                }

inicio:
                printf("\n\n\t\t\t MENU DE RELATÓRIO \n\t\t");

                for(r = 0; r < 45; r++)
                {
                    for(s = 0; s < 2000000; s++)
                    {
                    }
                    printf("_");
                }
                printf("\n\t\t\t1 - ORDENAR POR NOME\n");
                printf("\t\t\t2 - ORDENAR POR MATRÍCULA\n");
                printf("\t\t\t3 - ORDENAR POR IDADE\n");
                printf("\t\t\t6 - SAÍR\n");
                printf("\t\t\t OPÇÃO: ");
                scanf("%d",&teste);

                while(teste!=6)
                {
                    system("cls");
                    switch(teste)
                    {
                    case 1: //por ordem alfabética
                        teste=0;
                        while(teste==0)
                        {
                            teste = 1;
                            for(m = 0 ; m < (r-1) ; m++)
                            {
                                if(strcmp(aluno[ordem[m]].nome,aluno[ordem[m+1]].nome)>0)
                                {
                                    aux=ordem[m];
                                    ordem[m]=ordem[m+1];
                                    ordem[m+1]=aux;
                                    teste = 0;
                                }
                            }
                        }

                        for( m = 0 ; m < r ; m++ )
                        {
                            printf("\t\t\tNOME: %s\n",aluno[ordem[m]].nome);
                            printf("\t\t\tMATRÍCULA: %d\n",aluno[ordem[m]].matricula);
                            printf("\t\t\tENDEREÇO: %s, %d, %d\n",aluno[ordem[m]].local.rua,aluno[m].local.numero,aluno[m].local.cep);
                            printf("\t\t\tDATA DA MATRÍCULA: %d",aluno[ordem[m]].datamatricula);
                            system("\t\t\tdate /t\n");
                            printf("\t\t\tCPF: %d\n",aluno[ordem[m]].cpf);
                            printf("\t\t\tTELEFONE: %d\n",aluno[ordem[m]].telefone);
                            printf("\t\t\tNOTA 1: %.1f\n",aluno[ordem[m]].desemp.nota1);
                            printf("\t\t\tNOTA 2: %.1f\n",aluno[ordem[m]].desemp.nota2);
                            printf("\n\t\t\tNOTA FINAL: %.1f",aluno[ordem[m]].desemp.notafinal);
                            printf("\n\n");
                        }

                        system("pause");
                        break;

                    case 2: //ordena por matrícula

                        teste=0;
                        while(teste==0)
                        {
                            teste = 1;
                            for(m = 0 ; m < (r-1) ; m++)
                            {
                                if((aluno[ordem[m]].matricula,aluno[ordem[m+1]].matricula)>0)
                                {
                                    aux=ordem[m];
                                    ordem[m]=ordem[m+1];
                                    ordem[m+1]=aux;
                                    teste = 0;
                                }
                            }
                        }

                        for( m = 0 ; m < r ; m++ )
                        {
                            printf("\t\t\tNOME: %s\n",aluno[ordem[m]].nome);
                            printf("\t\t\tMATRÍCULA: %d\n",aluno[ordem[m]].matricula);
                            printf("\t\t\tENDEREÇO: %s, %d, %d\n",aluno[ordem[m]].local.rua,aluno[m].local.numero,aluno[m].local.cep);
                            printf("\t\t\tDATA DA MATRÍCULA: %d",aluno[ordem[m]].datamatricula);
                            system("\t\t\tdate /t\n");
                            printf("\t\t\tCPF: %d\n",aluno[ordem[m]].cpf);
                            printf("\t\t\tTELEFONE: %d\n",aluno[ordem[m]].telefone);
                            printf("\t\t\tNOTA 1: %.1f\n",aluno[ordem[m]].desemp.nota1);
                            printf("\t\t\tNOTA 2: %.1f\n",aluno[ordem[m]].desemp.nota2);
                            printf("\n\t\t\tNOTA FINAL: %.1f",aluno[ordem[m]].desemp.notafinal);

                            printf("\n\n");
                        }

                        system("pause");
                        break;
                    case 3:
//data(aluno[k].datanascimento,&aluno[k].dia,&aluno[k].mes,&aluno[k].ano);
                        teste=0;
                        while(teste==0)
                        {
                            teste = 1;
                            for(m = 0 ; m < (r-1) ; m++)
                            {
                                if(strcmp(aluno[ordem[m]].datanascimento,aluno[ordem[m+1]].datanascimento)>0)
                                {
                                    aux=ordem[m];
                                    ordem[m]=ordem[m+1];
                                    ordem[m+1]=aux;
                                    teste = 0;
                                }
                            }
                        }

                        for( m = 0 ; m < r ; m++ )
                        {
                            printf("\t\t\tNOME: %s\n",aluno[ordem[m]].nome);
                            printf("\t\t\tMATRÍCULA: %d\n",aluno[ordem[m]].matricula);
                            printf("\t\t\tENDEREÇO: %s, %d, %d\n",aluno[ordem[m]].local.rua,aluno[m].local.numero,aluno[m].local.cep);
                            printf("\t\t\tDATA DA MATRÍCULA: %d",aluno[ordem[m]].datamatricula);
                            printf("\t\t\tDATA DE NASCIMENTO:%d\n", aluno[ordem[m]].datanascimento);
                            printf("\t\t\tCPF: %d\n",aluno[ordem[m]].cpf);
                            printf("\t\t\tTELEFONE: %d\n",aluno[ordem[m]].telefone);
                            printf("\t\t\tNOTA 1: %.1f\n",aluno[ordem[m]].desemp.nota1);
                            printf("\t\t\tNOTA 2: %.1f\n",aluno[ordem[m]].desemp.nota2);
                            printf("\n\t\t\tNOTA FINAL: %.1f",aluno[ordem[m]].desemp.notafinal);

                            printf("\n\n");
                        }

                        system("pause");
                        break;
                    }
                }
            }
            break;


        case 6:
            break;
        default:
            printf("\t\t\t OPÇÃO INVÁLIDA.");
        }
    }
}
