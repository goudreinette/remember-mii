// int map(int value, int istart, int istop, int ostart, int ostop) {
//     return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
// }

float map(float value, float istart, float istop, float ostart, float ostop) {
    return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}


float lrp(float a, float b, float t) {
    return a + t * (b - a);
}
