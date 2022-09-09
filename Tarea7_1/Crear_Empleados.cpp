//Programa creacion de archivo de empleados generados aleatoriamente con sueldos aleatorios

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include<iomanip>

using namespace std;

string nombres = "C:\\Users\\JOR\\source\\repos\\Tarea7_1\\Tarea7_1\\nombres.txt";
string apellidos = "C:\\Users\\JOR\\source\\repos\\Tarea7_1\\Tarea7_1\\apellidos.txt";
string empleados = "C:\\Users\\JOR\\source\\repos\\Tarea7_1\\Tarea7_1\\empleados.dat";

struct Empleado {
    char nombre[50];
    float sueldoBasico;//oscila entre 1000 y 5000
};

void crearEmpleado(vector<string> nombres, vector<string> apellidos, vector<Empleado>& empleadosVec);
void mostrarEmpleados(vector<Empleado>& empleadosV);
void leerArchivoTxt(ifstream& fArchivo, string nombre, vector<string>& nombres);
void escribirArchivoBin(ofstream& fArchivo, string nombre, vector<Empleado>& empleadosVec);

int main()
{
    //declaracion de flujos para lectura y escritura
    ifstream f_nomAp;
    ofstream f_emp;

    //vectores para cargar los empleados
    vector<string> nomVector, apVector;
    vector<Empleado> empleadosVector;

    //semilla para numero pseudoaleatorio
    srand(time(NULL));

    leerArchivoTxt(f_nomAp, nombres, nomVector);
    leerArchivoTxt(f_nomAp, apellidos, apVector);

    cout << "Cuantos empleados quiere generar?: ";
    short int cEmpl;
    cin >> cEmpl;
    //crea y coloca 5 empleados en el vector de empleados
    for (int i = 0; i < cEmpl; i++) {
        crearEmpleado(nomVector, apVector, empleadosVector);
    }

    cout << "\n\nLos empleados generados aleatoriamente son:\n\n";
    mostrarEmpleados(empleadosVector);
    cout << endl;
    escribirArchivoBin(f_emp, empleados, empleadosVector);
    cout << "Empleados escritos en el archivo " << empleados << " exitosamente!\n\n";
    return 0;
}

//crea empleados aleatoriamente a partir de un archivo con nombres y otro de apellidos
void crearEmpleado(vector<string> nombresV, vector<string> apellidosV, vector<Empleado>& empleadosVec)
{
    Empleado empleado;
    string nomAp;

    //genera una posicion aleatoria para el vector de nombres
    int indNombre = rand() % nombresV.size();

    //genera una posicion aleatoria para el vector de apellidos
    int indApellido = rand() % apellidosV.size();

    //sueldo aleatorio
    float sueldo = (rand() % 4000 + 1001) + (rand() % 100 + 1) / 100.f;//parte entera entre 1000 y 5000 y parte decimal entre 1 y 100

    //inicializa los campos nombre y sueldoBasico
    nomAp = nombresV[indNombre] + " " + apellidosV[indApellido];
    for (int i = 0; i < 50; i++) {
        if (i < nomAp.size())
            empleado.nombre[i] = nomAp[i];
        else
            empleado.nombre[i] = '-';
    }
    empleado.sueldoBasico = sueldo;

    //coloca el empleado en empleadosVector
    empleadosVec.push_back(empleado);
}

//muestra un vector de empleados
void mostrarEmpleados(vector<Empleado>& empleadosV)
{
    cout << setw(4) << "#" << "|" << setw(26) << "Nombre" << setw(26) << "|" << setw(8) << "Sueldo" << endl;
    for (int i = 0; i < empleadosV.size(); i++) {
        cout << setw(4) << i + 1 << "|" << setw(2);
        for (int j = 0; j < 50; j++)
            cout << empleadosV[i].nombre[j];
        cout << "|" << setw(8) << empleadosV[i].sueldoBasico << endl << endl;
    }
}

//lee nombres y apellidos del archivo, y lo coloca en un vector
//el vector se usara para generar aleatoriamente empleados
void leerArchivoTxt(ifstream& fArchivo, string nombre, vector<string>& nombresV)
{
    //apertura de archivo
    fArchivo.open(nombre.c_str());
    if (fArchivo.fail()) {
        cout << "Imposible abrir el archivo " << nombre << endl;
        exit(-1);
    }

    //guarda la linea en nombreApellido y la coloca en el vector de nombres
    string nombreApellido;
    while (!fArchivo.eof()) {
        if (!fArchivo.eof()) {
            getline(fArchivo, nombreApellido);
            nombresV.push_back(nombreApellido);
        }
    }
    fArchivo.close();
}
//escribe empleados en un archivo binario
void escribirArchivoBin(ofstream& fArchivo, string nombre, vector<Empleado>& empleadosVec)
{
    fArchivo.open(nombre.c_str(), ios::binary);
    if (fArchivo.fail()) {
        cout << "Imposible abrir el archivo " << nombre << endl;
        exit(-1);
    }

    //escribe cada empleado del vector en el archivo
    for (Empleado emp : empleadosVec) {
        fArchivo.write((char*)&emp, sizeof(Empleado));
    }
    fArchivo.close();
}
