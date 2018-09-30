T::T () : T (nullptr, nullptr) {}

T::T (std::function<void(void)> setCallback,
    std::function<void(void)> clearCallback) :
    state (false),
    setCallback (setCallback),
    clearCallback (clearCallback)
{
}
