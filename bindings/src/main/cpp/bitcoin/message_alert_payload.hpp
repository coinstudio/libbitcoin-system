/**
 * Copyright (c) 2011-2017 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN__MESSAGE_ALERT_FORMATTED_PAYLOAD_HPP
#define LIBBITCOIN__MESSAGE_ALERT_FORMATTED_PAYLOAD_HPP

//#include <istream>
//#include <string>
#include <bitcoin/bitcoin/define.hpp>
#include <bitcoin/bitcoin/message/alert_payload.hpp>
//#include <bitcoin/bitcoin/math/elliptic_curve.hpp>
//#include <bitcoin/bitcoin/utility/data.hpp>
#include <utility_data_chunk.hpp>
#include <p_std_string.hpp>
#include <string_vector.hpp>
#include <uint32_t_vector.hpp>
//#include <bitcoin/bitcoin/utility/reader.hpp>
//#include <bitcoin/bitcoin/utility/writer.hpp>

namespace libbitcoin {
//namespace message {
namespace api {

class BC_API message_alert_payload
{
public:
    static message_alert_payload factory(uint32_t version, const utility_data_chunk& data);
//    static message_alert_payload factory(uint32_t version, std::istream& stream);
//    static message_alert_payload factory(uint32_t version, reader& source);

    message_alert_payload();
//    message_alert_payload(uint32_t version, uint64_t relay_until, uint64_t expiration,
//        uint32_t id, uint32_t cancel, const uint32_t_vector& set_cancel,
//        uint32_t min_version, uint32_t max_version,
//        const string_vector& set_sub_version, uint32_t priority,
//        const std::string& comment, const std::string& status_bar,
//        const std::string& reserved);
    message_alert_payload(uint32_t version, uint64_t relay_until, uint64_t expiration,
        uint32_t id, uint32_t cancel, uint32_t_vector&& set_cancel,
        uint32_t min_version, uint32_t max_version,
        string_vector&& set_sub_version, uint32_t priority,
        p_std_string& comment, p_std_string& status_bar,
        p_std_string& reserved);
//    message_alert_payload(const message_alert_payload& other);
    message_alert_payload(message_alert_payload&& other);

    uint32_t version() const;
    void set_version(uint32_t value);

    uint64_t relay_until() const;
    void set_relay_until(uint64_t value);

    uint64_t expiration() const;
    void set_expiration(uint64_t value);

    uint32_t id() const;
    void set_id(uint32_t value);

    uint32_t cancel() const;
    void set_cancel(uint32_t value);

    uint32_t_vector& set_cancel();
//    const uint32_t_vector& set_cancel() const;
//    void set_set_cancel(const uint32_t_vector& value);
    void set_set_cancel(uint32_t_vector&& value);

    uint32_t min_version() const;
    void set_min_version(uint32_t value);

    uint32_t max_version() const;
    void set_max_version(uint32_t value);

    string_vector& set_sub_version();
//    const string_vector& set_sub_version() const;
//    void set_set_sub_version(const string_vector& value);
    void set_set_sub_version(string_vector&& value);

    uint32_t priority() const;
    void set_priority(uint32_t value);

    p_std_string comment();
//    const std::string& comment() const;
//    void set_comment(const std::string& value);
    void set_comment(p_std_string& value);

    p_std_string status_bar();
//    const p_std_string status_bar() const;
//    void set_status_bar(const std::string& value);
    void set_status_bar(p_std_string& value);

    p_std_string reserved();
//    const p_std_string reserved() const;
//    void set_reserved(const std::string& value);
    void set_reserved(p_std_string& value);

    bool from_data(uint32_t version, const utility_data_chunk& data);
//    bool from_data(uint32_t version, std::istream& stream);
//    bool from_data(uint32_t version, reader& source);
    utility_data_chunk to_data(uint32_t version) const;
//    void to_data(uint32_t version, std::ostream& stream) const;
//    void to_data(uint32_t version, writer& sink) const;
    bool is_valid() const;
    void reset();
    size_t serialized_size(uint32_t version) const;

    /// This class is move assignable but not copy assignable.
//    alert_payload& operator=(alert_payload&& other);
    message_alert_payload& assign(message_alert_payload&& other);
//    void operator=(const alert_payload&) = delete;
//    void operator=(const alert_payload&) = delete;

//    bool operator==(const alert_payload& other) const;
    bool eq(const message_alert_payload& other) const;
//    bool operator!=(const alert_payload& other) const;
    bool ne(const message_alert_payload& other) const;

//    static const ec_uncompressed satoshi_public_key;

public:
    message::alert_payload getValue() {
        return value;
    }

    void setValue(message::alert_payload value) {
        this->value = value;
    }
private:
    message::alert_payload value;
//    uint32_t version_;
//    uint64_t relay_until_;
//    uint64_t expiration_;
//    uint32_t id_;
//    uint32_t cancel_;
//    uint32_t_vector set_cancel_;
//    uint32_t min_version_;
//    uint32_t max_version_;
//    string_vector set_sub_version_;
//    uint32_t priority_;
//    std::string comment_;
//    std::string status_bar_;
//    std::string reserved_;
};

} // namespace api
//} // namespace message
} // namespace libbitcoin

#endif