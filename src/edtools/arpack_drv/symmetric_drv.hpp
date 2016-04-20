#ifndef EDTOOLS_ARPACK_DRV_SYMMETRIC_DRV_HPP
#define EDTOOLS_ARPACK_DRV_SYMMETRIC_DRV_HPP

#include <Eigen/Dense>

namespace edtools {
  class ArpackDrvConfig;
  namespace arpack_drv {
    class SymmetricDrv {
    public:
      SymmetricDrv(const ArpackDrvConfig& config);
    };
  }
}

#endif
