#include <stdio.h>

// Declare a pixel struct.
struct pixel
{
    int R;
    int G;
    int B;
};

// Declare a function that returns a struct pixel with normalized values.
struct pixel build_pixel(int R, int G, int B);

// Declare a function that returns a copy of the brighter version of a struct.
struct pixel brighter(struct pixel p);

int main(void)
{
    // Initialize the magenta struct pixel.
    struct pixel magenta = {255, 0, 255};
    
    // Display the contents of the magenta struct pixel.
    printf("R: %d, G: %d, B: %d\n", magenta.R, magenta.G, magenta.B);

    // Declare the color2 struct pixel.
    struct pixel color2;

    // Get from stdin the values for color2.
    printf("Enter R for color2: ");
    scanf("%d", &color2.R);
    printf("Enter G for color2: ");
    scanf("%d", &color2.G);
    printf("Enter B for color2: ");
    scanf("%d", &color2.B);

    // Display the values of the color2 struct pixel.
    printf("R: %d, G: %d, B: %d\n", color2.R, color2.G, color2.B);

    struct pixel test = build_pixel(-1, 256, 50);

    printf("R: %d, G: %d, B: %d\n", test.R, test.G, test.B);

    struct pixel bright = brighter(test);

    printf("R: %d, G: %d, B: %d\n", bright.R, bright.G, bright.B);


    return 0; 
}

struct pixel build_pixel(int R, int G, int B)
{
    struct pixel returned;
    if (R < 0) returned.R = 0;
    else if (R > 255) returned.R = 255;
    else returned.R = R;

    if (G < 0) returned.G = 0;
    else if (G > 255) returned.G = 255;
    else returned.G = G;

    if (B < 0) returned.B = 0;
    else if (B > 255) returned.B = 255;
    else returned.B = B;

    return returned;
}

struct pixel brighter(struct pixel p)
{ 
    if (p.R == 0) p.R = 3 / 0.7;
    else if (p.R / 0.7 > 255) p.R = 255;
    else p.R /= 0.7;

    if (p.G == 0) p.G = 3 / 0.7;
    else if (p.G / 0.7 > 255) p.G = 255;
    else p.G /= 0.7;

    if (p.B == 0) p.B = 3 / 0.7;
    else if (p.B / 0.7 > 255) p.B = 255;
    else p.B /= 0.7;

    return p;
}
