#include "biblio.h"
int main()
{
    // declaração da variavel usada para o loop do codigo todo, garantirá que o usuario escolha quando continuar ou não no código
    int loop1 = 0, loop2 = 0;
    // fim da declaração

    // inicio da declaração da auxilia senha, para receber o tamanho da senha inserida com o usuario para comparar com a senha inserida na hora do cadastro armazenada na variavel confsenha
    int posicao;
    // fim da declaração
    setlocale(LC_ALL, "Portuguese");
    do // inicio do loop do codigo todo, tratamento de erro para garantir que o cliente escolha se quer ficar ou não no código
    {
        // chamando função locale para acrescentar o português a programação

        // declarando uma variavel usuario
        usuario novo_usuario;
        // fim da declaração
        loop2 = 0; // para evitar do tratamento de erro travar

        system("cls");
        printf("\n-----Bem vindo ao Any Animals-----\n\nComo posso ajudar ?\n");
        printf("\n01-Cadastrar usuário e pet;\n02-Exibir dados;\n03-Dados do sistema(Disque Denúncia);\n04-Alterar Dados;\n05-Excluir dados;\n06-Criar arquivo(De todos os dados);\n07-Sair do Any Animals;\n\nInsira: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer do teclado

        switch (opcao)
        {
        // caso para ler os dados do usuario e pet
        case 1:
            system("cls");
            ler_usuario(&novo_usuario);
            break;
        // caso para exibir os dados da struct
        case 2:
            system("cls");
            // declarado um if verificando se existe algum numero de senha para realizar o tratamento de erro para saber se o usuario criou algum cadastro ou não
            if (novo_usuario.num_senha == 1)
            {
                printf("\nInsira sua senha: ");
                scanf("%[^\n]", novo_usuario.senha);
                // variavel posicao recebe o tamanho da string senha
                posicao = strlen(novo_usuario.senha);
                // caso a senhas sejam iguais a função retorna 1
                if (confirma_senha(&novo_usuario.senha, &novo_usuario.confsenha, posicao) == 1)
                {
                    print_us(&novo_usuario, num);
                }
                else
                {
                    printf("\nSenha inválida!\n");
                }
                printf("\nPressione *enter* para voltar ao menu anterior...");
                getch();
            }
            else
            {
                printf("\nNenhum cadastro criado pressione *enter* para voltar ao menu anterior...");
                getch();
            }
            // fim do tratamento de erro para o caso do usuario não ter criado cadastro
            break;
        // dados do sistema
        case 3:
            system("cls");
            printf("\n-----------------------------------------------\n");
            printf("\nUpgrade idealizado e programado por : Alisson Ferreira Teles\n Heitor Carvalho Vilela\n Arthur Alves Silva");
            printf("\n-----------------------------------------------\n");
            printf("\nEmail para contato: alissontelesferreira@gmail.com\nTelefone para Denúncia: +55 64 999041235");
            printf("\n-----------------------------------------------\n");
            printf("\n\nPressione *enter* para voltar ao menu anterior...");
            getch();

            break;
            //fim do caso 3

            //inicio do caso de alterar dados
        case 4:
            // declarado um if verificando se existe algum numero de senha para realizar o tratamento de erro para saber se o usuario criou algum cadastro ou não
            if (novo_usuario.num_senha == 1)
            {

                system("cls");
                printf("\nInsira sua senha: ");
                scanf("%[^\n]", novo_usuario.senha);
                // variavel posicao recebe o tamanho da string senha
                posicao = strlen(novo_usuario.senha);
                // caso a senhas sejam iguais a função retorna 1
                if (confirma_senha(&novo_usuario.senha, &novo_usuario.confsenha, posicao) == 1)
                {

                    opcao1 = 0;
                    while (opcao1 != 6)
                    {
                        system("cls");
                        printf("\nInsira qual dado de usuário deseja alterar:\n\n01-Nome de usuario;\n02-Idade do usuario;\n03-Alterar Senha;\n04-Alterar dados do pet;\n05-Sair;\n\nInsira: ");

                        scanf("%d", &opcao1);
                        getchar(); // limpa o buffer do teclado
                        // switch case criado com a itenção de alteração de dados:
                        switch (opcao1)
                        {
                        // caso para alterar nome de usuario
                        case 1:
                            system("cls");
                            printf("\nNome atual: %s\nInsira o novo nome: ", novo_usuario.nome);
                            fflush(stdin);
                            scanf("%[^\n]", novo_usuario.nome);
                            printf("\nNovo nome : %s", novo_usuario.nome);
                            break;
                        // fim do caso

                        // caso para alterar o RG de usuario
                        case 2:
                            system("cls");
                            printf("\nIdade atual: %d\nInsira a nova idade: ", novo_usuario.idade);
                            fflush(stdin);
                            scanf("%d", &novo_usuario.idade);
                            printf("\nNova idade: %d", novo_usuario.idade);

                            break;
                        // fim do caso

                        // caso para alterar o RG de usuario
                        case 3:
                            system("cls");
                            // laço criado para que possa ser utilizado o tratamento de erro usando a variavel repet
                            do
                            {

                                printf("\nSenha atual: %s\nInsira a nova senha: ", novo_usuario.senha);
                                fflush(stdin);
                                scanf("%[^\n]", novo_usuario.senha);
                                printf("\nConfirme a senha : ");
                                fflush(stdin);
                                scanf("%[^\n]", novo_usuario.confsenha);
                                // tratamento de erro para verificar se as senhas estão iguais:
                                repet = 0; // para reiniciar o contador da variavel global repet
                                conf = strlen(novo_usuario.senha);
                                confirma_senha(novo_usuario.senha, novo_usuario.confsenha, conf);
                                // fim do tratamento de erro
                            } while (repet == 1);
                            printf("\nNova senha: %s", novo_usuario.senha);

                            break;
                        // fim do caso

                        // caso para alterar dados do pet
                        case 4:

                            system("cls");
                            alterar_pet(&novo_usuario);
                            printf("\nPressione enter para continuar no menu de escolha de alteração do usuário...");
                            getch;
                            break;
                            // fim do caso

                            break;
                        // fim do caso

                        // sair do menu de alteração
                        case 5:
                            printf("Pressione enter para voltar ao menu principal!");
                            opcao1 = 6;
                            getch();
                            break;
                            // fim do caso

                        default:
                            system("cls");
                            printf("\nErro inesperado, tente novamente!");
                            getch();
                            break;
                        }
                    }
                }
                else
                {
                    printf("\nSenha inválida!\n");
                    printf("\nPressione *enter* para voltar ao menu anterior...");
                    getch();
                }
                // fim do tratamento da senha
            }
            else
            {
                printf("\nNenhum cadastro criado pressione *enter* para voltar ao menu anterior...");
                getch();
            }
            // fim do tratamento de erro para o caso do usuario não ter criado cadastro
            break;
        //fim do alterar dados

        //caso de e
        case 5:
            system("cls");
            // declarado um if verificando se existe algum numero de senha para realizar o tratamento de erro para saber se o usuario criou algum cadastro ou não
            if (novo_usuario.num_senha == 1)
            {
                system("cls");
                printf("\nInsira sua senha: ");
                scanf("%[^\n]", novo_usuario.senha);
                // variavel posicao recebe o tamanho da string senha
                posicao = strlen(novo_usuario.senha);
                // caso a senhas sejam iguais a função retorna 1
                if (confirma_senha(&novo_usuario.senha, &novo_usuario.confsenha, posicao) == 1)
                {
                    excluir(&novo_usuario);
                }
                else
                {
                    printf("\nSenha inválida!\n");
                }
                printf("\nPressione *enter* para voltar ao menu anterior...");
                getch();
            }
            else
            {
                printf("\nNenhum cadastro criado pressione *enter* para voltar ao menu anterior...");
                getch();
            }
            // fim do tratamento de erro para o caso do usuario não ter criado cadastro
            break;
        // fim do caso

        // caso de fazer o arquivo
        case 6:
            system("cls");
            // declarado um if verificando se existe algum numero de senha para realizar o tratamento de erro para saber se o usuario criou algum cadastro ou não
            if (novo_usuario.num_senha == 1)
            {
                system("cls");
                printf("\nInsira sua senha: ");
                scanf("%[^\n]", novo_usuario.senha);
                // variavel posicao recebe o tamanho da string senha
                posicao = strlen(novo_usuario.senha);
                // caso a senhas sejam iguais a função retorna 1
                if (confirma_senha(&novo_usuario.senha, &novo_usuario.confsenha, posicao) == 1)
                {
                    arquivo(&novo_usuario);
                }
                else
                {
                    printf("\nSenha inválida!\n");
                }
                printf("\nPressione *enter* para voltar ao menu anterior...");
                getch();
                break;
            // fim do caso

            // caso para sair do código
            case 7:
                system("cls");
                loop = 0;
                // inicio do tratamento para que o usuario escolha se quer ou não continuar no código
                while (loop2 == 0)
                {
                    printf("\nDeseja continuar no Any Animals?\n01-Sim;\n02-Não;\n\nInsira: ");
                    scanf("%d", &loop1);
                    loop2++; // para fazer o laço while durar somente uma vez
                    if (loop1 == 2)
                    {
                        printf("\nTem certeza?\n01-Sim;\n02-Não;\n\nInsira: "); // inicio do tratamento para verificar se o usuario tem certeza
                        scanf("%d", &loop1);
                        if (loop1 == 1)
                        {
                            system("cls");
                            printf("\nMuito obrigado por usar o Any Animals, volte sempre!");
                            loop1 = 2; // loop1 recebe 2 para cortar com o Do WHile(loop1!=2)
                        }
                        else if (loop1 == 2)
                        {
                            loop1 = 0; // nada acontecerá e o código rodará normal
                        }
                    }
                    else if (loop1 == 1)
                    {

                        loop1 = 0; // nada acontece caso o usuario escolha 1, apenas retornará para o menu
                    }
                    else
                    {
                        printf("\nERRO: Valor inserido inválido, por favor tente novamente!");
                        loop1 = 0;
                    }
                }
            }
            else
            {
                printf("\nNenhum cadastro criado pressione *enter* para voltar ao menu anterior...");
                getch();
            }
            break;
        // fim do caso

        // caso digite qualquer dado fora do case
        default:
            printf("\nERRO: valor inserido inválido, tente novamente!\n Pressione enter para continuar\n");
            getch();
            system("cls");
            break;
            // fim do caso
        }
    } while (loop1 != 2);
    // fim do laço do código inteiro
}