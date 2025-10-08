#include <stdio.h>
#include <math.h> 
#include <string.h>

int main()
{
    // VARIAVEIS (start_var)
    float vlr_cmb = 0, cst_abs = 0, qtd_gsl = 0, vlc_med1 = 0, vlc_med2 = 0, atnm1 = 0, atnm2 = 0, temp = 0, qtd_tnq = 0, valor_combustivel = 0;
    int dslc = 0, cap_tnq = 0, combustivel = 0;
    
    // (end_var)

    //ENTRADA DE DADOS
    vlc_med1 = 80.00;                   //KH
    atnm1 = 20.00;                      //KM/L
    //qtd_gsl = 12.00;                  //LITRO
    //cst_abs = 78.00;                  //REAL
    //cap_tnq = 15;                     //LITRO
    
    printf("\n[1] gasolina comum");
    printf("\n[2] álcool");
    printf("\n[3] gasolina aditivada");
    printf("\nTipo de combustivel: ");
    scanf("%d", &combustivel);              
    switch (combustivel) {
        case 1:
        vlr_cmb = 4.60;
        break;
        case 2: 
        vlr_cmb = 4.00;
        break;
        case 3:
        vlr_cmb = 5.00;
        break;
    }
    
    //vlr_cmb = 6.50;                   //REAL
    
    //qtd_tnq = 3.00;                   //LITRO
    printf("Tempo de chegada: ");
    scanf("%f", &temp);                 //HORAS
    //temp = 1.5;                       //HORAS
    printf("Distância até o destino: ");
    scanf("%d", &dslc);                 //KM
    //dslc = 210;                       //KM

    //REGRA DE NEGOCIO
    vlc_med2 = dslc / temp;             //KM/H
    if (vlc_med1 > vlc_med2) {
    vlc_med1 = vlc_med1 - vlc_med2;     //KM/H
    } else { 
    vlc_med1 = vlc_med2 - vlc_med1;     //KM/H
    } 
    vlc_med1 = vlc_med1 / 5;            //Número qualquer
    
    atnm2 = vlc_med1 / 2;               //KM/L
    if (atnm1 > atnm2) {
    atnm2 = atnm1 - atnm2;              //KM/L
    } else {
    atnm2 = atnm2 - atnm1;  
    }
    
    cap_tnq = dslc / atnm2;             //LITRO
    printf("\nA capacidade do tanque é: %d", cap_tnq);
    printf("\nQuantidade de gasolina no tanque: ");
    scanf("%f", &qtd_tnq);              //LITRO
    
    while (qtd_tnq > cap_tnq) {
    printf("\nA quantidade de gasolina no tanque não pode ser maior do que a capacidade suportada.");
    printf("\nQuantidade de gasolina no tanque: ");
    scanf("%f", &qtd_tnq);              //LITRO
    }
    
    qtd_gsl = qtd_tnq - cap_tnq;        //LITRO
    
    cst_abs = qtd_gsl * vlr_cmb;        //REAL

    //RESULTADOS
    printf("\n A velocidade média do veículo é: %.2f KM/H", vlc_med2);
    printf("\n A autonomia do veículo é: %.2f KM/L", atnm2);
    printf("\n A capacidade do tanque é: %d LITRO(S)",cap_tnq);
    printf("\n O preço do combustivel é: R$ %.2f", vlr_cmb);
    printf("\n A quantidade de gasolina complementar é: %.2f LITRO(S)", fabs(qtd_gsl));
    printf("\n O custo de abastecimento é: R$ %.2f ", fabs(cst_abs));
    
    return 0;
}