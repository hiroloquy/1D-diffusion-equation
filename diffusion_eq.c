#include<stdio.h>
#include<math.h>

#define L 200.0             // Width
#define Nx 4000             // Number of divisions along the x-axis
#define Nt 550              // Number of data
#define dx 2 * L / Nx       // x increase
#define dt 20.0             // increase in t
#define D 10.0              // Diffusion coefficient
#define C0 10.0             // Initial value of concentration
#define PI 3.1415           // Pi
#define LOOP 10 // Diffusion source 2 * LOOP + 1

double f(double x,double t){
    double A = 2 * sqrt ( D * t ); // denominator of erf argument
    double c = 0 ; // concentration
    int i ; // counter

    // i = -sigma calculation from LOOP to LOOP
    for(i=-LOOP; i<=LOOP; i++){
        c += C0 *( erf((x-4*i*L)/A)- erf((x-(4*i+2)*L)/A))/2;
    }

    return c;
}

int main(void){
    double c , x , t ; // density, x coordinate, time t
    int i , j ; // x, t counter
    char filename[10];
    FILE*fp;

    for(i=0; i<=Nt; i++){
        sprintf(filename,"%03d.dat", i);

        /*t=0----------------------------------------------*/
        if(i==0){
            t = 0.00001 ; // Infinitely zero
            x =-L-(double)dx;
            fp = fopen(filename,"w");

            for(j=0; j<=Nx; j++){
                x +=(double)dx;
                if(x <0){
                    c=0.0;
                }else{
                    c = C0;
                }
                fprintf(fp,"%.4f  %5.3f  %5.3f\n", x, c,(double)C0-c);
            }
            fclose(fp);
            t =0;
        }else{

        /*t>0----------------------------------------------*/
            t += dt;
            x =-L-(double)dx;
            fp = fopen(filename,"w");
            for(j=0; j<=Nx; j++){
                x +=(double)dx;
                fprintf(fp,"%.4f   %5.3f   %5.3f\n", x, f(x, t), f(-x, t));
            }
            fclose(fp);
        }
    }
}