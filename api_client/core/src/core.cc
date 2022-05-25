#include <iostream>
#include <QApplication>

#include "core.h"

#include "add_chat_handler.h"
#include "auth_handler.h"
#include "send_msg_handler.h"
#include "update_chat_handler.h"
#include "report_handler.h"
#include "update_chats_handler.h"
#include "user_uc.h"
#include "calmgram_window.h"

namespace calmgram::api_client::client_core {

  void Core::run(int argc, char *argv[]) {
    if ( argc == 1) {
        std::cout << "no args, pls add -console or -window" << std::endl;
        return;
    }
    std::string arg(argv[1]);
    if (arg == "-window") {
      auto auth_handler = std::make_shared<network::AuthorisationHandler>();
      auto update_chats_handler = std::make_shared<network::UpdateChatsHandler>();
      auto update_chat_handler = std::make_shared<network::UpdateChatHandler>();
      auto send_msg_handler = std::make_shared<network::SendMessageHandler>();
      auto add_chat_handler = std::make_shared<network::AddChatHandler>();
      auto report_handler = std::make_shared<network::ReportHandler>();

      auto user_uc = std::make_shared<use_case::UserUseCase>(auth_handler, update_chats_handler,
          update_chat_handler, send_msg_handler, add_chat_handler, report_handler);
      QApplication a(argc, argv);
      user_interface::CalmgramWindow w(user_uc);
      w.show();

      a.exec();
    } else if (arg == "-console") {
      consol_run();
    } else {
        std::cout << "wrong args, pls use -console or -window" << std::endl;
    }

  }

  void Core::consol_run() {
    // int id;
    // int chat_id = 0;
    // int buff_id;
    // use_case::UserUseCase user(std::make_shared<network::UpdateChatHandler>(),
    //                           std::make_shared<network::SendMessageHandler>(),
    //                           std::make_shared<network::AddChatHandler>(),
    //                           std::make_shared<network::AuthorisationHandler>(),
    //                           std::make_shared<network::ReportHandler>());

    // std::string msg;
    // std::cout << "Enter id" << std::endl;
    // std::cin >> id;
    // user.Auth(id);
    // while (true) {
    //   std::cout << "Enter 1 to get chats " << std::endl;
    //   std::cout << "Enter 2 to open chat " << std::endl;
    //   std::cout << "Enter 3 to create chat " << std::endl;
    //   std::cout << "Enter 4 to send message  " << std::endl;
    //   std::cout << "Enter 5 to update chats " << std::endl;
    //   std::cout << "Enter 6 to report about msg " << std::endl;
    //   std::cin >> id;
    //   if (id == 1) {
    //     std::vector<int> chats = user.GetChats();
    //     for (size_t i = 0; i < chats.size(); i++) {
    //       std::cout << chats[i] << ", ";
    //     }
    //     std::cout << std::endl;
    //   } else if (id == 2) {
    //     std::cout << "Enter chatID to open chat " << std::endl;
    //     std::cin >> chat_id;
    //     std::vector<entities::Message> msgs = user.OpenChat(chat_id);
    //     std::cout << "msgs in chat " << msgs.size() << std::endl;
    //     for (size_t i = 0; i < msgs.size(); i++) {
    //       if (msgs[i].is_marked) {
    //         std::cout << msgs[i].owner_id << ":*censored*" << std::endl;
    //       } else {
    //         std::cout << msgs[i].owner_id << ":" << msgs[i].content.data
    //                   << std::endl;
    //       }
    //     }
    //   } else if (id == 3) {
    //     std::cout << "Enter userID to create chat with him" << std::endl;
    //     std::cin >> buff_id;
    //     std::vector<int> buff{buff_id};
    //     std::cout << "Added chat " << user.CreateChat(buff) << std::endl;
    //   } else if (id == 4) {
    //     std::cout << "write msg" << std::endl;
    //     std::cin.ignore(1, '\n');
    //     std::getline(std::cin, msg);
    //     user.SendMessage(msg, chat_id);
    //   } else if (id == 5) {
    //     std::vector<int> upd_chats = user.UpdateChats();
    //     std::vector<int> chats = user.GetChats();
    //     std::cout << "chats" << std::endl;
    //     for (size_t i = 0; i < chats.size(); i++) {
    //       size_t idx = 0;
    //       bool is_updated = false;
    //       while (idx < upd_chats.size() && !is_updated) {
    //         if (upd_chats[idx] == chats[i]) {
    //           is_updated = true;
    //         }
    //         idx++;
    //       }
    //       if (!is_updated) {
    //         std::cout << chats[i] << " ";
    //       } else {
    //         std::cout << chats[i] << "(*) ";
    //       }
    //     }
    //     std::cout << std::endl;
    //   } else if (id == 6) {
    //     std::cout << "Enter msg" << std::endl;
    //     std::getline(std::cin, msg);
    //     std::cout << "enter 1 if it need to censore" << std::endl << "enter 2 if it need to uncensore" << std::endl;
    //     std::cin >> buff_id;
    //     if (buff_id == 1) {
    //       user.ReportAboutMark(msg,true);
    //     } else if (buff_id == 2) {
    //       user.ReportAboutMark(msg,false);
    //     }
    //   }
    // }
  }

}  // namespace calmgram::api_client::core
