#ifndef WATERTANK_CONTROLLER_H
#define WATERTANK_CONTROLLER_H

#include "valve_TDF.h"
#include "watertank_LSF.h"

SCA_TDF_MODULE(controller_TDF) {
public:
  sca_tdf::sca_in<double> water_level;
  sca_tdf::sca_out<double> aperture_threshold;
  sca_tdf::sca_out<VALVE_COMMAND> command;

  explicit controller_TDF(sc_core::sc_module_name);

  void set_attributes() override;
  void processing() override;
private:
  int samples, counter;
  double current_aperture_threshold;
};

#endif //WATERTANK_CONTROLLER_H
