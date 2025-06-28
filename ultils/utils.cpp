#include "utils.h"
#include <cmath>

float calcularDistanciaEuclidiana(Local v1, Local v2) {
    float dx = v2.getCoordenadaX() - v1.getCoordenadaX();
    float dy = v2.getCoordenadaY() - v1.getCoordenadaY();
    return sqrt(dx * dx + dy * dy);
}