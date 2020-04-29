#include <stdlib.h>
#include <string.h>              //  Desenvolvedores: Yuri Regis Nascimento e Victor Araujo França
#include <locale.h>                               
#include <stdio.h>
#include <ctype.h>
#define NUM_ALUNO 20

struct dados_cerimonia {
    char dataevento[15];
    int  horarioevento;
    char localEvento[200];
    char nameApresent[200];
    int tipodecerimonia;
    int cadastro;
    int verificacaoTipo;
};


typedef struct Vars{
    char nome[200];
    int matricula;
    char email[200];
    char curso[200];
    int id;
    int ativo;
    int aprovado;
    struct dados_cerimonia cadastrocerimonia;
} Vars;

Vars vasr_system[NUM_ALUNO];

int i=0;
char res_1[2];
char res_2[2];
char res_3[2];
char busca[200];

void home();
void inicializar();
void cadastrarAluno();
void Coordenador();
void Cerimonialista();
void Dados();
void Coordenador_Confirma();

int main(){

    setlocale(LC_ALL, "Portuguese");

    home();
    return 0;
}

void home(){
    int opcao;

    do{
        printf("\n******** HOME *********");
        printf("\n 1- Inicializa o sistema");
        printf("\n 2- Cadastro do Aluno");
        printf("\n 3- Acesso do Coordenador");
        printf("\n 4- Acesso do Cerimonialista ");
        printf("\n 5- Sair do sistema");
        printf("\n Digite a opcao desejada: ");
        scanf("%d%*c", &opcao);

        switch(opcao){
            case 1:
                inicializar();
            break;
            case 2:
                cadastrarAluno();
            break;
            case 3:
                Coordenador();
            break;
            case 4:
                Cerimonialista();
            break;
            default:
                printf("\n B Y E");
                break;
            break;
        }
    }while(opcao <= 4);
}

void inicializar(){

    for (i=0; i<1 ;i++) {
        strcpy(vasr_system[i].nome," NULL ");
        vasr_system[i].matricula=0;
        strcpy(vasr_system[i].email, "NULL");
        strcpy(vasr_system[i].curso,"NULL");
    }
}

void cadastrarAluno(){
    system("cls");
    char nome[200];
    int matricula;
    char email[200];
    char curso[200];
    int id;


    int opc;
        do {
            printf("\n*****Bem Vindo*****\n");
            printf("\n1- Protocolar sua colação\n");
            printf("\n2- Confirma presença na colação\n");
            printf("\n3- Gerar seu certificado\n");
            printf("\n4- HOME ");
            printf("\nDigite a opção desejada: ");
            scanf("%d",&opc);

        switch (opc)
        {
            case 1:
                printf("Digite seu nome: ");
                fflush(stdin);
                fgets(nome,sizeof(nome),stdin);

                printf("Digite sua matricula: ");
                fflush(stdin);
                scanf("%d",&matricula);
                do{
                printf("Seu curso é de qual área:\n1- Saúde\n2-Exatas\n3-Humanas\nDigite: ");
                fflush(stdin);
                scanf("%d",&id);
                } while(id!=1 && id!=2 && id!=3);

                printf("Digite seu Email: ");
                fflush(stdin);
                fgets(email,sizeof(email),stdin);

                printf("Digite seu curso: ");
                fflush(stdin);
                fgets(curso,sizeof(curso),stdin);


                for (i=0; i < NUM_ALUNO; ++i)
                    {
                    if (vasr_system[i].ativo == 0)
                    {
                        strcpy(vasr_system[i].nome,nome);
                        vasr_system[i].matricula=matricula;
                        strcpy(vasr_system[i].email,email);
                        strcpy(vasr_system[i].curso,curso);
                        vasr_system[i].id=id;
                        vasr_system[i].ativo=1;
                        vasr_system[i].aprovado=1;
                        break;
                        }
                    }
        break;

            case 2:
                        system("cls");
                        for ( i=0; i < NUM_ALUNO ;++i) {
                        if (vasr_system[i].aprovado == 2) {
                        Dados();
                        }
                        else if(vasr_system[i].aprovado==1) {
                        printf("Necessário a aprovação do Coordenador.");
                        }
                        }
                break;
            case 3:
                printf("Gerar seu certificado: ");
                break;
            case 4:
                home();
                break;
            default:
                printf("Opção Invalida");

        }
        }while (opc!=3);
}


