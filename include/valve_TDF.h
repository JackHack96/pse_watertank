#ifndef WATERTANK_VALVE_TDF_H
#define WATERTANK_VALVE_TDF_H

#include <systemc-ams.h>

typedef enum {
  IDLE, OPEN, CLOSE
} VALVE_COMMAND;

SCA_TDF_MODULE(valve_TDF) {
public:
  sca_tdf::sca_in<double>        aperture_threshold;
  sca_tdf::sca_in<VALVE_COMMAND> command;

  sca_tdf::sca_out<double> aperture;

  explicit valve_TDF(sc_core::sc_module_name);

  void processing() override;

private:
  double current_aperture;
};

#endif //WATERTANK_VALVE_TDF_H
