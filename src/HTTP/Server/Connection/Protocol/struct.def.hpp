template <typename Interface, typename ... UpgradeTargets>
struct T : private FIFOProtocolInterface::T <Interface, UpgradeTargets ...>
{
	template <typename ... UpgradeArguments>
	T (const Config::T & config, UpgradeArguments && ... upgrade_arguments);

	using FIFOProtocolInterface::T <Interface, UpgradeTargets ...>::prime;

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

private:

	bool m_cancelled;
};
