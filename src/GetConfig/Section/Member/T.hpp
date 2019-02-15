T::T (bool optional,
    const std::unique_ptr<MemberType::T> & type,
    const std::unique_ptr<MemberValue::T> & value) :
    optional (optional),
    type (type->clone ()),
    value (value ? value->clone () : nullptr)
{
}

T::T (const T & other) : T (other.optional, other.type, other.value) {}
