#include <stdio.h>
#include <string.h>

int main() {
    // Dados da carta 1
    char estado1;
    char codigo1[10];
    char nomeCidade1[100];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Dados da carta 2
    char estado2;
    char codigo2[10];
    char nomeCidade2[100];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");

    printf("Estado: ");
    scanf(" %c", &estado1);
    getchar();

    printf("Código: ");
    fgets(codigo1, sizeof(codigo1), stdin);
    codigo1[strcspn(codigo1, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    getchar(); // limpa o buffer antes da próxima leitura

    // Leitura dos dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");

    printf("Estado: ");
    scanf(" %c", &estado2);
    getchar();

    printf("Código: ");
    fgets(codigo2, sizeof(codigo2), stdin);
    codigo2[strcspn(codigo2, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // ================================
    // Cálculos dos atributos derivados
    // ================================
    float densidade1 = populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    float densidade2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // Super Poder = População + Área + PIB + Pontos + PIB per Capita + (1 / Densidade)
    float superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);
    float superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // ================================
    // Exibição dos dados das cartas
    // ================================
    printf("\n===== Carta 1 =====\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n===== Carta 2 =====\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // ================================
    // Comparações e contagem de vitórias
    // ================================
    int vitorias1 = 0, vitorias2 = 0;

    printf("\n===== Comparação de Cartas =====\n");

    int compPop = populacao1 > populacao2;
    int compArea = area1 > area2;
    int compPib = pib1 > pib2;
    int compPontos = pontosTuristicos1 > pontosTuristicos2;
    int compDens = densidade1 < densidade2; // menor vence
    int compPibCapita = pibPerCapita1 > pibPerCapita2;
    int compSuper = superPoder1 > superPoder2;

    printf("População: Carta 1 venceu (%d)\n", compPop);
    printf("Área: Carta 1 venceu (%d)\n", compArea);
    printf("PIB: Carta 1 venceu (%d)\n", compPib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", compPontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", compDens);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", compPibCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", compSuper);

    // Contagem das vitórias
    vitorias1 = compPop + compArea + compPib + compPontos + compDens + compPibCapita + compSuper;
    vitorias2 = 7 - vitorias1; // o restante é da carta 2

    printf("\n===== Resultado Final =====\n");
    printf("Vitórias da Carta 1: %d\n", vitorias1);
    printf("Vitórias da Carta 2: %d\n", vitorias2);

    if (vitorias1 > vitorias2) {
        printf("🏆 Carta 1 venceu o duelo!\n");
    } else if (vitorias2 > vitorias1) {
        printf("🏆 Carta 2 venceu o duelo!\n");
    } else {
        printf("🤝 Empate total!\n");
    }

    return 0;
}
