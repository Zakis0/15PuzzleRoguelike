#pragma once
#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include <iostream>
#include <vector>

#include "../Error/error.h"

using namespace std;

#define BASE_EMPTY_PIXEL ' '

class Matrix {
    unsigned int width, height;
    char** field;

    void initMatrix(char pixel);

public:
    char emptyPixel;

    Matrix();
    Matrix(unsigned int height, unsigned int width, char emptyPixel = BASE_EMPTY_PIXEL, char initPixel = BASE_EMPTY_PIXEL);
    Matrix(const Matrix& matrix);
    ~Matrix();

    char** getField() const;
    unsigned int getHeight() const;
    unsigned int getWidth() const;

    void fillMatrixWith(char pixel);
    void copyField(const Matrix& matrix);
    void printMatrix();
    void clearMatrix();

    void cloneMatrix(const Matrix& matrix);

    Matrix scaleMatrix(unsigned int scale);
    void fillMatrixByVector(const vector<vector<char>>& vec);

    Matrix connectMatrixHorizontal(const Matrix& connectableMatrix, unsigned int connectableMatrixTopBias = 0, unsigned int connectableMatrixLeftBias = 0);
    Matrix connectMatrixVertical(const Matrix& connectableMatrix, unsigned int connectableMatrixTopBias = 0, unsigned int connectableMatrixLeftBias = 0);
    Matrix shiftMatrix(bool changeSize, int leftBias, int topBias = 0);
    Matrix overlayMatrix(const Matrix& overlaybleMatrix, bool overlaybleMatrixTransparency = true);
    Matrix roundMatrix(unsigned int radius);
    Matrix transpose();
};

#endif // MY_MATRIX_H
