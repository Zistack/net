struct T : Entity::T
{
	T (const std::shared_ptr<IO::Interface::ByteBlock::T> & byte_block);

	T (std::shared_ptr<IO::Interface::ByteBlock::T> && byte_block);

	bool
	isBlocking () const override;

	IO::Interface::ByteBlock::T &
	asBlocking () override;

	~T () override = default;

	private:
	std::shared_ptr<IO::Interface::ByteBlock::T> byte_block;
};
