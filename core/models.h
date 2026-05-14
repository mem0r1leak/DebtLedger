#pragma once
#include <cstdint>
#include <string>
#include <unordered_set>
#include <chrono>
#include <utility>

#include "uuid/uuid.h"

struct Product {
    Product(const uuid_t uid, std::string name, const uint32_t price, const std::chrono::seconds &timestamp)
        : name(std::move(name)),
          price(price),
          addition_timestamp(timestamp) {
        uuid_copy(id, uid);
    }

    uuid_t id{};
    std::string name;
    uint32_t price;
    std::chrono::seconds addition_timestamp;
};

struct HistProduct {
    Product product;
    std::vector<uuid_t> owners;
};

using ShoppingHistory = std::vector<HistProduct>;

struct Shared {
    std::vector<Product> wishlist;
    ShoppingHistory hist;
};

template <>
struct std::hash<Product> {
    size_t operator()(const Product& p) const noexcept {
        const size_t id = std::hash<const unsigned char*>{}(p.id);
        const size_t name = std::hash<std::string>{}(p.name);
        const size_t price = std::hash<uint32_t>{}(p.price);
        return id ^ name << 1 ^ price << 2;
    }
};

struct User {
    uuid_t id;
    std::string name;
    uint32_t debt;
    std::unordered_set<Product> products;
};
