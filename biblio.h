#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
// incio da declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
// fim da declaração das bibliotecas

// definindo uma constante global "tam"
#define tam 140
// fim da declaração da constante global

// declarando variaveis globais de opções para os swicth case
int opcao = 0, opcao1 = 0, opcao2 = 0;
// fim da declaração

// declarando variavel para receber o número de qual pet o dono deseja alterar algum dado e para se repetir deseje alterar mais de uma vez
int escolha = 0, loop = 0;
// fim da declaração

// declarando uma variavel i para usar no laço de repetição
int i;
// fim da declaração

// declarando variavel global para manipulação entre as funções de ler usuario e printar os dados
int num;
// fim da declaração

// declarando variavel global para manipulação entre as funções de confirmar senha e ler os dados de usuario
int repet = 2, conf;
// fim da declaração, conf irá receber o tamanho da string senha

// declaração da struct pet
typedef struct pet_struct
{
    char nome_pet[tam];   // receberá o nome do pet
    char raca[tam];       // receberá a raça do pet
    char especie[tam];    // receberá a espécie do pet
    char observacao[tam]; // guardará observações do pet(Exemplo: Condição de saúde/necessidades especiais, detalhes relevantes sobre o animal.)
} pet;
// fim da declaração da struct pet

// declaração da struct usuario
typedef struct usuario_struct
{
    char nome[tam];                      // receberá o nome do usuario
    char senha[tam], confsenha[tam];     // receberá a senha e a confirmação da senha respectivamente
    int idade;                           // receberá a idade do usuario
    pet pet1[tam];                       // recebe a struct pet alocada a um usuário
    int num_pet, quant_pet, num_usuario; // para reservar a quantidade de pets que o usuário e se já foi criado um cadastro possui
    int num_idd;                         // criados para realizar tratamento de erro pro caso do usuario digitar qualquer valor que não seja inteiro na idade
    int num_senha;                       // para verificar a quantidade de senhas que o usuario possui, para no menu principal, funcionar o tratamento de erro de solicitar ou não a senha caso o usuario tenha ou não

} usuario;
// fim da declaração do usuario

// função em passagem de parâmetros por referência e valor, para verificar se as senhas são iguais através da recursividade:
int confirma_senha(char *senha, char *confsenha, int n)
{
    if (n == 0)
    { // caso base: chegou ao fim da string
        if (strcmp(senha, confsenha) == 0)// se as strings são iguais
        {              
            repet = 2; // caso o usuario esteja tentando pela segunda vez ou mais
            return 1;  // retorna verdadeiro
        }
        else
        {
            repet = 1;
            system("cls");
            printf("\nERRO: As senhas não são iguais!");
            return 0; // senão, retorna falso
        }
    }
    else
    { // caso contrário, continua comparando caractere a caractere
        if (senha[n - 1] == confsenha[n - 1])
        {
            return confirma_senha(senha, confsenha, n - 1);
        }
        else
        {
            system("cls");
            printf("\nERRO: As senhas não são iguais!");
            repet = 1; // repet recebe 1, levando em consideração que este tratamento será feito utilizando o do while, Sempre que o valor de repet for igual a 1, o programa rodará novamente
            return 0;  // se encontrar um caractere diferente, retorna falso
        }
    }
}

// fim da função
//  declaração da função ler pet por referencia
void ler_pet(pet *usuario)
{
    system("cls");
    printf("\n-----------------------------------------------\n");
    printf("\nInsira o nome do animal: ");
    fflush(stdin);
    scanf("%[^\n]", usuario->nome_pet);
    // duas linhas acima somente para receber o nome do animal

    printf("\n-----------------------------------------------\n");
    printf("\nInsira a raça do animal: ");
    fflush(stdin);
    scanf("%[^\n]", usuario->raca);
    // duas linhas acima somente para receber a raça do animal
    printf("\n-----------------------------------------------\n");
    printf("\nInsira a espécie do pet: ");
    fflush(stdin);
    scanf("%[^\n]", usuario->especie);
    // duas linhas acima somente para receber a espécie do animal

    printf("\n-----------------------------------------------\n");
    printf("\nInsira observações sobre o animal\n(Exemplo: Condição de saúde/necessidades especiais, detalhes relevantes sobre o animal.)\nInsira observações: ");
    fflush(stdin);
    scanf("%[^\n]", usuario->observacao);
    // duas linhas acima somente para receber observações sobre o animal
}
// fim da declaração da função ler pet;