void Coordenador(){
    system("cls");
    int opc;
    char nome_tcc[11][100];
    do {
        printf("\n*****Bem-Vindo Coordenador*****");
        printf("\n1- Verificar alunos que precisam de aprovação para colação.\n");
        printf("\n2- Gerar relatório de alunos que defenderam o TCC nesse semestre.\n");
        printf("\n3- Lista de alunos que não foram protocolados por alguma razão ou cadastrar alunos que entregaram documentos fora do prazo\n");
        printf("\n4- Home");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&opc);

   switch (opc)
   {
    case 1:


    for ( i=0; i <= NUM_ALUNO ; ++i){


            if (vasr_system[i].ativo == 1 )
            {
            printf("\nNome: %s", vasr_system[i].nome);
            printf("\nMatricula do aluno: %d\n", vasr_system[i].matricula);
            printf("\nID do aluno: %d", vasr_system[i].id);
            printf("\n------------------------------------------------");
            }
   }
    printf("\nEsses são os alunos que precisam da aprovação para colação.");
    printf("\nDigite a NOME para aprovar cada um deles: ");
    fflush(stdin);
    fgets(busca,sizeof(busca),stdin);

       for ( i=0 ; i <= NUM_ALUNO ; ++i){

        if (strcmp(vasr_system[i].nome,busca )==0)
            {
       Coordenador_Confirma();
        }
        }
        break;
   case 2:
        printf("Digite o nome dos alunos defenderam o TCC nesse semestre. Você tem o limite de 10 nomes.");
        fflush(stdin);
        FILE *arquivo_exter;
        fflush(stdin);
        arquivo_exter=fopen("alunostcc.txt","a");
        for (i=1; i < 11; i++){
        printf("\n%d-",i);
        fgets(nome_tcc[i],sizeof(nome_tcc),stdin);
        }
        fprintf(arquivo_exter,"Lista de Alunos:\n");
        for (i= 1; i < 11; i++) {
        fprintf(arquivo_exter,"%d-""%s",i,nome_tcc[i]);
        }
        fclose(arquivo_exter);
        printf("Lista gerada com sucesso.");
        break;
   case 3:
   do {
        printf("\n1- Alunos que não foram protocolados por não entregarem documentos.");
        printf("\n2- Cadastrar alunos que entregaram documentos fora do prazo.");
        printf("\n3- Home");
        printf("\nDigite uma opção: ");
        scanf("%d",&opc);
   switch(opc){

        case 1:
        printf("Esse foram os alunos que não foram protocolados por não terem entregado o TCC, o nada consta ou ainda falta disciplinas para serem cursadas pelo aluno.");
        for ( i=0; i <= NUM_ALUNO ; ++i) {
        if (vasr_system[i].ativo == -1)
        Dados();
            }
        break;
        case 2:
            printf("Cadastrar aluno que entregou fora do prazo:");
            for ( i=0; i <= NUM_ALUNO ; ++i) {
            if (vasr_system[i].ativo == -1)
            Dados();
            }
            printf("\nEsses são os alunos que precisam da aprovação para colação.");
            printf("\nDigite a NOME para aprovar cada um deles: ");
            fflush(stdin);
            fgets(busca,sizeof(busca),stdin);
            Coordenador_Confirma();
            printf("O aluno estará na próxima Colação que se encaixar com a sua ID.");
          break;
        case 3:
            home();
            break;
            default:
            printf("Opção invalida");
            break;
}
   }while (opc!=3);
   case 4:
         home();
         break;
    default:
        printf("Opção Invalida");
        }
   } while (opc!=4);
}


