#include <stdio.h> // Para funções de entrada (scanf) e saída (printf)

/**
 * Nível Básico: Lógica de Decisão
 *
 * Este programa cadastra duas cartas do Super Trunfo, calcula
 * seus atributos derivados (Densidade, PIB per Capita) e, em seguida,
 * usa 'if-else' para comparar um atributo (População) e declarar um vencedor.
 */
int main() {
    // --- Variáveis para a Carta 1 ---
    char estado1[4];       // String para o estado (ex: "SP", "RJ")
    char codigo1[5];       // String para o código (ex: "A01")
    char nomeCidade1[100]; // String para o nome
    int populacao1;        // Inteiro para população (conforme requisito)
    float area1;
    float pib1;            // Lido em bilhões
    int pontosTuristicos1;
    float densidade1;      // Valor calculado
    float pibPerCapita1;   // Valor calculado

    // --- Variáveis para a Carta 2 ---
    char estado2[4];
    char codigo2[5];
    char nomeCidade2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;

    printf("=== Batalha Super Trunfo (Nível Básico: Decisão) ===\n");

    // --- Bloco de Cadastro da Carta 1 ---
    // (Reaproveitando a lógica de entrada dos desafios anteriores)
    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (ex: SP): ");
    scanf("%s", estado1); // Lendo uma string (não precisa de &)

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    // O " " antes do %[^\n] é vital para consumir o "Enter" anterior
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a População (apenas números): ");
    scanf("%d", &populacao1); // %d para 'int'

    printf("Digite a Área (em km², apenas números): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais, apenas números): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);


    // --- Bloco de Cadastro da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (ex: RJ): ");
    scanf("%s", estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a População (apenas números): ");
    scanf("%d", &populacao2); // %d para 'int'

    printf("Digite a Área (em km², apenas números): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais, apenas números): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);


    // --- Bloco de Cálculos ---
    // (Obrigatório pelo requisito "Calcular... Densidade e PIB per capita")
    
    // Cálculos da Carta 1
    densidade1 = (float)populacao1 / area1;
    // Converte PIB de "bilhões" para "reais" (multiplica por 1e9)
    pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;

    // Cálculos da Carta 2
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;


    // --- Bloco de Exibição dos Dados ---
    // (Obrigatório pelo requisito "calcular e exibir")
    
    printf("\n--- Dados da Carta 1 ---\n");
    printf("Cidade: %s (%s) / Código: %s\n", nomeCidade1, estado1, codigo1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n--- Dados da Carta 2 ---\n");
    printf("Cidade: %s (%s) / Código: %s\n", nomeCidade2, estado2, codigo2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);


    // --- Bloco de Comparação (Foco do Desafio) ---
    //
    // Atributo escolhido no código: População
    // Regra: Maior valor vence
    //
    
    printf("\n-------------------------------------------------");
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("-------------------------------------------------\n\n");

    // Exibe os valores que estão sendo comparados
    printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, populacao2);
    printf("\nResultado: ");

    // Estrutura de decisão 'if', 'if-else' e 'else'
    if (populacao1 > populacao2) {
        // Bloco executado se a condição (populacao1 > populacao2) for VERDADEIRA
        printf("Carta 1 (%s) venceu!\n", nomeCidade1);
    } 
    else if (populacao2 > populacao1) {
        // Bloco executado se a primeira condição for FALSA, 
        // mas esta (populacao2 > populacao1) for VERDADEIRA
        printf("Carta 2 (%s) venceu!\n", nomeCidade2);
    } 
    else {
        // Bloco executado se NENHUMA das condições anteriores for verdadeira
        printf("Empate!\n");
    }

    /* // Exemplo de como seria a lógica para Densidade (Menor vence):
    
    if (densidade1 < densidade2) {
        printf("Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (densidade2 < densidade1) {
        printf("Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Empate!\n");
    }
    */

    return 0;
}