//
//  ScopedPointer.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#pragma once

// Will delete the given pointer when class destructs.
template <typename T>
class ScopedPointer
{
public:
   ScopedPointer(T* targetPointer)
   : targetPointer_(targetPointer)
   {
   }

   virtual ~ScopedPointer()
   {
      delete targetPointer_;
   }

   operator T* ()
   {
   return targetPointer_;
   }

private:
   T* targetPointer_;
};
