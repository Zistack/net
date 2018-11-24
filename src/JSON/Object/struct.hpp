struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	template <class Iterable,
	    typename = typename std::enable_if<std::is_convertible<
	        decltype (*std::declval<Iterable> ().begin ()),
	        std::pair<std::string, std::unique_ptr<Value::T>>>::value>::type>
	T (const Iterable & members);

	bool
	contains (const std::string & name) const;

	Value::T *
	at (const std::string & name) const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation = 0) override;

	T &
	asObject () override;

	~T () override = default;

	private:
	std::unordered_map<std::string, std::unique_ptr<Value::T>> members;
};
