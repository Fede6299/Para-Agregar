#include <iostream>
#include <array>

using std::array;

/*
Necesidad #4: Dado los importes, meses, números de los tres vendedores, y
números de las cuatro regiones (0, 1, 2, 4), mostrar total de ventas por mes,
vendedor, y región.
*/

array<array<array<int, 12>, 3>, 4> programa();

int main()
{
    array<array<array<int, 12>, 3>, 4> resultado{programa()};

    for (auto totalDeLaRegion : resultado)
    {
        for (auto ventasXVendedor : totalDeLaRegion)
        {
            for (auto totalDelMes : ventasXVendedor)
            {
                std::cout << totalDelMes << '\t';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

array<array<array<int, 12>, 3>, 4> programa()
{
    array<array<array<int, 12>, 3>, 4> total{};
    for (int numeroZona, numeroVendedor, mes, importe; std::cin >> importe >> mes >> numeroVendedor >> numeroZona;)
        total.at(numeroZona).at(numeroVendedor).at(mes) += importe;
    return total;
}
