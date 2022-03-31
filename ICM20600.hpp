#include "I2CUtils/I2C_Device.hpp"

#pragma once

#ifndef __ICM20600_HPP__
#define __ICM20600_HPP__

class ICM20600 : public I2CDevice {
private:

    //
    constexpr static uint8_t _xg_offs_tcH = 0x04;
    constexpr static uint8_t _xg_offs_tcL = 0x05;    
    constexpr static uint8_t _yg_offs_tcH = 0x07;
    constexpr static uint8_t _yg_offs_tcL = 0x08;
    constexpr static uint8_t _zg_offs_tcH = 0x0A;
    constexpr static uint8_t _zg_offs_tcL = 0x0B;
    //
    constexpr static uint8_t _self_test_x_acc = 0x0D;
    constexpr static uint8_t _self_test_y_acc = 0x0E;
    constexpr static uint8_t _self_test_z_acc = 0x0F;
    //
    constexpr static uint8_t _xg_offs_usrH = 0x13;
    constexpr static uint8_t _xg_offs_usrL = 0x14;    
    constexpr static uint8_t _yg_offs_usrH = 0x15;
    constexpr static uint8_t _yg_offs_usrL = 0x16;
    constexpr static uint8_t _zg_offs_usrH = 0x17;
    constexpr static uint8_t _zg_offs_usrL = 0x18;
    //
    constexpr static uint8_t _smplrt_div = 0x19;
    //
    constexpr static uint8_t _config = 0x1A;
    constexpr static uint8_t _gyro_config = 0x1B;
    constexpr static uint8_t _acc_config = 0x1C;
    constexpr static uint8_t _acc_config2 = 0x1D;
    constexpr static uint8_t _lp_mode_cfg = 0x1E;
    //
    constexpr static uint8_t _acc_wom_x_thr = 0x20;
    constexpr static uint8_t _acc_wom_y_thr = 0x21;
    constexpr static uint8_t _acc_wom_z_thr = 0x22;
    //
    constexpr static uint8_t _fifo_en = 0x23;
    constexpr static uint8_t _fsync_int = 0x36;
    constexpr static uint8_t _int_pin_cfg = 0x37;
    constexpr static uint8_t _int_en = 0x38;
    constexpr static uint8_t _fifo_wm_int_stat = 0x39;
    constexpr static uint8_t _int_stat = 0x3A;
    //
    constexpr static uint8_t _acc_xoutH = 0x3B;
    constexpr static uint8_t _acc_xoutL = 0x3C;
    constexpr static uint8_t _acc_youtH = 0x3D;
    constexpr static uint8_t _acc_youtL = 0x3E;
    constexpr static uint8_t _acc_zoutH = 0x3F:
    constexpr static uint8_t _acc_zoutL = 0x40;
    constexpr static uint8_t _temp_outH = 0x41;
    constexpr static uint8_t _temp_outL = 0x42;
    constexpr static uint8_t _gyro_xoutH = 0x43;
    constexpr static uint8_t _gyro_xoutL = 0x44;
    constexpr static uint8_t _gyro_youtH = 0x45;
    constexpr static uint8_t _gyro_youtL = 0x46;
    constexpr static uint8_t _gyro_zoutH = 0x47;
    constexpr static uint8_t _gyro_zoutL = 0x48;
    //
    constexpr static uint8_t _self_test_x_gyro = 0x50;
    constexpr static uint8_t _self_test_y_gyro = 0x51;
    constexpr static uint8_t _self_test_z_gyro = 0x52;
    //
    constexpr static uint8_t _fifo_wm_th1 = 0x60;
    constexpr static uint8_t _fifo_wm_th2 = 0x61;
    constexpr static uint8_t _signal_path_rst = 0x68;
    constexpr static uint8_t _acc_intel_ctrl = 0x69;
    constexpr static uint8_t _usr_ctrl = 0x6A;
    constexpr static uint8_t _pwr_mgmt_1 = 0x6B;
    constexpr static uint8_t _pwr_mgmt_2 = 0x6C;
    constexpr static uint8_t _i2c_cf = 0x70;
    constexpr static uint8_t _fifo_cntH = 0x72;
    constexpr static uint8_t _fifo_cntL = 0x73;
    constexpr static uint8_t _fifo_r_w = 0x74;
    constexpr static uint8_t _who_am_i = 0x75;
    //
    constexpr static uint8_t _xa_offsH = 0x77;
    constexpr static uint8_t _xa_offsL = 0x78;
    constexpr static uint8_t _ya_offsH = 0x7A;
    constexpr static uint8_t _ya_offsL = 0x7B;
    constexpr static uint8_t _za_offsH = 0x7D;
    constexpr static uint8_t _za_offsL = 0x7E;

    constexpr static uint8_t _def_base_address = 0x68;
    

public:

    enum class gyro_range : uint8_t {
        RANGE_250DPS    = 0b00,
        RANGE_500DPS    = 0b01,
        RANGE_1KDPS     = 0b10,
        RANGE_2KDPS     = 0b11
    }

    enum class acc_range : uint8_t {
        RANGE_2G    = 0b00,
        RANGE_4G    = 0b01,
        RANGE_8G    = 0b10,
        RANGE_16G   = 0b11
    }

    enum class acc_lp_filter_samples : uint8_t {
        SAMPLES_4   = 0b00,
        SAMPLES_8   = 0b01,
        SAMPLES_16  = 0b10,
        SAMPLES_32  = 0b11
    }

    ICM20600(uint8_t i2c_addr) : I2CDevice(i2c_addr) {};

    ICM20600() : I2CDevice(_def_base_address) {};

    void begin(){
        Wire.begin();
    }


};

#endif
