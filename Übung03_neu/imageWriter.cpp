#include <iostream>
#include <sstream>
#include <vector>

#include "CImg.h"
using namespace cimg_library;

typedef unsigned long long ptr_type;

class WriteImage {
public:
  WriteImage(const char *filename, int columns, int rows)
      : image(columns, rows, 1, 1, 0), filename(filename), curCol(0), curRow(0),
        columns(columns), rows(rows) {}

  ~WriteImage() {
    image.save(filename.c_str());
  }

  void putPixel(char pixel) {
    int ptr = pixel;

    image(curCol, curRow, 0, 0) = pixel;

    if (++curCol >= columns) {
      curCol = 0;
      if (++curRow >= rows)
        curRow = 0;
    }
  }

  void write_padded_image() {
    CImg<unsigned char> img_new(columns + 2, rows + 2, 1, 1, 0xFF);
    std::cout << image.width() << " " << image.height() << std::endl;
    for (int y = 1; y <= image.height(); y++) {
      for (int x = 1; x <= image.width(); x++) {
        img_new(x, y, 0, 0) = image(x-1, y-1, 0, 0);
      }
    }

    std::string basename = filename.substr(0, filename.find(".png"));
    std::stringstream s;
    s << basename;
    s << "_padded.png";
    img_new.save(s.str().c_str());
    std::cout << "Saved padded image" << std::endl;
  }

private:
  CImg<unsigned char> image;
  std::string filename;
  unsigned int curCol;
  unsigned int curRow;
  unsigned int columns;
  unsigned int rows;
};

extern "C" {
ptr_type writeImage_create(char *filename, unsigned int iteration, int columns,
                           int rows) {
  std::stringstream s;
  s << filename;
  s << iteration;
  s << ".png";
  std::cout << "Writing to " << s.str() << std::endl;
  return (ptr_type) new WriteImage(s.str().c_str(), columns, rows);
}

void writeImage_delete(ptr_type addr) { 
    delete ((WriteImage *)addr); }

void writeImage_putPixel(ptr_type addr, char pixel) {
  return ((WriteImage *)addr)->putPixel(pixel);
}

void writeImage_save_padded(ptr_type addr) {
    std::cout << "addr = " << addr << std::endl;
    return ((WriteImage *)addr)->write_padded_image();
}
}
