#include "mydatastore.h"
#include "user.h"
#include "product.h"
#include "util.h"
#include <map>
#include <string>
#include <set>
#include <vector>
#include <deque>
#include <iostream>

// default constructor
MyDataStore::MyDataStore(){}

// destructor, delete all the products and users
MyDataStore::~MyDataStore()
{
  for (Product* p: products_)
  {
    delete p;
  }
  // create an iterator
  std::map<std::string, User*>::iterator it = users_.begin();
  while (it != users_.end())
  {
    delete it -> second;
    it ++;
  }
}

// add product to datastore
void MyDataStore::addProduct(Product* p)
{
  // insert the product into the products set
  products_.insert(p); 

  // update keywords dictionary
  // first create the keywords for this product
  std::set<std::string> productKeywords = p->keywords();
  // update the product set related to keywords
  for (std::string keyword: productKeywords)
  {
    keywords_[keyword].insert(p);
  }
}

void MyDataStore::addUser(User* u)
{
  // insert the user into users_ map
  users_[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  // create an empty set to see the matches
  std::set<Product*> match;

  // handle the edge cases, if terms have no element, and try to settle the first element
  if (terms.size() == 0)
  {
    return std::vector<Product*>();
  }

  // first word, as we don't want the match to be empty all the time when doing intersection
  std::string firstWord = convToLower(terms[0]);
  std::map<std::string, std::set<Product*>>::iterator it = keywords_.find(firstWord);
  if (it != keywords_.end())
  {
    // if find, then give the set of products that match with the keywords to match
    match = it->second;
  }
  else
  {
    // if it is and, then exit
    if (type == 0)
    {
      return std::vector<Product*>();
    }
    // if it is or, then try to deal with the rest of the words
  }
  // start from the second word
  for (size_t i = 1; i < terms.size(); i++)
  {
    std::string wordI = convToLower(terms[i]);
    std::map<std::string, std::set<Product*>>::iterator it = keywords_.find(wordI);
    if (it != keywords_.end())
    {
      // if and then intersection
      if (type == 0)
      {
        match = setIntersection(match, it->second);
      }
      // if or then setUnion
      else
      {
        match = setUnion(match, it->second);
      }
    }
  }

  // as the output requires the vector, we have to output vector
  std::vector<Product*> matches;
  for (Product* p: match)
  {
    matches.push_back(p);
  }
  return matches;
}

void MyDataStore::dump(std::ostream& os)
{
  // save to database through required format
  os << "<products>" << std::endl;
  for (Product* p: products_)
  {
    p -> dump(os);
  }
  os << "</products>" << std::endl;
  os << "<users>" << std::endl;
  std::map<std::string, User*>::iterator it = users_.begin();
  while (it != users_.end())
  {
    it -> second -> dump(os);
    it++;
  }
  os << "</users>" << std::endl;
}

void MyDataStore::addCart(std::string userName, Product* p)
{
  // check if the user is valid
  if (users_.find(userName) == users_.end())
  {
    std::cout << "Invalid request" << std::endl;
    return;
  }
  carts_[userName].push_back(p);
}

void MyDataStore::viewCart(std::string userName)
{
  // check if the user is valid
  if (users_.find(userName) == users_.end())
  {
    std::cout << "Invalid username" << std::endl;
    return;
  }
  // check if the cart is empty
  if (carts_[userName].empty())
  {
    std::cout << "Cart is empty of this user :<" << std::endl;
    return;
  }
  // go though display logic
  std::deque<Product*> tempDe = carts_[userName];
  int countNum = 1;
  for (Product* p: tempDe)
  {
    std::cout << "Item " << countNum << std::endl;
    std::cout << p -> displayString() << std::endl;
    countNum++;
  }

}
void MyDataStore::buyCart(std::string userName)
{
  // check if the user is valid
  if (users_.find(userName) == users_.end())
  {
    std::cout << "Invalid username" << std::endl;
    return;
  }
  User* user = users_[userName];
  if (carts_[userName].empty())
  {
    return;
  }
  // get user's cart and prepare a cart for unseccusflly bought items
  std::deque<Product*>& cart = carts_[userName];
  std::deque<Product*> restItem;

  while (!cart.empty())
  {
    Product* p = cart.front();
    cart.pop_front();
    if (p -> getQty() > 0 && user-> getBalance() >= p->getPrice())
    {
      p->subtractQty(1);
      user->deductAmount(p->getPrice());
    }
    else
    {
      restItem.push_back(p);
    }
  }
  cart = restItem;

}




