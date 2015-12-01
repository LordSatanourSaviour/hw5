#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
    
    const string fname_out = "data_euler.txt"; // creating output file
    ofstream out(fname_out.c_str());
    int N=2000; // amount of steps
    
    const double dt = M_PI/100; // step size
    
    double yf[2]; //initialise arrays
    double yb[2];
    double yfn[2];
    double ybn[2];
    
    yf[0] = 1; // initial conditions
    yf[1] = 0;
    yb[0] = 1;
    yb[1] = 0;
    
    out << 0*dt << "\t" << yf[0] << "\t"  << yf[1] << "\t" << yb[0] << "\t" << yb[1] << endl; // first entry for t=0
    
    for (int i = 0; i < N; i++) {
        
        
        
         yfn[0] = yf[0] + dt * yf[1]; // forward Euler
    
         yfn[1] = yf[1] - dt * yf[0];
     
         ybn[0] = (1.0/(1.0+dt*dt)) * (yb[0] + dt * yb[1]); //backward Euler
    
         ybn[1] = (1.0/(1.0+dt*dt)) * (yb[1] - dt * yb[0]);
        
         out << (i+1)*dt << "\t" << yfn[0] << "\t"  << yfn[1] << "\t" << ybn[0] << "\t" << ybn[1] << endl; // write data to output file and append every new calculation
   
    
         yf[0] = yfn[0];
         yf[1] = yfn[1];
         yb[0] = ybn[0];
         yb[1] = ybn[1];
        
        
    
    }
    
    
    
    
    
    out.close();
    
    return 0;
}