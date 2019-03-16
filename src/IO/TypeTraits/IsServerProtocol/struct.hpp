template <typename ServerProtocol,
    typename
#ifndef IO_TypeTraits_IsServerProtocol_struct_hpp
#define IO_TypeTraits_IsServerProtocol_struct_hpp
    = void
#endif /* IO_TypeTraits_IsServerProtocol_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename ServerProtocol>
using MakeResult = std::invoke_result_t<
    decltype (&std::remove_cv_t<std::remove_reference_t<ServerProtocol>>::make),
    std::remove_cv_t<std::remove_reference_t<ServerProtocol>> *>;

template <typename ServerProtocol>
using ConnectionProtocol = std::remove_reference_t<decltype (
    *std::declval<MakeResult<ServerProtocol>> ())>;

template <typename ServerProtocol>
static constexpr const bool returns_unique_ptr =
    std::is_same_v<MakeResult<ServerProtocol>,
        std::unique_ptr<ConnectionProtocol<ServerProtocol>>>;

template <typename ServerProtocol>
static constexpr const bool connection_protocol_is_protocol =
    IsProtocol::T<ConnectionProtocol<ServerProtocol>>::value;

template <typename ServerProtocol>
struct T<ServerProtocol,
    std::enable_if_t<returns_unique_ptr<ServerProtocol> &&
        connection_protocol_is_protocol<ServerProtocol>>> : std::true_type
{
};
