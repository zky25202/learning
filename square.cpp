//
//  square.cpp
//  Project4
//
//  Created by francis on 2019/7/12.
//  Copyright © 2019 francis. All rights reserved.
//

#include <stdio.h>
#include "square.h"

// Piece* in this ADT don't require deep copy and overriding assignment operation

Square::Square(Vaxis v,Haxis h):v(v),h(h),p(nullptr){
}

Vaxis Square::getV() const{
    return v;
}

void Square::setV(Vaxis v){
    this->v = v;
}

Haxis Square::getH() const{
    return h;
}

void Square::setH(Haxis h){
    this->h = h;
}

const Piece& Square::getPiece() const{
    if (p == nullptr) {
        SquareException err = SquareException(*this, "empty");
        throw err;
    }
    return *p;
}

void Square::setPiece(const Piece *p){
    this->p = p;
}

bool Square::isEmpty() const{
    return p == nullptr;
}

bool Square::isOnFirstDiagonal() const{
    return int(v) == int(h);
}

bool Square::isOnSecondDiagonal() const{
    return this->h + this->v == 3;
}

std::string vAxisShortString[] = {"A","B","C","D"};

std::string Square::toString() const{
    std::string outStr = "";
    outStr += vAxisShortString[int(this->v)];
    outStr += std::to_string(int(this->h)+1);
    return outStr;
}
