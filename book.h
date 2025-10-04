#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include <string>
#include <set>

class Book: public Product{
  public:
    // constructor
    Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author);
    ~Book();
    // extract keywords
    std::set<std::string> keywords() const;
    // display string for user
    std::string displayString() const;
    // save to database
    void dump(std::ostream& os) const;

  private:
    std::string isbn_;
    std::string author_;
};

#endif
