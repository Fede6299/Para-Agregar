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

enum Region {norte, este, sur, oeste, error};

/* --------------------------------------------------------- */

dimensionTres leerDatos();
void mostarTotales(dimensionTres);
Region conversorRegion(string);
int conversorVendedor(string);
void Maximo(dimensionTres);
void Minimo(dimensionTres);
void Promedio(dimensionTres);

/* --------------------------------------------------------- */

int main()
{
    dimensionTres total{leerDatos()};
    mostarTotales(total);
    Maximo(total);
    Minimo(total);
    Promedio(total);
}

dimensionTres leerDatos()
{
    dimensionTres informe{};
    string region, vendedor;

    for (int mes, importe; std::cin >> importe >> mes >> vendedor >> region;)
        informe.at(conversorRegion(region)).at(conversorVendedor(vendedor)).at(mes) += importe;
    return informe;
}

/* --------------------------------------------------------- */

Region conversorRegion(string nombreZona)
{
    if (nombreZona == "Norte"s)
        return norte;
    if (nombreZona == "Este"s)
        return este;
    if (nombreZona == "Sur"s)
        return sur;
    if (nombreZona == "Oeste"s)
        return oeste;
    return error;
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

void Maximo(dimensionTres max)
{
    {
        int indexRegion{};
        int maxRegion{};
        for (int region = 0; region < 4; region++)
        {
            int totalRegion{};
            for (int vendedor = 0; vendedor < 3; vendedor++)
            {
                for (int mes = 0; mes < 12; mes++)
                {
                    totalRegion += max.at(region).at(vendedor).at(mes);
                }
                cout << '\n';
            }
            cout << "Total de la region " << region << ": " << totalRegion;

            if (totalRegion > maxRegion)
            {
                maxRegion = totalRegion;
                indexRegion = region;
            }
        }
        cout << "\n"
             << "Region con mas ventas: " << indexRegion << ": con $ " << maxRegion;
    }
}

/* --------------------------------------------------------- */

void Minimo(dimensionTres Min)
{
    {
        int indexRegion{};
        int minRegion{};
        for (int region = 0; region < 4; region++)
        {
            int totalRegion{};
            for (int vendedor = 0; vendedor < 3; vendedor++)
            {
                for (int mes = 0; mes < 12; mes++)
                {
                    totalRegion += Min.at(region).at(vendedor).at(mes);
                }
                cout << '\n';
            }
            cout << "Total de la region " << region << ": " << totalRegion;

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
             << "Region con menos ventas: " << indexRegion << ": con $ " << minRegion;
    }
}

/* --------------------------------------------------------- */

void Promedio(dimensionTres Prom)
{
    {
        int totalRegion{};
        for (int region = 0; region < 4; region++)
        {
            for (int vendedor = 0; vendedor < 3; vendedor++)
            {
                for (int mes = 0; mes < 12; mes++)
                {
                    totalRegion += Prom.at(region).at(vendedor).at(mes);
                }
                cout << '\n';
            }
            cout << "Total de la region " << region << ": " << totalRegion;
        }
        cout << "\n"
             << "Promedio por regiones redondeado: " << totalRegion / 4;
    }
}
