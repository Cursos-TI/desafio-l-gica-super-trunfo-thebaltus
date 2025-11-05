#include <stdio.h> // Para funções de entrada (scanf) e saída (printf)

/**
 * Nível Intermediário: Menu com Switch e Lógica de Decisão
 *
 * Este programa cadastra duas cartas, calcula seus atributos derivados,
 * e então apresenta um menu (usando 'switch') para o usuário escolher
 * qual atributo comparar (usando 'if-else').
 */
int main() {
    // --- Variáveis para a Carta 1 ---
    // (O desafio menciona "país", mas vamos manter a estrutura 
    // "cidade/estado" dos desafios anteriores, pois a lógica é a mesma)
    char estado1[4];
    char codigo1[5];
    char nomeCidade1[100];
    int populacao1;
    float area1;
    float pib1; // Lido em bilhões
    int pontosTuristicos1;
    
    // Atributos calculados
    float densidade1;
    float pibPerCapita1; // Calculado, mas não usado no menu deste nível

    // --- Variáveis para a Carta 2 ---
    char estado2[4];
    char codigo2[5];
    char nomeCidade2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Atributos calculados
    float densidade2;
    float pibPerCapita2; // Calculado, mas não usado no menu deste nível

    // --- Variável para o Menu ---
    int escolhaMenu;

    printf("=== Batalha Super Trunfo (Nível Intermediário: Switch) ===\n");

    // --- Bloco de Cadastro da Carta 1 ---
    // (Reaproveitando a lógica de entrada dos desafios anteriores)
    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (ex: SP): ");
    scanf("%s", estado1);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade/País: ");
    scanf(" %[^\n]", nomeCidade1); // O " " consome o 'Enter' anterior

    printf("Digite a População: ");
    scanf("%d", &populacao1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite o N° de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);


    // --- Bloco de Cadastro da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (ex: RJ): ");
    scanf("%s", estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade/País: ");
    scanf(" %[^\n]", nomeCidade2); // O " " consome o 'Enter' anterior

    printf("Digite a População: ");
    scanf("%d", &populacao2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite o N° de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);


    // --- Bloco de Cálculos ---
    // (Calcula os atributos derivados conforme requisitos)
    
    // Cálculos da Carta 1
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;

    // Cálculos da Carta 2
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;


    // --- Bloco do Menu Interativo ---
    
    printf("\n\n-------------------------------------------------");
    printf("\n--- Escolha o Atributo para a Batalha ---");
    printf("\n-------------------------------------------------\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica (Menor vence!)\n");
    printf("\nDigite sua escolha (1-5): ");
    
    // Lê a escolha do usuário
    scanf("%d", &escolhaMenu);

    printf("\n-------------------------------------------------");
    printf("\n              Resultado da Batalha\n");
    printf("-------------------------------------------------\n");

    // --- Estrutura Switch ---
    // O 'switch' direciona o programa para o 'case' 
    // correspondente à escolha do usuário.
    switch (escolhaMenu) {
        
        // --- Caso 1: Comparação de População ---
        case 1:
            printf("Atributo: População (Maior vence)\n\n");
            // Exibe os valores que estão sendo comparados
            printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, populacao1);
            printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, populacao2);
            printf("\nResultado: ");

            // Lógica de decisão 'if-else'
            if (populacao1 > populacao2) {
                printf("Carta 1 (%s) venceu!\n", nomeCidade1);
            } else if (populacao2 > populacao1) {
                printf("Carta 2 (%s) venceu!\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break; // 'break' é essencial para sair do switch

        // --- Caso 2: Comparação de Área ---
        case 2:
            printf("Atributo: Área (Maior vence)\n\n");
            printf("Carta 1 - %s (%s): %.2f km²\n", nomeCidade1, estado1, area1);
            printf("Carta 2 - %s (%s): %.2f km²\n", nomeCidade2, estado2, area2);
            printf("\nResultado: ");

            if (area1 > area2) {
                printf("Carta 1 (%s) venceu!\n", nomeCidade1);
            } else if (area2 > area1) {
                printf("Carta 2 (%s) venceu!\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        // --- Caso 3: Comparação de PIB ---
        case 3:
            printf("Atributo: PIB (Maior vence)\n\n");
            printf("Carta 1 - %s (%s): %.2f bilhões\n", nomeCidade1, estado1, pib1);
            printf("Carta 2 - %s (%s): %.2f bilhões\n", nomeCidade2, estado2, pib2);
            printf("\nResultado: ");

            if (pib1 > pib2) {
                printf("Carta 1 (%s) venceu!\n", nomeCidade1);
            } else if (pib2 > pib1) {
                printf("Carta 2 (%s) venceu!\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        // --- Caso 4: Comparação de Pontos Turísticos ---
        case 4:
            printf("Atributo: Número de Pontos Turísticos (Maior vence)\n\n");
            printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, pontosTuristicos1);
            printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, pontosTuristicos2);
            printf("\nResultado: ");

            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Carta 1 (%s) venceu!\n", nomeCidade1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Carta 2 (%s) venceu!\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        // --- Caso 5: Densidade Demográfica (REGRA INVERTIDA) ---
        case 5:
            printf("Atributo: Densidade Demográfica (MENOR vence)\n\n");
            printf("Carta 1 - %s (%s): %.2f hab/km²\n", nomeCidade1, estado1, densidade1);
            printf("Carta 2 - %s (%s): %.2f hab/km²\n", nomeCidade2, estado2, densidade2);
            printf("\nResultado: ");

            // A lógica 'if' é invertida (usa < em vez de >)
            if (densidade1 < densidade2) {
                printf("Carta 1 (%s) venceu!\n", nomeCidade1);
            } else if (densidade2 < densidade1) {
                printf("Carta 2 (%s) venceu!\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        // --- 'default': Trata entradas inválidas ---
        default:
            printf("Opção inválida!\n");
            printf("Você digitou '%d'. Por favor, reinicie e escolha um número entre 1 e 5.\n", escolhaMenu);
            break;
    }

    return 0; // Indica que o programa terminou com sucesso
}