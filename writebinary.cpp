template<class T>
bool escribe_binario(string file, T dato)
{
ofstream f;
f.open(file.c_str(),ios::out|ios::binary);
if(!f.is_open())
return false;
f.write((char*)&dato, sizeof(dato));
//f.write(reinterpret_cast <char *>(&dato), sizeof(dato));
f.close();
return true;
}
