template <typename Responder, typename ... UpgradeTargets>
struct T : Base::T <Responder, UpgradeTargets ...>
{
	template <typename ... ResponderArguments, typename ... UpgradeArguments>
	T
	(
		std::chrono::milliseconds input_timeout,
		std::chrono::milliseconds output_timeput,
		const TransferEncoding::Config::T & transfer_encoding_config,
		uint64_t temp_file_threshhold,
		const std::tuple <ResponderArguments ...> & responder_arguments,
		UpgradeArguments && ... upgrade_arguments
	);

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

private:

	bool m_cancelled;
};
