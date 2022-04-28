#ifndef API_CLIENT_USER_UC_H
#define API_CLIENT_USER_UC_H

#include "interfaces_user_uc.h"
#include "interfaces_handlers.h"

namespace calmgram::api_client::use_case {

    class UserUseCase : public IUserUC {
    private:
        entities::Profile profile_;
        network::IUpdateChat& update_chat_;
        network::ISendMessage& send_msg_;
        network::IAddChat& add_chat_;
        network::IAuthorisation& auth_;
    public:
        UserUseCase(int id,
                    network::IUpdateChat& update_chat,
                    network::ISendMessage& send_msg,
                    network::IAddChat& add_chat,
                    network::IAuthorisation& auth);
        ~UserUseCase() = default;

        std::vector<int> GetChats() override;  // получение (локально) вектора id чатов у пользователя
        std::vector<entities::Message> OpenChat(int chat_id) override; // получение (локально) вектора сообщений в чате
        bool CreateChat(int target_id) override;  // создание чата с пользователем с target_id 
        bool SendMessage(std::string str,bool is_img, int chat_id) override;  // отправка сообщения на сервер
        std::vector<int> UpdateChats() override; // обновление сообщений в чатах и и получение обновленных чатов
    };
}  // namespace calmgram::api_server::use_case

#endif  //API_CLIENT_USER_UC_H
