#ifndef API_CLIENT_INTERFACES_USER_UC_H
#define API_CLIENT_INTERFACES_USER_UC_H

#include "entities.h"

#include <vector>
#include <string>

namespace calmgram::api_client::use_case {

    class IUserUC {
    public:
        virtual ~IUserUC() = default;

        virtual void Auth(int id) = 0;
        virtual std::vector<int> GetChats() = 0;
        virtual std::vector<entities::Message> OpenChat(int chat_id) = 0;
        virtual bool CreateChat(std::vector<int> target_ids) = 0;
        virtual bool SendMessage(std::string str, int chat_id) = 0;
        virtual std::vector<int> UpdateChats() = 0;
        virtual void ReportAboutMark(std::string msg, bool is_marked) = 0;
    };
}  // namespace calmgram::api_server::use_case

#endif //API_CLIENT_INTERFACES_USER_UC_H
