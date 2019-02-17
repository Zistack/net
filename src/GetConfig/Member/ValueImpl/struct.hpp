template <typename ValueType>
struct T : Value::T
{
	std::unique_ptr<Value::T>
	clone () const override;
};
