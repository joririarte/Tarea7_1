//Menu principal
#include <iostream>
using namespace std;
int main()
{
    short int op;
    //bucle para la navegacion en el menu
    do {
        system("cls");
        cout << "-->EJERCICIO 1<--";
        cout << "\n\nMenu:\n\n";
        cout << "\n1. Cargar empleados";
        cout << "\n2. Leer y procesar datos";
        cout << "\n0. Salir";
        cout << "\n\nIngrese una opcion: ";
        cin >> op;
        switch (op) {
        case 1://carga de empleados con el programa que crea una cantidad aleatoria
            system("cls");
            cout << "--> CREAR EMPLEADOS <--\n\n";
            system("C:\\Users\\jiriartechamorro\\source\\repos\\joririarte\\Tarea7_1\\x64\\Debug\\Crear_Empleados.exe");
            cout << endl;
            system("pause");
            break;
        case 2://lectura y procesamiento de los empleados cargados
            system("cls");
            cout << "--> PROCESAR DATOS DE EMPLEADOS <--\n\n";
            system("C:\\Users\\jiriartechamorro\\source\\repos\\joririarte\\Tarea7_1\\x64\\Debug\\Procesar_Empleados.exe");
            cout << endl;
            system("pause");
            break;
        case 0://salir
            break;
        }
    } while (op != 0);
    return 0;
}
