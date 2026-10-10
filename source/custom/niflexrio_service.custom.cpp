#include <niflexrio.pb.h>
#include <niflexrio/niflexrio_service.h>

namespace niflexrio_grpc {
::grpc::Status NiFlexRIOService::ConvertApiErrorStatusForNiFpga_Session(::grpc::ServerContextBase* context, int32_t status, NiFpga_Session session)
{
  std::string description("Error");
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}
}  // namespace niflexrio_grpc