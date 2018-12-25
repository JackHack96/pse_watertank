#include "valve_TDF.h"
#include "watertank_LSF.h"
#include "controller_TDF.h"

int sc_main(int argc, char *argv[]) {
  sca_tdf::sca_signal<double> water_level;
  sca_tdf::sca_signal<double> aperture_threshold;
  sca_tdf::sca_signal<VALVE_COMMAND> command;
  sca_tdf::sca_signal<double> current_aperture;

  // Create instances
  controller_TDF controller("controller");
  valve_TDF valve("valve");
  watertank_LSF watertank("water_level");

  // Bind signals
  valve.command(command);
  valve.aperture_threshold(aperture_threshold);
  valve.aperture(current_aperture);

  watertank.aperture(current_aperture);
  watertank.water_level(water_level);

  controller.water_level(water_level);
  controller.command(command);
  controller.aperture_threshold(aperture_threshold);

  sca_trace_file *file = sca_create_vcd_trace_file("watertank");
  sca_trace(file, water_level, "water_level");
  sca_trace(file, aperture_threshold, "aperture_threshold");
  sca_trace(file, current_aperture, "current_aperture");
  sca_trace(file, command, "command");

  sc_start(1500, SC_SEC);
  sca_close_vcd_trace_file(file);
}