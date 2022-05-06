#ifndef CALMGRAM_API_SERVER_LIBS_BOOST_JSON_PARSER_IMPL_HPP
#define CALMGRAM_API_SERVER_LIBS_BOOST_JSON_PARSER_IMPL_HPP

#include "json_parser.h"

#include <sstream>
#include <string>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

namespace calmgram::api_server::json {

class JsonParser::JsonParserImpl {
 public:
  JsonParserImpl(std::string const& str) {
    std::stringstream in(str);
    boost::property_tree::read_json(in, pt_);
  }
  template <typename T>
  T GetValue(std::string const& name, T const& default_value) const {
    return pt_.get<T>(name, default_value);
  }

 private:
  boost::property_tree::ptree pt_;
};

}  // namespace calmgram::api_server::json

#endif  // CALMGRAM_API_SERVER_LIBS_BOOST_JSON_PARSER_IMPL_HPP