#include "controller_TDF.h"

controller_TDF::controller_TDF(sc_core::sc_module_name) :
    command("command"), aperture_threshold("aperture_threshold"), water_level("water_level") {
  current_aperture_threshold = 0.7;
  counter = 0;
}

void controller_TDF::set_attributes() {
  this->set_timestep(1, SC_MS);
  water_level.set_delay(1);
  samples = 1500;
}

void controller_TDF::processing() {
  if (water_level.read() >= 5 && water_level.read() <= 8.8) {
    command = IDLE;
    counter = 0;
  } else if (water_level.read() > 8.8 && counter == samples) {
    command = CLOSE;
    current_aperture_threshold *= 0.7;
    counter = 0;
  } else if (water_level.read() < 5 && counter == samples) {
    command = OPEN;
    current_aperture_threshold *= 1.1;
    counter = 0;
  }
  aperture_threshold = current_aperture_threshold;
  counter++;
}
