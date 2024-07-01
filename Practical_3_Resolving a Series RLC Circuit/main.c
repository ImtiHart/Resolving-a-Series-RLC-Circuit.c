#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Initialize components of the code
float Xc, Xl, X, f, c, L, Z, sum, R, Irms, Vs, Z, VR, VL, VC, P, fR, L;
char choice;

int main()
{
    //Alow user to input what to calculate
    printf("A 40μF capacitor is in series with 100mH inductor, a 30ohm resistor,\nand a 15V AC signal with a frequency of 60Hz.\nWrite a C program utilizing your knowledge of functions to perform the following operations:\n");
    printf("Choose what you would like to calculate: \n a-Capacitive reactance \n b-inductive reactance \n c-impedance \n d-rms current \n e-voltage across resistor \n f-voltage across inductor \n g-voltage across capacitor \n h-power consumed in circuit \n i-resonant frequency of circuit.\n");
    printf("What would you like to calculate, choose the letter associated with it? ");
    scanf("%c", &choice);
    //Create choices of what to calculate
    switch(choice)
    {
    case 'a':
        c_reactant();
        break;
    case 'b':
        i_reactants();
        break;
    case 'c':
        impedance();
        break;
    case 'd':
        rms_I();
        break;
    case 'e':
        V_R();
        break;
    case 'f':
        V_L();
        break;
    case 'g':
        V_C();
        break;
    case 'h':
        Power();
        break;
    case 'i':
        Frequency();
        break;
    }

}

//Create functions for the different operations to calulate the 'choice' of user
void c_reactant()
{
    printf("\nWhat is the value of AC frequency and capacitance?");
    scanf("%f %f", &f, &c);
    Xc=1/(2*3.141592654*f*c);
    printf("\nCapacitive reactance: %.2fOhms", Xc);
    return Xc;
}
void i_reactants()
{
    printf("\nWhat is the value of AC frequency and inductance?");
    scanf("%f %f", &f, &L);
    Xl= 2*3.141592654*f*L;
    printf("\nInductive reactance: %.2fOhms", Xl);
    return Xl;
}
void impedance()
{
    c_reactant();
    i_reactants();
    printf("\nWhat is the value of resistance?");
    scanf("%f", &R);
    X= Xl-Xc;
    sum= (pow(R, 2))+ pow(X, 2);
    Z= sqrt(sum);
    printf("\nImpedance: %.2fOhms", Z);
    return Z;
}

void rms_I()
{
    impedance();
    printf("\nWhat is the value of the voltage of the source?");
    scanf("%f", &Vs);
    Irms=Vs/Z;
    printf("\nRms current: %.2fA", Irms);
    return Irms;
}

void V_R()
{
    rms_I();
    printf("\nWhat is the value of resistance?");
    scanf("%f", &R);
    VR=Irms*R;
    printf("\nVoltage across resistor: %.2fV", VR);
    return VR;
}

void V_L()
{
    i_reactants();
    rms_I();
    VL=Xl*Irms;
    printf("\nVoltage across inductor: %.2fV", VL);
    return VL;
}

void V_C()
{
    c_reactant();
    rms_I();
    VC=Xc*Irms;
    printf("\nVoltage across capacitor: %.2fV", VC);
    return VC;
}

void Power()
{
    rms_I();
    printf("\nWhat is the value of resistance?");
    scanf("%f", &R);
    P=(pow(Irms, 2))*R;
    printf("\nPower consumed in circuit: %.2fW", P);
    return P;
}

void Frequency()
{
    printf("\nWhat is the value of inductance and capacitance?");
    scanf("%f %f", &L, &c);
    fR=1/(2*3.141592654*(sqrt(L*c)));
    printf("\nResonant frequency of circuit: %.2fHz", fR);
    return fR;
}

