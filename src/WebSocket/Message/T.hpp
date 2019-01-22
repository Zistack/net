T::T (Type::T message_type, std::unique_ptr<HTTP::Entity::T> && body) :
    message_type (message_type),
    body (std::move (body))
{
}
