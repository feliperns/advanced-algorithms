#include <vector>
#include <map>
#include <exception>
#include <stdexcept>

template <typename T>
class mapper
{
public:
    void add(const T& val)
    {
        if(_mapping.find(val) == _mapping.end())
        {
            auto cur_size = _reverseMapping.size();
            _mapping[val] = cur_size;
            _reverseMapping.push_back(val);
        }
    }
    
    int map(const T& val) const
    {
        auto it = _mapping.find(val);
        if(it == _mapping.end())
        {
            throw std::invalid_argument();
        }
        
        return it->second;
    }
    
    T reverse_map(unsigned int val) const
    {
        if(val > _reverseMapping.size())
        {
            throw std::invalid_argument();
        }
        
        return _reverseMapping[val];
    }
    
private:
    std::map<T, unsigned int> _mapping;
    std::vector<T> _reverseMapping;
};