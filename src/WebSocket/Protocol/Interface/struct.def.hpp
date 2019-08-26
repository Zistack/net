template <typename Dispatcher>
struct T : Implementation::T <Dispatcher>
{
	using Implementation::T <Dispatcher>::T;

private:

	using Implementation::T <Dispatcher>::output;

	friend Input::T <T, Dispatcher>;
	friend Output::T <T>;
};

