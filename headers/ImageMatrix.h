#ifndef IMAGE_MATRIX_H
#define IMAGE_MATRIX_H

#include <vector>
#include "RGBCell.h"
#include <QImage>
#include "TCore.h"

class ImageMatrix
{
private:
    std::vector <std::vector <RGBCell>> _data;
public:
    ImageMatrix(QImage *image);
    QImage convertToImage();
    int getN(); // число элементов по горизонтали
    int getM(); // число элементов по вертикали
    RGBCell getRGBValue(int i, int j);

    // void doConvolution(const TCore *with);   // TODO : либо реализуй и здесь 
            // свёртки с какой-нибудь прикольной шнягой, либо удали функцию 
};

#endif //IMAGE_MATRIX_H