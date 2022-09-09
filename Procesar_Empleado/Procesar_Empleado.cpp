//Lee un archivo de empleados y procesa la informacion

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//ruta al archivo
string nArchivo = "C:\\Users\\JOR\\source\\repos\\Tarea7_1\\Tarea7_1\\empleados.dat";

struct Empleado {
    char nombre[50];
    float sueldoBasico;//oscila entre 1000 y 5000
};

void leerArchivoEmp(ifstream& fArchivo, string nombre, vector<Empleado>& empleados);
void mostrarEmpleados(vector<Empleado>& empleadosV);

int main()
{
    ifstream f_emp;
    vector<Empleado> empleados;
    //cat1 sueldo entre 1000 y 2000
    //cat2 sueldo entre 2001 y 3000
    //cat3 sueldo mayor a 3000
    int cat1 = 0, cat2 = 0, cat3 = 0;

    //almacenaran los montos de cada categoria
    float mCat1 = 0.f, mCat2 = 0.f, mCat3 = 0.f;

    leerArchivoEmp(f_emp, nArchivo, empleados);
    cout << "\nLista de Empleados\n\n";
    mostrarEmpleados(empleados);
    //procesa la informacion de los empleados
    for (Empleado emp : empleados) {
        if (emp.sueldoBasico <= 2000) {
            cat1++;
            mCat1 += emp.sueldoBasico;
        }
        else if (emp.sueldoBasico > 2000 && emp.sueldoBasico <= 3000) {
            cat2++;
            mCat2 += emp.sueldoBasico;
        }
        else {
            cat3++;
            mCat3 += emp.sueldoBasico;
        }
    }
    cout << "\n\n\n-->DATOS IMPORTANTES<--";
    cout << "\n\nCantidad de empleados de la Categoria 1 (1000 a 2000): " << cat1;
    cout << "\nLa categoria 1 se lleva un presupuesto de: " << mCat1;
    cout << "\n\nCantidad de empleados de la Categoria 2 (2001 a 3000): " << cat2;
    cout << "\nLa categoria 2 se lleva un presupuesto de: " << mCat2;
    cout << "\n\nCantidad de empleados de la Categoria 3 (+3000): " << cat3;
    cout << "\nLa categoria 3 se lleva un presupuesto de: " << mCat3<<endl<<endl;
    return 0;
}

void leerArchivoEmp(ifstream& fArchivo, string nombre, vector<Empleado>& empleados)
{
    //apertura del archivo
    fArchivo.open(nombre.c_str(), ios::binary);
    if (fArchivo.fail()) {
        cout << "Imposible abrir archivo " << nombre << endl;
        exit(-1);
    }

    //se obtiene el tamaño del archivo
    fArchivo.seekg(0, ios::end);
    unsigned long int final = fArchivo.tellg(), actual;
    
    //se ubica el cursor de lectura al principio del archivo para leer
    fArchivo.seekg(0, ios::beg);
    
    //struct donde se colocara cada empleado leido
    Empleado emp;
    
    //lectura de todo el archivo
    do {
        fArchivo.read((char*)&emp, sizeof(Empleado));
        
        //coloca cada empleado en el vector
        empleados.push_back(emp);

        //obtiene la posicion actual despues de haber leido el empleado
        actual = fArchivo.tellg();
    } while (actual < final);

    fArchivo.close();
}

//muestra un vector de empleados
void mostrarEmpleados(vector<Empleado>& empleadosV)
{
    cout <<setw(4)<< "#" << "|" <<setw(26)<< "Nombre" <<setw(26) <<"|"<<setw(8)<< "Sueldo" << endl;
    for (int i = 0; i < empleadosV.size(); i++) {
        cout << setw(4) << i + 1 << "|" << setw(2);
        for (int j = 0; j < 50; j++)
            cout << empleadosV[i].nombre[j];
        cout<< "|" << setw(8) << empleadosV[i].sueldoBasico<<endl<<endl;
    }
}
