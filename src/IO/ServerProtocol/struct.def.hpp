template <typename Protocol, typename ... Arguments>
struct T
{
	T (Arguments ... arguments);

	std::unique_ptr <Protocol>
	make ();

	~T () = default;

private:

	std::tuple <Arguments ...> m_arguments;
};

static_assert
(
	IsServerProtocol::T <T <DummyProtocol::T>>::value
);
