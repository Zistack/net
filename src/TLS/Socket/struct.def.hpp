template <typename Specialization>
struct T : private StreamInterface::T <Specialization>
{
	using StreamInterface::T <Specialization>::reciever;
	using StreamInterface::T <Specialization>::sender;

protected:

	using StreamInterface::T <Specialization>::T;

	~T () = default;

private:

	using StreamInterface::T <Specialization>::tcp_socket;
	using StreamInterface::T <Specialization>::session;
};
