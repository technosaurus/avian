/* Copyright (c) 2008-2014, Avian Contributors

   Permission to use, copy, modify, and/or distribute this software
   for any purpose with or without fee is hereby granted, provided
   that the above copyright notice and this permission notice appear
   in all copies.

   There is NO WARRANTY for this software.  See license.txt for
   details. */

#ifndef AVIAN_UTIL_FIXED_ALLOCATOR_H
#define AVIAN_UTIL_FIXED_ALLOCATOR_H

#include "allocator.h"
#include "abort.h"
#include "slice.h"

namespace avian {
namespace util {

// An Allocator that allocates, bump-pointer style, out of a pre-defined chunk
// of memory.
class FixedAllocator : public Allocator {
 public:
  FixedAllocator(Aborter* a, Slice<uint8_t> memory);

  virtual void* tryAllocate(unsigned size);

  void* allocate(unsigned size, unsigned padAlignment);

  virtual void* allocate(unsigned size);

  virtual void free(const void* p, unsigned size);

  Aborter* a;
  Slice<uint8_t> memory;
  size_t offset;
};

}  // namespace util
}  // namespace avian

#endif  // AVIAN_UTIL_FIXED_ALLOCATOR_H
