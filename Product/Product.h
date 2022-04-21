//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#ifndef LAB_9_LIVE_PRODUCT_H
#define LAB_9_LIVE_PRODUCT_H


class Product {
private:
    int code;
    char *name;
    float price;
public:
    Product();
    Product(const Product &product);
    Product(int code1, const char *name1, float price1);
    void setCode(int code1);
    void setName(const char *name1);
    void setPrice(float price1);
    int getCode();
    const char* getName();
    float getPrice();
    Product &operator=(const Product& product);
    bool operator==(const Product& product);
    ~Product();
};


#endif //LAB_9_LIVE_PRODUCT_H
