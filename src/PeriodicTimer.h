class PeriodicTimer {
 public:
  explicit PeriodicTimer(float period) : period_ms(static_cast<unsigned long>(period * 1000.0f)) {
    nextEvent_ms = millis() + period_ms;
  }

  bool hasFired() {
    if (millis() >= nextEvent_ms) {
      nextEvent_ms = millis() + period_ms;
      return true;
    }
    return false;
  }

 private:
  const unsigned long period_ms;
  unsigned long nextEvent_ms = 0;
};