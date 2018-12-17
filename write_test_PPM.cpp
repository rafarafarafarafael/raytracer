#include <iostream>
#include <fstream>

int main(){
    int nx = 200;
    int ny = 100;
    std::ofstream out_file;
    out_file.open("test_image.ppm");
    out_file << "P3\n" << nx << " " << ny << "\n255\n";
    for(int j = ny - 1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            float r = float(i) / nx;
            float g = float(j) / ny;
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            out_file << ir << " " << ig << " " << ib << "\n";
        }
    } 
    out_file.close();
    return 0;
}