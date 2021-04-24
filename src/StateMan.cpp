#include "StateMan.hpp"

Engine::StateMan::StateMan() : mAdd(false), mReplace(false), mRemove(false)
{
}

Engine::StateMan::~StateMan()
{
}

void Engine::StateMan::Add(std::unique_ptr<State> toAdd, bool Replace)
{
     mAdd = true;
     mNewState = std::move(toAdd);
     mReplace = Replace;
}

void Engine::StateMan::popCurrent()
{
     mRemove = true;
}

void Engine::StateMan::processStateChange()
{
     if (mRemove && (!mStateStack.empty()))
     {
          mStateStack.pop();

          if (!mStateStack.empty())
          {
               mStateStack.top()->Start();
          }
          mRemove = false;
     }

     if (mAdd)
     {
          if (mReplace && (!mStateStack.empty()))
          {
               mStateStack.pop();
               mReplace = false;
          }

          if (!mStateStack.empty())
          {
               mStateStack.top()->Pause();
          }

          mStateStack.push(std::move(mNewState));
          mAdd = false;
     }
}

std::unique_ptr<Engine::State> &Engine::StateMan::getCurrent()
{
     return mStateStack.top();
}
