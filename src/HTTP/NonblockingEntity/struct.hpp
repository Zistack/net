struct T : Entity::T
{
	T (const std::shared_ptr<IO::Interface::NonblockingByteBlock::T> &
	        byte_block);

	T (std::shared_ptr<IO::Interface::NonblockingByteBlock::T> && byte_block);

	bool
	isNonblocking () const override;

	IO::Interface::NonblockingByteBlock::T &
	asNonblocking () override;

	void
	reset () override;

	off_t
	size () const override;

	~T () override = default;

	private:
	std::shared_ptr<IO::Interface::NonblockingByteBlock::T> byte_block;
};
