#ifndef NAMESPACE_H
#define NAMESPACE_H

#include <string>

namespace  FSM {
    enum EVENT {
        IOS_HOLD,
        RADAR_POWER_ON,
        IOS_PAR_SET,
        IOS_PAUSE,
        IOS_OPERATE,
        QUICK_WARMUP_TRUE,
        QUICK_WARMUP_FALSE,
        RADAR_POWER_OFF,
        WOW_TRUE,
        WOW_FALSE,
        RADAR_TOTAL_FAIL_TRUE,
        RADAR_TOTAL_FAIL_FALSE,
        RADAR_SHUTDOWN_TRUE,
        RADAR_SHUTDOWN_FALSE,
        LIQUID_COOLANT_FAILURE_TRUE,
        LIQUID_COOLANT_FAILURE_FALSE,
		SHUTDOWN_FAILURE_OVERRIDE_TRUE,
		SHUTDOWN_FAILURE_OVERRIDE_FALSE,
        EVENT_INVALID,
        EVENT_UNKNOWN,
        EVENT_NULL,
        EVENT_MAX_VALUE
    };

    const std::string events[] = {
        std::string("IOS_HOLD"),
        std::string("RDR_POWER_ON"),
        std::string("IOS_PAR_SET"),
        std::string("IOS_PAUSE"),
        std::string("IOS_OPERATE"),
        std::string("QUICK_WARMUP_TRUE"),
        std::string("QUICK_WARMUP_FALSE"),
        std::string("RDR_POWER_OFF"),
        std::string("WOW_TRUE"),
        std::string("WOW_FALSE"),
        std::string("RADAR_TOTAL_FAIL_TRUE"),
        std::string("RADAR_TOTAL_FAIL_FALSE"),
        std::string("RADAR_SHUTDOWN_TRUE"),
        std::string("RADAR_SHUTDOWN_FALSE"),
        std::string("LIQUID_COOLANT_FAILURE_TRUE"),
        std::string("LIQUID_COOLANT_FAILURE_FALSE"),
		std::string("SHUTDOWN_FAILURE_OVERRIDE_TRUE"),
		std::string("SHUTDOWN_FAILURE_OVERRIDE_FALSE"),
        std::string("EVENT_INVALID"),
        std::string("EVENT_UNKNOWN"),
        std::string("EVENT_NULL")
    };

    enum STATE
    {
        OFF,
        WARMUP,
        STANDBY,
        ON,
        HOLD,
        TOTAL_FAIL,
        INVALID,
        MAX_VALUE
    };

    const std::string states[] = {
        std::string("OFF"),
        std::string("WARMUP"),
        std::string("STANDBY"),
        std::string("ON"),
        std::string("HOLD"),
        std::string("TOTAL FAIL"),
        std::string("INVALID")
    };
}

#endif // NAMESPACE_H
