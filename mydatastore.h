#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "user.h"
#include "product.h"
#include "util.h"
#include <map>
#include <string>
#include <set>
#include <vector>
#include <deque>
#include <iostream>

class MyDataStore: public DataStore{
  public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& os);

    void addCart(std::string userName, Product* p);
    void viewCart(std::string userName);
    void buyCart(std::string userName);


  private:
    std::set<Product*> products_;
    std::map<std::string, User*> users_; // this should be a map because we use user_name to do a lot of things
    std::map<std::string, std::set<Product*>> keywords_;
    std::map<std::string, std::deque<Product*>> carts_;

};

#endif