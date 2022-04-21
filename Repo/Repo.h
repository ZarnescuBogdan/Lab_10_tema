//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#ifndef LAB_9_LIVE_REPO_H
#define LAB_9_LIVE_REPO_H

#include "../Product/Product.h"
#include <vector>

using namespace std;

class Repo {
    vector<Product> products;
    int noProducts;
public:
    Repo();
    void addProduct(Product &product);
    vector<Product> getAll();
    Product getProductByCode(int code);
    int getSize();
    ~Repo();
};


#endif //LAB_9_LIVE_REPO_H
