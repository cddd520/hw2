#include "book.h"
#include "util.h"
#include "product.h"
#include <sstream>

// constructor for Book class
Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author): Product(category, name, price, qty), isbn_(isbn), author_(author){}

// destructor for Book class
Book::~Book(){}

// extract the keywords from all string inputs
std::set<std::string> Book::keywords() const
{
  // initialize an empty set
  std::set<std::string> keywordsSet;

  // now I should get the set for name, isbn, and author
  std::set<std::string> nameSet = parseStringToWords(name_);
  keywordsSet = setUnion(keywordsSet, nameSet);

  std::set<std::string> isbnSet = parseStringToWords(isbn_);
  keywordsSet = setUnion(keywordsSet, isbnSet);

  std::set<std::string> authorSet = parseStringToWords(author_);
  keywordsSet = setUnion(keywordsSet, authorSet);

  // return the keywords set
  return keywordsSet;
}

std::string Book::displayString() const
{
  // create a string for display
  std::string bookString = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ +
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

  return bookString;
}

void Book::dump(std::ostream& os) const
{
  os << "book" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << std::endl;
}

