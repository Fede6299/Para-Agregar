# Para-Agregar

• Describir en readme.md las ventajas y desventajas de
aplicar:
* for-intervalo en vez de for clásico.
* std::array<T,N> en vez de T[N].
* .at( ) en vez de [ ]

* En C++, tanto .at() como [] se utilizan para acceder a los elementos de un arreglo. La principal diferencia entre ellos es que .at() realiza una verificación de límites, lo que significa que si se intenta acceder a un elemento fuera de los límites del arreglo, se lanzará una excepción std::out_of_range. Por otro lado, [] no realiza ninguna verificación de límites y puede causar errores impredecibles si se intenta acceder a un elemento fuera de los límites del arreglo.

* En C++, tanto `std::array<T,N>` como `T[N]` se utilizan para representar arreglos de tamaño fijo. La principal diferencia entre ellos es que `std::array<T,N>` es un contenedor que encapsula una matriz de tamaño fijo, mientras que `T[N]` es una matriz de estilo C.

`std::array<T,N>` es un tipo agregado con la misma semántica que una estructura que contiene una matriz de estilo C `T[N]` como su único miembro de datos no estático. A diferencia de una matriz de estilo C, no decae a `T*` automáticamente. Como un tipo agregado, puede ser inicializado con inicialización de agregado dada a lo sumo por `N` inicializadores que son convertibles a `T`: `std::array<int, 3> a ={1, 2, 3};`. El contenedor combina el rendimiento y la accesibilidad de una matriz de estilo C con los beneficios de un contenedor estándar, como conocer su propio tamaño, admitir la asignación, iteradores de acceso aleatorio, etc. 

Por otro lado, `T[N]` es una matriz de estilo C que no tiene ninguna función miembro y se puede utilizar para representar arreglos de tamaño fijo. A diferencia de `std::array<T,N>`, se puede acceder a los elementos del arreglo utilizando un índice y no se realiza ninguna verificación de límites.

En general, si desea aprovechar las ventajas que ofrece un contenedor estándar y desea evitar errores comunes al trabajar con matrices de estilo C, debe usar `std::array<T,N>`. Si está seguro de que su programa no accederá a elementos fuera de los límites del arreglo y desea utilizar índices para acceder a los elementos del arreglo, puede usar `T[N]`.

Por lo tanto, si desea asegurarse de que su programa no acceda a elementos fuera de los límites del arreglo, debe usar .at(). Si está seguro de que su programa no accederá a elementos fuera de los límites del arreglo, puede usar [] para acceder a los elementos del arreglo.

* En C++, hay dos formas de iterar sobre los elementos de un arreglo: el **for clásico** y el **for rango**.

El **for clásico** se utiliza para iterar sobre los elementos de un arreglo utilizando un índice. Por ejemplo, si tenemos un arreglo `arr` de tamaño `n`, podemos iterar sobre sus elementos utilizando el siguiente código:

```c++
for (int i = 0; i < n; i++) {
    // Acceder al elemento arr[i]
}
```

Por otro lado, el **for rango** se utiliza para iterar sobre los elementos de un arreglo sin utilizar un índice. En su lugar, se utiliza una variable que toma el valor de cada elemento del arreglo en cada iteración. Por ejemplo, si tenemos un arreglo `arr` de tamaño `n`, podemos iterar sobre sus elementos utilizando el siguiente código:

```c++
for (auto x : arr) {
    // Acceder al elemento x
}
```

La principal diferencia entre ambos es que el **for clásico** es más flexible y permite acceder a los elementos del arreglo utilizando un índice, lo que puede ser útil en algunas situaciones. Sin embargo, también es más propenso a errores, ya que es fácil cometer errores al utilizar el índice incorrecto o al salirse de los límites del arreglo.

Por otro lado, el **for rango** es más seguro, ya que no permite acceder a los elementos del arreglo utilizando un índice y realiza una verificación de límites en tiempo de ejecución para evitar errores. Además, es más fácil de leer y escribir que el **for clásico**, lo que lo hace ideal para la mayoría de las situaciones.
