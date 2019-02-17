T::T (bool optional,
    const std::unique_ptr<GetConfig::Member::Type::T> & type,
    const std::unique_ptr<GetConfig::Member::Value::T> & value) :
    optional (optional),
    type (type->clone ()),
    value (value ? value->clone () : nullptr)
{
}

T::T (const T & other) : T (other.optional, other.type, other.value) {}
