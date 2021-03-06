#include "utils.hpp"
#include "attachment.hpp"

discord::Attachment::Attachment(nlohmann::json const data)
    : size{ data["size"] },
    /**
     * @brief Constructs an Attachment from raw event data
     */
      width{ get_value(data, "width", 0) },
      height{ get_value(data, "height", 0) },
      id{ to_sf(data["id"]) },
      url{ data["url"] },
      filename{ data["filename"] },
      proxy_url{ data["proxy_url"] } {
}