void Cerimonialista(){
    char localEvento[200];
    char dataevento[200];
    char horarioevento[200];
    char nameApresent[200];
    int cpfApresent;
    char confirmar[30];

    int opc;
    do{
        printf("\n*****Acesso do cerimonialista*****");


        printf("\n1 - Cadastrar evento");
        printf("\n2- Confirmar presença de aluno");
        printf("\n3- Gerar relatorio do evento");
        printf("\n4- Voltar para home");
        printf("\n5- Dia do evento");
        printf("\n6- Lista de alunos confirmados no evento");
        printf("\nDigite uma das opções: ");
        scanf("%d%*c", &opc);

        switch (opc)
        {
        case 1:
            printf("\nDefina o local do evento: ");
            fflush(stdin);
            fgets(localEvento,sizeof(localEvento),stdin);

            printf("\nDefina a data do evento: ");
            fflush(stdin);
            fgets(dataevento,sizeof(dataevento),stdin);

            printf("\nDefina o horario do evento: ");
            fflush(stdin);
            fgets(horarioevento,sizeof(horarioevento),stdin);

            printf("\nCadastrar o apresentador do evento!");
            printf("\n Nome: ");
            fflush(stdin);
            fgets(nameApresent,sizeof(nameApresent),stdin);

           /* printf("\n Digite o CPF: ");
            fflush(stdin);
            scanf("%d", &cpfApresent);*/
            for (i=0; i <= NUM_ALUNO; ++i)
                    {
                        if (vasr_system[i].cadastrocerimonia.tipodecerimonia==1){
                        fflush(stdin);
                        strcpy(vasr_system[i].cadastrocerimonia.localEvento,localEvento);
                        strcpy(vasr_system[i].cadastrocerimonia.dataevento,dataevento);
                        vasr_system[i].cadastrocerimonia.horarioevento=horarioevento;
                        strcpy(vasr_system[i].cadastrocerimonia.nameApresent,nameApresent);
                        vasr_system[i].cadastrocerimonia.tipodecerimonia=1;
                        printf("Foi1");
                        break;
                        }
                        else if (vasr_system[i].cadastrocerimonia.tipodecerimonia==2){
                        strcpy(vasr_system[i].cadastrocerimonia.localEvento,localEvento);
                        strcpy(vasr_system[i].cadastrocerimonia.dataevento,dataevento);
                        vasr_system[i].cadastrocerimonia.horarioevento=horarioevento;
                        strcpy(vasr_system[i].cadastrocerimonia.nameApresent,nameApresent);
                        vasr_system[i].cadastrocerimonia.tipodecerimonia=2;
                        printf("Foi2");
                        fflush(stdin);
                        break;

                        }

                        }



        break;

        case 2:

                for ( i=0; i < NUM_ALUNO ;++i){
                    if (vasr_system[i].aprovado == 2){
                        printf("\n Nome do aluno: %s", vasr_system[i].nome);
                        printf("\n Matricula do aluno %d", vasr_system[i].matricula);
                        printf("\n E-mail do aluno: %s", vasr_system[i].email);
                        printf("\n Id do aluno %d", vasr_system[i].id);
                        printf("\n Curso do aluno %s", vasr_system[i].curso);


                        printf("\nConfirme a presença do aluno!");
                        printf("\nDigite s para confirmar: ");
                        scanf("%s", &confirmar);
                        if(strcmp(confirmar,"s")==0){
                            printf("\nAluno confirmado no evento");
                            vasr_system[i].aprovado = 3;

                        }
                        else{
                            vasr_system[i].aprovado=1;
                            printf("\nAluno não confirmado no evento");
                        }
                    }
                }


        break;
        case 3:
            printf("\nRELATORIO EM ANDAMENTO");
        break;

        case 4:
            home();
        break;

        case 5:
            system("cls");
            printf("\n***** EVENTO ******");
            printf("\n Local do evento - %s", &localEvento);
            printf("\n Data do evento - %s", &dataevento);
            printf("\n Horario do evento - %d", &horarioevento);
            printf("\n Apresentador do evento - %s", &nameApresent);
        break;

        case 6:

           for (i = 0; i <= NUM_ALUNO; ++i){
                 if(vasr_system[i].aprovado == 3){
                    printf("\n Nome do aluno: %s", vasr_system[i].nome);
                    printf("\n Matricula do aluno: %d", vasr_system[i].matricula);
                    printf("\n Curso do aluno: %s", vasr_system[i].curso);
                    fflush(stdin);
                    break;
                    printf("\nALUNO CONFIRMADO NO EVENTO");
                    fflush(stdin);
                    printf("\n----------------------------------------------");
                }
            }
        break;

        default:
            printf("\n");
        break;

        }
    }while(opc != 6);


}

