//
// Created by eal on 16/12-2025.
//

#include "TimeKeeper.hpp"
#include "util/ModelStorage.hpp"

TimeKeeper::TimeKeeper(const std::shared_ptr<spdlog::logger>& logger) : logger_(logger)
{
}

void TimeKeeper::advance()
{
  if (events_.empty())
  {
    logger_->error("Attempted to advance time with no scheduled events.");
    return;
  }
  const auto nextEvent = events_.top();
  seconds_ = nextEvent.gameSeconds_;
  nextEvent.callback_();
  events_.pop();
}

void TimeKeeper::scheduleEvent(const int64_t atSeconds, const std::function<void()>& callback)
{
  if (atSeconds < seconds_)
  {
    logger_->error("Event attempted scheduled in the past at: {}", atSeconds);
    return;
  }
  events_.emplace(atSeconds, callback);
}

int64_t TimeKeeper::getCurrentSeconds() const
{
  return seconds_;
}
