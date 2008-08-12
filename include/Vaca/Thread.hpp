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

#ifndef VACA_THREAD_HPP
#define VACA_THREAD_HPP

#include "Vaca/base.hpp"
#include "Vaca/Exception.hpp"
#include "Vaca/NonCopyable.hpp"
#include "Vaca/Slot.hpp"

namespace Vaca {

class Frame;
class Widget;

class CreateThreadException : public Exception
{
public:

  CreateThreadException() : Exception() { }
  CreateThreadException(const String& message) : Exception(message) { }
  virtual ~CreateThreadException() throw() { }

};
  
/**
 * A thread of execution.
 */
class VACA_DLL Thread : public NonCopyable
{
  friend class Frame;

public:

  typedef MSG Message;

private:

  HANDLE m_handle;
  ThreadId m_id;

public:

  Thread();
  ~Thread();

  /**
   * @exception CreateThreadException
   */
  template<typename F>
  explicit Thread(F f) {
    _Thread(Slot0_fun<void, F>(f));
  }

  ThreadId getId() const;

  void join();
  bool isJoinable() const;

  void setPriority(int priority);

  //////////////////////////////////////////////////////////////////////
  // functions for the current thread

  static void doMessageLoop();
  static void doMessageLoopFor(Widget* widget);

  static void pumpMessageQueue();
  static void breakMessageLoop();

  static void yield();

protected:

  static bool getMessage(Message& msg);
  static bool peekMessage(Message& msg);
  static void processMessage(Message& msg);
  static bool preTranslateMessage(Message& msg);

private:

  void _Thread(const Slot0<void>& slot);
  static void addFrame(Frame* frame);
  static void removeFrame(Frame* frame);

};

void VACA_DLL __vaca_remove_all_thread_data();

Widget* VACA_DLL __vaca_get_outside_widget();
void VACA_DLL __vaca_set_outside_widget(Widget* widget);

} // namespace Vaca

#endif