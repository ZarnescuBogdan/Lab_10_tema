//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "Product.h"
#include <cstring>

Product::Product() {
    this->code = 0;
    this->name = nullptr;
    this->price = 0.0;
}

Product::Product(const Product &product) {
    this->code = product.code;
    this->name = new char[strlen(product.name) + 1];
    strlcpy(this->name, product.name, size_t(this->name));
    this->price = product.price;
}

Product::Product(int code1, const char *name1, float price1) {
    this->code = code1;
    this->name = new char[strlen(name1) + 1];
    int size = size_t(this->name);
    int size1 = size_t(name1);
    strlcpy(this->name, name1, size_t(this->name));
    this->price = price1;
}

void Product::setCode(int code1) {
    this->code = code1;
}

void Product::setName(const char *name1) {
    if(this->name) {
        delete[] this->name;
    }
    this->name = new char[strlen(name1) + 1];
    strlcpy(this->name, name1, size_t(this->name));
}

void Product::setPrice(float price1) {
    this->price = price1;
}

int Product::getCode() {
    return this->code;
}

const char *Product::getName() {
    return this->name;
}

float Product::getPrice() {
    return this->price;
}

Product::~Product() {
    if(this->name) {
        delete[] this->name;
        this->code = 0;
        this->name = nullptr;
        this->price = 0.0;
    }
}

Product &Product::operator=(const Product &product) {
    this->setCode(product.code);
    this->setName(product.name);
    this->setPrice(product.price);
    return *this;
}

bool Product::operator==(const Product &product) {
    return ((this->code == product.code) and (strcmp(this->name, product.name) == 0) and (this->price == product.price));
}


