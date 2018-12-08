T::T (const std::shared_ptr<IO::Interface::ByteBlock::T> & byte_block) :
    byte_block (byte_block)
{
}

T::T (std::shared_ptr<IO::Interface::ByteBlock::T> && byte_block) :
    byte_block (std::move (byte_block))
{
}
