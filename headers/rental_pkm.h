#ifndef RENTAL_PKM
#define RENTAL_PKM

class RentalPkm
{
public:
    RentalPkm(short id=1, short level=2){
        cl_rental_pkm_id = id;
        cl_rental_pkm_level = level;
    }
    // ~RentalPkm();

    short getRentalPkmId(){ return cl_rental_pkm_id; }
    short getRentalPkmLevel(){ return cl_rental_pkm_level; }

    void setRentalPkmId(short id=1){
         cl_rental_pkm_id = id;
    }
    void setRentalPkmLevel(short level=2){
         cl_rental_pkm_level = level;
    }

// private:
    short cl_rental_pkm_id;
    short cl_rental_pkm_level;
};

#endif // RENTAL_PKM
