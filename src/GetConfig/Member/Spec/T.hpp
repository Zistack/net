template <typename MemberType>
T::T (std::string identifier,
    std::string description,
    bool optional,
    const MemberType & type,
    std::optional<typename MemberType::ValueType::InterfaceType>
        default_value) :
    identifier (identifier),
    type (std::make_unique<MemberType> (type)),
    description (description),
    optional (optional),
    default_value (default_value ?
            std::make_unique<MemberType::ValueType> (*default_value) :
            nullptr)
{
}

T::T (const T & other) :
    identifier (other.identifier),
    description (other.description),
    optional (other.optional),
    type (other.type->clone ()),
    default_value (
        other.default_value ? other.default_value->clone () : nullptr)
{
}
