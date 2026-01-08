/*
 *Scenario: You are building a high-performance backend.
 *The system needs to support multiple caching backends (e.g., Redis, Memcached)
 *depending on the environment (Dev vs. Production).
 *
Requirements:

Config-Driven: The cache type must be decided at runtime based on a configuration object.

Avoid Conditional Complexity: Do not use long if-else or switch chains in the Factory.

Memory Safety: Ensure no memory leaks

Extensibility: New cache types should be addable without modifying the CacheFactory source code.
 */

#include<iostream>
#include<map>
#include<functional>
#include<stdexcept>
#include<memory>
#include<string>

/**
 Interface
 *
 */

class ICache {
public:
    virtual void set(const std::string &key, const std::string &value) =0;

    virtual std::string get(const std::string &key) = 0;

    virtual ~ICache() = default;
};

/** Extensible concrete products
 *
 */
class RedisCache : public ICache {
public:
    void set(const std::string &key, const std::string &value) override {
        std::cout << key << " rediscache " << value << std::endl;
    };
    std::string get(const std::string &key) override {
        return key;
    };
};

class MemcachedCache : public ICache {
    public:
    void set(const std::string &key, const std::string &value) override {
        std::cout << key << " memcached " << value << std::endl;
    }
    std::string get(const std::string &key) override {
        return key;
    }
};

//for avoiding if else we can use a registry based approach

struct Config {
    std::string cacheType;
};


class CacheFactory {
    public:
       using CreatorFunc = std::function<std::unique_ptr<ICache>()>;
       static void registerCache(const std::string &cacheType, CreatorFunc creator) {
           getRegistry()[cacheType] = creator;
       };

       static std::unique_ptr<ICache> create(const Config& cfg) {
           auto it = getRegistry().find(cfg.cacheType);
           if (it == getRegistry().end()) {
               throw std::runtime_error("No cache type registered");
           }
           return it->second();
       }

private:
    static std::map<std::string, CreatorFunc>& getRegistry() {
        static std::map<std::string, CreatorFunc> registry;
        return registry;
    }
};

int main() {
    CacheFactory::registerCache("redis",[](){ return std::make_unique<RedisCache>(); });
    CacheFactory::registerCache("memcached", [](){return std::make_unique<MemcachedCache>();});

    Config cfg = {"redis"};

    try {
        auto cache = CacheFactory::create(cfg);
        cache->set("user", "value");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}


