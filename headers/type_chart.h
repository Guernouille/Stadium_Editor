#ifndef TYPE_CHART
#define TYPE_CHART

class TypeChart
{
public:
    TypeChart(short type1=0, short type2=0, short multiplier=10){
        cl_type1 = type1;
        cl_type2 = type2;
        cl_multiplier = multiplier;
    }
    // ~TypeChart();

    short getType1(){ return cl_type1; }
    short getType2(){ return cl_type2; }
    short getMultiplier(){ return cl_multiplier; }

    void setType1(short type1=0){
         cl_type1 = type1;
    }
    void setType2(short type2=0){
         cl_type2 = type2;
    }
    void setMultiplier(short multiplier=0){
         cl_multiplier = multiplier;
    }

private:
    short cl_type1;
    short cl_type2;
    short cl_multiplier;
};

#endif // TYPE_CHART
