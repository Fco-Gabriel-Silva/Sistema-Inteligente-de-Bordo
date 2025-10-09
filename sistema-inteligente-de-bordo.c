#include <stdio.h>
#include <math.h> 
#include <string.h>

int main()
{
    // VARIAVEIS (start_var)
    float vlr_cmb = 0, cst_abs = 0, qtd_gsl = 0, vlc_med = 0, atnm_calc = 0, vlc_med1 = 0, vlc_med2 = 0, atnm = 0, atnm1 = 0, atnm2 = 0, temp = 0, qtd_tnq = 0;
    int dslc = 0, cmb_ncs = 0, cmbs = 0;
    char comb[50]; 
    // (end_var)

    //ENTRADA DE DADOS
    vlc_med = 80.00;                     //KM/H 
    atnm = 20.00;                        //KM/L
    
    printf("\n[1] gasolina comum");
    printf("\n[2] álcool");
    printf("\n[3] gasolina aditivada");
    printf("\nTipo de combustivel: ");
    scanf("%d", &cmbs);          //Número qualquer
    
    switch (cmbs) {
    case 1:                     
        vlr_cmb = 6.50;                  
        strcpy(comb, "Gasolina comum");
        break;
    case 2: 
        vlr_cmb = 6.00;                  
        strcpy(comb, "Álcool");
        break;
    case 3:
        vlr_cmb = 7.00;                 
        strcpy(comb, "Gasolina aditivada");
        break;
    default:
        strcpy(comb, "Combustível desconhecido");
        break;
}
    
    printf("Tempo de chegada (Horas): ");       
    scanf("%f", &temp);                  //HORAS
    
    printf("Distância até o destino (Km): ");
    scanf("%d", &dslc);                  //KM


    //REGRA DE NEGOCIO
    vlc_med1 = dslc / temp;              //KM/H 
    if (vlc_med1 > vlc_med) {
    vlc_med2 = vlc_med1 - vlc_med;       //KM/H
    } else { 
    vlc_med2 = vlc_med - vlc_med1;       //KM/H
    } 
    
    atnm_calc = vlc_med2 / 5;            //Número qualquer
    
    atnm1 = atnm_calc / 2;               //KM/L
    if (atnm > atnm1) {
    atnm2 = atnm - atnm1;               //KM/L 
    } else {
    atnm2 = atnm1 - atnm;              //KM/L 
    }
    
    cmb_ncs = dslc / atnm2;             //LITRO
    printf("\nO combustivel necessário para chegar ao destino: %d LITRO(S)", cmb_ncs); 
    printf("\nQuantidade de gasolina no tanque (Litros): ");
    scanf("%f", &qtd_tnq);              //LITRO
    
    while (qtd_tnq > cmb_ncs) { 
    printf("\nA quantidade de gasolina no tanque não pode ser maior do que a capacidade suportada.");
    printf("\nQuantidade de gasolina no tanque (Litros): ");
    scanf("%f", &qtd_tnq);              //LITRO
    }
    
    qtd_gsl = qtd_tnq - cmb_ncs;        //LITRO 
    
    cst_abs = qtd_gsl * vlr_cmb;        //REAL

    //RESULTADOS
    printf("\n A velocidade média do veículo é: %.2f KM/H", vlc_med1);
    printf("\n A autonomia do veículo é: %.2f KM/L", atnm1);
    printf("\n O combustivel necessário para chegar ao destino é: %d LITRO(S)",cmb_ncs); 
    printf("\n O tipo de combustível do veículo é: %s", comb);
    printf("\n O preço do combustivel é: R$ %.2f", vlr_cmb);
    printf("\n A quantidade de gasolina complementar é: %.2f LITRO(S)", fabs(qtd_gsl));
    printf("\n O custo de abastecimento é: R$ %.2f ", fabs(cst_abs));
    
    return 0;
}