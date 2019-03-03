T::T (std::chrono::milliseconds output_timeout, uint64_t chunk_size) :
    output_timeout (output_timeout),
    message_sender (output_timeout, chunk_size, this->output_mutex),
    ping_pong_sender (output_timeout, this->output_mutex),
    close_bit (this->close_mutex)
{
}
