```c++
#include <iostream>
#include <array>
#include <string>

/* --------------------------------------------------------- */

using std::array;
using std::cout;
using namespace std::literals;
using std::string;
using dimensionTres = array<array<array<int, 12>, 3>, 4>;

/* --------------------------------------------------------- */

enum struct Regiones{norte, este, sur, oeste, error};

 enum struct Temporada{primavera, verano, otoño, invierno};

/* --------------------------------------------------------- */

dimensionTres leerDatos();
void mostarTotales(dimensionTres);
Regiones conversorRegion(string);
int conversorVendedor(string);
void Maximo(dimensionTres);
void Minimo(dimensionTres);
void Promedio(dimensionTres);
int TotalRegion(dimensionTres, int);
int conversionDeEnumAlInt(Regiones , string);

/* --------------------------------------------------------- */

int main()
{
    mostarTotales(leerDatos());
    Maximo(leerDatos());
    Minimo(leerDatos());
    Promedio(leerDatos());
}

dimensionTres leerDatos()
{
    dimensionTres informe{};
    string region, vendedor;
    Regiones zonas;
    for (int mes, importe; std::cin >> importe >> mes >> vendedor >> region;)
        informe.at(conversionDeEnumAlInt(zonas, region)).at(conversorVendedor(vendedor)).at(mes) += importe;
    return informe;
}

/* --------------------------------------------------------- */

Regiones conversorRegion(string nombreZona)
{
    if (nombreZona == "Norte"s)
        return Regiones::norte;
    if (nombreZona == "Este"s)
        return Regiones::este;
    if (nombreZona == "Sur"s)
        return Regiones::sur;
    if (nombreZona == "Oeste"s)
        return Regiones::oeste;
    return Regiones::error;
}

/* --------------------------------------------------------- */

int conversionDeEnumAlInt(Regiones region, string nombreZona)
{
        if(Regiones::norte == conversorRegion(nombreZona))
            return 0;
        if(Regiones::este == conversorRegion(nombreZona))
            return 1;
        if(Regiones::sur == conversorRegion(nombreZona))
            return 2;
        if(Regiones::oeste == conversorRegion(nombreZona))
            return 3;
        return 9;    
}

/* --------------------------------------------------------- */

int conversorVendedor(string nombreVendedor)
{
    if (nombreVendedor == "Pablo"s)
        return 0;
    if (nombreVendedor == "Victor"s)
        return 1;
    if (nombreVendedor == "Federico"s)
        return 2;
    return 9;
}

/* --------------------------------------------------------- */

void mostarTotales(dimensionTres informe)
{
    cout << "__________________________________________________________________________________________________________________________________________________" << '\n';
    for (int region{1}; auto vendedoresPorRegion : informe)
    {
        cout << "| REGION " << region++ << " :|\n";
        cout << "|___________|"
             << "\n";
        for (int vendedor{1}; auto mesesPorVendedor : vendedoresPorRegion)
        {
            cout << " ___________" << '\n';
            cout << "|VENDEDOR " << vendedor++ << ":|\n";
            cout << "|___________|" << '\n'
                 << '\n';
            for (int meses{1}; auto ventasPorMes : mesesPorVendedor)
            {
                cout << "| mes " << meses++ << ": " << ventasPorMes << "  ";
            }
            cout << '\n';
        }
        cout << "__________________________________________________________________________________________________________________________________________________" << '\n';
    }
}

/* --------------------------------------------------------- */

int TotalRegion(dimensionTres datos, int region)
{
    int totalRegion{};

    for (int vendedor{}; vendedor < 3; vendedor++)
    {
        for (int mes{}; mes < 12; mes++)
        {
            totalRegion += datos.at(region).at(vendedor).at(mes);
        }
    }
    return totalRegion;
}

/* --------------------------------------------------------- */
void Maximo(dimensionTres Max)
{
    int indexRegion{};
    int maxRegion{};

    for (int region{}; region < 4; region++)
    {
        int totalRegion = TotalRegion(Max, region);
        cout << "Total de la region " << region << ": " << totalRegion;

        if (totalRegion > maxRegion)
        {
            maxRegion = totalRegion;
            indexRegion = region;
        }
        cout << "\n";
    }
    cout << "\n"
         << "La region con mas ventas es " << indexRegion << " con $ " << maxRegion;
}

/* --------------------------------------------------------- */

void Minimo(dimensionTres Min)
{
    int indexRegion{};
    int minRegion{};

    for (int region{}; region < 4; region++)
    {
        int totalRegion = TotalRegion(Min, region);
        if (totalRegion < minRegion)
        {
            minRegion = totalRegion;
            indexRegion = region;
        }

        if (region == 0)
        {
            minRegion = totalRegion;
        }
    }
    cout << "\n"
         << '\n'
         << "La region con menos ventas es " << indexRegion << " con $ " << minRegion;
}

/* --------------------------------------------------------- */

void Promedio(dimensionTres Prom)
{   
    int totalRegiones{};
    for (int region{}; region < 4; region++)
    {
    totalRegiones += TotalRegion(Prom, region);
    }
    cout << "\n"
         << '\n'
         << "Promedio por regiones redondeado $ " << totalRegiones / 4;
}
```