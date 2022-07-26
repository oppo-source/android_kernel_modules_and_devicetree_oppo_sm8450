/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2018, The Linux Foundation. All rights reserved.
 */

#ifndef _OPLUS_CAM_SENSOR_CORE_H_
#define _OPLUS_CAM_SENSOR_CORE_H_
#include "cam_sensor_dev.h"

#define CAM_IMX709_SENSOR_ID 0x709

struct cam_sensor_i2c_reg_setting_array {
	struct cam_sensor_i2c_reg_array reg_setting[1280];
	unsigned short size;
	enum camera_sensor_i2c_type addr_type;
	enum camera_sensor_i2c_type data_type;
	unsigned short delay;
};

struct cam_sensor_settings {
	struct cam_sensor_i2c_reg_setting_array imx586_setting0;
	struct cam_sensor_i2c_reg_setting_array imx586_setting1;
	struct cam_sensor_i2c_reg_setting_array streamoff;
	struct cam_sensor_i2c_reg_setting_array s5k3m5_setting;
	struct cam_sensor_i2c_reg_setting_array imx471_setting;
	struct cam_sensor_i2c_reg_setting_array imx481_setting;
	struct cam_sensor_i2c_reg_setting_array gc5035_setting;
	struct cam_sensor_i2c_reg_setting_array imx689_setting;
	struct cam_sensor_i2c_reg_setting_array gc2375_setting;

	struct cam_sensor_i2c_reg_setting_array hi846_setting; //Rear_UW
	struct cam_sensor_i2c_reg_setting_array imx615_setting; //Front_Main
	struct cam_sensor_i2c_reg_setting_array imx616_setting; //Front_Main
	struct cam_sensor_i2c_reg_setting_array gc8054_setting; //Front_UW
	struct cam_sensor_i2c_reg_setting_array ov02b10_setting;
	struct cam_sensor_i2c_reg_setting_array ov8856_setting;
	struct cam_sensor_i2c_reg_setting_array gc02m1b_setting;
	struct cam_sensor_i2c_reg_setting_array imx686_setting;
	struct cam_sensor_i2c_reg_setting_array imx789_setting;
	struct cam_sensor_i2c_reg_setting_array ov08a10_setting;
	struct cam_sensor_i2c_reg_setting_array imx766_setting;
	struct cam_sensor_i2c_reg_setting_array imx682_setting;
	struct cam_sensor_i2c_reg_setting_array imx709_setting;
	struct cam_sensor_i2c_reg_setting_array s5kjn1sq03_setting;
};

int cam_ftm_power_down(struct cam_sensor_ctrl_t *s_ctrl);
int cam_ftm_power_up(struct cam_sensor_ctrl_t *s_ctrl);

bool cam_ftm_if_do(void);

int oplus_cam_sensor_update_setting(struct cam_sensor_ctrl_t *s_ctrl);
void cam_sensor_get_dt_data(struct cam_sensor_ctrl_t *s_ctrl);

uint32_t cam_override_chipid(struct cam_sensor_ctrl_t *s_ctrl);

int cam_sensor_match_id_oem(struct cam_sensor_ctrl_t *s_ctrl,uint32_t chip_id);

int32_t cam_sensor_update_id_info(struct cam_cmd_probe_v2 *probe_info,
    struct cam_sensor_ctrl_t *s_ctrl);

int cam_sensor_stop(struct cam_sensor_ctrl_t *s_ctrl);
int cam_sensor_start(struct cam_sensor_ctrl_t *s_ctrl);
int32_t oplus_cam_sensor_driver_cmd(struct cam_sensor_ctrl_t *s_ctrl,void *arg);

#endif /* _OPLUS_CAM_SENSOR_CORE_H_ */
