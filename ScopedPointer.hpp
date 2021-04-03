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

   void reset(T* newValue)
   {
      if (targetPointer_ != nullptr)
      {
         delete targetPointer_;
      }
      targetPointer_ = newValue;
   }

private:
   T* targetPointer_;
};
