#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Engine
{
     class StateMan
     {
     private:
          std::stack<std::unique_ptr<State>> mStateStack;
          std::unique_ptr<State> mNewState;

          bool mAdd = false, mReplace = false, mRemove = false;

     public:
          StateMan();
          ~StateMan();

          void Add(std::unique_ptr<State> toAdd, bool Replace = false);
          void popCurrent();
          void processStateChange();
          std::unique_ptr<State> &getCurrent();
     };
} //Namespace Engine