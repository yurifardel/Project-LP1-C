#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#define NUM_ALUNO 20

typedef struct dados_cerimonia {
    char dataevento[15];
    char  horarioevento[200];
    char localEvento[200];
    char nameApresent[200];
    int tipodecerimonia;
    int quant;
    int verificacaoC;
}dados_cerimonia;
dados_cerimonia cerimonia[2];

typedef struct Vars{
    char nome[200];
    int matricula;
    char curso[200];
    int id;
    int aluno;
} Vars;
Vars vasr_system[NUM_ALUNO];

int i=0,escolha=0;
int quantA[10];
int quantA1[10];
int total=1,total1=1;
char res_1[2];
char res_2[2];
char res_3[2];
char busca[200];
char newchance[2];

void home();
void inicializar();
void cadastrarAluno();
void Coordenador();
void Coordenador1();
void Cerimonialista();
void Dados();
void Coordenador_Confirma();
void cerimonia_cerimonialista();
void cerimonia_aluno();
void coordenador_novachance();
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
        printf("\n 2- Acesso do Aluno");
        printf("\n 3- Acesso Coordenador SISTEMAS DE INFORMAÇÃO");
        printf("\n 4- Acesso Coordenador de ODONTOLOGIA");
        printf("\n 5- Acesso do Cerimonialista ");
        printf("\n 6- Sair do sistema");
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
                Coordenador1();
                break;
            case 5:
                Cerimonialista();
            break;
            default:
                printf("\n B Y E");
            break;
        }
    }while(opcao <= 5);
}

void inicializar(){

    for (i=0; i<1 ;i++) {
        strcpy(vasr_system[i].nome," NULL ");
        vasr_system[i].matricula=0;
        strcpy(vasr_system[i].curso,"NULL");
    }
}

