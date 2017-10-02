#include <cudaCompress/Timing.h>

#include <cudaCompress/cudaUtil.h>
#include <B3D_cudaCompress/util.h>

#include <B3D_cudaCompress/InstanceImpl.h>


namespace cudaCompress {

void setTimingDetail(Instance* pInstance, ETimingDetail detail)
{
    pInstance->setTimingDetail(detail);
}

void getTimings(Instance* pInstance, std::vector<std::string>& names, std::vector<float>& times)
{
    pInstance->getTimings(names, times);
}

void printTimings(Instance* pInstance)
{
    pInstance->printTimings();
}

void resetTimings(Instance* pInstance)
{
    pInstance->resetTimings();
}

}
