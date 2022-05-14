#include "update_chat_handler.h"

#include <iostream>

namespace calmgram::api_client::network {

  bool UpdateChatHandler::Execute(int user_id, int chat_id, time_t last_update) {
    if (!DataToRequest(user_id, chat_id, last_update)) {
      return false;
    }
    network::RequestSender req_sender;
    std::string response = req_sender.Execute(request_, "/chat/update", true);
    if (response == "Error") {
      return false;
    }
    if (!ResponseToData(response)) {
      return false;
    }
    return true;
  }

  bool UpdateChatHandler::DataToRequest(int user_id,
                                          int chat_id,
                                          time_t last_update) {
    try {
      boost::property_tree::ptree tree;
      tree.put("user_id", user_id);
      tree.put("chat_id", chat_id);
      tree.put("from_time", last_update);
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
  bool UpdateChatHandler::ResponseToData(std::string response) {
    try {
      std::stringstream buff;
      buff << response;
      boost::property_tree::ptree tree;
      boost::property_tree::read_json(buff, tree);
      output_.clear();
      for (auto& item : tree.get_child("msgs")) {
        entities::Message buf_msg;
        buf_msg.owner_id = item.second.get<int>("owner_id");
        buf_msg.is_marked = item.second.get<bool>("is_marked");
        buf_msg.time = item.second.get<time_t>("created");
        buf_msg.content.type = entities::TEXT;
        buf_msg.content.data = item.second.get<std::string>("text");

        output_.push_back(buf_msg);
      }
    } catch (std::exception const& e) {
      std::cout << __FILE__ << ':' << __LINE__ << ": " << e.what() << '\n';
      return false;
    }
    return true;
  }
  
}  // namespace calmgram::api_client::network
