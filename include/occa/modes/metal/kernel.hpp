#ifndef OCCA_MODES_METAL_KERNEL_HEADER
#define OCCA_MODES_METAL_KERNEL_HEADER

#include <occa/core/launchedKernel.hpp>
#include <occa/api/metal.hpp>

namespace occa {
  namespace metal {
    class device;

    class kernel : public occa::launchedModeKernel_t {
      friend class device;

    private:
      api::metal::device_t metalDevice;
      mutable api::metal::function_t metalFunction;

    public:
      kernel(modeDevice_t *modeDevice_,
             const std::string &name_,
             const std::string &sourceFilename_,
             const occa::properties &properties_);

      kernel(modeDevice_t *modeDevice_,
             const std::string &name_,
             const std::string &sourceFilename_,
             api::metal::device_t metalDevice_,
             api::metal::function_t metalFunction_,
             const occa::properties &properties_);

      ~kernel();

      int maxDims() const;
      dim maxOuterDims() const;
      dim maxInnerDims() const;

      void deviceRun() const;
    };
  }
}

#endif
