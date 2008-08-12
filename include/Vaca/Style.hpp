// Vaca - Visual Application Components Abstraction
// Copyright (c) 2005, 2006, 2007, 2008, David A. Capello
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in
//   the documentation and/or other materials provided with the
//   distribution.
// * Neither the name of the Vaca nor the names of its contributors
//   may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef VACA_STYLE_HPP
#define VACA_STYLE_HPP

#include "Vaca/base.hpp"

namespace Vaca {

/**
 * A Widget style: it is a pair of values: regular style (a set of
 * Win32's @c WS_ values) and extended style (a set of Win32's @c WS_EX_
 * values).
 *
 * You can add and substract styles with the + and - operators.
 *
 * @code
 * {
 *    Frame frame(..., FrameStyle + ClientEdgeStyle - MinimizableFrameStyle)
 *    Edit edit("", EditStyle + ClientEdgeStyle)
 *    ...
 * }
 * @endcode
 */
class VACA_DLL Style
{
public:

  int regular;
  int extended;

  Style(int regular, int extended);

  Style operator+(const Style& style) const;
  Style operator-(const Style& style) const;
//   Style operator|(const Style& style) const;
  Style operator&(const Style& style) const;

  bool operator==(const Style& style) const;
  bool operator!=(const Style& style) const;

};

} // namespace Vaca

#endif