// declarando uma função para ler a struct usuario por referencia, apontando um ponteiro para o endereço da struct
void ler_usuario(usuario *usuario)
{

    // declaração para verificar se o usuário deseja declararar os dados do pet e para tratmento de erro
    int aux = 0, j;
    // fim da declaração
    usuario->num_usuario = 0;
    usuario->quant_pet = 0;

    if (usuario->num_usuario == 0)
    {
        usuario->num_usuario++;
        printf("\n-----------------------------------------------\n");
        printf("\nInsira o nome de usuário: ");
        fflush(stdin);
        scanf("%[^\n]", usuario->nome);

        do
        {
            usuario->num_idd = 0;
            printf("\n-----------------------------------------------\n");
            printf("\nInsira sua idade(Ex: 16): ");
            scanf("%d", &usuario->idade);
            getchar(); // limpa o buffer do teclado

            if ((usuario->idade < 13) || (usuario->idade > 130)) // Definimos idade mínima para 13 anos e máxima para 130
            {
                system("cls");
                printf("\nDado inserido inválido! Aperte *enter* para tentar novamente");
                getch();
            }
            else
            {
                usuario->num_idd = 2; // num idd recebe 2 para que o código pare de rodar
            }

        } while (usuario->num_idd != 2);
        // fim do laço, só encerrará caso o usuario digite dados que entrem no if e retornem 2 para as respectiveis variaveis acima

        // inicio do laço para tratamento de erro de digito errado

        // laço criado para que possa ser utilizado o tratamento de erro usando a variavel repet
        do
        {
            printf("\n-----------------------------------------------\n");
            printf("\nInsira sua senha: ");
            fflush(stdin);
            scanf("%[^\n]", usuario->senha);
            // duas linhas acima somente para receber a senha do usuario

            printf("\n-----------------------------------------------\n");
            printf("\nConfirme sua senha: ");
            fflush(stdin);
            scanf("%[^\n]", usuario->confsenha);
            // variavel conf recebe o tamanho da senha

            // tratamento de erro para verificar se as senhas estão corretas
            conf = strlen(usuario->senha);
            confirma_senha(usuario->senha, usuario->confsenha, conf);
            // fim do tratamento de erro
            usuario->num_senha = 1;

        } while (repet == 1);
        // fim do laço de tratamento para a senha

        // duas linhas acima somente para confirmar a senha do usuario

        printf("\n-----------------------------------------------\n");
        printf("\nDeseja criar quantos cadastros de pet ?\n Insira: ");
        scanf("%d", &num);
        usuario->num_pet = num; // variavel num.pet respsonsável por criar o tratamento de erro para o caso de o usuario querer alterar dados de pets à mais do que tem atriuidos ao mesmo usuario, variavel num responsável pela  transição global entre funções
        // laço criado para preenchimento de quantos cadastros de pets forem necessários
        for (j = 0; j < num; j++)
        {
            printf("\nO número do Pet: %d", usuario->quant_pet);
            ler_pet(&usuario->pet1[j]);
            usuario->quant_pet++; // armazenar a quantidade de pets criados
        }
        // fim do laço
    }
    else
    {
        printf("\n----Atingido número máximo de contas pessoais por dispositivo!, pressione *enter* para voltar ao menu anterior !----\n");
        getch();
    }
}
// fim da função leitura por valor

// declarando função print, para printar os dados dos usuarios:
void print_us(usuario *usuario, int n)// n indica a quantidade de pets criados;
{
    // declaração de uma variavel i local para manipulação do laço de repetição
    int i;
    // fim da declaração

    // iniciando print de cada dado da struct:
    system("cls");
    printf("\n-----------------------------------------------\n");
    printf("\nNome de usuário: %s", usuario->nome);

    printf("\n-----------------------------------------------\n");
    printf("\nIdade do usuário: %d", usuario->idade);

    printf("\n-----------------------------------------------\n");
    printf("\nSenha do usuário: %s", usuario->senha);
    // laço de repetição para printar os dados de todos os cadastros de pets criados
    for (i = 0; i < num; i++)
    {
        printf("\n----------------Dados do Pet-------------------\n");
        printf("\nNome do pet[%d]: %s", i + 1, usuario->pet1[i].nome_pet);

        printf("\n-----------------------------------------------\n");
        printf("\nRaça do pet[%d]: %s", i + 1, usuario->pet1[i].raca);

        printf("\n-----------------------------------------------\n");
        printf("\nEspécie do pet[%d]: %s", i + 1, usuario->pet1[i].especie);

        printf("\n-----------------------------------------------\n");
        printf("\nObservações do pet[%d]: %s", i + 1, usuario->pet1[i].observacao);
        printf("\n-----------------------------------------------\n");
        printf("Aperte enter para continuar");
        getch();
    }
}

