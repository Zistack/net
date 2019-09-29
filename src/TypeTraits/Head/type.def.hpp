template <typename ... Types>
using T = std::tuple_element_t <0, std::tuple <Types ...>>;
