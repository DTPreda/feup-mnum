#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

double dy(double x){
  return 2.5*exp(2.5*x);
}

double f(double x){
  return sqrt(1 + pow(dy(x), 2));
}

double trapezoid(double a, double b, double h, double(*f)(double)){
  double ret = f(a) + f(b);
  for(int i = 1; i < (int)((b-a)/h); i++){ // IMPORTANTE: É ATÉ < N PORQUE ASSIM O ÚLTIMO FICA EXCLUÍDO, NUNCA É DADO O PASSO PARA B
    ret += 2*f(a + i*h);
  }
  return ret*h/2;
}

double simpson(double a, double b, double h, double (*f)(double)){
  double ret = f(a) + f(b);

  for(int i = 1; i < (int)((b-a)/h); i++){ // IMPORTANTE: É ATÉ < N PORQUE ASSIM O ÚLTIMO FICA EXCLUÍDO, NUNCA É DADO O PASSO PARA B
    if(i % 2 == 0){
      ret += 2*f(a + i*h);
    } else{
      ret += 4*f(a + i*h);
    }
  }
  return ret*h/3;
}

void show_trapezoid_table(double a, double b, double h, double (*f)(double)){
  cout << "---TRAPEZOID RULE---" << endl;

  double hh = h/2;
  double hhh = hh/2;

  double l1 = trapezoid(a, b, h, f), l2 = trapezoid(a, b, hh, f), l3 = trapezoid(a, b, hhh, f);

  cout << "L1: " << l1 << endl;
  cout << "L2: " << l2 << endl;
  cout << "L3: " << l3 << endl;

  double qc = (l2 - l1) / (l3 - l2);

  cout << "QC: " << qc << endl;

  double estimate = (l3 - l2)/3;

  cout << "Epsilon'': " << estimate << endl;
}

void show_simpson_table(double a, double b, double h, double (*f)(double)){
  cout << "---SIMPSON'S RULE---" << endl;

  double hh = h/2;
  double hhh = hh/2;

  double l1 = simpson(a, b, h, f), l2 = simpson(a, b, hh, f), l3 = simpson(a, b, hhh, f);

  cout << "L1: " << l1 << endl;
  cout << "L2: " << l2 << endl;
  cout << "L3: " << l3 << endl;

  double qc = (l2 - l1) / (l3 - l2);

  cout << "QC: " << qc << endl;

  double estimate = (l3 - l2)/3;

  cout << "Epsilon'': " << estimate << endl;
}

int main(int argv, char* argc[]){
  cout << fixed << setprecision(5);

  double a = 0, b = 1, h = 0.125;
  show_trapezoid_table(a, b, h, f);

  cout << endl;

  show_simpson_table(a, b, h, f);

  return 0;
}