int alterar_pet(usuario *usuario)
{
    int tratamento = 0;
    loop = 0; // garantindo que não falhará
    printf("\nInsira de qual pet deseja alterar os dados: ");
    scanf("%d", &escolha);
    if ((escolha < 0) || (escolha > usuario->num_pet))//tratamento de erro para garantir que o usuário inseriu um dado correto

    {
        printf("\n----Dado inserido inválido, pressione *enter* para voltar ao menu anterior !----\n");
        getch();
        loop = 2;
    }
    while (loop != 2) // laço para garantir que caso o usuario deseje ele consiga alterar mais de 1 dado de pet por vez
    {
        system("cls");
        loop = 0; // para evitar do laço dar qualquer problema durante a repetição,variavel só será definida nos casos de saida do usuario;
        opcao2 = 0;

        getchar(); // limpa o buffer do teclado
        printf("\nEscolha qual dado do pet deseja alterar:\n01-Nome;\n02-Raça;\n03-Especie;\n04-observações;\n05-Alterar todos os dados;\n06-Voltar ao menu anterior;\n\nInsira:");
        scanf("%d", &opcao2);
        getchar(); // limpa o buffer do teclado
        switch (opcao2)
        {

        // alterar nome do pet
        case 1:
            printf("\nNome atual do Pet[%d]: %s\nInsira o novo nome do Pet[%d]: ", escolha, usuario->pet1[escolha - 1].nome_pet, escolha);
            fflush(stdin);
            scanf("%[^\n]", usuario->pet1[escolha - 1].nome_pet);
            printf("\nNome do Pet[%d]: %s", escolha, usuario->pet1[escolha - 1].nome_pet);
            printf("\n\nPressione enter para voltar ao menu de alteração de dados do pet...\n");
            getch();

            break;
        // fim do caso

        // alterar raça do pet
        case 2:
            system("cls");
            printf("\nRaça atual do Pet[%d]: %s\nInsira a nova raça do Pet[%d]: ", escolha, usuario->pet1[escolha - 1].raca, escolha);
            fflush(stdin);
            scanf("%[^\n]", &usuario->pet1[escolha - 1].raca);
            printf("\nRaça atualizada do Pet[%d]: %s\n", escolha, usuario->pet1[escolha - 1].raca);
            printf("\n\nPressione enter para voltar ao menu de alteração de dados do pet...\n");
            getch();
            break;
        // fim do caso

        // alterar especie do pet
        case 3:
            system("cls");
            printf("\nEspecie atual do Pet[%d]: %s\nInsira a nova especie do Pet[%d] ", escolha, usuario->pet1[escolha - 1].especie, escolha);
            fflush(stdin);
            scanf("%[^\n]", usuario->pet1[escolha - 1].especie);
            printf("\nNova espécie do Pet[%d]: %s\n", escolha, usuario->pet1[escolha - 1].especie);
            printf("\n\nPressione enter para voltar ao menu de alteração de dados do pet...\n");
            getch();

            break;
        // fim do caso

        // alterar observação
        case 4:
            system("cls");
            printf("\nObservações atuais do Pet[%d]: %s\nInsira as novas observações do Pet[%d]: ", escolha, usuario->pet1[escolha - 1].observacao, escolha);
            fflush(stdin);
            scanf("%[^\n]", usuario->pet1[escolha - 1].observacao);
            printf("\nObservações atualizadas do Pet[%d]: %s\n", escolha, usuario->pet1[escolha - 1].observacao);
            printf("\n\nPressione enter para voltar ao menu de alteração de dados do pet...\n");
            getch();
            break;
        // fim do caso

        // caso para alterar todos os dados:
        case 5:
            system("cls");
            printf("\nNome atual do Pet[%d]: %s\nInsira o novo nome do Pet[%d]: ", escolha, usuario->pet1[escolha - 1].nome_pet, escolha);
            fflush(stdin);
            scanf("%[^\n]", usuario->pet1[escolha - 1].nome_pet);
            printf("\nNome atualizado do Pet[%d]: %s", escolha, usuario->pet1[escolha - 1].nome_pet);

            system("cls");
            printf("\nRaça atual do Pet[%d]: %s\nInsira a nova raça do Pet[%d]: ", escolha, usuario->pet1[escolha - 1].raca, escolha);
            fflush(stdin);
            scanf("%[^\n]", &usuario->pet1[escolha - 1].raca);
            printf("\nRaça atualizada do Pet[%d]: %s\n", escolha, usuario->pet1[escolha - 1].raca);

            system("cls");
            printf("\nEspecie atual do Pet[%d]: %s\nInsira a nova especie do Pet[%d] ", escolha, usuario->pet1[escolha - 1].especie, escolha);
            fflush(stdin);
            scanf("%[^\n]", usuario->pet1[escolha - 1].especie);
            printf("\nNova espécie do Pet[%d]: %s\n", escolha, usuario->pet1[escolha - 1].especie);

            system("cls");
            printf("\nObservações atuais do Pet[%d]: %s\nInsira as novas observações do Pet[%d]: ", escolha, usuario->pet1[escolha - 1].observacao, escolha);
            fflush(stdin);
            scanf("%[^\n]", usuario->pet1[escolha - 1].observacao);
            printf("\nObservações atualizadas do Pet[%d]: %s\n", escolha, usuario->pet1[escolha - 1].observacao);
            printf("\n\nPressione enter para voltar ao menu de alteração de dados do pet...\n");
            getch();

            break;
        // fim do caso

        // caso para sair do menu de alteração
        case 6:
            printf("\nPressione enter para voltar ao menu anterior!");
            loop = 2; // para o código voltar ao menu anterior
            break;
        // fim do caso

        // caso insira dado errado
        default:
            system("cls");
            printf("\nERRO: valor inserido inválido, tente novamente!\n Pressione enter para continuar\n");
            // falta ultimo tratamento de erro
            loop = 0; // para garantir que o código não encerre
            break;
        }
    }
    // fim do laço
}
// fim da função

