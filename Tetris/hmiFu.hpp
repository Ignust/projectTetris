#ifndef HMIFU_HPP
#define HMIFU_HPP

#include "hmi/config_hmi.hpp"

#if defined HMI_QtUi
  #include "hmi/hmi_QtUi.hpp"
#elif defined HMI_Win7
  #include "hmi/hmi_Win7.hpp"
#else
  #include "hmi/hmi_Base.hpp"
#endif

class HmiFu{
public:
    HmiFu() {}
    ~HmiFu() {}


private:
#if defined HMI_QtUi
    Hmi_QtUi mHmi;
#elif defined HMI_Win7
    Hmi_Win7 mHmi;
#else
    Hmi_Base mHmi;
#endif
};

#endif // HMIFU_HPP
