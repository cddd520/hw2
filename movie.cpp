#include "movie.h"
#include "util.h"
#include "product.h"
#include <sstream>

// constructor for Movie class
Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating): Product(category, name, price, qty), genre_(genre), rating_(rating){}

// destructor for Movie class
Movie::~Movie(){};

// extract the keywords from all string inputs
std::set<std::string> Movie::keywords() const
{
  // initialize an empty set
  std::set<std::string> keywordsSet;

  // now I should get the set for name and genre
  std::set<std::string> nameSet = parseStringToWords(name_);
  keywordsSet = setUnion(keywordsSet, nameSet);

  std::set<std::string> genreSet = parseStringToWords(genre_);
  keywordsSet = setUnion(keywordsSet, genreSet);

  // return the keywords set
  return keywordsSet;
}

std::string Movie::displayString() const
{
  // create a string for display
  std::string movieString = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ +
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

  return movieString;
}

void Movie::dump(std::ostream& os) const
{
  os << "movie" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << std::endl;
}

