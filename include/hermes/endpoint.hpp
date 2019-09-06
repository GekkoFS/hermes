#ifndef __HERMES_ENDPOINT_HPP__
#define __HERMES_ENDPOINT_HPP__

#include <cstddef>
#include <string>
#include <memory>

#include <hermes/detail/address.hpp>

namespace hermes {

/** */
class endpoint {

    friend class async_engine;

    endpoint(const std::shared_ptr<detail::address>& address) :
        m_address(address) { }

public:
    endpoint(const endpoint& /*other*/) = default;
    endpoint& operator=(const endpoint& /*other*/) = default;
    endpoint(endpoint&& /*rhs*/) = default;
    endpoint& operator=(endpoint&& /*rhs*/) = default;

    const std::string
    to_string() const {
        return m_address->to_string();
    }

private:
    std::shared_ptr<detail::address>
    address() const {
        return m_address;
    }

private:
    std::shared_ptr<detail::address> m_address;
}; // class endpoint

} // namespace hermes

#endif // __HERMES_ENDPOINT_HPP__
