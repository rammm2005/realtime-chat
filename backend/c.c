#include <stdio.h>
#include <stdlib.h>

// Definisikan struct untuk kubus
struct CubeStruct
{
    double side;
    double surfaceArea;
    double volume;
};

// Definisikan union yang memiliki field untuk kubus
union CubeUnion
{
    double side;
    struct
    {
        double surfaceArea;
        double volume;
    };
};

int main()
{
    struct CubeStruct cubeStruct;
    union CubeUnion cubeUnion;

    // Input sisi untuk kubus
    printf("Masukkan sisi untuk kubus: ");
    scanf("%lf", &cubeStruct.side);
    cubeUnion.side = cubeStruct.side; // Menyimpan nilai sisi ke dalam union

    // Menghitung luas permukaan dan volume kubus menggunakan struct dan union
    cubeStruct.surfaceArea = 6 * cubeStruct.side * cubeStruct.side;
    cubeStruct.volume = cubeStruct.side * cubeStruct.side * cubeStruct.side;

    cubeUnion.surfaceArea = 6 * cubeUnion.side * cubeUnion.side;
    cubeUnion.volume = cubeUnion.side * cubeUnion.side * cubeUnion.side;

    // Menampilkan hasil dan ukuran memori yang digunakan oleh struct dan union
    printf("\nKubus menggunakan struct:\n");
    printf("Sisi: %.2f\n", cubeStruct.side);
    printf("Luas permukaan: %.2f\n", cubeStruct.surfaceArea);
    printf("Volume: %.2f\n", cubeStruct.volume);

    printf("\nKubus menggunakan union:\n");
    printf("Sisi: %.2f\n", cubeUnion.side);
    printf("Luas permukaan: %.2f\n", cubeUnion.surfaceArea);
    printf("Volume: %.2f\n", cubeUnion.volume);

    printf("Ukuran memori struct: %zu bytes\n", sizeof(struct CubeStruct));
    printf("Ukuran memori union: %zu bytes\n", sizeof(union CubeUnion));
    return 0;
}