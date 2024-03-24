#include <string>
#include <tuple>
#include <type_traits>
#include "dbg.h"

using UserInfo = std::tuple<std::string, std::string, std::size_t>;

enum class UserInfoFields
{
    uiName,
    uiEmail,
    uiReputation
};

template <typename E>
using uderlying_type_t = typename std::underlying_type<E>::type;

template <typename E>
constexpr uderlying_type_t<E> toUType(E enumerator) noexcept
{
    return static_cast<uderlying_type_t<E>>(enumerator);
}

// template <typename E>
// constexpr auto toUType(E enumerator) noexcept
// {
//     return static_cast<std::underlying_type_t<E>>(enumerator);
// }

int main()
{
    UserInfo uInfo;
    std::get<toUType(UserInfoFields::uiName)>(uInfo) = "Scott Meyers";
    dbg(uInfo);
}