#include <stdio.h> // Para funções de entrada/saída (printf, scanf)
#include <string.h> // Para a função strcpy (copiar strings)

/**
 * Nível Avançado: Lógica de Decisão Integrada
 *
 * Este programa cadastra duas cartas, permite ao usuário escolher
 * DOIS atributos diferentes através de menus dinâmicos (switch),
 * soma os valores desses atributos (com lógica especial para densidade)
 * e declara um vencedor final (usando operador ternário).
 */
int main() {
    // --- Variáveis para a Carta 1 ---
    char estado1[4], codigo1[5], nomeCidade1[100];
    int populacao1, pontosTuristicos1;
    float area1, pib1, densidade1, pibPerCapita1;

    // --- Variáveis para a Carta 2 ---
    char estado2[4], codigo2[5], nomeCidade2[100];
    int populacao2, pontosTuristicos2;
    float area2, pib2, densidade2, pibPerCapita2;

    // --- Variáveis para a Lógica do Jogo ---
    int escolhaMenu1, escolhaMenu2;
    
    // Armazena os valores dos atributos escolhidos para a soma
    float valorAttr1_C1 = 0, valorAttr1_C2 = 0;
    float valorAttr2_C1 = 0, valorAttr2_C2 = 0;
    
    // Armazena os nomes dos atributos para exibição
    char nomeAttr1[50], nomeAttr2[50];
    
    // Armazena as somas finais
    float somaC1, somaC2;

    printf("=== Batalha Super Trunfo (Nível Avançado: Decisão Final) ===\n");

    // --- Bloco de Cadastro da Carta 1 ---
    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (ex: SP): ");
    scanf("%s", estado1);
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade/País: ");
    scanf(" %[^\n]", nomeCidade1);
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
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a População: ");
    scanf("%d", &populacao2);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Digite o N° de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Bloco de Cálculos ---
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;
    
    // --- Menu 1: Escolha do Primeiro Atributo ---
    printf("\n\n-------------------------------------------------");
    printf("\n--- Escolha o PRIMEIRO Atributo para a Batalha ---");
    printf("\n-------------------------------------------------\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica (Menor vence)\n");
    printf("\nDigite sua escolha (1-5): ");
    scanf("%d", &escolhaMenu1);

    // Armazena o valor e o nome do Atributo 1
    switch (escolhaMenu1) {
        case 1:
            valorAttr1_C1 = (float)populacao1;
            valorAttr1_C2 = (float)populacao2;
            strcpy(nomeAttr1, "População"); // Copia a string
            break;
        case 2:
            valorAttr1_C1 = area1;
            valorAttr1_C2 = area2;
            strcpy(nomeAttr1, "Área");
            break;
        case 3:
            valorAttr1_C1 = pib1;
            valorAttr1_C2 = pib2;
            strcpy(nomeAttr1, "PIB");
            break;
        case 4:
            valorAttr1_C1 = (float)pontosTuristicos1;
            valorAttr1_C2 = (float)pontosTuristicos2;
            strcpy(nomeAttr1, "Pontos Turísticos");
            break;
        case 5:
            // Lógica de inversão: 1.0 / densidade
            // Assim, uma densidade MENOR (ex: 1000) gera um valor MAIOR (0.001)
            // para a soma, o que é o "correto" para a regra "maior soma vence".
            valorAttr1_C1 = 1.0 / densidade1;
            valorAttr1_C2 = 1.0 / densidade2;
            strcpy(nomeAttr1, "Densidade (Poder)");
            break;
        default:
            printf("Erro: Opção inválida! Encerrando.\n");
            return 1; // Encerra o programa com código de erro
    }

    // --- Menu 2: Escolha do Segundo Atributo (Dinâmico) ---
    printf("\n-------------------------------------------------");
    printf("\n--- Escolha o SEGUNDO Atributo para a Batalha ---");
    printf("\n(Você já escolheu: %d. %s)", escolhaMenu1, nomeAttr1);
    printf("\n-------------------------------------------------\n");

    // Lógica do menu dinâmico:
    // Só exibe a opção se ela NÃO foi a primeira escolha.
    if (escolhaMenu1 != 1) { printf("1. População\n"); }
    if (escolhaMenu1 != 2) { printf("2. Área\n"); }
    if (escolhaMenu1 != 3) { printf("3. PIB\n"); }
    if (escolhaMenu1 != 4) { printf("4. Número de Pontos Turísticos\n"); }
    if (escolhaMenu1 != 5) { printf("5. Densidade Demográfica (Menor vence)\n"); }
    
    printf("\nDigite sua escolha: ");
    scanf("%d", &escolhaMenu2);

    // Validação: Garante que o usuário não escolheu o mesmo atributo
    if (escolhaMenu2 == escolhaMenu1) {
        printf("Erro: Você não pode escolher o mesmo atributo duas vezes! Encerrando.\n");
        return 1; // Encerra o programa
    }

    // Armazena o valor e o nome do Atributo 2
    switch (escolhaMenu2) {
        case 1:
            valorAttr2_C1 = (float)populacao1;
            valorAttr2_C2 = (float)populacao2;
            strcpy(nomeAttr2, "População");
            break;
        case 2:
            valorAttr2_C1 = area1;
            valorAttr2_C2 = area2;
            strcpy(nomeAttr2, "Área");
            break;
        case 3:
            valorAttr2_C1 = pib1;
            valorAttr2_C2 = pib2;
            strcpy(nomeAttr2, "PIB");
            break;
        case 4:
            valorAttr2_C1 = (float)pontosTuristicos1;
            valorAttr2_C2 = (float)pontosTuristicos2;
            strcpy(nomeAttr2, "Pontos Turísticos");
            break;
        case 5:
            // Aplicamos a mesma lógica de inversão da densidade
            valorAttr2_C1 = 1.0 / densidade1;
            valorAttr2_C2 = 1.0 / densidade2;
            strcpy(nomeAttr2, "Densidade (Poder)");
            break;
        default:
            printf("Erro: Opção inválida! Encerrando.\n");
            return 1; // Encerra o programa com código de erro
    }

    // --- Bloco Final de Cálculo e Exibição ---

    // Calcula a soma final para cada carta
    somaC1 = valorAttr1_C1 + valorAttr2_C1;
    somaC2 = valorAttr1_C2 + valorAttr2_C2;

    printf("\n\n=================================================");
    printf("\n               RESULTADO FINAL (SOMA)\n");
    printf("=================================================\n");

    // Exibe os dados da Carta 1
    printf("\n--- Carta 1: %s (%s) ---\n", nomeCidade1, estado1);
    printf("  Atributo 1 (%s): %.2f\n", nomeAttr1, valorAttr1_C1);
    printf("  Atributo 2 (%s): %.2f\n", nomeAttr2, valorAttr2_C1);
    printf("  SOMA TOTAL: %.2f\n", somaC1);

    // Exibe os dados da Carta 2
    printf("\n--- Carta 2: %s (%s) ---\n", nomeCidade2, estado2);
    printf("  Atributo 1 (%s): %.2f\n", nomeAttr1, valorAttr1_C2);
    printf("  Atributo 2 (%s): %.2f\n", nomeAttr2, valorAttr2_C2);
    printf("  SOMA TOTAL: %.2f\n", somaC2);

    // --- Determinação do Vencedor (usando Operador Ternário) ---
    printf("\n-------------------------------------------------");
    printf("\nVENCEDOR (Maior Soma Vence): %s\n", 
           (somaC1 > somaC2) ? "Carta 1 Venceu!" : 
           ((somaC2 > somaC1) ? "Carta 2 Venceu!" : "Empate!")
    );
    printf("-------------------------------------------------\n");

    return 0; // Indica que o programa terminou com sucesso
}