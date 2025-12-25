//
// Created by eal on 16/12-2025.
//

#ifndef TIMEKEEPER_HPP
#define TIMEKEEPER_HPP
#include <queue>

#include "TimeEvent.hpp"
#include "spdlog/spdlog.h"


class TimeKeeper {
public:
  explicit TimeKeeper(const std::shared_ptr<spdlog::logger>& logger);
  void advance();
  void scheduleEvent(int64_t atSeconds, const std::function<void()>& callback);
  [[nodiscard]] int64_t getCurrentSeconds() const;
private:
  std::shared_ptr<spdlog::logger> logger_;
  int64_t seconds_ = 0;
  std::priority_queue<TimeEvent> events_;
};



#endif //TIMEKEEPER_HPP