// inicio da função excluir dados:
void excluir(usuario *usuario)
{
    // variavel LOCAL escolha  para que o usuario possa escolher de qual pet excluir, e variavel ex_dado para saber qual dado deja excluir
    int ex_dado;
    // fim da declaaração
    //  criação da variavel repet local e escolha para laço de repetição e escolha do usuario
    int repet = 0, escolha;
    // usando if como tratamento de erro para o caso de não ter sido criado um usuario
    repet = 0;
    if ((usuario->num_usuario < 0))
    {
        printf("\nERRO: Quantidade de usuários inválido para essa opção, presione *enter* para voltar ao menu anterior...");
        getch();
        repet = 1;
    }
    // fim do if

    // inicio do while para tratamentp
    while (repet != 1)
    {
        system("cls");
        printf("Qual tipo de dado deseja excluir?\n");
        printf("01-Nome;\n");
        printf("02-idade;\n");
        printf("03-Senha;\n");
        printf("04-Excluir todos os dados do usuário;\n05-Excluir dados do Pet;\n06-Voltar ao menu anterior;\n\n Insira: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        // caso para apagar o nome
        case 1:
            system("cls");
            strcpy(usuario->nome, "");
            printf("Nome excluido com sucesso, pressione *enter* para continuar!\n");
            getch();
            break;
        // fim do caso

        // caso para mudar a idade
        case 2:
            usuario->idade = 0;
            printf("Idade excluida com sucesso,pressione *enter* para continuar!\n");
            getch();
            break;
        // fim do caso

        // caso para apagar a senha
        case 3:
            strcpy(usuario->senha, "");
            printf("Senha excluida com sucesso, pressione *enter* para continuar!\n");
            getch();
            break;
        // fim do caso

        // caso para apagar todos os dados do usuário
        case 4:
            strcpy(usuario->nome, "");
            printf("Nome excluido com sucesso!\n");
            getch();
            break;
        // fim do caso

        // caso excluir pet
        case 5:
            loop = 0; // para garantir que o caso não vá bugar
            system("cls");
            printf("----Excluir dados do Pet----\nEscolha de qual pet deseja excluir algum dado: ");
            scanf("%d", &escolha);
            if ((escolha < 0) || (escolha > usuario->num_pet))
            {
                printf("\n----Dado inserido inválido, pressione *enter* para voltar ao menu anterior !----\n");
                getch();
                loop = 2;
            }
            while (loop != 2) // laço para garantir que caso o usuario deseje ele consiga alterar mais de 1 dado de pet por vez
            {
                printf("\nEscolha qual dado de Pet deseja excluir: \n01-Nome;\n02-Raça;\n03-Especie;\n04-observações;\n05-Excluir todos os dados;\n06-Voltar ao menu anterior;\n\nInsira: ");
                scanf("%d", &ex_dado);
                switch (ex_dado)
                {
                // nome do pet
                case 1:
                    system("cls");
                    strcpy(usuario->pet1[escolha - 1].nome_pet, "");
                    printf("\nDado excluído com sucesso!\nAperte *enter* para voltar ao menu de excluir...");
                    getch();
                    break;
                // fim do caso

                // excluir raça do pet
                case 2:
                    system("cls");
                    strcpy(usuario->pet1[escolha - 1].raca, "");
                    printf("\nDado excluído com sucesso!\nAperte *enter* para voltar ao menu de excluir...");
                    getch();
                    break;

                // fim do caso

                // excluir especie do pet
                case 3:
                    system("cls");
                    strcpy(usuario->pet1[escolha - 1].especie, "");
                    printf("\nDado excluído com sucesso!\nAperte *enter* para voltar ao menu de excluir...");
                    getch();

                    break;
                // fim do caso

                // excluir observações do pet
                case 4:
                    system("cls");
                    strcpy(usuario->pet1[escolha - 1].observacao, "");
                    printf("\nDado excluído com sucesso!\nAperte *enter* para voltar ao menu de excluir...");
                    getch();

                    break;
                // fim do caso

                // excluir todos os dados do pet
                case 5:
                    system("cls");
                    strcpy(usuario->pet1[escolha - 1].nome_pet, "");
                    strcpy(usuario->pet1[escolha - 1].raca, "");
                    strcpy(usuario->pet1[escolha - 1].especie, "");
                    strcpy(usuario->pet1[escolha - 1].observacao, "");
                    printf("Todos os dados do Pet[%d] excluídos com sucesso!\nPressione *enter* para continuar...", escolha);
                    getch();
                    break;
                // fim do caso

                // caso para voltar ao menu anterior
                case 6:
                    system("cls");
                    printf("\nPressione enter para voltar ao menu anterior!");
                    getch();
                    loop = 2; // para o código voltar ao menu anterior

                    break;
                // fim do caso
                default:
                    system("cls");
                    printf("\nERRO: valor inserido inválido, tente novamente!\n Pressione enter para continuar\n");
                    // falta ultimo tratamento de erro
                    loop = 0; // para garantir que o código não encerre
                    break;
                }
            }
            break;
            // fim do caso pet
        case 6:
            repet = 1; // parará o laço while e permitirá que o usuário volte ao menu anterior
            break;

        default:
            break;
        }
    }
    // fim do laço
}
// fim da função excluir

