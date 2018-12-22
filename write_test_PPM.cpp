#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"

int main(){
    int nx = 200;
    int ny = 100;
    std::ofstream out_file;
    out_file.open("test_image.ppm");
    out_file << "P3\n" << nx << " " << ny << "\n255\n";
    std::stringstream data;
    for(int j = ny - 1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            float r = float(i) / nx;
            float g = float(j) / ny;
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            out_file << ir << " " << ig << " " << ib << std::endl;
            data << ir << " " << ig << " " << ib << std::endl;
        }
    } 
    out_file.close();
    //unsigned char* datastr = NULL;
    //datastr = (unsigned char*)malloc(nx*ny*3);

    //data >> datastr;
    //std::cout << data.str();
    std::string tmp = data.str();
    //datastr = tmp.c_str();
    stbi_write_png("test.png", nx, ny, 3, tmp.c_str(), 0);
    return 0;
}