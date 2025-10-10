#include <stdio.h>
#include <math.h> 
#include <string.h>

int main()
{
    // VARIAVEIS (start_var)
    float vlr_cmb = 0, cst_abs = 0, qtd_cmb = 0, vlc_pdr = 0, vlc_real = 0, atn_pdr = 0, atn_cal = 0, temp = 0, qtd_tnq = 0, dif_vlc = 0;
    int dslc = 0, cmb_ncs = 0, cmbs = 0;
    char tip_cmb[50]; 
    // (end_var)

    // ENTRADA DE DADOS
    vlc_pdr = 80.00;                    // KM/H 
    atn_pdr = 20.00;                    // KM/L
    
    printf("\n[1] Gasolina comum");
    printf("\n[2] Álcool");
    printf("\n[3] Gasolina aditivada");
    printf("\nTipo de combustivel: ");
    scanf("%d", &cmbs);                 // Número qualquer
    
    switch (cmbs) {
        case 1:                     
            vlr_cmb = 6.50;                  
            strcpy(tip_cmb, "Gasolina comum");
            break;
        case 2: 
            vlr_cmb = 6.00;                  
            strcpy(tip_cmb, "Álcool");
            break;
        case 3:
            vlr_cmb = 7.00;                 
            strcpy(tip_cmb, "Gasolina aditivada");
            break;
        default:
            strcpy(tip_cmb, "Combustível desconhecido");
            break;
    }
    
    printf("Tempo de chegada (Horas): ");       
    scanf("%f", &temp);                 // HORAS
    
    printf("Distância até o destino (Km): ");
    scanf("%d", &dslc);                 // KM


    // REGRA DE NEGOCIO
    vlc_real = dslc / temp;             // KM/H 
    
    if (vlc_pdr > vlc_real) {
        dif_vlc  = vlc_pdr - vlc_real;  // KM/H
    } else { 
        dif_vlc  = vlc_real - vlc_pdr;  // KM/H
    } 
    
    dif_vlc  = dif_vlc  / 5;            // Número qualquer
    atn_cal = dif_vlc  / 2;             // KM/L
    
    if (atn_pdr > atn_cal) {
        atn_cal = atn_pdr - atn_cal;    // KM/L 
    } else {
        atn_cal = atn_cal - atn_pdr;    // KM/L 
    }
    
    cmb_ncs = dslc / atn_cal;           // LITRO
    
    // ENTRADA DE DADOS (cmb_ncs)
    printf("\nO combustivel necessário para chegar ao destino: %d LITRO(S)", cmb_ncs); 
    printf("\nQuantidade de gasolina no tanque (Litros): ");
    scanf("%f", &qtd_tnq);              // LITRO
    
    while (qtd_tnq > cmb_ncs) { 
        printf("\nA quantidade de gasolina no tanque não pode ser maior do que a capacidade suportada.");
        printf("\nQuantidade de gasolina no tanque (Litros): ");
        scanf("%f", &qtd_tnq);          // LITRO
    }
    
    // REGRA DE NEGOCIO (continuacao)
    qtd_cmb = qtd_tnq - cmb_ncs;        // LITRO 
    cst_abs = qtd_cmb * vlr_cmb;        // REAL

    // RESULTADOS
    printf("\n A velocidade média do veículo é: %.2f KM/H", vlc_real);
    printf("\n A autonomia do veículo é: %.2f KM/L", atn_cal);
    printf("\n O combustivel necessário para chegar ao destino é: %d LITRO(S)", cmb_ncs); 
    printf("\n O tipo de combustível do veículo é: %s", tip_cmb);
    printf("\n O preço do combustivel é: R$ %.2f", vlr_cmb);
    printf("\n A quantidade de gasolina complementar é: %.2f LITRO(S)", fabs(qtd_cmb));
    printf("\n O custo de abastecimento é: R$ %.2f ", fabs(cst_abs));
    
    return 0;
}