// incio da função arquivo
void arquivo(usuario *usuario)
{
    system("cls");
    // criando um ponteiro do tipo arquivo para abrir o arquivo
    FILE *arquivo = fopen("Dados.txt", "w");

    // fim da declaração do ponteiro

    // tratamento de erro para o caso de dar erro ao abrir o arquivo
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    // fim do tratamento de erro da abertura do arquivo

    // imprime os dados do usuario
    fprintf(arquivo, "Nome do usuario : %s\n\n", usuario->nome);
    fprintf(arquivo, "Idade do usuario: %d\n\n", usuario->idade);
    fprintf(arquivo, "senha do usuario: %s\n\n", usuario->senha);
    system("cls");
    printf("\nDados do usuário imprimidos com sucesso!\n");
    for (i = 0; i < usuario->quant_pet; i++)
    {
        fprintf(arquivo, "Nome do Pet[%d]: %s\n\n ", i + 1, usuario->pet1[i].nome_pet);
        fprintf(arquivo, "Raça do Pet[%d]: %s\n\n", i + 1, usuario->pet1[i].raca);
        fprintf(arquivo, "Especie do Pet[%d]: %s\n\n", i + 1, usuario->pet1[i].especie);
        fprintf(arquivo, "Observações do Pet[%d]: %s\n\n", i + 1, usuario->pet1[i].observacao);
        printf("\nDados do Pet[%d] imprimidos com sucesso!\n", i + 1);
    }
    fclose(arquivo);
}
// fim da função criar arquivo

#endif