#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  // create a intersection set to store the data 
  std::set<T> intersect;
  // create iterator for s1
  typename std::set<T>::iterator it = s1.begin();
  while (it != s1.end())
  {
    // see whether the s1 data is in s2
    if (s2.find(*it) != s2.end())
    {
      intersect.insert(*it);
    }
    it++;
  }
  //return final output
  return intersect;

}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  // create a union set to store the data 
  typename std::set<T> unionSet;
  // simply put all the data from s1 and s2 into the union, because set will handle repetitve automatically
  typename std::set<T>::iterator it1 = s1.begin();
  typename std::set<T>::iterator it2 = s2.begin();
  while (it1 != s1.end())
  {
    unionSet.insert(*it1);
    it1++;
  }
  while (it2 != s2.end())
  {
    unionSet.insert(*it2);
    it2++;
  }
  // return the final output
  return unionSet;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
