//
//  ExtendedSet.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-19.
//
//

#pragma once

#include <set>

template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>>
class ExtendedSet : public std::set<Key, Compare, Allocator>
{
public:
   bool contains(const Key& value) const
   {
      return this->find(value) != this->end();
   }
};
