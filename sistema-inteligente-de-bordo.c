#include <stdio.h>

int main()
{
    // VARIAVEIS (start_var)
    float vlr_gsl = 0, cst_abs = 0, qtd_gsl = 0, vlc_med1 = 0, vlc_med2 = 0, atnm1 = 0, atnm2 = 0, temp = 0, qtd_tnq = 0;
    int dslc = 0, cap_tnq = 0;
    // (end_var)

    //ENTRADA DE DADOS
    vlr_gsl = 6.50;     //REAL
    cst_abs = 78.00;    //REAL
    qtd_gsl = 3.00;     //LITRO
    vlc_med1 = 80.00;    //KM/H
    atnm1 = 20.00;       //KM/L
    temp = 1.5;         //HORAS
    qtd_tnq = 3.00;     //LITRO
    dslc = 210;         //KM
    cap_tnq = 15;       //LITRO

    //REGRA DE NEGOCIO
    vlc_med2 = dslc / temp;             //KM/H
    vlc_med1 = vlc_med2 - vlc_med1;     //KM/H
    vlc_med1 = vlc_med1 / 5;            //Número qualquer
    
    atnm2 = vlc_med1 / 2;               //KM/L
    atnm2 = atnm1 - atnm2;              //KM/L
    
    cap_tnq = dslc / atnm2;             //LITRO
    qtd_gsl = qtd_tnq - cap_tnq;        //LITRO
    
    cst_abs = qtd_gsl * vlr_gsl;        //REAL

    //RESULTADOS
    
}