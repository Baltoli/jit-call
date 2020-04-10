#pragma once

namespace jitcall {

class Result {
public:
  template <typename T> T as() const;

private:
};

template <typename T> T Result::as() const { return T{}; }

} // namespace jitcall
