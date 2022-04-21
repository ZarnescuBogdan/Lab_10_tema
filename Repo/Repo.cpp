//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "Repo.h"

Repo::Repo() {
    this->noProducts = 0;
}

void Repo::addProduct(Product &product) {
    this->products.push_back(product);
    this->noProducts++;
}

vector<Product> Repo::getAll() {
    return this->products;
}

Product Repo::getProductByCode(int code) {
    for(auto& p: this->getAll()) {
        if(p.getCode() == code) {
            return p;
        }
    }
    throw runtime_error("There is no product with given code!");
}

int Repo::getSize() {
    return this->noProducts;
}

Repo::~Repo() = default;