void Dados(){
        printf("\n Nome do aluno: %s\n", vasr_system[i].nome);
        printf("\n Matricula do aluno: %d\n", vasr_system[i].matricula);
        printf("\n E-mail do aluno: %s\n", vasr_system[i].email);
        printf("\n Id do aluno %d\n", vasr_system[i].id);
        printf("\n Curso do aluno %s\n", vasr_system[i].curso);
        printf("\n\n------------------------------------------------");
}
void Coordenador_Confirma() {
        for ( i=0 ; i <= NUM_ALUNO ; ++i){

        if (strcmp(vasr_system[i].nome,busca)==0)
            {
        printf("\n\n Nome do aluno: %s", vasr_system[i].nome);
        printf("\n\n Matricula do aluno: %d", vasr_system[i].matricula);
        printf("\n\n Email do aluno: %s", vasr_system[i].email);
        printf("\n\n O curso do aluno: %s",vasr_system[i].curso);
        printf("\nID do aluno: %d", vasr_system[i].id);
        printf("\n\n O aluno entrou entregou o TCC [S/N]: ");
        fflush(stdin);
        fgets(res_1,sizeof(res_1),stdin);
        printf("\n\n O aluno entregou o nada consta [S/N]: ");
        fflush(stdin);
        fgets(res_2,sizeof(res_2),stdin);
        printf("\n\n O aluno concluiu toda a grade curricular do seu curso [S/N]: ");
        fflush(stdin);
        fgets(res_3,sizeof(res_3),stdin);

        if (strcmp(res_1,"s")==0 && strcmp(res_2,"s")==0 && strcmp(res_3,"s")==0 && vasr_system[i].id==1){
            vasr_system[i].ativo=0;
            vasr_system[i].aprovado=2;
            vasr_system[i].id=1;
            printf("ALUNO APROVADO-1");

        }
        else if (strcmp(res_1,"s")==0 && strcmp(res_2,"s")==0 && strcmp(res_3,"s")==0 && vasr_system[i].id==2){
            vasr_system[i].ativo=0;
            vasr_system[i].aprovado=2;
            vasr_system[i].id=2;
            printf("ALUNO APROVADO-2");

        }
         else if (strcmp(res_1,"s")==0 && strcmp(res_2,"s")==0 && strcmp(res_3,"s")==0 && vasr_system[i].id==3) {
            vasr_system[i].ativo=0;
            vasr_system[i].aprovado=2;
            vasr_system[i].id=3;
            printf("ALUNO APROVADO-3");
         }
        else  {
           vasr_system[i].ativo=-1;
           vasr_system[i].aprovado=1;
           printf("Aluno não poderá colar grau.");
           }
        }
        }



}
void escolha_cerimonialista (int opc, struct dados_cerimonia x){
    for (int i=0;i<NUM_ALUNO;i++){




    }

}