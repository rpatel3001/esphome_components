#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/binary_output.h"
#include "esphome/components/output/float_output.h"
#include "esphome/components/fan/fan.h"

namespace esphome {
namespace ifan {

class IFan : public Component, public fan::Fan {
 public:
  IFan() {}
  void setup() override;
  void dump_config() override;
  void set_direction(output::BinaryOutput *direction) { this->direction_ = direction; }
  fan::FanTraits get_traits() override;

 protected:
  void control(const fan::FanCall &call) override;
  void write_state_();
  
  void set_off();
  void set_low();
  void set_med();
  void set_high();
  output::BinaryOutput *direction_{nullptr};
  int speed_count_{};
};

}  // namespace speed
}  // namespace esphome
