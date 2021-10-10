#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"
#include "vec3.h"

int main(){
    const int nx = 200;
    const int ny = 100;
    const int chan_num = 3;

    // create array to hold data for png
    const int data_size = nx * ny * chan_num;
    unsigned char data[nx * ny * chan_num];
    int index = 0;

    for(int j = ny - 1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            vec3 rgb = vec3(i, j, 0.2);
            rgb /= vec3(float(nx), float(ny), float(1));
            int ir = int(255.99 * rgb.r());
            int ig = int(255.99 * rgb.g());
            int ib = int(255.99 * rgb.b());

            data[index++] = (unsigned char)(ir);
            data[index++] = (unsigned char)(ig);
            data[index++] = (unsigned char)(ib);
        }
    } 

    stbi_write_png("test.png", nx, ny, chan_num, data, nx * chan_num);
    return 0;
}