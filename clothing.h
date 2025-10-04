#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include <string>
#include <set>

class Clothing: public Product{
  public:
    // constructor
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size);
    ~Clothing();
    // extract keywords
    std::set<std::string> keywords() const;
    // show user the string 
    std::string displayString() const;
    // dump to database
    void dump(std::ostream& os) const;

  private:
    std::string brand_;
    std::string size_;
};

#endif