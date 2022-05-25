#ifndef CALMGRAM_API_SERVER_USE_CASE_TEST_H
#define CALMGRAM_API_SERVER_USE_CASE_TEST_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "add_chat_uc.h"
#include "send_msg_uc.h"
#include "update_chat_uc.h"
#include "user_auth_uc.h"

namespace calmgram::api_server::tests {

class MockICreateSession : public use_case::ICreateSession {
 public:
  MOCK_METHOD(std::string,
              CreateSession,
              (std::string_view user_login),
              (override));
};

class MockIGetSessionLogin : public use_case::IGetSessionLogin {
 public:
  MOCK_METHOD(std::string,
              GetSessionLogin,
              (std::string_view token),
              (const, override));
};

class MockICheckUser : public use_case::ICheckUser {
 public:
  MOCK_METHOD(bool,
              CheckUser,
              (std::string_view login, std::string_view password),
              (const, override));
  MOCK_METHOD(bool, CheckUser, (std::string_view login), (const, override));
};

class MockICheckUserAccessToChat : public use_case::ICheckUserAccessToChat {
 public:
  MOCK_METHOD(bool,
              CheckUserAccessToChat,
              (std::string_view user_login, int chat_id),
              (const, override));
};

class MockICreateUser : public use_case::ICreateUser {
 public:
  MOCK_METHOD(bool,
              CreateUser,
              (std::string_view login, std::string_view password),
              (const, override));
};

class MockICreateChat : public use_case::ICreateChat {
 public:
  MOCK_METHOD(int,
              CreateChat,
              (std::vector<std::string_view> const& users),
              (const, override));
};

class MockIGetMsgs : public use_case::IGetMsgs {
 public:
  MOCK_METHOD(std::vector<entities::Message>,
              GetMsgs,
              (int chat_id, time_t from_time),
              (const, override));
};

class MockISendMsg : public use_case::ISendMsg {
 public:
  MOCK_METHOD(void,
              SendMsg,
              (entities::Message const& msg, int chat_id),
              (const, override));
};

class MockIAnalysisText : public use_case::IAnalysisText {
 public:
  MOCK_METHOD(bool, AnalysisText, (std::string_view msg), (const, override));
};

}  // namespace calmgram::api_server::tests

#endif  // CALMGRAM_API_SERVER_USE_CASE_TEST_H