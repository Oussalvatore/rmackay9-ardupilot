/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef AP_Compass_PX4_H
#define AP_Compass_PX4_H

#include "Compass.h"
#include "AP_Compass_Backend.h"

class AP_Compass_PX4 : public AP_Compass_Backend
{
public:
    bool        init(void);
    bool        read(void);
    void        accumulate(void);

    // return the number of compass instances
    uint8_t get_count(void) const { return _num_instances; }

    // return the primary compass
    uint8_t get_primary(void) const;

    AP_Compass_PX4(Compass &compass);
    // detect the sensor
    static AP_Compass_Backend *detect(Compass &compass);

private:
    uint8_t  _num_instances;
    int      _mag_fd[COMPASS_MAX_INSTANCES];
    Vector3f _sum[COMPASS_MAX_INSTANCES];
    uint32_t _count[COMPASS_MAX_INSTANCES];
    uint64_t _last_timestamp[COMPASS_MAX_INSTANCES];

    virtual bool        read_raw(void) { return false;}
    virtual bool        re_initialise(void) {return false;}

};

#endif // AP_Compass_PX4_H