void cadastrarAluno(){
    system("cls");
    char nome[200];
    int matricula;
    char curso[200];
    int id;
    char confirA[2];
    int opc;
        do {
            printf("\n***** Bem-Vindo *****\n");
            printf("\n1- Protocolar colação\n");
            printf("\n2- Confirma presença na colação\n");
            printf("\n3- Gerar certificado\n");
            printf("\n4- HOME ");
            printf("\nDigite a opção: ");
            scanf("%d",&opc);

        switch (opc)
        {
            case 1:
                system("cls");
                printf("***** Protocolar colação ***** \n");
                printf("\nAO CADASTRAR SEUS DADOS VOCÊ DECLARA QUE CUMPRIU TODAS AS DISCIPLINAS E ATIVIDADES COMPLEMENTARES ATÉ SUA FORMATURA.");
                printf("\n(ESSES DADOS AINDA SERÃO ANALISADOS PELO COORDENADOR DO SEU CURSO!)");
                printf("\nDigite seu nome: ");
                fflush(stdin);
                fgets(nome,sizeof(nome),stdin);
                printf("Digite sua matricula: ");
                scanf("%d",&matricula);
                printf("Qual a area do seu curso?\n1- Exatas\n2- Saúde\n Digite: ");
                scanf("%d",&id);
                printf("Digite seu curso: ");
                fflush(stdin);
                fgets(curso,sizeof(curso),stdin);
                printf("\nProtocolado com sucesso!");
                 printf("\n\n------------------------------------------------");
                for (i=0; i < NUM_ALUNO; ++i)
                    {
                        if (vasr_system[i].aluno == 0)
                        {
                            strcpy(vasr_system[i].nome,nome);
                            vasr_system[i].matricula=matricula;
                            strcpy(vasr_system[i].curso,curso);
                            vasr_system[i].id=id;
                            vasr_system[i].aluno=1;
                            break;
                        }
                    }

        break;

            case 2:
                        system("cls");
                        printf("***** Confirma presença na colação *****\n");
                        printf("\nEssas são as colações da UNIESP para o semestre:");
                        for (i=0; i <3 ;++i){
                            if(cerimonia[i].verificacaoC==1){
                                cerimonia_aluno(i);
                            }
                        }
                        printf("\nDigite seu nome: ");
                        fflush(stdin);
                        fgets(busca,sizeof(busca),stdin);
                        fflush(stdin);
                        for ( i=0; i <=NUM_ALUNO ; ++i) {
                            if ((strcmp(vasr_system[i].nome,busca)==0) && vasr_system[i].aluno==2 && cerimonia[vasr_system[i].id].verificacaoC==1) {
                            Dados();
                            printf("\nEssa são as informação da sua colação");
                            cerimonia_aluno(vasr_system[i].id);
                            printf("\nConfirma sua presença na cerimonia[s/n]?");
                            printf("\nPor algum caso o aluno não possa estar presente deve confirmar sua presença e entregar a procuração na coordenação do curso.");
                            printf("\nCaso não confirme sua presença ficará na lista do coordenador de até que outra cerimonia se compatível com sua ID: ");
                            fflush(stdin);
                            fgets(confirA,sizeof(confirA),stdin);
                            if ((strcmp(confirA,"s")==0)){
                                if (vasr_system[i].id==1 && total<=10){
                                quantA[i]+=1;
                                total+=quantA[i];
                                vasr_system[i].aluno=3;
                                printf("\n\nPresença confirmada!");
                                printf("\n\n----------------------------------------------");
                            }
                            else if (vasr_system[i].id==2 && total1<=10){
                                quantA1[i]+=1;
                                total1+=quantA1[i];
                                vasr_system[i].aluno=3;
                                printf("\n\nPresença confirmada!");
                                printf("\n\n----------------------------------------------");
                            }
                            else  {
                                printf("Limite de vagas excedido");
                                printf("Você está na lista dos  seu coordenador e será cadastradado por ele na próxima cerimônia que for compátivel com sua ID. Será necessário que o aluno confirme sua presença.");
                                printf("\n\n------------------------------------------------");
                                vasr_system[i].aluno=-4;
                            }
                        }
                        else if (strcmp(vasr_system[i].nome,busca)==0 && strcmp(confirA,"n")==0 ){
                            printf("\n\nO aluno marcou que não irá a cerimonia marcada.\nLogo, o aluno entra na lista do seu coordenador e será cadastradado por ele na próxima cerimônia que for compátivel com sua ID.\nSerá necessário que o aluno confirme sua presença.");
                            printf("\n\n------------------------------------------------");
                            vasr_system[i].aluno=-4;
                        }
                        }
                        else if (vasr_system[i].aluno==-1 && strcmp(vasr_system[i].nome,busca)==0){
                           printf("\n\n Aluno com pedências. Procure coordenador do seu curso");
                           printf("\n\n------------------------------------------------");
                        }
        }
                break;
            case 3:
                system("cls");
                printf("***** Gerar certificado *****\n");
                printf("\nDigite seu nome: ");
                fflush(stdin);
                fgets(busca,sizeof(busca),stdin);
                for (i=0;i<NUM_ALUNO;++i){
                    if ((strcmp(vasr_system[i].nome,busca)==0) && vasr_system[i].aluno==4){
                    printf("Parabéns! Você pode gerar seu certificado.");
                    printf("\n\n------------------------------------------------");
                    vasr_system[i].aluno=0;
                }
                else if (strcmp(vasr_system[i].nome,busca)==0 && vasr_system[i].aluno==-4){
                    printf("Você não compareceu a cerimonia marcada e se encontra na lista com seu coordenador.");
                    printf("O seu Coordenador vai cadastrar novamente o aluno quando outra cerimônia marcada for compátivel com sua ID. Será necessário que o aluno confirme sua presença.");
                }
        }
                break;
            case 4:
                system("cls");
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
    char nome_tcc[11][2][200];
    int matriculaC[11][2];
    char escolhaC[2];
    int j;
    do {
        printf("\n***** Bem-Vindo Coordenador *****");
        printf("\n1- Verificar alunos que precisam de aprovação para colação.\n");
        printf("\n2- Gerar relatório de alunos que defenderam o TCC nesse semestre.\n");
        printf("\n3- Alunos que não foram protocolados\nCadastrar alunos que entregaram documentos fora do prazo\nLista de alunos que não compareceram a cerimonia\n");
        printf("\n4- Home ");
        printf("\nDigite a opção: ");
        scanf("%d",&opc);

   switch (opc)
   {
    case 1:
    system("cls");
    printf("***** Verificação de alunos *****\n");
    for ( i=0; i <= NUM_ALUNO ; ++i){
        if (vasr_system[i].aluno == 1 && vasr_system[i].id==1)
        {
            Dados();
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
       system("cls");
       printf("***** Gerar relatório *****\n");
        printf("Digite o nome dos alunos defenderam o TCC nesse semestre. Você tem o limite de 10 nomes.");
        FILE *arquivo_exter;
        arquivo_exter=fopen("alunostcc.txt","a");
        for (i=1; i < 11; i++){
            for (j=1; j< 2;j++){
                printf("\nDigite o nome do aluno: ");
                fflush(stdin);
                gets(nome_tcc[i][j]);
                printf("Digite a matricula: ");
                scanf("%d",&matriculaC[i][j]);
            }
        }
        fprintf(arquivo_exter,"Lista de Alunos:\n");
        for (i=1; i < 11; i++) {
            printf("\n");
            for (j=1;j< 2;j++){
                fprintf(arquivo_exter,"%d- Nome:%s - Matricula:%d\n",i,nome_tcc[i][j],matriculaC[i][j]);
            }
        }
        fclose(arquivo_exter);
        printf("Lista gerada com sucesso.");
        break;
   case 3:
   system("cls");
   do {
        printf("\n1- Lista alunos que não foram protocolados por não entregarem documentos.Cadastro de alunos que entregaram documentos fora do prazo.");
        printf("\n2- Lista de alunos que não compareceram a cerimonia ou confirmaram que não iriam a ela.Cadastro desse alunos na próxima cerimônia.");
        printf("\n3- Menu anterior ");
        printf("\nDigite: ");
        scanf("%d",&opc);
   switch(opc){
        case 1:
        system("cls");
        printf("***** Lista e cadastro de alunos que entregaram fora do prazo ***** \n");
        printf("\nEsse foram os alunos que não foram protocolados por não terem entregado o TCC, o nada consta ou ainda falta disciplinas para serem cursadas pelo aluno.");
        for ( i=0; i <= NUM_ALUNO ; ++i) {
            if (vasr_system[i].aluno == -1 && vasr_system[i].id==1)
            Dados();
        }
            printf("\nDigite\n[s]- Para cadastrar esse alunos\n[n]- Para voltar ao menu\n Digite: ");
            fflush(stdin);
            fgets(escolhaC,sizeof(escolhaC),stdin);
            if((strcmp(escolhaC,"s")==0)){
                for ( i=0; i <= NUM_ALUNO ; ++i) {
                    printf("\nDigite a NOME para aprovar cada um deles: ");
                    fflush(stdin);
                    fgets(busca,sizeof(busca),stdin);
                    Coordenador_Confirma();
                }
            }
            else {
                Coordenador();
            }
            break;
        case 2:
            system("cls");
            printf("***** Lista de alunos que não compareceram a cerimonia ou confirmaram que não iriam a ela.Cadastro desse alunos na próxima cerimônia *****");
            printf("\n\nLista de alunos que não compareceram a cerimonia ou não confirmaram a presença.");
            printf("\n\nAssim, na próxima cerimônia o coordenador deve cadastrar os alunos para que eles confirmem a presença na cerimônia que compete a cada um");
            for (i=0;i<NUM_ALUNO;++i){
                if(vasr_system[i].aluno==-4 && vasr_system[i].id==1){
                    Dados();
                }
            }
            printf("\nDigite\n[s]- Para cadastrar esse alunos\n[n]- Para voltar ao menu: ");
            fflush(stdin);
            fgets(escolhaC,sizeof(escolhaC),stdin);
            if((strcmp(escolhaC,"s")==0)){
                printf("\nDigite a NOME para aprovar cada um deles: ");
                fflush(stdin);
                fgets(busca,sizeof(busca),stdin);
                for (i=0; i <= NUM_ALUNO ; ++i) {
                    if (strcmp(vasr_system[i].nome,busca)==0 && vasr_system[i].aluno==-4 && vasr_system[i].id==1){
                        Dados();
                        printf("\nCadastrar aluno na nova cerimônia\ns-sim\nn-não: ");
                        fflush(stdin);
                        fgets(newchance,sizeof(newchance),stdin);
                        if (strcmp(newchance,"s")==0){
                            vasr_system[i].aluno=2;
                            printf("Realizado com sucesso!");
                        }
                        else {
                            printf("Cadastro não realizado");
                        }
                    }
                }
            }
            else {
                Coordenador();
            }
            break;
        case 3:
            system("cls");
            Coordenador();
            break;
            default:
            printf("Opção Invalida");
            break;
}
   }while (opc!=3);
   case 4:
       system("cls");
         home();
         break;
    default:
        printf("Opção Invalida");
        }
   } while (opc!=4);
}
void Coordenador1(){
    system("cls");
    int opc;
    char nome_tcc1[11][2][200];
    int matriculaC1[11][2];
    char escolhaC1[2];
    int j;
    do {
        printf("\n***** Bem-Vindo Coordenador *****");
        printf("\n1- Verificar alunos que precisam de aprovação para colação.\n");
        printf("\n2- Gerar relatório de alunos que defenderam o TCC nesse semestre.\n");
        printf("\n3- Alunos que não foram protocolados\nCadastrar alunos que entregaram documentos fora do prazo\nLista de alunos que não compareceram a cerimonia\n");
        printf("\n4- Home ");
        printf("\n Digite: ");
        scanf("%d",&opc);

   switch (opc)
   {
    case 1:
    system("cls");
    printf("***** Verificação de alunos *****\n");
    for ( i=0; i <= NUM_ALUNO ; ++i){
            if (vasr_system[i].aluno == 1 && vasr_system[i].id==2)
            {
                Dados();
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
        system("cls");
        printf("***** Gerar relatório *****\n");
        printf("Digite o nome dos alunos defenderam o TCC nesse semestre. Você tem o limite de 10 nomes.");
        FILE *arquivo_exter;
        arquivo_exter=fopen("tccalunos1.txt","a");
        for (i=1; i < 11; i++){
            for (j=1;j<2;j++){
                printf("\nDigite o nome do aluno: ");
                fflush(stdin);
                gets(nome_tcc1[i][j]);
                printf("Digite a matricula do aluno: ");
                scanf("%d",&matriculaC1[i][j]);
            }
        }
        fprintf(arquivo_exter,"Lista de Alunos:\n");
        for (i= 1; i < 11; i++) {
            printf("\n");
            for (j=1;j< 2;j++){
                fprintf(arquivo_exter,"%d- Nome: %s - Matricula: %d\n",i,nome_tcc1[i][j],matriculaC1[i][j]);
            }
        }
        fclose(arquivo_exter);
        printf("Lista gerada com sucesso.");
        break;
        case 3:
   system("cls");
   do {
        printf("\n1- Lista alunos que não foram protocolados por não entregarem documentos.Cadastro de alunos que entregaram documentos fora do prazo.");
        printf("\n2- Lista de alunos que não compareceram a cerimonia ou confirmaram que não iriam a ela.Cadastro desse alunos na próxima cerimônia.");
        printf("\n3- Menu anterior: ");
        scanf("%d",&opc);
   switch(opc){
       case 1:
        system("cls");
        printf("***** Lista e cadastro de alunos que entregaram fora do prazo ***** \n");
        printf("\nEsse foram os alunos que não foram protocolados por não terem entregado o TCC, o nada consta ou ainda falta disciplinas para serem cursadas pelo aluno.");
        for ( i=0; i <= NUM_ALUNO ; ++i) {
            if (vasr_system[i].aluno == -1 && vasr_system[i].id==2)
                Dados();
            }
            printf("\nDigite:\n[s]- Para cadastrar esse alunos\n[n]- Para voltar ao menu: ");
            fflush(stdin);
            fgets(escolhaC1,sizeof(escolhaC1),stdin);
            if((strcmp(escolhaC1,"s")==0)){
                for ( i=0; i <= NUM_ALUNO ; ++i) {
                    printf("\nDigite a NOME para aprovar cada um deles: ");
                    fflush(stdin);
                    fgets(busca,sizeof(busca),stdin);
                    Coordenador_Confirma();
                }
            }
            else {
                Coordenador1();
            }
            break;
        case 2:
            system("cls");
            printf("***** Lista de alunos que não compareceram a cerimonia ou confirmaram que não iriam a ela.Cadastro desse alunos na próxima cerimônia *****");
            printf("\nLista de alunos que não compareceram a cerimonia ou não confirmaram a presença.");
            printf("\nAssim, na próxima cerimônia o coordenador deve cadastrar os alunos para que eles confirmem a presença na cerimônia que compete a cada um");
            for (i=0;i<NUM_ALUNO;++i){
                if(vasr_system[i].aluno==-4 && vasr_system[i].id==2){
                    Dados();
                }
            }
            printf("\nDigite\n[s]- Para cadastrar esse alunos\n[n]- Para voltar ao menu: ");
            fflush(stdin);
            fgets(escolhaC1,sizeof(escolhaC1),stdin);
            if((strcmp(escolhaC1,"s")==0)){
                printf("\nDigite a NOME para aprovar cada um deles: ");
                fflush(stdin);
                fgets(busca,sizeof(busca),stdin);
                for (i=0; i <= NUM_ALUNO ; ++i) {
                    if (strcmp(vasr_system[i].nome,busca)==0 && vasr_system[i].aluno==-4 && vasr_system[i].id==2){
                        Dados();
                        printf("\nCadastrar aluno na nova cerimônia\ns-sim\nn-não: ");
                        fflush(stdin);
                        fgets(newchance,sizeof(newchance),stdin);
                        if (strcmp(newchance,"s")==0){
                            vasr_system[i].aluno=2;
                            printf("\n\nRealizado com sucesso!");
                        }
                        else {
                            printf("\n\nCadastro não realizado");
            }
                    }
                }
            }
            else {
                Coordenador1();
            }
            break;
        case 3:
            system("cls");
            Coordenador1();
            break;
            default:
            printf("Opção Invalida");
            break;
}
   }while (opc!=3);
    case 4:
       system("cls");
         home();
         break;
    default:
        printf("Opção Invalida");
        }
   } while (opc!=4);

}
void Cerimonialista(){
    system("cls");
    char localEvento[200];
    char dataevento[200];
    char horarioevento[200];
    char nameApresent[200];
    char confirmar[2];
    int tipodecerimonia;
    int opc;
    char finalizar[2];
    do{
        printf("\n***** Acesso do cerimonialista *****");
        printf("\n1- Cadastrar evento");
        printf("\n2- Confirmar presença de aluno");
        printf("\n3- Gerar relatorio do evento e finalizar cerimônias.");
        printf("\n4- Voltar para home");
        printf("\nDigite uma das opções: ");
        scanf("%d%*c", &opc);
        switch (opc)
        {
        case 1:
            system("cls");
            printf("***** Cadastrar evento *****\n");
            printf("Digite o ID da cerimonia:\n1- Exatas\n2- Saúde\nDigite: ");
            scanf("%d",&tipodecerimonia);
            printf("\nDefina o local do evento: ");
            fflush(stdin);
            fgets(localEvento,sizeof(localEvento),stdin);
            printf("\nDefina a data do evento: ");
            fflush(stdin);
            fgets(dataevento,sizeof(dataevento),stdin);
            printf("\nDefina o horario do evento: ");
            fflush(stdin);
            fgets(horarioevento,sizeof(horarioevento),stdin);
            printf("\nCadastrar o apresentador do evento");
            printf("\n Nome: ");
            fflush(stdin);
            fgets(nameApresent,sizeof(nameApresent),stdin);
            for (i=0; i < 3; ++i) {
                   if (cerimonia[tipodecerimonia].verificacaoC==0) {
                        strcpy(cerimonia[tipodecerimonia].localEvento,localEvento);
                        strcpy(cerimonia[tipodecerimonia].dataevento,dataevento);
                        strcpy(cerimonia[tipodecerimonia].horarioevento,horarioevento);
                        strcpy(cerimonia[tipodecerimonia].nameApresent,nameApresent);
                        cerimonia[tipodecerimonia].quant=10;
                        cerimonia[tipodecerimonia].tipodecerimonia=tipodecerimonia;
                        cerimonia[tipodecerimonia].verificacaoC=1;
                        printf("\nRealizado com sucesso");
            printf("\n\n------------------------------------------------");
                        break;
                             }
                    }
        break;
        case 2:
            system("cls");
            printf("***** Confirmar presença de aluno *****");
                for (i=0; i < NUM_ALUNO ;++i){
                    if (vasr_system[i].aluno == 3){
                        Dados();
                        printf("\nDigite [s/n] para confirmar a presença do aluno: ");
                        fflush(stdin);
                        fgets(confirmar,sizeof(confirmar),stdin);
                        if((strcmp(confirmar,"s")==0)){
                            printf("\nAluno compareceu a cerimônia.");
                            printf("\n\n------------------------------------------------");
                            vasr_system[i].aluno = 4;
                        }
                        else {
                            vasr_system[i].aluno= -4;
                            printf("\nAluno não compareceu a cerimônia.");
                            printf("\n\n------------------------------------------------");
                        }
                    }
                }
        break;
        case 3:
            system("cls");
            printf("***** Relatorios dos Eventos *****\n");
            printf("Escolha o tipo de Cerimônia\n1- Exatas\n2- Saúde\n Digite: ");
            scanf("%d",&escolha);
        for (i=0;i<3;++i){
            if (cerimonia[i].verificacaoC==1 && cerimonia[i].tipodecerimonia==escolha){
                cerimonia_cerimonialista(escolha);
                printf("Essa cerimônia já ocorreu?\ns-sim\nn-não\nDigite: ");
                fflush(stdin);
                fgets(finalizar,sizeof(finalizar),stdin);
                if (strcmp(finalizar,"s")==0){
                    cerimonia[escolha].verificacaoC=0;
                    printf("\n\nAtualizado com sucesso!");
                }
                else {
                    printf("\n\nO cerimonialista precisa atulizar o sistema quando a cerimônia tiver ocorrido.");
                }
            }
        }
        break;
        case 4:
            system("cls");
            home();
        break;

        default:
            printf("Opção Invalida");
        break;
        }
    }while(opc != 4);
}
void Dados(){
        printf("\nNome: %s", vasr_system[i].nome);
        printf("\nMatricula: %d\n", vasr_system[i].matricula);
        printf("\nId: %d\n", vasr_system[i].id);
        printf("\nCurso: %s\n", vasr_system[i].curso);
        printf("\n------------------------------------------------");
}
void Coordenador_Confirma() {
        for ( i=0 ; i <= NUM_ALUNO ; ++i){

            if (strcmp(vasr_system[i].nome,busca)==0) {
                Dados();
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
                vasr_system[i].aluno=2;
                printf("ALUNO APROVADO-ID-1\n\nNecessário a confirmação do aluno.");
                printf("\n\n------------------------------------------------");
            }
            else if (strcmp(res_1,"s")==0 && strcmp(res_2,"s")==0 && strcmp(res_3,"s")==0 && vasr_system[i].id==2){
                vasr_system[i].aluno=2;
                printf("ALUNO APROVADO-ID-2\n\nNecessário a confirmação do aluno.");
                printf("\n\n------------------------------------------------");
            }
            else  {
                vasr_system[i].aluno=-1;
                printf("\n\nAluno não poderá colar grau.");
                printf("\n\n------------------------------------------------");
           }
        }
        }
}
void cerimonia_cerimonialista (int tipo){
        printf("\n Local do evento: %s", cerimonia[tipo].localEvento);
        printf("\n Data do evento: %s", cerimonia[tipo].dataevento );
        printf("\n Horario do evento: %s",cerimonia[tipo].horarioevento );
        printf("\n Apresentador do evento: %s", cerimonia[tipo].nameApresent);
        printf("\n Tipo de cerimonia cadastrada: %d",cerimonia[tipo].tipodecerimonia );
        if (cerimonia[tipo].tipodecerimonia==1){
            printf("\nEssa é a quantidade de vagas que existem nessa cerimonia até o momento: %d ",cerimonia[tipo].quant-total);
        }
        else if (cerimonia[tipo].tipodecerimonia==2) {
            printf("\nEssa é a quantidade de vagas que existem nessa cerimonia até o momento: %d ",cerimonia[tipo].quant-total1);
        }

}
void cerimonia_aluno (int tipo) {
        printf("\n Local do evento: %s", cerimonia[tipo].localEvento);
        printf("\n Data do evento: %s", cerimonia[tipo].dataevento );
        printf("\n Horario do evento: %s",cerimonia[tipo].horarioevento );
        printf("\n Apresentador do evento: %s", cerimonia[tipo].nameApresent);
        printf("\n Tipo de cerimonia cadastrada: %d",cerimonia[tipo].tipodecerimonia );
        printf("\n\n------------------------------------------------");
}

