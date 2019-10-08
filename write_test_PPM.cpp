#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"

int main(){
    const int nx = 200;
    const int ny = 100;
    const int chan_num = 3;
    // std::ofstream out_file;
    // out_file.open("test_image.ppm");
    // out_file << "P3\n" << nx << " " << ny << "\n255\n";

    // create array to hold data for png
    const int data_size = nx * ny * chan_num;
    unsigned char data[nx * ny * chan_num];
    int index = 0;

    for(int j = ny - 1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            float r = float(i) / nx;
            float g = float(j) / ny;
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            // out_file << ir << " " << ig << " " << ib << std::endl;
            // data << ir << " " << ig << " " << ib << std::endl;
            data[index++] = (unsigned char)(ir);
            data[index++] = (unsigned char)(ig);
            data[index++] = (unsigned char)(ib);
        }
    } 
    // out_file.close();
    //datastr = (unsigned char*)malloc(nx*ny*3);
    //data >> datastr;
    //std::cout << data.str();
    // std::string tmp = data.str();
    //datastr = tmp.c_str();
    stbi_write_png("test.png", nx, ny, chan_num, data, nx * chan_num);
    return 0;
}