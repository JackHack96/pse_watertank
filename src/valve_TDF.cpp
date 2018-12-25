#include "valve_TDF.h"

valve_TDF::valve_TDF(sc_core::sc_module_name) :
    aperture_threshold("aperture_threshold"),
    command("command"),
    aperture("aperture") {

}

void valve_TDF::processing() {
  switch (command.read()) {
  case IDLE:
    break;
  case OPEN:
    if (current_aperture < aperture_threshold.read()) // valve's aperture can be opened more
      current_aperture += 0.25 * get_timestep().to_seconds();
    else // we can't open the valve more than this
      current_aperture = aperture_threshold.read();
    break;
  case CLOSE:
    if (current_aperture > 0) // valve's aperture can be closed more
      current_aperture -= 0.25 * get_timestep().to_seconds();
    else // we can't close the valve more than this
      current_aperture = 0;
    break;
  }
  aperture.write(current_aperture);
}
