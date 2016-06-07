#ifndef TYPE_CHART
#define TYPE_CHART

class TypeChart
{
public:
    TypeChart(int8_t type1=0, int8_t type2=0, int8_t multiplier=10){
        cl_type1 = type1;
        cl_type2 = type2;
        cl_multiplier = multiplier;
    }
    // ~TypeChart();

    uint8_t getType1(){ return cl_type1; }
    uint8_t getType2(){ return cl_type2; }
    uint8_t getMultiplier(){ return cl_multiplier; }

    void setType1(int8_t type1=0){
         cl_type1 = type1;
    }
    void setType2(int8_t type2=0){
         cl_type2 = type2;
    }
    void setMultiplier(int8_t multiplier=0){
         cl_multiplier = multiplier;
    }

private:
    uint8_t cl_type1;
    uint8_t cl_type2;
    uint8_t cl_multiplier;
};

#endif // TYPE_CHART
