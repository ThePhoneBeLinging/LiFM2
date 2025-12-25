//
// Created by eal on 16/12-2025.
//

#ifndef TIMEEVENT_HPP
#define TIMEEVENT_HPP
#include <cstdint>
#include <functional>

struct TimeEvent {
  int64_t gameSeconds_;
  std::function<void()> callback_;
  bool operator<(const TimeEvent &other) const
  {
    return gameSeconds_ > other.gameSeconds_;
  }
};


#endif //TIMEEVENT_HPP
