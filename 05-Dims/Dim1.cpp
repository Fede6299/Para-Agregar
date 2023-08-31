#include <iostream>
#include <array>

using std::array;

/* Necesidad #2: Dado los importes y meses (de 0 a 11), mostrar ventas totales
por mes. */

array<int, 12> totalVentasPorMes(); // declaracion de la funcion que calcula el total de ventas segun mes

int main()
{
    array<int, 12> resultados{totalVentasPorMes()};

    for (auto totalDelMes : resultados)
        std::cout << totalDelMes << '\n';
}

array<int, 12> totalVentasPorMes()
{ // definicion de la funcion
    array<int, 12> total{};
    for (int importe, mes; std::cin >> importe >> mes;)
        total.at(mes - 1) += importe;
    return total;
}
