#include <vector>
#include <map>
#include <exception>
#include <stdexcept>

namespace advalgo {

// This "identity mapper" purpose is to provide a no-overhead implementation if the entries are integers in a reasonable range (like 0 to n-1)
// It also illustrates the "interface" for a mapper
class identity_mapper
{
public:
    size_t operator[](size_t val) const
    {
        return get(val);
    }
    
    size_t get(size_t val) const
    {
        return val;
    }
    
    size_t get_reverse(size_t val) const
    {
        return val;
    }
};

template <typename T>
class ordered_mapper
{
public:    
    size_t operator[](const T& val)
    {
        return insert(val);
    }
    
    size_t operator[](const T& val) const
    {
        return get(val);
    }
    
    size_t get(const T& val) const
    {
        auto it = _mapping.find(val);
        if(it == _mapping.end())
        {
            throw std::invalid_argument();
        }
        
        return it->second;
    }
    
    T get_reverse(size_t val) const
    {
        if(val > _reverseMapping.size())
        {
            throw std::invalid_argument();
        }
        
        return _reverseMapping[val];
    }
    
    bool contains(const T& val) const
    {
        auto it = _mapping.find(val);
        return (it != _mapping.end());
    }
    
    size_t size() const
    {
        return _mapping.size();
    }
    
private:
    size_t insert(const T& val)
    {
        auto pairItBool = _mapping.emplace(val, _mapping.size());
        return pairItBool.first->second;
    }
    
private:
    std::map<T, size_t> _mapping;
    std::vector<T> _reverseMapping;
};

} /* namespace advalgo */