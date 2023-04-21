
#ifndef CARGARCLIENTESMEMORIA_H
#define CARGARCLIENTESMEMORIA_H

#include <fstream>
#include <list>
using namespace std;

struct Cliente {
    int codigo;
    string nombre;
    int prioridad;
};

void LeerClientes(list<Cliente>& listaClientes) {
    ifstream archivo("../Clientes.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo clientes\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        Cliente cliente;
        istringstream iss(linea);
        iss >> cliente.codigo;
        iss.ignore();
        getline(iss, cliente.nombre, '\t');
        iss >> cliente.prioridad;
        listaClientes.push_back(cliente);
    }

    archivo.close();
}

#endif // CARGARCLIENTESMEMORIA_H
