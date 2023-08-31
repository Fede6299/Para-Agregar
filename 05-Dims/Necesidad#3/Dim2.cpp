#include <iostream>
#include <array>

using std::array;

array<array<unsigned, 12>, 3> totalVentasPorVendedor();

int main()
{
    array<array<unsigned, 12>, 3> resultados{totalVentasPorVendedor()};

    for (auto ventasXVendedor : resultados)
    {
        for (auto totalDelMes : ventasXVendedor)
        {
            std::cout << totalDelMes << '\t';
        }
        std::cout << '\n';
    }
}

array<array<unsigned, 12>, 3> totalVentasPorVendedor()
{
    array<array<unsigned, 12>, 3> total{};
    for (int importe, mes, vendedor; std::cin >> importe >> mes >> vendedor;)
        total.at(vendedor).at(mes) += importe;
    return total;
}
