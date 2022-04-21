//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "tests.h"
#include "../Product/Product.h"
#include <cassert>
#include "../Repo/Repo.h"
#include <vector>

void testConstructorProduct() {
    Product product;
    assert(product.getCode() == 0);
    assert(product.getName() == nullptr);
    assert(product.getPrice() == 0.0);
}

void testConstructor2Product() {
    const char *name = "ciocolata";
    Product product(1, name, 10);
    assert(product.getCode() == 1);
    assert(strcmp(product.getName(), name) == 0);
    assert(product.getPrice() == 10);
}

void testSetterGetter() {
    Product product;
    const char *name = "suc";
    product.setCode(2);
    product.setName(name);
    product.setPrice(7);
    assert(product.getCode() == 2);
    assert(strcmp(product.getName(), name) == 0);
    assert(product.getPrice() == 7);
}

void testAddProduct() {
    Repo repo;
    const char *n1 = "croissant";
    const char *n2 = "ciocolata";
    const char *n3 = "suc";
    Product p1, p2, p3;
    p1.setCode(1);
    p1.setName(n1);
    p1.setPrice(5);
    p2.setCode(2);
    p2.setName(n2);
    p2.setPrice(10);
    p3.setCode(3);
    p3.setName(n3);
    p3.setPrice(7);
    repo.addProduct(p1);
    repo.addProduct(p2);
    repo.addProduct(p3);
    assert(repo.getSize() == 3);
    assert(repo.getProductByCode(1) == p1);
    assert(repo.getProductByCode(2) == p2);
    assert(repo.getProductByCode(3) == p3);
}

void testAll() {
    testConstructorProduct();
    testConstructor2Product();
    testSetterGetter();
    testAddProduct();
}
