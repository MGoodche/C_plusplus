class Polinomio {
// polinomio cout:= a[n-1]x^(n-1) + ... + a[0]
public:
Polinomio();
Polinomio(int g, double *c);
Polinomio(double c);
void SetValue(int i, double c);
void SetValue(int g, double *c);
Polinomio operator +(const Polinomio& p);
double operator [](double x);
friend std::istream& operator>> (std::istream& in, Polinomio& p);
friend std::ostream& operator<< (std::ostream& out, const Polinomio& p);
private:
int grado;
double *coef;
};

Polinomio Polinomio::operator +(const Polinomio& p){
double *c;
if(this->grado>p.grado){
c = new double[this->grado+1];
for (int i = 0; i <= p.grado; i++ )
c[i] = this->coef[i] + p.coef[i];
for (int i = p.grado+1; i <= this->grado; i++)
c[i] = this->coef[i];
return Polinomio(this->grado, c);
}else {

c = new double[p.grado+1];
for (int i = 0; i <= this->grado; i++ )
c[i] = this->coef[i] + p.coef[i];
for (int i = this->grado+1; i <= p.grado; i++)
c[i] = p.coef[i];
return Polinomio(p.grado, c);
}
}

double Polinomio::operator [](double x){
double eval = this->coef[0];
double cof;
for (int i = 1; i <= grado; i++){
cof = this->coef[i];
for(int j = 0; j < i; j++)
cof = cof*x;
eval += cof;
}
return eval;
