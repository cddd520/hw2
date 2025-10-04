#include "clothing.h"
#include "util.h"
#include "product.h"
#include <sstream>

// constructor for Clothing class
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size): Product(category, name, price, qty), brand_(brand), size_(size){}

// destructor for Clothing class
Clothing::~Clothing(){};

// extract the keywords from all string inputs
std::set<std::string> Clothing::keywords() const
{
  // initialize an empty set
  std::set<std::string> keywordsSet;

  // now I should get the set for name and brand
  std::set<std::string> nameSet = parseStringToWords(name_);
  keywordsSet = setUnion(keywordsSet, nameSet);

  std::set<std::string> brandSet = parseStringToWords(brand_);
  keywordsSet = setUnion(keywordsSet, brandSet);

  // return the keywords set
  return keywordsSet;
}

std::string Clothing::displayString() const
{
  // create a string for display
  std::string clothingString = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ +
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

  return clothingString;
}

void Clothing::dump(std::ostream& os) const
{
  os << "clothing" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << brand_ << "\n" << size_ << std::endl;
}

