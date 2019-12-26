template <typename Interface, typename ... UpgradeTargets>
struct T : FIFOProtocolInterface::T <Interface, UpgradeTargets ...>
{
	using FIFOProtocolInterface::T <Interface, UpgradeTargets ...>::prime;

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

protected:

	template <typename ... UpgradeArguments>
	T
	(
		const Config::T & config,
		const std::optional <HostData::T> & host_data,
		UpgradeArguments && ... upgrade_arguments
	);

	const T &
	http () const;

	T &
	http ();

	~T () = default;

private:

	using FIFOProtocolInterface::T <Interface, UpgradeTargets ...>::readRequest;
	using FIFOProtocolInterface::T <Interface, UpgradeTargets ...>::map;
	using FIFOProtocolInterface::
		T <Interface, UpgradeTargets ...>::
		writeResponse;

	using FIFOProtocolInterface::
		T <Interface, UpgradeTargets ...>::
		m_upgrade_mutex;
	using FIFOProtocolInterface::
		T <Interface, UpgradeTargets ...>::
		m_upgrade_factory;
	using FIFOProtocolInterface::
		T <Interface, UpgradeTargets ...>::
		m_upgrade_protocol;

	bool m_cancelled;
};
