#pragma once
template<typename T>
class Vertex {
public:
    using id_type = std::size_t;

    id_type id{};
    T value{};

    bool operator==(const Vertex& rhs) const noexcept {
        return id == rhs.id && value == rhs.value;
    }
};