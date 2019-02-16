template <typename MemberType>
T::T (std::string identifier,
    std::string description,
    bool optional,
    std::optional<typename MemberType::ValueType::InterfaceType>
        default_value) :
    identifier (identifier),
    type (std::make_unique<MemberType> ()),
    description (description),
    optional (optional),
    default_value (default_value ?
            std::make_unique<MemberType::ValueType> (*default_value) :
            nullptr)
{
}
