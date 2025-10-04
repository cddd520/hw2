#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include <string>
#include <set>

class Movie: public Product{
  public:
    // constructor
    Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
    ~Movie();
    // extract keywords
    std::set<std::string> keywords() const;
    // show user the string of output
    std::string displayString() const;
    // dump into database
    void dump(std::ostream& os) const;

  private:
    std::string genre_;
    std::string rating_;
};

#endif