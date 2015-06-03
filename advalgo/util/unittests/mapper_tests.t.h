// MyTestSuite.h
#include <cxxtest/TestSuite.h>
#include "mapper.h"
#include <string>

using namespace advalgo;

class MapperTests : public CxxTest::TestSuite
{
public:
    void testNewOrderedMapperIsEmpty()
    {
        ordered_mapper<int> om;
        TS_ASSERT_EQUALS(0, om.size());
    }
    
    void testFirstElementUsedInOrderedMapperMapsToZero()
    {
        ordered_mapper<std::string> om;
        TS_ASSERT_EQUALS(0, om["zero"]);
    }
    
    void testSecondElementUsedInOrderedMapperMapsToOne()
    {
        ordered_mapper<std::string> om;
        om["zero"];
        TS_ASSERT_EQUALS(1, om["one"]);
    }
    
    void testEachNewElementMapsToPreviousSize()
    {
        ordered_mapper<std::string> om;
        size_t num_iterations = 10;
        for(size_t i=0;i<num_iterations;++i)
        {
            char number[10];
            snprintf(number, sizeof(number), "%lu", i);
            TS_ASSERT_EQUALS(i, om[number]);
        }
    }
    
    void testExistingElementMapsToPreviousValue()
    {
        ordered_mapper<std::string> om;
        TS_ASSERT_EQUALS(0, om["zero"]);
        TS_ASSERT_EQUALS(1, om["one"]);
        TS_ASSERT_EQUALS(0, om["zero"]);
    }
    
};
