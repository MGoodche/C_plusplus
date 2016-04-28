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
