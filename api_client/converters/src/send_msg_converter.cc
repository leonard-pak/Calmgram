#include "send_msg_converter.h"
#include "entities.h"

#include <iostream>

namespace calmgram::api_client::converters {

bool SendMessageConverter::DataToRequest(int chat_id,
                                         int user_id,
                                         entities::Content content) {
  try {
    boost::property_tree::ptree tree;
    tree.put("chat_id", chat_id);
    tree.put("user_id", user_id);
    tree.put("text", content.data);
    std::ostringstream buf;
    write_json(buf, tree, false);
    std::string json = buf.str();

    request_ = json;
  } catch (std::exception const& e) {
    std::cout << __FILE__ << ':' << __LINE__ << ": " << e.what() << '\n';
    return false;
  }
  return true;
}
bool SendMessageConverter::ResponseToData(std::string response) {
  try {
    if (response.empty())
      return true;
    // по идее не нужно вообще респонс обрабатывать, но на будущее мало-ли
  } catch (std::exception const& e) {
    std::cout << __FILE__ << ':' << __LINE__ << ": " << e.what() << '\n';
    return false;
  }
  return true;
}

}  // namespace calmgram::api_client::converters